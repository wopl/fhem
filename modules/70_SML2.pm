##############################################################################
#
# 70_SML2.pm
#
# a module to show smartmeter data
#
# 2014 by Wolfram Plettscher <wolfram at plettscher.de>>
#
# $Id: 70_SML2.pm xxxx 2014-03-23 xx:xx:xxZ plettscher $
#
# Version = 0.1
#
##############################################################################
#
# define <name> SML2 <host> <port> [<interval>]
#
# The default for <interval> is 300 (i.e. 5 minutes).
#
##############################################################################

package main;
use IO::Socket::INET;

my @gets = ('HT',
      'NT', 
      'ACT', 
      'AVG'); 

##############################################################################
sub
SML2_Initialize($)
{
Log3 $hash, 4, "SML2_Initialize";
my ($hash) = @_;

 $hash->{DefFn}    = "SML2_Define";
 $hash->{UndefFn}  = "SML2_Undef";
}

##############################################################################
sub
SML2_Define($$)
  {
  Log3 $hash, 4, "SML2_Define";

  my ($hash, $def) = @_;
  my @args = split("[ \t]+", $def);

  if (int(@args) < 4)
    {
    return "energy_Define: too few arguments. Usage:\n" .
      "define <name> SML2 <host> <port> [<interval> [<timeout>]]";
    }

  $hash->{Host}     = $args[2];
  $hash->{Port}     = $args[3];

  ### default Interval = 5Min
  if ( int(@args) >= 5 ){
    $hash->{Interval} = int($args[4]);
  }else{
    $hash->{Interval} = 300;
  }

  ### default Timeout = 4s
  $hash->{Timeout} = int(@args) >= 6 ? int($args[5]) : 4;

  Log3 $hash, 4, "$hash->{NAME} will read from SML2 at $hash->{Host}:$hash->{Port} " ;

  $hash->{STATE} = "Initialized";
 
  ### initialize all "readings"
  my $timenow = TimeNow();
  for my $get (@gets)
    {
    $hash->{READINGS}{$get}{VAL}  = -1;
    $hash->{READINGS}{$get}{TIME} = $timenow;
    }

  ### enter mainLoop to read data from SmartMeter
  SML2_mainLoop($hash);

  return undef;

  } ### of sub SML2_Define

##############################################################################
sub
SML2_mainLoop($)
  {
  my ($hash) = @_;
  my $logmessage = "";
 
  Log3 $hash, 4, "SML2_mainLoop $hash->{Interval}";

  ### restart timer each time we enter this sub
  if ($hash->{Interval} > 0)
    {
    InternalTimer(gettimeofday() + $hash->{Interval}, "SML2_mainLoop", $hash, 0);
    }

  ### read HTML-page(s) and write updated "readings"
  read_HTNT ($hash);
  read_ActAvg ($hash);

  ### prepare message for logfile
  $logmessage .= "HT: " . $hash->{READINGS}{HT}{VAL};  
  $logmessage .= " NT: " . $hash->{READINGS}{NT}{VAL};  
  $logmessage .= " ACT: " . $hash->{READINGS}{ACT}{VAL};  
  $logmessage .= " AVG: " . $hash->{READINGS}{AVG}{VAL};  
  readingsSingleUpdate ($hash, "SML2", $logmessage, 1);

  return undef;

  } ### of sub SML2_mainLoop

##############################################################################
sub
read_HTNT($)
  {
  my ($hash) = @_;
  my $ip = $hash->{Host};
  my $port = $hash->{Port};
  my $timeout = $hash->{Timeout};
  my $url =  "/?action=20";
  my $socket ;
  my $buf ;
  my $message ;
  my @array ;
  my $counts = 0 ;
  my $HT = -1;
  my $NT = -1;

  Log3 $hash, 4, "$hash->{NAME} $ip : $port : $url";

  $socket = new IO::Socket::INET (
    PeerAddr => $ip,
    PeerPort => $port,
    Proto    => 'tcp',
    Reuse    => 0,
    Timeout  => $timeout
    );

  Log3 $hash, 4, "$hash->{NAME} socket new";

  if (defined ($socket) and $socket and $socket->connected())
    {
    Log3 $hash, 4, "$hash->{NAME} Connected ...";
    print $socket "GET $url HTTP/1.0\r\n\r\n";
    $socket->autoflush(1);

    ### read socket until buffer end
    while ((read $socket, $buf, 1024) > 0)
      {
      Log3 $hash, 5,"buf: $buf";
      $message .= $buf;
      }
    }else{
      Log3 $hash, 3, "$hash->{NAME} Cannot open socket ...";
      $success = 1;
      return 0;
    }

  ### check line by line
  @array = split(/\n/,$message);
  foreach (@array)
    {

    ### we test for "HT:"
    if ( $_ =~ /^<h3>(.*)HT:(.*)$/)
      {
      $HT = 1;
      }
    if ( $HT == 1 )
      {
      if ( $_ =~ /^<h3>(.*) kWh<\/h3>(.*)$/)
        {
        $HT = $1;
        $counts = 0;
        }
      }

    ### now we test for "NT:"
    if ( $_ =~ /^<h3>(.*)NT:(.*)$/)
      {
      $NT = 1;
      }
    if ( $NT == 1 )
      {
      if ( $_ =~ /^<h3>(.*) kWh<\/h3>(.*)$/)
        {
        $NT = $1;
        $counts = 0;
        }
      }

    } ### of foreach

  ### "HT:" and "NT:" found, prepare for "readings" Update
  readingsBeginUpdate ($hash);
  readingsBulkUpdate ($hash, "HT", $HT);
  readingsBulkUpdate ($hash, "NT", $NT);
  readingsEndUpdate ($hash, 1);
  Log3 $hash, 4, "HT= $HT";
  Log3 $hash, 4, "NT= $NT";

  } ### of sub read_HTNT

##############################################################################
sub
read_ActAvg($)
  {
  my ($hash) = @_;
  my $ip = $hash->{Host};
  my $port = $hash->{Port};
  my $timeout = $hash->{Timeout};
  my $url =  "/?action=1";
  my $socket ;
  my $buf ;
  my $message ;
  my @array ;
  my $ACT = -1;
  my $AVG = -1;

  Log3 $hash, 4, "$hash->{NAME} $ip : $port : $url";

  $socket = new IO::Socket::INET (
    PeerAddr => $ip,
    PeerPort => $port,
    Proto    => 'tcp',
    Reuse    => 0,
    Timeout  => $timeout
    );

  Log3 $hash, 4, "$hash->{NAME} socket new";

  if (defined ($socket) and $socket and $socket->connected())
    {
    Log3 $hash, 4, "$hash->{NAME} Connected ...";
    print $socket "GET $url HTTP/1.0\r\n\r\n";
    $socket->autoflush(1);

    ### read socket until buffer end
    while ((read $socket, $buf, 1024) > 0)
      {
      Log3 $hash, 5,"buf: $buf";
      $message .= $buf;
      }
    }else{
      Log3 $hash, 3, "$hash->{NAME} Cannot open socket ...";
      $success = 1;
      return 0;
    }

  ### check line by line
  @array = split(/\n/,$message);
  foreach (@array)
    {

    ### we test for "ACT:"
    ### looks like: <div class="whats">7 W</div>
    if ( $_ =~ /^<div class="whats">(.*) W(.*)$/)
     {
     $ACT = $1;
     }

    ### now we test for "AVG:"
    ### looks like: <div class="small-whats">16 W</div>
    if ( $_ =~ /^<div class="small-whats">(.*) W(.*)$/)
     {
     $AVG = $1;
     }

    } ### of foreach

  ### "ACT:" and "AVG:" found, prepare for "readings" Update
  readingsBeginUpdate ($hash);
  readingsBulkUpdate ($hash, "ACT", $ACT);
  readingsBulkUpdate ($hash, "AVG", $AVG);
  readingsEndUpdate ($hash, 1);
  Log3 $hash, 4, "ACT= $ACT";
  Log3 $hash, 4, "AVG= $AVG";

  } ### of sub read_ActAvg

##############################################################################
sub
SML2_Undef ($$)
{
Log3 $hash, 4, "SML2_Undef";
 my ($hash, $args) = @_;

 RemoveInternalTimer($hash) if $hash->{Interval};
 return undef;
}

1;
