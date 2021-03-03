#include <stdio.h>
#if !runLocal
#include "pico/binary_info.h"
#include "pico/stdlib.h"
#include "pins.h"
#endif


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
	#if !runLocal
    //bi_decl(bi_2pins_with_func(6, 7, GPIO_FUNC_I2C))
    //bi_decl(bi_1pin_with_name(PIN_LED,"On board LED"));
    //bi_decl(bi_4pins_with_names(9,"Pin for X",10,"Pin For Y",11,"Pin For Z",12,"Pin For W"));
	#endif
}

void init() {
	#if !runLocal
    stdio_init_all();
    gpio_init(PIN_LED);
    gpio_set_dir(PIN_LED,GPIO_OUT);
    #endif
	printf("[START APPLICATION]");
}
bool on = false;
void loop(){
	#if !runLocal
    sleep_ms(300);
    gpio_put(PIN_LED,on);
	#endif
    printf("Blink");
    on = !on;
}