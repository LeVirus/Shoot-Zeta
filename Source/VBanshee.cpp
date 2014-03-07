#include "Jeu.hpp"

using namespace std;//TMPPPPPPPPPPPPPPPPPPP

extern Jeu *memJeu;

VBanshee::VBanshee( short position, short inclinaison){
  Vaisseau::initVaisseau( inclinaison);
  initialiser();
  degatsCol=30;
  pointDeVie=10;
  //definition masque collision
  std::vector<lc::Point> tab;
  tab.resize(4);
  tab[0]=lc::Point(0,0);
  tab[1]=lc::Point(longueur-10,0);
  tab[2]=lc::Point(longueur-10,largeur-10);
  tab[3]=lc::Point(0,largeur-10);
  masqueCol->attribuerTab(tab);
  frameMove=10;
  frameShoot=10;
  positionInitial=position;
  diagonale=7;
  velocite=10;
  choixTypeTir=EST;
}

void VBanshee::explode(){
  if(!explose)explose=true;
  switch(frameExplode){//generer image sprite
	 case 1://vaisseau Joueur
		sprite.setTextureRect(sf::IntRect(390, 315, 55, 120));
		break;
	 case 2://vaisseau Joueur TMP
		sprite.setTextureRect(sf::IntRect(377, 6, 51, 139));
		break;
	 case 3://tir Joueur
		sprite.setTextureRect(sf::IntRect(375, 160, 64, 45));
		break;
	 case 0://tir Joueur
		//sprite.setTextureRect(sf::IntRect(375, 160, 64, 45));
		break;
	 default://tir Joueur TMP
		deplacer(10000, 0);		  
	 break;
  }
  frameExplode++;
}

short VBanshee::getType(){
  return VAISSEAU_E;
}

void VBanshee::initialiser(){
  sprite.setTexture( memJeu->getNiveau().getTextEnnemi() );
  sprite.setTextureRect(sf::IntRect(187, 153, 30, 30));
  sprite.setScale (2, 2);
  longueur=60;
  largeur=60;
  Entite::initialiser();
}
	 //virtual bool checkCollisions(Entite *b);
void VBanshee::gestionBot(){
  if(frameActuelle%frameMove==0){//deplacement
	 deplacer(velocite, angle);
  }
  if(frameActuelle==30){
	 frameActuelle=0;
	 tirer(TBANCHEE);
  }
  else frameActuelle++;
}

VBanshee::~VBanshee(){
  
}
