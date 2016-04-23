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
AT+CMGS=***REMOVED***

<message>

Crtl^z
```

Lecture d'un SMS depuis la sim:

```
AT+CMGL
```

Suppression d'un SMS :

```
AT+CMGD=<id>
```
