#include <iostream>
#include <string>
#include <cstdio>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include "gm862.h"
#include "gmmysql.h"

using namespace std;


int main(void)
{
	cout << "salut" << endl;
	
	/*
	LPCWSTR com = L"\\\\.\\COM7";
	char pin_code[5] = "1234";
	char *msg;
	c__rs232 gm862(com);
	c__gmmysql gmmysql();

	gm862.confCom(CBR_9600, FALSE, 8, NOPARITY, ONESTOPBIT); // configure serial port
	gm862.initModem(pin_code); // init modem


	/*
	while (msg = gm862.getMsg()) { // loop listen
		cout << "Message reçu: " << msg << endl;
	}
	*/
	system("pause");
}