//
// Created by linco on 23/10/2021.
//

#ifndef YOKAIHUNT_BATTLE_H
#define YOKAIHUNT_BATTLE_H

#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class Battle {
private:
    int lifeyokai, lifeplayer, atky1, atky2, atkp;
    Texture texturesprite, texturesprite2, textureportrait;
    Sprite spriteb, sportrait;
    String nome;

public:
    Battle(std::string nomem, int atky1, int atky2, const std::string& sprite, const std::string& sprite2, const std::string& portrait, float, float);
    const Sprite &getPt() const;
    int battle(RenderWindow&);


};
static int compare(int, int);
int finalbattle(RenderWindow&);

#endif //YOKAIHUNT_BATTLE_H
