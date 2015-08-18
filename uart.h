//Needs testing
//This uses RC6 and RC7 as TX and RX respectively.
char UART_Init(const long int baudrate)
{
	if(OSCTUNEbits.PLLEN==1)
	{
        //Look at page 339
        SPBRG = 103;
        
        TXSTA1bits.SYNC = 0;
        RCSTA1bits.SPEN=1;
        TXSTA1bits.BRGH=0;
        
        //SPEN = 1;
        
        //Set C7 (RX) as input
        TRISCbits.TRISC7=0;
        //TRISC7 = 1;
        //SEt C6 (TX) as output
        TRISCbits.TRISC6=0;
        //TRISC6 = 1;
        
        RCSTA1bits.CREN = 1;
        TXSTA1bits.TXEN = 1;
	  return 1;
	}
	return 0;
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