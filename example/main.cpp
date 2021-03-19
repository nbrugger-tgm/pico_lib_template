#include <pico/stdlib.h>
#include <mylib/adder.h>


int main() {
    stdio_init_all();
    while (1)
        printf("10 + 20 = %d",add(10,20));
}