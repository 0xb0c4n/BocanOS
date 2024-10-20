# BocanOS

Ce projet est un exemple de système d'exploitation simple. Il utilise un fichier en assembleur pour générer un fichier binaire, et un fichier d'image de disquette (floppy) pour l'exécuter dans un émulateur.

## Prérequis

Assurez-vous d'avoir les outils suivants installés sur votre système :

- **nasm** : l'assembleur utilisé pour assembler le code source.
- **make** : pour automatiser la compilation et la construction.
- **qemu** : l'émulateur utilisé pour tester l'OS.

### Installation des dépendances (sur une distribution basée sur Debian)

```bash
sudo apt-get update
sudo apt-get install nasm qemu-system-x86 make
```

### Compilation et exécution

Exécutez ensuite ces commandes :
```bash
make
```
