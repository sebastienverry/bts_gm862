#include <iostream>
#include <string>

#include "c__rs232.hpp"

using namespace std;

int main(void)
{
    unsigned char RxBuf[256];
    unsigned int NbRecus;
   c__rs232 my_rs("COM1");

   my_rs.confCom(CBR_9600,FALSE,8,NOPARITY,ONESTOPBIT);


   my_rs.TxData((char *)"AT+CMGF=1\r",strlen("AT+CMGF=1\r"));
   NbRecus=my_rs.RxData((char *)RxBuf,sizeof RxBuf);
   RxBuf[NbRecus]='\0';

   cout<<RxBuf<<endl;

    return 0;
}
