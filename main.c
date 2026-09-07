//orchestrator
#import <stdio.h>

gpioInitialise(void);

if (gpioInitialise() < 0){
   // pigpio initialisation failed.
} else{
   // pigpio initialised okay.
}


gpioTerminate(void);
