#include "Jeu.hpp"
#include "TirJoueur.hpp"

using namespace std;

extern Jeu *memJeu;

TirJoueur::TirJoueur( Vaisseau *Vaiss, short inclinaison){
  Tir::initTir(Vaiss, inclinaison);
  initialiser();
  degatsCol=2;
  velocite=40;

}

void TirJoueur::initialiser(){
  sprite.setTexture( memJeu->getTexture() );
  sprite.setTextureRect(sf::IntRect(82, 202, 38, 13));
  longueur=38;
  largeur=13;
  Entite::initialiser();
}

short TirJoueur::getType(){
  return TIR_J;
}

void TirJoueur::explode(){  
  /*if(!explose)explose=true;
    switch(frameExplode){//generer image sprite
		case 1://vaisseau Joueur
		  sprite.setTextureRect(sf::IntRect(390, 315, 55, 120));
		  //sprite.setScale (0.1, 0.1);
		  break;
		//case 2://vaisseau Joueur TMP
		case 0://tir Joueur
		  //sprite.setTextureRect(sf::IntRect(375, 160, 64, 45));
		  break;
		default://tir Joueur TMP
		  deplacer(10000, 0);		  
		break;
	 }
    frameExplode++;*/
}

void TirJoueur::gestionBot(){
  //sprite.move(X,Y);
  deplacer(  velocite, angle );
}

TirJoueur::~TirJoueur(){} 
