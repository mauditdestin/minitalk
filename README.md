# Minitalk

Minitalk est un projet qui permet la communication entre deux processus via des signaux Unix (`SIGUSR1` et `SIGUSR2`). Ce programme transmet un message texte bit par bit du client vers le serveur en utilisant uniquement des signaux, sans passer par les classiques pipes ou sockets.

---

## Fonctionnement

- Le **serveur** démarre et affiche son PID (Process ID).
- Le **client** envoie un message au serveur en convertissant chaque caractère en bits.
- Chaque bit est transmis via un signal :
  - `SIGUSR1` = bit 0
  - `SIGUSR2` = bit 1
- Le serveur reçoit les signaux, reconstruit le message et l’affiche.
- À la fin, le serveur envoie une confirmation au client.

---

## Installation

Clonez le dépôt et compilez avec `make` :

```bash
git clone <URL_DU_REPO>
cd minitalk
make
