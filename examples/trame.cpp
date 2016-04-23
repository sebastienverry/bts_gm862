int CRS232::Rxd(char *Tab, int taille) /* Rxd est la fonction r�ception donn�e */
{
	cout << "====== Debut de la reception ======" << endl;
	DWORD NbRxd;
	NbRxd = 0;
	int i;
	i = 0;

	Tab = (char *)memset(tab, 0, taille);	/*
											#include <string.h>
											void *memset(void *s, int c, size_t n);*/
	while ((i < taille) && (NbRxd != 0 || i == 0))
	{
		ReadFile(hcom, &tab[i], 1, &NbRxd, NULL);
		if (NbRxd != 0) i++;
	}
	cout << "La trame � bien ete recu: " << tab << endl;
	cout << "===== Fin de la reception =====" << endl;
	return(i);
}

/*Ca nous permet de recevoir la trame sous forme de tableau appeler tab */




// pour apr�s d�cryptage de la trame


void CR232::DecrypTrame(char *Buff)
{
	if (Buff[0] == '$') // �a a pour but de bien d�l�miter les different partie dans la trame en y mettant le symbole $ a chaque de but de trame
	{
		cout << "Debut de la trame sans soucis" << endl;
	}
	else
	{
		cout << "La trame n'a pas �t� recu" << endl;
	}
	if (Buff == "\n\r") // a la fin de la trame l'afficheur va a la ligne pour signifier une nouvelle trame
	{
		cout << "Fin de la trame" << endl;
	}
}
