#include "Send.h"


void Send_To(unsigned char comp,unsigned char dat)
{
	P0 = dat;
	P2 = P2 & 0x1f | (comp << 5);
	P2 &= 0x1f;
}