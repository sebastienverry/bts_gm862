# Initialisation du module GM862-GPS

## Configuration série

Vitesse 9600bps
8bit
ixon
ixonc


## Commande AT:

Vérification fonctionnement ligne série:

```
AT
```

Identification sur la carte sim via le code pin:
```
AT+CPIN=0000
```

Réception GSM OK ?

```
AT+CREG?
```

Envoi d'un SMS:
```
AT+CMGF=1
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
