/******************************************************************************
 ***                                                                        ***
 *** tf_fenster.c                            (C) Wolfram Plettscher 05.2014 ***
 ***                                                                        ***
 *** Interrupt driven messages to FHEM on windows/doors open/close          ***
 *** using Tinkerforge Master-Brick and IO-16 Bricklet                      ***
 ***                                                                        ***
 ******************************************************************************/

#include <stdio.h>
#include <pthread.h>

#include "./tinkerforge_c_bindings/bindings/ip_connection.h"
#include "./tinkerforge_c_bindings/bindings/bricklet_io16.h"

#define HOST "172.22.1.5"
#define PORT 4223
#define CALL "/usr/share/fhem/fhem.pl"
#define UID "7NE"      // UID of IO-16 Bricklet
#define IOMASK_A    0x3f  // define pins on port A relevant for FHEM update
#define FLOORMASK_A 0x3f  // define pins for floor consolidation
#define IOMASK_B    0xff  // define pins on port B relevant for FHEM update
#define FLOORMASK_B 0x38  // define pins for floor consolidation (1st floor windows)
#define FLOORMASK_C 0x07  // define pins for floor consolidation (roof windows)

// Global Variables
IO16 io;
IPConnection ipcon;


/******************************************************************************
 *                                                                            *
 * notify_FHEM                                                                *
 *                                                                            *
 * for each pin now set the apropriate FHEM device                            *
 *                                                                            *
 ******************************************************************************/
void notify_FHEM (char port, int pin, int status) {

  char cmd[80] = "/usr/share/fhem/fhem.pl 7072 'set ";
  //char cmd[80] = strcat (CALL, " 7072 'set ");

  // here we assign Tinkerforge IO-Pins to FHEM device names
  if (port == 'a') {
    switch (pin) {
      case 0: strcat (cmd, "Fenster_GastWC"); break;
      case 1: strcat (cmd, "Fenster_Gast"); break;
      case 2: strcat (cmd, "Fenster_Kueche_links"); break;
      case 3: strcat (cmd, "Fenster_Kueche_rechts"); break;
      case 4: strcat (cmd, "Tuer_Essz"); break;
      case 5: strcat (cmd, "Tuer_Wohnz"); break;
      case 6: strcat (cmd, "Port_A6"); break;
      case 7: strcat (cmd, "Port_A7"); break;
    }
  }

  if (port == 'b') {
    switch (pin) {
      case 0: strcat (cmd, "Fenster_Treppe"); break;
      case 1: strcat (cmd, "Fenster_Serverraum"); break;
      case 2: strcat (cmd, "Fenster_Waschkueche"); break;
      case 3: strcat (cmd, "Fenster_Bad"); break;
      case 4: strcat (cmd, "Tuer_Schlafz"); break;
      case 5: strcat (cmd, "Tuer_Arbeitsz"); break;
      case 6: strcat (cmd, "SmokeMaint"); break;
      case 7: strcat (cmd, "FireAlarm"); break;
    }
  }

  if (status == 0)
    strcat (cmd, " off'");
  else
    strcat (cmd, " on'");

  // run FHEM command to set status of device
  printf ("%s\n", cmd);
  system (cmd);
}


/******************************************************************************
 *                                                                            *
 * run_system_cmd                                                             *
 *                                                                            *
 ******************************************************************************/
void run_system_cmd (char* mycmd) {

  printf ("\n%s\n\n", mycmd);
  system (mycmd);
}


/******************************************************************************
 *                                                                            *
 * notify_floor                                                               *
 *                                                                            *
 * similar to notify_FHEM, but now we aggregate on a floor level              *
 * in addition we set LEDs on status-display                                  *
 *                                                                            *
 ******************************************************************************/
void notify_floor (char port, uint8_t value_mask) {

  char* cmd;

  // Port A handles all windows/doors on ground floor
  if (port == 'a') {

    // Filter only relevant pins and check if ALL are closed
    if ((value_mask & FLOORMASK_A) == 0) {
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set _Fenster_EG off'");
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set hmStatus_Led_03 led green'");
    } else {
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set _Fenster_EG on'");
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set hmStatus_Led_03 led red'");
    }
  }

  // Port B handles all windows/doors on first floor
  if (port == 'b') {

    // Filter only relevant pins (1st floor) and check if ALL are closed
    if ((value_mask & FLOORMASK_B) == 0) {
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set _Fenster_OG off'");
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set hmStatus_Led_02 led green'");
    } else {
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set _Fenster_OG on'");
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set hmStatus_Led_02 led red'");
    }

    // Filter only relevant pins (roof windows) and check if ALL are closed
    if ((value_mask & FLOORMASK_C) == 0) {
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set _Fenster_Dach off'");
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set hmStatus_Led_01 led green'");
    } else {
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set _Fenster_Dach on'");
      run_system_cmd ("/usr/share/fhem/fhem.pl 7072 'set hmStatus_Led_01 led red'");
    }
  }
}


/******************************************************************************
 *                                                                            *
 * cb_interrupt                                                               *
 *                                                                            *
 * Callback function for IO_interrupts                                        *
 *                                                                            *
 ******************************************************************************/
void cb_interrupt (char port, uint8_t interrupt_mask, uint8_t value_mask, void *user_data) {

  (void) user_data; // avoid unused parameter warning

// printf("Interrupt on port: %c\n", port);
// printf("Interrupt by: %d\n", interrupt_mask);
// printf("Value: %d\n", value_mask);

  int i,irq,status,ret;

  // check each pin separately
  for (i=0; i<8; i++) {
    // isolate bits for irq and status
    irq = (interrupt_mask >> i) & 0x01;
    status = (value_mask >> i) & 0x01;

    // Interrupt occured on this pin
    if (irq == 1) {

      // we will trigger FHEM to update individual devices
      notify_FHEM (port, i, status);

      // status 1 = open/on, 0 = closed/off
//    if (status == 1) {
//      printf ("Pin %d open\n",i);
//    } else {
//      printf ("Pin %d closed\n",i);
//    }

    }
  }

  // set floor device (aggregated port a or port b)
  notify_floor (port, value_mask);
}


/******************************************************************************
 *                                                                            *
 * thread1                                                                    *
 *                                                                            *
 * This thread covers all triggers initiated from the IO-Board                *
 *                                                                            *
 ******************************************************************************/
int thread1() {

  // Enable interrupt on all pins of port a
  io16_set_port_interrupt (&io, 'a', 0xFF);
  io16_set_port_interrupt (&io, 'b', 0xFF);

  // Register callback for interrupts
//io16_register_callback(&io, IO16_CALLBACK_INTERRUPT, (void *)cb_interrupt, NULL);

//  printf("Press ctrl+c to close\n");
//  ipcon_join_thread(&ipcon); // Join mainloop of IP connection

  ipcon_wait(&ipcon);
//  printf("Press key to exit\n");
//  getchar();
//  ipcon_destroy (&ipcon);
}


/******************************************************************************
 *                                                                            *
 * thread2                                                                    *
 *                                                                            *
 * This thread scans IO-pins by timing intervals                              *
 *                                                                            *
 ******************************************************************************/
void *thread2 (void* zzz) {

  // Parameter zzz is not used, but will kept for demonstration purpose
  // char *message;
  // message = (char *) zzz;
  // printf ("%s\n", message);

  int i, err;
  uint8_t value_mask=255;

  // first 5 Minutes we will update FHEM every 30 seconds
  for (i=0; i<10; i++) {

    // read input ports from Tinkerforge IO-bricklet
    // update FHEM via cb_interrupt
    err = io16_get_port (&io, 'a', &value_mask); 
// printf("PortA_err: %d\n", err);
    cb_interrupt ('a', IOMASK_A, value_mask, NULL);
    err = io16_get_port (&io, 'b', &value_mask); 
// printf("PortB_err: %d\n", err);
    cb_interrupt ('b', IOMASK_B, value_mask, NULL);

    sleep (30);
  }

  // now we reduce to once every 5 Minutes; endless loop
  while (1) {

    // read input ports from Tinkerforge IO-bricklet
    // update FHEM via cb_interrupt
    err = io16_get_port (&io, 'a', &value_mask); 
    cb_interrupt ('a', IOMASK_A, value_mask, NULL);
    err = io16_get_port (&io, 'b', &value_mask); 
    cb_interrupt ('b', IOMASK_B, value_mask, NULL);

    sleep (300);
  }
}


/******************************************************************************
 *                                                                            *
 * main                                                                       *
 *                                                                            *
 * will fork into two threads:                                                *
 *   thread1 : will react on IO-Interrupts                                    *
 *   thread2 : will react on timing intervals                                 *
 *                                                                            *
 ******************************************************************************/
int main() {
//  string sIdentifier;
  char sIdentifier[80] = "";
 
  // Create IP connection
  ipcon_create (&ipcon);

  // Create device object
  io16_create(&io, UID, &ipcon); 

  // Connect to Master-Brick
  if (ipcon_connect (&ipcon, HOST, PORT) < 0) {
    fprintf (stderr, "Could not connect\n");
    printf("ipcon_connect: Could not connect\n");
    exit (1);
  }

  // Register callback for interrupts
  io16_register_callback(&io, IO16_CALLBACK_INTERRUPT, (void *)cb_interrupt, NULL);
//  printf ("io16_register_callback \n");

  // set all pins on port a and b to input / pull-up
//  io16_set_port_configuration(&io, 'a', 255, 'i', true);
//  io16_set_port_configuration(&io, 'b', 255, 'i', true);
  io16_set_port_configuration(&io, 'a', 0xff, 'i', true);
  io16_set_port_configuration(&io, 'b', 0xff, 'i', true);

  // Don't use device before it is added to a connection

  // Create second thread to poll IO-pins on given intervals
  pthread_t thread;
  int rc;
  char* z = "new Thread\n";
  rc = pthread_create(&thread, NULL, thread2, (void*) z);

  // the main thread will react on IO-pins interrupts
  thread1();
}
