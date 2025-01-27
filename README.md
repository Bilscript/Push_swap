# Push_swap
```
██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗ 
██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗
██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝
██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝ 
██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║     
╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝
```
## 📑 Sommaire
1. [Description](#-description)
2. [Objectifs](#-objectifs)
3. [Instructions Disponibles](#-instructions-disponibles)
4. [Installation](#️-installation)
5. [Utilisation](#-utilisation)
6. [Fonctionnalités](#-fonctionnalités)
7. [Performance](#-performance)
8. [Tests](#-tests)
9. [Contribution](#-contribution)
10. [Notes](#-notes)
11. [License](#️-license)

## 📝 Description
Push_swap est un projet de tri qui consiste à trier des données sur une pile, avec un ensemble limité d'instructions, en utilisant le moins de coups possibles. Pour le faire, vous avez à votre disposition un ensemble d'entiers, deux piles nommées a et b, et un ensemble d'instructions pour manipuler les piles.

Représentation visuelle des piles :
```
    Pile A      Pile B
    ----        ----
->  3           1
    2           4
    6           
    5           
    ----        ----
```

## 🎯 Objectifs
- Apprendre à manipuler différents algorithmes de tri
- Optimiser le choix et l'utilisation des structures de données
- Développer la logique et l'optimisation de code

## 📚 Instructions Disponibles

| Commande | Description | Visualisation |
|----------|-------------|---------------|
| `sa` | swap a - échange les 2 premiers éléments de la pile a | `2 1 3` → `1 2 3` |
| `sb` | swap b - échange les 2 premiers éléments de la pile b | `2 1 3` → `1 2 3` |
| `ss` | `sa` et `sb` en même temps | - |
| `pa` | push a - prend le premier élément de b et le met sur a | `b:1 → a` |
| `pb` | push b - prend le premier élément de a et le met sur b | `a:1 → b` |
| `ra` | rotate a - décale d'une position vers le haut tous les éléments de la pile a | `1 2 3` → `2 3 1` |
| `rb` | rotate b - décale d'une position vers le haut tous les éléments de la pile b | `1 2 3` → `2 3 1` |
| `rr` | `ra` et `rb` en même temps | - |
| `rra` | reverse rotate a - décale d'une position vers le bas tous les éléments de la pile a | `1 2 3` → `3 1 2` |
| `rrb` | reverse rotate b - décale d'une position vers le bas tous les éléments de la pile b | `1 2 3` → `3 1 2` |
| `rrr` | `rra` et `rrb` en même temps | - |

## 🛠️ Installation

```bash
git clone https://github.com/votre-username/push_swap.git
cd push_swap
make
```

## 💻 Utilisation

```bash
./push_swap 2 1 3 6 5 8
```
ou
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG
```

Exemple de sortie :
```
pb
ra
pb
ra
sa
pa
pa
```

## ✨ Fonctionnalités
- Gestion des erreurs (doublons, caractères non numériques, etc.)
- Optimisation pour différentes tailles de pile
- Visualisation des mouvements effectués

## 📊 Performance
Le programme doit respecter les limites suivantes :

| Nombre d'éléments | Coups maximum |
|-------------------|---------------|
| 3 nombres | 3 coups |
| 5 nombres | 12 coups |
| 100 nombres | 700 coups |
| 500 nombres | 5500 coups |

```
Performance Chart:
┌────────────┐   
│     ▃     │ 3 nombres (3 coups)
│    ▃ ▃   │ 5 nombres (12 coups)
│   ▃   ▃  │ 100 nombres (700 coups)
│  ▃     ▃ │ 500 nombres (5500 coups)
└────────────┘
```

## 🧪 Tests
Pour tester votre programme :
```bash
# Compte le nombre d'opérations
./push_swap 2 1 3 6 5 8 | wc -l  

# Vérifie si le tri est correct
./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8  

# Test avec des nombres aléatoires
ARG=$(shuf -i 1-100 -n 100 | tr "\n" " "); ./push_swap $ARG | wc -l
```

## 🤝 Contribution
N'hésitez pas à contribuer au projet en :
1. [Ouvrant une issue](https://github.com/votre-username/push_swap/issues)
2. [Soumettant une pull request](https://github.com/votre-username/push_swap/pulls)

## 📝 Notes
- Le programme ne doit pas avoir de fuites de mémoire
- Le code doit respecter la [Norme de 42](https://github.com/42School/norminette)
- Les fonctions externes autorisées sont :
  - write
  - read
  - malloc
  - free
  - exit

## ⚖️ License
Ce projet est réalisé dans le cadre du cursus de l'école 42.

---
*Made by [Bilscript]*
