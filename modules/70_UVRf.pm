# $Id: 70_UVRf.pm xxxx 2013-06-26 09:08:00Z wplettscher $
##############################################################################
###                                                                        ###
### UVRf heating control                   Copyright W.Plettscher, 07.2013 ###
###                                                                        ###
### Access "Technische Alternative UVR1611" through "Bootloader-NET        ###
### and read functions                                                     ###
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
use Time::HiRes qw(gettimeofday);
use HttpUtils;
use WWW::Mechanize;

##############################################################################
###                                                                        ###
### UVRf_Initialize                                                        ###
###                                                                        ###
##############################################################################
sub UVRf_Initialize($) {

  my ($hash) = @_;

  $hash->{DefFn}   = "UVRf_Define";
  $hash->{UndefFn} = "UVRf_Undef";
  $hash->{GetFn}   = "UVRf_Get";
  $hash->{SetFn}   = "UVRf_Set";
  $hash->{AttrList}= "loglevel:0,1,2,3,4,5 localicons ".
                      $readingFnAttributes;

}

##############################################################################
###                                                                        ###
### UVRf_UpdateReading                                                     ###
###                                                                        ###
##############################################################################
sub UVRf_UpdateReading($$$$) {

  my ($hash,$prefix,$key,$value)= @_;

  Log 1, "DEBUG updateReading UVRf: $prefix $key $value";

  return 1;
}

##############################################################################
###                                                                        ###
### UVRf_selectCAN                                                         ###
###                                                                        ###
##############################################################################
sub UVRf_selectCAN($)
{
##  my $m=WWW::Mechanize->new();
#  my $url = "http://172.22.1.4/can.htm";
  
#  $m->get($url);

  ### select the radio-button for CAN1
#  $m->submit_form (form_number => 1, fields => {blaB => 1});
#  $m->select("blaB",1);

  ### now submit the selection of the CAN-Bus
#  $m->get ("580000.htm");
#  $m->click("");
#  $m->submit();

  my ($hash)= @_;
  my $ip= $hash->{IP};
  my $response = GetFileFromURL("http://" . $ip . "/can.htm?blaB=1", 3, undef, 1);
}

##############################################################################
###                                                                        ###
### UVRf_RetrieveData                                                      ###
###                                                                        ###
##############################################################################
sub UVRf_RetrieveData($)
{
  my ($hash)= @_;
  
  my $ip= $hash->{IP};

  my $response = "";
  $response = GetFileFromURL("http://" . $ip . "/581E01.htm", 3, undef, 1);
  my $logline = "";
  my @l2;
  my @l3;
  my $text = "";

#  Log 3, "DEBUG UVRf";
  if (!defined ($response))
    {
    return 1;
    }

  ### substitute all "&nbsp;" by " "
  $response =~ s/&nbsp\;/ /g;

  ### all logical elements are separated by 21 "-"; so we use this pattern
  ### to get a number of blocks containing values
  my @l1 = split("---------------------",$response);

#  Log 3, "DEBUG UVRf: line=\"$l1[6]\"";

  ############################################################################
  ### block 1 Analysis: "Eingänge"
  if ((defined ($l1[1])) && ($l1[1] =~ /EINGAENGE/)) {

    @l2 = split("<br>",$l1[1]);
#    Log 3, "DEBUG UVRf: Eingang 1 = $l2[3] Eingang 2 = $l2[5] ";

    ### $l2[3] now contains a single line with Temperature TKollektor
    @l3 = split(/ +/,$l2[3]);
#    Log 3, "DEBUG UVRf: TKollektor=$l3[1]";

    my $Eingang1 = $l3[1];
    ### convert decimal comma to decimal point
    $Eingang1 =~ s/,/./g;
    $text = "xxx";
    $text = sprintf "%5.1f", $Eingang1;
    $logline = $text;

    ### $l2[5] now contains a single line with Temperature Eisspeicher
    @l3 = split(/ +/,$l2[5]);
#    Log 3, "DEBUG UVRf: Eisspeicher=$l3[1]";

    my $Eingang2 = $l3[1];
    ### convert decimal comma to decimal point
    $Eingang2 =~ s/,/./g;
    $text = "xxx";
    $text = sprintf "%5.1f", $Eingang2;

    $logline = $logline . " " . $text;
  }
  else {
    Log 3, "UVRf: Problem block 1 Eingänge";
    Log 3, "$response";
    return 1;
  }

  ############################################################################
  ### block 2 Analysis: "Ausgänge"
  if ((defined ($l1[2])) && ($l1[2] =~ /AUSGAENGE/)) {

    @l2 = split("<br>",$l1[2]);
#    Log 3, "DEBUG UVRf: Ausgang 2 = $l2[3] Ausgang 4 = $l2[6] ";

    my $Ausgang2;
    my $Ausgang4;

    if ($l2[3] =~ /AUS/) {
      $Ausgang2 = 0;
    } else {
      $Ausgang2 = 1;
    }

    if ($l2[6] =~ /AUS/) {
      $Ausgang4 = 0;
    } else {
      $Ausgang4 = 1;
    }

    $logline = $logline . " " . $Ausgang2 . " " . $Ausgang4;
  }
  else {
    Log 3, "UVRf: Problem block 2 Ausgänge";
    Log 3, "$response";
    return 1;
  }

  ############################################################################
  ### block 3 Analysis: "Wärmequelle Kollektor"
  if ((defined ($l1[3])) && ($l1[3] =~ /WQ Kollektor/)) {

    @l2 = split("<br>",$l1[3]);
#    Log 3, "DEBUG UVRf: WQ Kollektor=\"$l2[3]\"";

    ### @l2 now contains a single line with values... to be splitted for h,mins
    @l3 = split(/ +/,$l2[3]);
#    Log 3, "DEBUG UVRf: Values=$l3[1] $l3[3]";

    my $WQKollektor_h = $l3[1] + $l3[3] / 60;

    ### round to two digits
    $WQKollektor_h = int (100 * $WQKollektor_h + 0.5) / 100;
    $text = "";
    $text = sprintf "%7.2f", $WQKollektor_h;

#    Log 3, "Debug UVRf: WQKollektor_h = $WQKollektor_h";
    $logline = $logline . " " . $text;
  }
  else {
    Log 3, "UVRf: Problem block 3 Wärmequelle Kollektor";
    Log 3, "$response";
    return 1;
  }

  ############################################################################
  ### block 4 Analysis: "Regeneration1"
  if ((defined ($l1[4])) && ($l1[4] =~ /Regeneration1/)) {

    @l2 = split("<br>",$l1[4]);
#    Log 3, "DEBUG UVRf: Regeneration1=\"$l2[3]\"";

    ### @l2 now contains a single line with values... to be splitted for h,mins
    @l3 = split(/ +/,$l2[3]);
#    Log 3, "DEBUG UVRf: Values=$l3[1] $l3[3]";

    my $Regeneration1_h = $l3[1] + $l3[3] / 60;

    ### round to two digits
    $Regeneration1_h = int (100 * $Regeneration1_h + 0.5) / 100;
    $text = "";
    $text = sprintf "%7.2f", $Regeneration1_h;

#    Log 3, "Debug UVRf: Regeneration1_h = $Regeneration1_h";
    $logline = $logline . " " . $text;
  }
  else {
    Log 3, "UVRf: Problem block 4 Regeneration1";
    Log 3, "$response";
    return 1;
  }

  ############################################################################
  ### block 5 Analysis: "Regeneration2"
  if ((defined ($l1[5])) && ($l1[5] =~ /Regeneration2/)) {

    @l2 = split("<br>",$l1[5]);
#    Log 3, "DEBUG UVRf: Regeneration2=\"$l2[3]\"";

    ### @l2 now contains a single line with values... to be splitted for h,mins
    @l3 = split(/ +/,$l2[3]);
#    Log 3, "DEBUG UVRf: Values=$l3[1] $l3[3]";

    my $Regeneration2_h = $l3[1] + $l3[3] / 60;

    ### round to two digits
    $Regeneration2_h = int (100 * $Regeneration2_h + 0.5) / 100;
    $text = "";
    $text = sprintf "%7.2f", $Regeneration2_h;

#    Log 3, "Debug UVRf: Regeneration2_h = $Regeneration2_h";
    $logline = $logline . " " . $text;
  }
  else {
    Log 3, "UVRf: Problem block 5 Regeneration2";
    Log 3, "$response";
    return 1;
  }

  ############################################################################
  ### block 6 Analysis: "Betriebsdauer Verdichter"
  if ((defined ($l1[6])) && ($l1[6] =~ /Verdichter/)) {

    @l2 = split("<br>",$l1[6]);
#    Log 3, "DEBUG UVRf: Verdichter=\"$l2[3]\"";

    ### @l2 now contains a single line with values... to be splitted for h,mins
    @l3 = split(/ +/,$l2[3]);
#    Log 3, "DEBUG UVRf: Values=$l3[1] $l3[3]";

    my $Verdichter_h = $l3[1] + $l3[3] / 60;

    ### round to two digits
    $Verdichter_h = int (100 * $Verdichter_h + 0.5) / 100;
    $text = "";
    $text = sprintf "%7.2f", $Verdichter_h;

#    Log 3, "Debug UVRf: Verdichter_h = $Verdichter_h";
    $logline = $logline . " " . $text;
  }
  else {
    Log 3, "UVRf: Problem block 6 Betriebsdauer Verdichter";
    Log 3, "$response";
    return 1;
  }

  ############################################################################
  ### block 7 Analysis: "Wärmequelle Zusatzheizung"
  if ((defined ($l1[7])) && ($l1[7] =~ /ZH WQ/)) {

    @l2 = split("<br>",$l1[7]);
#    Log 3, "DEBUG UVRf: Zusatzheizung=\"$l2[3]\"";

    ### @l2 now contains a single line with values... to be splitted for h,mins
    @l3 = split(/ +/,$l2[3]);
#    Log 3, "DEBUG UVRf: Values=$l3[1] $l3[3]";

    my $Zusatzheizung_h = $l3[1] + $l3[3] / 60;

    ### round to two digits
    $Zusatzheizung_h = int (100 * $Zusatzheizung_h + 0.5) / 100;
    $text = "";
    $text = sprintf "%7.2f", $Zusatzheizung_h;

#    Log 3, "Debug UVRf: Zusatzheizung_h = $Zusatzheizung_h";
    $logline = $logline . " " . $text;
  }
  else {
    Log 3, "UVRf: Problem block 7 Wärmequelle Zusatzheizung";
    Log 3, "$response";
    return 1;
  }

  ### write accumulated logline into logfile
  readingsBulkUpdate($hash, "UVR1611", $logline);

}  #end sub


##############################################################################
###                                                                        ###
### UVRf_GetUpdate                                                         ###
###                                                                        ###
##############################################################################
sub UVRf_GetUpdate($)
{
  my ($hash) = @_;

  if(!$hash->{LOCAL}) {
    InternalTimer(gettimeofday()+$hash->{INTERVAL}, "UVRf_GetUpdate", $hash, 1);
  }

  readingsBeginUpdate($hash);

  ### from time to time we have to select the CAN-channel;
  ### to ensure right functionality we do it every time we read the data
  UVRf_selectCAN($hash);

  ### read page with real data
  UVRf_RetrieveData($hash);

  readingsEndUpdate($hash, defined($hash->{LOCAL} ? 0 : 1)); # DoTrigger, because sub is called by a timer instead of dispatch

  return 1;
}


##############################################################################
###                                                                        ###
### UVRf_Get                                                               ###
###                                                                        ###
##############################################################################
sub UVRf_Get($@) {

  my ($hash, @a) = @_;

  return "argument is missing" if(int(@a) != 2);

  $hash->{LOCAL} = 1;
  UVRf_GetUpdate($hash);
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
### UVRf_Set                                                               ###
###                                                                        ###
##############################################################################
sub UVRf_Set($@) {
  my ($hash, @a) = @_;

  my $cmd= $a[1];

  # usage check
  if((@a == 2) && ($a[1] eq "update")) {
    RemoveInternalTimer($hash);
    UVRf_GetUpdate($hash);
    return undef;
  } else {
    return "Unknown argument $cmd, choose one of update";
  }
}

##############################################################################
###                                                                        ###
### UVRf_Define                                                            ###
###                                                                        ###
##############################################################################
sub UVRf_Define($$) {

  my ($hash, $def) = @_;

  # define <name> UVRf <ip> [interval]
  # define myuvr UVRf 192.168.178.25 900

  my @a = split("[ \t][ \t]*", $def);

  return "syntax: define <name> UVRf <ip> [interval]"
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
  UVRf_GetUpdate($hash);
  delete $hash->{LOCAL};

  InternalTimer(gettimeofday()+$hash->{INTERVAL}, "UVRf_GetUpdate", $hash, 0);

  return undef;
}

##############################################################################
###                                                                        ###
### UVRf_Undef                                                              ###
###                                                                        ###
##############################################################################
sub UVRf_Undef($$) {

  my ($hash, $arg) = @_;

  RemoveInternalTimer($hash);
  return undef;
}

1;

=pod
=begin html

<a name="UVRf"></a>
<h3>UVRf</h3>
<ul>
  <br>

  <a name="UVRfdefine"></a>
  <b>Define</b>
  <ul>
    <code>define &lt;name&gt; UVRf &lt;ip&gt; [&lt;interval&gt;]</code><br>
    <br>
    Defines a device for UVR1611 measurement readings.<br><br>

    Read function-values from UVR1611 (Technische Alternative)<br><br>

    This modules call the HTML-page myUVRip/581E01.htm where all function values
    (Funktionsübersicht) are stored. Please check this is the same HTML in your system.<br><br>

    Then the modules splits into "blocks" separated by "------------". Those blocks now
    contain one of more  values. The values extracted are written into the log (without any headers).
    As number and order of values are implementation specific, you have to modify this
    source-code to fit your individual needs.<br><br>

    Please provide feedback for any general modification to have a common code-base.<br><br>

    Examples:
    <pre>
      define heating UVRf 192.168.1.1 300
     </pre>
  </ul>
  <br>

</ul>

=end html
=cut
