void CSockets::activation()
{
	char hostname[] = { 0 };

	
	sin.sin_addr.s_addr = INADDR_ANY; // ecoute sur toutes les IP locales
	sin.sin_family = AF_INET;
	sin.sin_port = htons();
	erreur = bind(id_socket, (struct sockaddr*)&source, sizeof(source)); /* La fonction bind permet de lier la socket à un port et adresse Ip d'écoute */

	if (erreur != 0)
		cout << "Impossible d'ecouter le port choisie : " << "" << WSAGetLastError() << endl; // WSAGetLastError function returns the error status for the last Windows Sockets operation that failed.
}