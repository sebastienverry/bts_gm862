CRS232::CRS232()
{
	hCom = CreateFile(
		"COMx",                         // Choix du port  COMx ? 
		GENERIC_READ | GENERIC_WRITE, 	// acces pour lire et ecrire sur le port 
		0,                            	// acc?s exclusif au port de COM 
		NULL,                         	// securite par defaut 
		OPEN_EXISTING,                	// Fichier special associe  la ressource COM1 deja existant.
		0, 															// mode synchrone (BLOQUANT)
		NULL);
	if (hCom == INVALID_HANDLE_VALUE)
	{
		cout << "\n\t Erreur d'ouverture de port.\n" << endl;
		exit(-1);
	}

	cout << "\n Le Port que vous voulez utiliser est ouvert \n" << endl;

}