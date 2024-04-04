#ifndef _SSI_H_
#define _SSI_H_

typedef enum {
    SSI_0,
    SSI_1,
    SSI_2,
    SSI_3
} SSI_n;

void SSI_Master_Init(uint08_t SSI_n);
void SSI_Slave_Init(uint08_t SSI_n);
void SSI_SendByte(uint08_t data, uint08_t SSI_n);
uint08_t SSI_ReceiveByte(uint08_t SSI_n);

#endif