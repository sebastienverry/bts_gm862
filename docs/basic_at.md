# Initialisation du module GM862-GPS

## Configuration série

Vitesse 9600bps
8bit
ixon
ixonc


## Commande AT:

Vérification que le modem est en marche:

```
AT
```

Configuration du code Pin de la carte:
```
AT+CPIN=0000
```

Réception GSM OK ?

```
AT+CREG?
```

Envoi d'un SMS:

 Sélection du format des messages, 1 signifie qu'il est en mode Texte.
```
AT+CMGF=1
```
Commande pour rentrer le numéros de téléphone du réceptionneur et du message a envoyer
```
AT+CMGS=<phone number>

<message>

Crtl^z
```

Lecture d'un SMS depuis la sim:

```
AT+CMGL
```
### Suppression

Supprime les SMS déjà lus
```
AT+CMGD =1
```

Supprime les SMS lus, et envoyés
```
T+CMGD=2
```

 Supprime les SMS lus, envoyés et non envoyés
```
AT+CMGD=3
```
Supprimes tous les SMS (lus, non lus, envoyés et non envoyés)
```
AT+CMGD=4 
```
### Reboot 

Reset le modem 
```
ATZ
```
### Lecture SMS
Lire les messages contenu sur la carte Sim
```
AT+CMGL
```
