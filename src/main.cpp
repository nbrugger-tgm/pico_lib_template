#include <stdio.h>
#include "pico/binary_info.h"
#include "pico/stdlib.h"
#include "pins.h"

#pragma ide diagnostic ignored "EndlessLoop"


//local definitions
void init();
void loop();
void info();

int main() {
    info();
    init();
    while(true) {
       loop();
    }
}

void info() {
    //bi_decl(bi_2pins_with_func(6, 7, GPIO_FUNC_I2C))
    //bi_decl(bi_1pin_with_name(PIN_LED,"On board LED"));
    //bi_decl(bi_4pins_with_names(9,"Pin for X",10,"Pin For Y",11,"Pin For Z",12,"Pin For W"));
}

void init() {
    stdio_init_all();
    gpio_init(PIN_LED);
    gpio_set_dir(PIN_LED,GPIO_OUT);
    printf("[START APPLICATION]");
}
bool on = false;
void loop(){
    sleep_ms(300);
    printf("Blink");
    gpio_put(PIN_LED,on);
    on = !on;
}