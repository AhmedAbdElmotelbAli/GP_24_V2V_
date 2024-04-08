/* include all C function to test */

#include <stdint.h>
/* include state.h */
#include "state.h"
/* include all modules */
#include "Controller.h"
#include "LCD_Print.h"
#include "Recieve_WIFI.h"

void setup(){
    /* init all the drivers */
    
    /* init IRQ */

    /* init HAL */

    /* init block */

    /* set state pointers for each block */
    Recieve_Wifi_state = STATE(Recieve_Wifi_busy);
    Controller_state = STATE(Controller_normal);
    LCD_Print_state = STATE(LCD_Print_normal);
}

int32_t main(){
    setup();
    while (1){
        /* write all states to be called sequencial */
        Recieve_Wifi_state();
        C_state();
        LCD_Print_state();
    }
    return 0;
}
