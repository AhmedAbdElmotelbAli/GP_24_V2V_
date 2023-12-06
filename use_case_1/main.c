/* include all C function to test */
#include <stdio.h>
#include <stdlib.h>
/* include state.h */
#include "state.h"
/* include all modules */
#include "C.h"
#include "LCDP.h"
#include "RWIFI.h"

void setup(){
    /* init all the drivers */
    
    /* init IRQ */

    /* init HAL */

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
