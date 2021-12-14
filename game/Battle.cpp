//
// Created by linco on 23/10/2021.
//
/** \file */

#include "Battle.h"
#include <string>


Battle::Battle(std::string nomem, int atky1, int atky2, const std::string& sprite, const std::string& sprite2, const std::string& portrait, float x, float y) : atky1(atky1), atky2(atky2) {
    nome = nomem;
    lifeyokai = 6;
    lifeplayer = 4;
    textureportrait.loadFromFile(portrait);
    sportrait.setTexture(textureportrait);
    sportrait.setPosition(x, y);
    sportrait.setScale(.28, .28);
    texturesprite.loadFromFile(sprite);
    texturesprite2.loadFromFile(sprite2);
    spriteb.setTexture(texturesprite);
    spriteb.setPosition(470,150);
    //spriteb.setScale(.28, .28);
}

//rapido 1, forte 2, tecnico 3
int Battle::battle(RenderWindow &window) {
    Event bat;
    Texture t;
    t.loadFromFile("tabelaataque.png");
    Sprite s(t);
    s.setScale(.3, .3);
    s.setPosition(50, 450);
    Font font;
    font.loadFromFile("Japanola.ttf");
    spriteb.setTexture(texturesprite);
    
    while(window.isOpen()) {
        atkp = 0;
        while (window.pollEvent(bat)) {
            if (bat.type == Event::KeyPressed) {
                if (bat.key.code == Keyboard::Left) {
                    atkp = 1;
                } else if (bat.key.code == Keyboard::Up) {
                    atkp = 2;
                } else if (bat.key.code == Keyboard::Right) {
                    atkp = 3;
                }
            }
        }

        if (atkp != 0) {
            spriteb.move(-20, +10);
            if (lifeyokai > 3) {
                if (compare(atky1, atkp) == 1) {
                    lifeyokai -= 1;
                } else if (compare(atky1, atkp) == 0) {
                    lifeplayer -= 1;
                } else if (compare(atky1,atkp) == 2) {
                    lifeyokai -= 1;
                    lifeplayer -= 1;
                }
            } else if (lifeyokai <= 3) {
                if (compare(atky2, atkp) == 1) {
                    lifeyokai -= 1;
                } else if (compare(atky2, atkp) == 0) {
                    lifeplayer -= 1;
                }else if (compare(atky2,atkp) == 2) {
                    lifeyokai -= 1;
                    lifeplayer -= 1;
                }
            }
            if (lifeplayer < 1 || lifeyokai < 1) {
                if (lifeplayer < 1) {
                    lifeyokai = 6;
                    lifeplayer = 4;
                    return 0;
                } else if (lifeplayer<4) {
                    lifeyokai = 6;
                    lifeplayer = 4;
                    return 1;
                } else if (lifeplayer == 4) {
                    lifeyokai = 6;
                    lifeplayer = 4;
                    return 3;
                }
            }
        }
        if(lifeyokai==3){
            spriteb.setTexture(texturesprite2);
        }

        window.clear();
        char *v;
        itoa(lifeplayer, v, 10);
        String vidaplayer = "Sua vida: ";
        vidaplayer = vidaplayer+v;
        Text vidap(vidaplayer, font, 80);
        vidap.setPosition(400, 600);
        Text name(nome, font, 60);
        name.setPosition(40, 0);
        window.draw(vidap);
        window.draw(spriteb);
        if (spriteb.getPosition().x<470 && spriteb.getPosition().y>150){
            spriteb.move(+0.2, -0.1);
        }
        window.draw(s);
        window.draw(name);
        window.display();
    }
}

const sf::Sprite &Battle::getPt() const {
    return sportrait;
}

int compare(int y, int p) {
    // 1>2, 2>3, 3>1
    if(p==1){
        if(y==1){
            return 2;
        }else if(y==2){
            return 1;
        }else if(y==3){
            return 0;
        }
    }else if(p==2){
        if(y==1){
            return 0;
        }else if(y==2){
            return 2;
        }else if(y==3){
            return 1;
        }
    }else if(p==3){
        if(y==1){
            return 1;
        }else if(y==2){
            return 0;
        }else if(y==3){
            return 2;
        }
    }
    return 2;
}

int finalbattle(RenderWindow &window) {
    int lifeplayer = 4, lifeyokai = 9;
    Event bat;
    Texture t;
    t.loadFromFile("tabelaataque.png");
    Sprite s(t);
    s.setScale(.3, .3);
    s.setPosition(50, 450);
    Font font;
    font.loadFromFile("Japanola.ttf");
    Texture t1, t2, t3;
    t1.loadFromFile("tamamo1.png");
    t2.loadFromFile("tamamo2.png");
    t3.loadFromFile("tamamo3.png");
    Sprite stamamo;
    stamamo.setTexture(t1);
    stamamo.setPosition(450,100);
    stamamo.setScale(.8, .8);

    while(window.isOpen()) {
        int atkp = 0;
        while (window.pollEvent(bat)) {
            if (bat.type == Event::KeyPressed) {
                if (bat.key.code == Keyboard::Left) {
                    atkp = 1;
                } else if (bat.key.code == Keyboard::Up) {
                    atkp = 2;
                } else if (bat.key.code == Keyboard::Right) {
                    atkp = 3;
                }
            }
        }

        if (atkp != 0) {
            stamamo.move(-20, +10);
            if (lifeyokai > 6) {
                if (compare(1, atkp) == 1) {
                    lifeyokai -= 1;
                } else if (compare(1, atkp) == 0) {
                    lifeplayer -= 1;
                } else if (compare(1,atkp) == 2) {
                    lifeyokai -= 1;
                    lifeplayer -= 1;
                }
            }  else if (lifeyokai <= 3) {
                if (compare(2, atkp) == 1) {
                    lifeyokai -= 1;
                } else if (compare(2, atkp) == 0) {
                    lifeplayer -= 1;
                } else if (compare(2, atkp) == 2) {
                    lifeyokai -= 1;
                    lifeplayer -= 1;
                }
            } else if (lifeyokai <= 6) {
                if (compare(3, atkp) == 1) {
                    lifeyokai -= 1;
                } else if (compare(3, atkp) == 0) {
                    lifeplayer -= 1;
                }else if (compare(3,atkp) == 2) {
                    lifeyokai -= 1;
                    lifeplayer -= 1;
                }
            }
            if (lifeplayer < 1 || lifeyokai < 1) {
                if (lifeplayer < 1) {
                    return 0;
                } else if (lifeplayer < 4) {
                    return 1;
                } else if (lifeplayer == 4) {
                    return 3;
                }
            }
        }
        if(lifeyokai == 6){
            stamamo.setTexture(t2);
        } else if (lifeyokai == 3){
            stamamo.setTexture(t3);
        }

        window.clear();
        String vidaplayer = "Sua vida: ";
        /*
        char *v;
        itoa(lifeplayer, v, 10);
        vidaplayer = vidaplayer+v;
        */
        if(lifeplayer==4){
            vidaplayer = vidaplayer+"4";
        }else if(lifeplayer == 3){
            vidaplayer = vidaplayer+"3";
        }else if(lifeplayer == 2){
            vidaplayer = vidaplayer+"2";
        }else if (lifeplayer == 1){
            vidaplayer = vidaplayer+"1";
        }

        Text vidap(vidaplayer, font, 80);
        vidap.setPosition(400, 600);
        Text name("Tamamo-no-Mae - A Raposa de Nove Caudas", font, 60);
        name.setPosition(20, 0);
        window.draw(vidap);
        window.draw(stamamo);
        if (stamamo.getPosition().x<450 && stamamo.getPosition().y>100){
            stamamo.move(+0.2, -0.1);
        }
        window.draw(s);
        window.draw(name);
        window.display();
    }
}
