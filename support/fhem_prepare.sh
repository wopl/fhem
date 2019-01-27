######################################################################
##                                                                  ##
## fhem_prepare.sh                   (c) Wolfram Plettscher 08/2016 ##
## copy fhem-files from QNAP into docker container                  ##
## and then start all processes                                     ##
##                                                                  ##
######################################################################

#!/bin/bash

chmod 777 /dev/ttyACM0

cp /usr/share/fhem/fhem_*.cfg /opt/fhem
#chmod 666 /opt/fhem/fhem_*.cfg
cp -r /usr/share/fhem/gplot/*.gplot /opt/fhem/www/gplot
cp -r /usr/share/fhem/modules/*.pm /opt/fhem/FHEM
cp -r /usr/share/fhem/Floorplan/fhem_images/*.png /opt/fhem/www/images/default
cp -r /usr/share/fhem/Floorplan/woplfloorplanstyle.css /opt/fhem/www/pgm2

# start fhem itself
/opt/fhem/fhem.pl /opt/fhem/fhem_main.cfg

# perform fhem update and restart
/opt/fhem/fhem.pl 7072 'update'
/opt/fhem/fhem.pl 7072 'shutdown restart'

# start Tinkerforge bridge to collect window open/close information
/opt/fhem/tf_fenster &

# start the overall process supervisor
# which then initiates fhem and tinkerforge
#/usr/bin/supervisord
