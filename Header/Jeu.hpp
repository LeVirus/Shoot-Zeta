#ifndef JEU
#define JEU

#include "constantes.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "Entite.hpp"
#include "Tir.hpp"
#include "Vaisseau.hpp"
#include "Niveau.hpp"
#include "../lib/Headers/Cercle.hpp"
#include "../lib/Headers/Polygone.hpp"
#include "VJoueur.hpp"
#include "VBanshee.hpp"
#include "TirJoueur.hpp"
#include "TirBanshee.hpp"

class Jeu;

class Jeu{
  private:
	 sf::Texture texture;
	 VJoueur *joueur;
	 short largeurFenetre, longueurFenetre, frame;
	 std::list<Entite*> chaineEntites;
	 std::list<Entite*>::iterator itEntite, itAux;
	 //sf::Image textVaisseau;
	 sf::RenderWindow window;
	 sf::View camera;
	 Niveau *actuel;//un niveau créé a la fois
	 //sf::Texture textureV;
	 unsigned short compteurFrameLvl;
  public:
	 Jeu();
	 void actionEntites();
	 void pushEntite(Entite *a);
	 sf::RenderWindow *getWindow();
	 void viderListe();
	 const Niveau &getNiveau()const;
	 //void deplacerCamera();
	 const sf::Texture &getTexture();
	 void lancerJeu();
	 
	 ~Jeu();
};

#endif 

/*Projet debuté debut juillet 2013*/
