### #!/bin/bash
###############################################################################
#                                                                             #
# QNAP autorun.sh                                  Wolfram Plettscher 10/2017 #
# support loading driver for /dev/ttyACM0                                     #
# check after every QNAP firmware update !                                    #
#                                                                             #
###############################################################################

### install on QNAP boot-flash ################################################
### mount -t ext2 /dev/sde6 /mnt/config
### then put this file as autorun.sh
### umount /dev/sde6
### verify cdc-acm.ko is present
### reboot QNAP

#ln -s /lib/modules/misc/cdc-acm.ko /lib/modules/`uname -r`/misc
#/sbin/modprobe /lib/modules/misc/cdc-acm.ko

/sbin/insmod /lib/modules/misc/cdc-acm.ko
