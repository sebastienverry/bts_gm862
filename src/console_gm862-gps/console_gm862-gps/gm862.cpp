#include "gm862.h"

using namespace std;

c__rs232::c__rs232(LPCWSTR port)
{
	hCom = CreateFile(
		port,                           // Choix du port « COMx »
		GENERIC_READ | GENERIC_WRITE, 	// accès pour lire et écrire sur le port
		0,                            	// accès exclusif au port COM
		NULL,                         	// sécurité par défaut
		OPEN_EXISTING,                	// Fichier spécial associé à la ressource COM1 déjà existant.
		0, 								// mode synchrone (BLOQUANT)
		NULL);
	cerr << "nativeOpen.afterCreateFile(" << hCom << ")" << endl;
	cerr << "port: " << port << ", errorCode: " << GetLastError() << endl;

	if (hCom == INVALID_HANDLE_VALUE)
	{
		cerr << "ERROR Creating File " << port << endl;
		exit(1);
	}
	cout << "SUCCESS Creating File " << port << endl;
}



BOOL c__rs232::confCom(int baud_rate, BOOL f_parity, int byte_size, int parity, int stop_bit)
{
	DCB sConfig;
	if (GetCommState(hCom, &sConfig) == 0)
	{
		cerr << "ERROR Getting Configuration: " << GetLastError() << endl;
		return FALSE;
	}

	sConfig.BaudRate = baud_rate;
	sConfig.fParity = f_parity;
	sConfig.ByteSize = byte_size;
	sConfig.Parity = parity;
	sConfig.StopBits = stop_bit;

	if (SetCommState(hCom, &sConfig) == 0)
	{
		cerr << "ERROR Setting Configuration: " << GetLastError() << endl;
		return FALSE;
	}
	Sleep(500);
	return TRUE;
}

BOOL c__rs232::TxData(char *buffer)
{
	unsigned int i;
	unsigned long size_1 = 1;
	unsigned long number_bytes_buffer = strlen(buffer) + 1;

	// Debug
	cout << "---" << endl;
	cout << "Sending:" << endl;
	cout << buffer << endl;
	cout << "---" << endl;

	for (i = 0; i < number_bytes_buffer; i++)
	{
		if (WriteFile(hCom, &buffer[i], 1, &size_1, NULL) == 0)
		{
			cout << "pb" << endl;
			return FALSE;
		}
	}
	cerr << "nativeOpen.afterCreateFile(" << hCom << ")" << endl;
	cerr << "errorCode: " << GetLastError() << endl;
	Sleep(500);
	return TRUE;
}

BOOL c__rs232::TxData(std::string & buffer, unsigned long number_bytes_buffer)
{
	return 0;
}

unsigned int c__rs232::RxData(char *buffer, unsigned long number_bytes_buffer)
{
	unsigned int i = 0;
	unsigned long number_bytes_read = 1;
	setTimeout(0);

	do
	{
		if (ReadFile(hCom, (buffer + i), number_bytes_read, &number_bytes_read, NULL) == 0)
			return 0;
		if (number_bytes_read == 1) {
			++i;
		}
		if (i == 1)
		{
			setTimeout(20);
		}
		cout << "buff: " << buffer << endl;
	} while ((number_bytes_read == 1) && (i < number_bytes_buffer));

	return i;
}

BOOL c__rs232::setTimeout(int TO)
{
	COMMTIMEOUTS time_out;
	time_out.ReadIntervalTimeout = 0;
	time_out.ReadTotalTimeoutMultiplier = 0;
	time_out.ReadTotalTimeoutConstant = TO;
	if (SetCommTimeouts(hCom, &time_out) == 0)
		return FALSE;
	return TRUE;
}
BOOL c__rs232::initModem(char *pinCode)
{
	char RxBuf[256];
	char msg[30];
	char dest[50];
	unsigned long lenChar;

	//cout << "PinCode: " << pinCode << endl;

	//this->TxData("ATZ");
	//Sleep(1000);

	//this->TxData("AT+CMGF=1\r"); //  Commande AT pour avoir le message en mode texte.
	//system("pause");
	//lenChar = this->RxData(msg, sizeof(msg));
	//msg[lenChar] = '\0';
	//cout << "taille AT+CMGF: " << lenChar << "msg: " << msg << endl;
	//system("pause");

	/* Modem is alive ?*/
	this->TxData("AT\r");
	system("pause");
	lenChar = 30;
	cout << "Resultat readfile: " << ReadFile(hCom, msg, lenChar, &lenChar, NULL) << endl;
	cout << "msg: " << msg << endl;
	/*
	lenChar = this->RxData(msg, sizeof(msg));
	cout << "taille:" << lenChar << endl;
	msg[++lenChar] = '\0';
	cout << "message: " << msg << endl;
	*/
	system("pause");
	exit(1);
	//system("exit");

	/* Enter PinCode */
	this->TxData("AT+CPIN=1234");


	/* GSM is OK ? */
	this->TxData("AT+CREG?\r");

	/* Send SMS */
	this->TxData("AT+CMGS=0635521953\r");
	this->TxData("Coucou toi \x1a");
	//this->TxData("");

	/*
	this->RxData(msg, sizeof(msg));
	cout << "rxdata : " << msg << endl;
	*/
	/*
	sprintf_s(dest, 9 + sizeof(pinCode), "AT+CPIN='%d'");
	this->RxData(msg, sizeof msg);

	sprintf_s(dest, 12, "AT+CMGF=1\r");  //  Commande AT pour avoir le message en mode texte.
	this->TxData(dest, strlen(dest));

	*/
	return TRUE;
}

c__rs232::~c__rs232(void)
{
	CloseHandle(hCom);
}
