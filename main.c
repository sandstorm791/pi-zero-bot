//orchestrator
#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define LEFT_MOTOR_PIN 12
#define RIGHT_MOTOR_PIN 18
#define FREQUENCY 25000

int main() {
    printf("initializing hardware pwm...");

    if (gpioInitialise() < 0) {
        fprintf(stderr, "pigpio initialization failed\n");
        return 1;
    }
    printf("success\n");

    

    gpioHardwarePWM(HARDWARE_PWM_PIN, 0, 0);
    gpioTerminate();

    return 0;
}
