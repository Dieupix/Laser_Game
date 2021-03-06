<img align="right" src="https://www.fst.uha.fr/wp-content/uploads/2018/06/cropped-logo-site-V3.png" title="Logo de la Faculté des Sciences et Techniques (FST) de Mulhouse - Université de Haute Alsace (UHA)">

# Projet de POO - Laser Game

[![License Apach-2.0](https://img.shields.io/github/license/Dieupix/Laser_Game?color=dark&style=for-the-badge)](https://github.com/Dieupix/Laser_Game/blob/main/LICENSE.md)
[![Faculté FST](https://img.shields.io/badge/Faculté-FST-blue?style=for-the-badge)](https://www.fst.uha.fr)
[![Université UHA](https://img.shields.io/badge/Université-UHA-darkblue?style=for-the-badge)](https://www.uha.fr)

- Ce projet concerne la création d'un jeu de tir avec des lasers.
- Il s'appuie de Code::Blocks pour coder le jeu en C++.
- Le projet est réalisé dans le cadre d'un projet scolaire en L3 MIAGE à l'Université de Haute Alsace ([UHA](https://www.uha.fr)).
- La structure du projet est disponible <a href="#structure">ici</a>.
- Les contributions sont disponibles <a href="#contributions">en fin de page</a>.

## Le projet

Ce projet consiste à créer un jeu de tir avec des lasers. Sur un terrain entouré de murs, se placent un tireur et une cible. Le tireur tire un laser qui doit toucher la cible pour gagner. Au préalable, le joueur peut poser des miroirs pour faire dévier le laser de sa trajectoire et éviter certains obstacles.

<a id="user-content-structure" class="anchor" href="#structure" aria-hidden="true"></a>
## Structure du projet

```
Laser_Game
├── Headers
|   ├── enumTypes.h
|   ├── game.h
|   ├── grid.h
|   ├── ground.h
|   ├── laser.h
|   ├── mirror.h
|   ├── object.h
|   ├── point.h
|   ├── shooter.h
|   ├── target.h
|   ├── viewer.h
|   ├── viewerOnTerminal.cpp
|   └── wall.h
└── Sources
    ├── game.cpp
    ├── grid.cpp
    ├── ground.cpp
    ├── laser.cpp
    ├── main.cpp
    ├── mirror.cpp
    ├── object.cpp
    ├── point.cpp
    ├── shooter.cpp.cpp
    ├── target.cpp
    ├── viewerOnTerminal.cpp
    └── wall.cpp
    
testLaser_Game
├── Headers
|   ├── Laser_Game
|   |   ├── enumTypes.h
|   |   ├── game.h
|   |   ├── grid.h
|   |   ├── ground.h
|   |   ├── laser.h
|   |   ├── mirror.h
|   |   ├── object.h
|   |   ├── point.h
|   |   ├── shooter.h
|   |   ├── target.h
|   |   ├── viewer.h
|   |   ├── viewerOnTerminal.cpp
|   |   └── wall.h
|   └── testLaser_Game
|       └── doctest.h
└── Sources
    ├── Laser_Game
    |   ├── game.cpp
    |   ├── grid.cpp
    |   ├── ground.cpp
    |   ├── laser.cpp
    |   ├── main.cpp
    |   ├── mirror.cpp
    |   ├── object.cpp
    |   ├── point.cpp
    |   ├── shooter.cpp.cpp
    |   ├── target.cpp
    |   ├── viewerOnTerminal.cpp
    |   └── wall.cpp
    └── testLaser_Game
        ├── groundTest.cpp
        ├── laserTest.cpp
        ├── main.cpp
        ├── mirrorTest.cpp
        ├── objectTest.cpp
        ├── targetTest.cpp
        └── wallTest.cpp
```

<a id="user-content-contributions" class="anchor" href="#contributions" aria-hidden="true"></a>
## Contributions au projet

Professeur(s) encadrant(s) :\
\- M. RIVIÈRE Stéphane

L'équipe du MOE :
| Membre            | Rôle                  |
|:---|:---|
| BARRÈRE Manuel    | Responsable projet & développeur   |
| CHARRIER Mathis   | Développeur           |
| JANON Alexandre   | Développeur           |
| TAMRABET Meriem   | Développeur           |

Merci à [Discord](https://discord.com) pour la communication au sein du groupe.\
Merci à [Doctest](https://github.com/doctest/doctest) pour le framework.\
Merci à [GanttProject](https://www.ganttproject.biz) pour son application GanttProject.\
Merci à [Google](https://google.com) pour ses applications telles que Doc, Drive, etc.\
Merci à [shields.io](https://shields.io) pour la création des badges.

Un grand merci à [GitHub](https://github.com) pour l'hébergement du projet.

---

[![Discord Dieupix](https://img.shields.io/badge/Discord-Dieupix%230340-purple?style=for-the-badge&logo=discord)](https://discord.com)
