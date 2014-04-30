# $Id: 70_UVRm.pm xxxx 2013-09-28 09:08:00Z wplettscher $
##############################################################################
###                                                                        ###
### UVRm heating control                   Copyright W.Plettscher, 12.2013 ###
###                                                                        ###
### Access "Technische Alternative UVR1611" through "Bootloader-NET        ###
### and read measures 1..16.                                               ###
###                                                                        ###
##############################################################################
#
#     This file is part of fhem.
# 
#     Fhem is free software: you can redistribute it and/or modify
#     it under the terms of the GNU General Public License as published by
#     the Free Software Foundation, either version 2 of the License, or
#     (at your option) any later version.
# 
#     Fhem is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#     GNU General Public License for more details.
# 
#     You should have received a copy of the GNU General Public License
#     along with fhem.  If not, see <http://www.gnu.org/licenses/>.
#


package main;

use strict;
use warnings;
#use Switch;
use Time::HiRes qw(gettimeofday);
use HttpUtils;

##############################################################################
###                                                                        ###
### UVRm_Initialize                                                        ###
###                                                                        ###
##############################################################################
sub UVRm_Initialize($) {

  my ($hash) = @_;

  $hash->{DefFn}   = "UVRm_Define";
  $hash->{UndefFn} = "UVRm_Undef";
  $hash->{GetFn}   = "UVRm_Get";
  $hash->{SetFn}   = "UVRm_Set";
  $hash->{AttrList}= "loglevel:0,1,2,3,4,5 localicons ".
                      $readingFnAttributes;

}

##############################################################################
###                                                                        ###
### UVRm_UpdateReading                                                     ###
###                                                                        ###
##############################################################################
sub UVRm_UpdateReading($$$$) {

  my ($hash,$prefix,$key,$value)= @_;

  Log 1, "DEBUG updateReading UVRm: $prefix $key $value";

  return 1;
}

##############################################################################
###                                                                        ###
### UVRm_RetrieveData                                                      ###
###                                                                        ###
##############################################################################
sub UVRm_RetrieveData($)
{
  my ($hash)= @_;
  
  my $ip= $hash->{IP};

  my $text;
#  my $fc = undef;
#  my $xml = GetFileFromURL("http://weather.yahooapis.com/forecastrss?w=" . $location . "&u=" . $units, 3, undef, 1);
#  return 0 if( ! defined $xml || $xml eq "");

#  my $response = GetFileFromURL("http://172.22.1.4/580400.htm", 3, undef, 1);
  my $response = GetFileFromURL("http://" . $ip . "/580400.htm", 3, undef, 1);
  my $logline = "";

  if (!defined ($response))
    {
    return 1;
    }

#  foreach my $l (split([\<\>],$response)) {
  foreach my $l1 (split("<",$response)) {
    foreach my $l2 (split(">",$l1)) {
      ### only lines with nbsp are of interest
      if ($l2 =~ /nbsp/) {

        ### eliminate nbsp and degC from line
        $l2 =~ s/&nbsp\;/ /g;
        $l2 =~ s/&deg\;C /  /g;
        
#        Log 1, "DEBUG UVRm: line=\"$l2\"";

        ### eliminate two lines that do not contain values
        next if ($l2 =~ /MESSWERT/);
        next if ($l2 =~ /NETZWERK/);

        ### convert decimal comma to decimal point
        $l2 =~ s/,/./g;

#        Log 3, "UVRm line: $l2";

        ### we now got a single line only containing the header and two values
        my ($v1, $v2) = split ":",$l2;

        my $v3 = substr ($v2,9,8);
        $v2 = substr ($v2,0,8);

         ### early error-handling
         if ((!defined ($v2)) || (!defined ($v3)))
            {
              Log 3, "UVRm: Problem";
              Log 3, "$l2";
              return 1;
            }

        ### each of the 8 lines contain 2 values
        ### which will be formatted and added to the logline
#        switch ($v1) {
#          case "1:"

         ### hopefully the lines are o.k., so continue processing
         if ($v1 eq "  1")
            {
              $logline = UVRm_FormatData ($v2);
              $logline = $logline . " " . UVRm_FormatData ($v3);
            }
         elsif (($v1 eq " 3") ||
                ($v1 eq " 5") ||
                ($v1 eq " 7") ||
                ($v1 eq " 9") ||
                ($v1 eq "11") ||
                ($v1 eq "13") ||
                ($v1 eq "15"))
#          case ["3:", "5:", "7:", "9:", "11:", "13:", "15"]
             {
              $logline = $logline . " " . UVRm_FormatData ($v2);
              $logline = $logline . " " . UVRm_FormatData ($v3);
            }
#       }

      }
    }
  }

  ### write accumulated logline into logfile
  readingsBulkUpdate($hash, "UVR1611", $logline);

}  #end sub



##############################################################################
###                                                                        ###
### UVRm_FormatData                                                        ###
### Format the data read from UVR device to build a nice log-format        ###
###                                                                        ###
##############################################################################
sub UVRm_FormatData($)
{
  my ($arg) = @_;
  my $text;

  ### protocol all lines for debugging purpose
#  Log 3, "UVRm Format b: $arg";

  my ($v1, $v2, $v3) = split " ",$arg;

  ### transform EIN/AUS into 1/0 values
  if ($arg =~ "EIN") 
    {$text = "1";}

  elsif ($arg =~ "AUS") 
    {$text = "0";}

  ### transform "-----" into "-"
  elsif ($arg =~ "-----") 
    {$text = "-";}

  ### otherwise we assume a numerical value
  else
    {
#    Log 3, "UVRm Format num: $arg";
    my $firstchar = substr ($arg,0,1);
    if ($firstchar eq "-")
      {$arg = 0 - substr($arg,1,6);}
    ### numerical values are formatted as "-xx.x"
    $text = sprintf "%5.1f", $arg;
    }

  ### protocol all lines for debugging purpose
#  Log 3, "UVRm Format e: $text";

  return $text;
}  #end sub

##############################################################################
###                                                                        ###
### UVRm_GetUpdate                                                         ###
###                                                                        ###
##############################################################################
sub UVRm_GetUpdate($)
{
  my ($hash) = @_;

  if(!$hash->{LOCAL}) {
    InternalTimer(gettimeofday()+$hash->{INTERVAL}, "UVRm_GetUpdate", $hash, 1);
  }

  readingsBeginUpdate($hash);

  UVRm_RetrieveData($hash);

#  Log GetLogLevel($hash->{NAME},4), "UVRm ". $hash->{NAME} . ": $val";
  readingsEndUpdate($hash, defined($hash->{LOCAL} ? 0 : 1)); # DoTrigger, because sub is called by a timer instead of dispatch

  return 1;
}


##############################################################################
###                                                                        ###
### UVRm_Get                                                               ###
###                                                                        ###
##############################################################################
sub UVRm_Get($@) {

  my ($hash, @a) = @_;

  return "argument is missing" if(int(@a) != 2);

  $hash->{LOCAL} = 1;
  UVRm_GetUpdate($hash);
  delete $hash->{LOCAL};

  my $reading= $a[1];
  my $value;

  if(defined($hash->{READINGS}{$reading})) {
        $value= $hash->{READINGS}{$reading}{VAL};
  } else {
        return "no such reading: $reading";
  }

  return "$a[0] $reading => $value";
}

##############################################################################
###                                                                        ###
### UVRm_Set                                                               ###
###                                                                        ###
##############################################################################
sub UVRm_Set($@) {
  my ($hash, @a) = @_;

  my $cmd= $a[1];

  # usage check
  if((@a == 2) && ($a[1] eq "update")) {
    RemoveInternalTimer($hash);
    UVRm_GetUpdate($hash);
    return undef;
  } else {
    return "Unknown argument $cmd, choose one of update";
  }
}


##############################################################################
###                                                                        ###
### UVRm_Define                                                            ###
###                                                                        ###
##############################################################################
sub UVRm_Define($$) {

  my ($hash, $def) = @_;

  # define <name> UVRm <ip> [interval]
  # define myuvr UVRm 192.168.178.25 900

  my @a = split("[ \t][ \t]*", $def);

  return "syntax: define <name> UVRm <ip> [interval]"
    if(int(@a) < 3 && int(@a) > 5); 

  $hash->{STATE} = "Initialized";
  $hash->{fhem}{interfaces}= "v1;v2;v3";

  my $name      = $a[0];
  my $ip        = $a[2];
  my $interval  = 900;
  if(int(@a)>=4) { $interval= $a[3]; }

  $hash->{IP}           = $ip;
  $hash->{INTERVAL}     = $interval;
  $hash->{READINGS}{current_date_time}{TIME}= TimeNow();
  $hash->{READINGS}{current_date_time}{VAL}= "none";

  $hash->{LOCAL} = 1;
  UVRm_GetUpdate($hash);
  delete $hash->{LOCAL};

  InternalTimer(gettimeofday()+$hash->{INTERVAL}, "UVRm_GetUpdate", $hash, 0);

  return undef;
}

##############################################################################
###                                                                        ###
### UVRm_Undef                                                              ###
###                                                                        ###
##############################################################################
sub UVRm_Undef($$) {

  my ($hash, $arg) = @_;

  RemoveInternalTimer($hash);
  return undef;
}


1;

=pod
=begin html

<a name="UVRm"></a>
<h3>UVRm</h3>
<ul>
  <br>

  <a name="UVRmdefine"></a>
  <b>Define</b>
  <ul>
    <code>define &lt;name&gt; UVRm &lt;ip&gt; [&lt;interval&gt;]</code><br>
    <br>
    Defines a device for UVR1611 measurement readings.<br><br>

  </ul>
  <br>
</ul>

=end html
=cut
