//Needs testing
//This uses RC6 and RC7 as TX and RX respectively.
void UART_Init(const long int baudrate)
{
	unsigned int x;
	x = (_XTAL_FREQ - baudrate*64)/(baudrate*64);
	if(x>255)
	{
		x = (_XTAL_FREQ - baudrate*16)/(baudrate*16);
        TXSTA2bits.BRGH=1;
		//BRGH = 1;
	}
	if(x<256)
	{
        SPBRG = x;
        TXSTA1bits.SYNC = 0;
        RCSTA1bits.SPEN=1;
        //SPEN = 1;
        TRISC7 = 1;
        TRISC6 = 1;
        RCSTA1bits.CREN = 1;
        TXSTA2bits.TXEN = 1;
	  //return 1;
	}
	//return 0;
}

char UART_TX_Empty()
{
    return TXSTA1bits.TRMT;
  //return TRMT;
}

char UART_Data_Ready()
{
   return RCIF;
}
char UART_Read()
{
 
  while(!RCIF);
  return RCREG;
}

void UART_Read_Text(char *Output, unsigned int length)
{
	int i;
	for(int i=0;i<length;i++)
		Output[i] = UART_Read();
}

void UART_Write(char data)
{
  while(!TXSTA1bits.TRMT);
  TXREG = data;
}

void UART_Write_Text(char *text)
{
  int i;
  for(i=0;text[i]!='\0';i++)
	  UART_Write(text[i]);
}