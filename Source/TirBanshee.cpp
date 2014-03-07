#include "Jeu.hpp"

using namespace std;

extern Jeu *memJeu;

TirBanshee::TirBanshee( Vaisseau *Vaiss, short inclinaison){
  Tir::initTir(Vaiss, inclinaison);
  initialiser();
  degatsCol=1;
  velocite=4;
  /*std::vector<lc::Point> tab;
  masqueCol=new lc::Polygone;
  Entite::initialiserEntite(inclinaison,type);
  tab.resize(4);
  tab[0]=lc::Point(-velocite+longueur,0);
  tab[1]=lc::Point(longueur,0);
  tab[2]=lc::Point(longueur,largeur);
  tab[3]=lc::Point(-velocite+longueur,largeur);
  masqueCol->attribuerTab(tab);
  masqueCol->setRotation( getAngleCentre() );
  active=true;
  memoV=Vaiss;
  
  
  sprite.setPosition (  memoV->getSprite().getPosition ().x ,memoV->getSprite().getPosition ().y );*/
    //definition masque collision
}

short TirBanshee::getType(){
  return TIR_E;
}

void TirBanshee::initialiser(){
  sprite.setTexture( memJeu->getNiveau().getTextEnnemi() );
  sprite.setTextureRect(sf::IntRect(290, 100, 15, 15));
  sprite.setScale (2, 2);
  longueur=30;
  largeur=30;
  Entite::initialiser();
}

void TirBanshee::explode(){  
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

void TirBanshee::gestionBot(){
  //sprite.move(X,Y);
  deplacer(  velocite, angle );
}

TirBanshee::~TirBanshee(){} 
