#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Battle.h"

using namespace sf;



int main() {
    float posicaoCursor[2][6] = {
            {250, 700, 1150, 250, 700, 1150},
            {300, 300, 300, 600, 600, 600}
    };
    int pos=0, cond=2;
    int b=0, h=0, i=0, k=0, r=0, y=0, perfeitos = 0;
//rapido 1, forte 2, tecnico 3
    Battle baku("Baku - A Anta Faminta", 2,3, "baku-sprite.png", "baku-sprite2.png", "baku-portrait.png", 0, 100);
    Battle heikegani("Heikegani - O Caranguejo Raivoso", 3,2, "heikegani-sprite.png", "heikegani-sprite2.png", "heikegani-portrait.png", 450, 100);
    Battle ichimokuren("Ichimokuren - O Dragao do Vento", 2,1, "ichimokuren-sprite.png", "ichimokuren-sprite2.png", "ichimokuren-portrait.png", 900, 100);
    Battle karakasa("Karakasa - O Guarda-chuva Amaldicoado", 3,1, "karakasa-sprite.png", "karakasa-sprite2.png", "karakasa-portrait.png", 0, 400);
    Battle rokurokubi("Rokurokubi - A Mulher-cobra", 1,2, "rokurokubi-sprite.png", "rokurokubi-sprite2.png", "rokurokubi-portrait.png", 450, 400);
    Battle yatagarasu("Yatagarasu - O Corvo de Tres Pernas", 1,3, "yatagarasu-sprite.png", "yatagarasu-sprite2.png", "yatagarasu-portrait.png", 900, 400);

    RenderWindow window(VideoMode(1280, 720), "hunt");
    window.setKeyRepeatEnabled(false);

    Font font;
    font.loadFromFile("Japanola.ttf");
    Text titulo("Yokai Hunt!", font, 80);
    titulo.setPosition(450, 0);
    Text resultado;
    Texture texture;
    texture.loadFromFile("cursor.png");
    Sprite cursor(texture);
    cursor.setScale(.3,.3);
    Texture c;
    c.loadFromFile("comando.png");
    Sprite comando(c);
    comando.setScale(.3,.3);

    Music music;
    music.openFromFile("tema.ogg");
    music.play();
    music.setLoop(true);

    while (window.isOpen()){
        // Process events
        Event event;
        while (window.pollEvent(event)) {
            if(event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape){
                    window.close();
                } else if (event.key.code == Keyboard::Right) {
                    if (pos < 5) {
                        pos++;
                    } else {
                        pos = 0;
                    }
                } else if (event.key.code == Keyboard::LControl && perfeitos == 6){
                        cond = finalbattle(window);
                } else if (event.key.code == Keyboard::LControl) {
                    switch (pos) {
                        case 0:
                            cond = baku.battle(window);
                            if(cond == 3 && b==0){
                                b=1;
                                perfeitos += 1;
                            }
                            break;
                        case 1:
                            cond = heikegani.battle(window);
                            if(cond == 3 && h==0){
                                h=1;
                                perfeitos += 1;
                            }
                            break;
                        case 2:
                            cond = ichimokuren.battle(window);
                            if(cond == 3 && i==0){
                                i=1;
                                perfeitos += 1;
                            }
                            break;
                        case 3:
                            cond = karakasa.battle(window);
                            if(cond == 3 && k==0){
                                k=1;
                                perfeitos += 1;
                            }
                            break;
                        case 4:
                            cond = rokurokubi.battle(window);
                            if(cond == 3 && r==0){
                                r=1;
                                perfeitos += 1;
                            }
                            break;
                        case 5:
                            cond = yatagarasu.battle(window);
                            if(cond == 3 && y==0){
                                y=1;
                                perfeitos += 1;
                            }
                            break;
                        default:
                            break;
                    }
                }
            }

            if (cond == 1) {
                resultado.setString("Vitoria!");
                resultado.setFont(font);
                resultado.setCharacterSize(60);
                resultado.setPosition(970, 0);
                resultado.setFillColor(Color::Green);
                cond = 2;
            } else if (cond == 0) {
                resultado.setString("Derrota!");
                resultado.setFont(font);
                resultado.setCharacterSize(60);
                resultado.setPosition(970, 0);
                resultado.setFillColor(Color::Red);
                cond = 2;
            } else if (cond == 3) {
                resultado.setString("Perfeito!!");
                resultado.setFont(font);
                resultado.setCharacterSize(60);
                resultado.setPosition(970, 0);
                resultado.setFillColor(Color::Yellow);
                cond = 2;
            }
        }
        if (perfeitos == 6){
            Texture boss;
            boss.loadFromFile("tamamo.png");
            Sprite final(boss);
            final.setPosition(280, 100);
            final.setScale(.5, .5);
            window.clear();
            window.draw(titulo);
            window.draw(resultado);
            window.draw(final);
            cursor.setPosition(700, 400);
            window.draw(cursor);
            window.draw(comando);
            window.display();
        } else {
            // Clear screen
            window.clear();
            window.draw(titulo);
            window.draw(resultado);
            window.draw(baku.getPt());
            window.draw(heikegani.getPt());
            window.draw(ichimokuren.getPt());
            window.draw(karakasa.getPt());
            window.draw(rokurokubi.getPt());
            window.draw(yatagarasu.getPt());
            cursor.setPosition(posicaoCursor[0][pos], posicaoCursor[1][pos]);
            window.draw(cursor);
            window.draw(comando);
            window.display();
        }
    }
    return 0;
}
