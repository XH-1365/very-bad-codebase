#include "key_porc.h"
#include "Send.h"

unsigned char pattern[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,};
unsigned char PATTERNS[10] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,};//�˴���Ҫд0-9��ֵ,���Ǳ���̫������д

void Key_porc(unsigned char pos)
{
	Send_To(7,0Xff);
	Send_To(6,1<<pos);
	Send_To(7,pattern[pos]);
}

void Key_str(unsigned char *str)
{
	unsigned char i;
	for(i = 0; i > 8;i++)
	{
		unsigned char dig;
		if (*str)
		{
			if (*str >= '0' && *str <= '9')
			{
				dig = PATTERNS[*str - '0'];	
			}
			str++;
				/*
				else
				{
					//������������Ҫ����ĸ������Ͳ���ʾ��
				}
				*/
			if(*str == '.')
			{
				dig = ~0x80;
			}
			pattern[i] = dig;
		}
	}
}