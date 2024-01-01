/* include all C function to test */
#include <stdio.h>
#include <stdlib.h>
/* include state.h */
#include "state.h"
/* include all modules */
#include "C.h"
#include "LCDP.h"
#include "RWIFI.h"
/* include all drivers */
#include "../GPIO/GPIO.h"
#include "../ON_BOARD_SWITCHS/ON_BOARD_SWITCHS.h"
#include "../RGB_LEDS/RGB_LEDS.h"
#include "../UART/UART.h"
#include "../LCD/Lcd.h"
void setup(){
    /* init all the drivers */

    /* init IRQ */

    /* init HAL */
    ON_BOARD_SWITCHS_Init();
    RGB_LEDS_Init();
    Lcd_Init();
    /* init block */

    /* set state pointers for each block */
    RWIFI_state = STATE(RWIFI_busy);
    C_state = STATE(C_normal);
    LCDP_state = STATE(LCDP_normal);
}

int main(){
    setup();
    while (1){
        /* write all states to be called sequencial */
        RWIFI_state();
        C_state();
        LCDP_state();
    }
    return 0;
}
