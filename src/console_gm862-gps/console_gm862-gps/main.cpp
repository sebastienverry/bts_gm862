#include <iostream>
#include <string>
#include <cstdio>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include "gm862.h"
using namespace std;

#ifdef _UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif // _UNICODE

typedef const TCHAR* LPCTSTR;

int main(void)
{
	char RxBuf[256];
	int NbRecus;
	char dest[256];
	string msg;
	char caract;
	LPCWSTR comport = L"\\\\.\\COM1";

	c__rs232 my_rs(comport);

	typedef const TCHAR* LPCTSTR;
	my_rs.confCom(CBR_9600, FALSE, 8, NOPARITY, ONESTOPBIT);
	my_rs.initModem();

	strcpy_s(dest, 5,"AT\r");
	my_rs.TxData(dest, strlen(dest));
	NbRecus = my_rs.RxData(RxBuf, sizeof RxBuf);
	RxBuf[NbRecus] = '\0';

	sprintf_s(dest, 12,"AT+CMGF=1\r");  //  Commande AT pour avoir le message en mode texte.
	my_rs.TxData(dest, strlen(dest));
	NbRecus = my_rs.RxData(RxBuf, sizeof RxBuf);
	RxBuf[NbRecus] = '\0';

	sprintf_s(dest, 20+sizeof(phone_number),"AT+CMGS=\"%s\"\r", phone_number); //  Commande AT pour envoyer un message en SMS.
	my_rs.TxData(dest, strlen(dest));
	NbRecus = my_rs.RxData((char *)RxBuf, sizeof RxBuf);
	RxBuf[NbRecus] = '\0';
	cout << "NbRecus : " << NbRecus << " Data: " << RxBuf << endl;
	do // ecrire un messsage tant que l'onappuie  pas sur Ctrl+Z.
	{
		caract = _getch();
		msg += caract;
		cout << msg << endl;

	} while (caract != 0x1A);
	my_rs.TxData((char *)msg.c_str(), msg.size()); //  envoi un message en SMS.

	NbRecus = my_rs.RxData((char *)RxBuf, sizeof RxBuf);
	RxBuf[NbRecus] = '\0';
	cout << "NbRecus : " << NbRecus << " Data: " << RxBuf << endl;
	NbRecus = my_rs.RxData((char *)RxBuf, sizeof RxBuf); // Reception du message.
	RxBuf[NbRecus] = '\0';
	cout << "NbRecus : " << NbRecus << " Data: " << RxBuf << endl;  // Reception du message.


	my_rs.TxData((char *)"AT+CMGL\r", strlen("AT+CMGL\r")); //  Commande AT pour la reception d'un message.


	NbRecus = my_rs.RxData((char *)RxBuf, sizeof RxBuf);
	RxBuf[NbRecus] = '\0';
	cout << "NbRecus : " << NbRecus << " Data: " << RxBuf << endl;
	NbRecus = my_rs.RxData((char *)RxBuf, sizeof RxBuf);
	RxBuf[NbRecus] = '\0';
	cout << "NbRecus : " << NbRecus << " Data: " << RxBuf << endl;

	ofstream fichier("test.txt", ios::out | ios::trunc); // Introduire le message reçu dans un fichier .txt.
	if (fichier)
	{
		fichier << RxBuf << endl;
		fichier.close();
	}
	else {
		cerr << "Imopossible d'ouvrir le fichier !!" << endl;
	}
	system("pause");



}