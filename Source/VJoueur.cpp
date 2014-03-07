#include "Jeu.hpp"

using namespace std;

extern Jeu *memJeu;

VJoueur::VJoueur( short position, short inclinaison){
  Vaisseau::initVaisseau( inclinaison);
  initialiser();
  degatsCol=30;
  pointDeVie=10;
  //definition masque collision
  std::vector<lc::Point> tab;
  tab.resize(4);
  tab[0]=lc::Point(0,0);
  tab[1]=lc::Point(longueur-20,0);
  tab[2]=lc::Point(longueur-20,largeur-20);
  tab[3]=lc::Point(0,largeur-20);
  masqueCol->attribuerTab(tab);
  frameMove=5;
  frameShoot=180;
  positionInitial=position;
  diagonale=4;
  velocite=5;
  choixTypeTir=TRIPLE_AVANT;
}

void VJoueur::initialiser(){
  sprite.setTexture( memJeu->getTexture() );
  sprite.setTextureRect(sf::IntRect(220, 0, 80, 75));
  longueur=80;
  largeur=75;
  Entite::initialiser();
}

short VJoueur::getType(){
  return VAISSEAU_J;
}

void VJoueur::explode(){
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
	 //virtual bool checkCollisions(Entite *b);
//void VJoueur::gestionBot(){
  /*if(frameActuelle%frameMove==0){//deplacement
	 deplacer(velocite, angle);
  }
  if(frameActuelle==30){
	 frameActuelle=0;
	 tirer();
  }
  else frameActuelle++;*/
//}
	 
void VJoueur::gestionBot(){}//pour eviter bug

void VJoueur::deplacerJoueur(short choix){
  sf::IntRect tmpRect( memJeu->getWindow()->getViewport( memJeu->getWindow()->getView () ));
  //recup du rect de la vue courante
  short ox=sprite.getGlobalBounds().left, oy=sprite.getGlobalBounds().top, x=0, y=0;
  //cout<<"fssdsdcxsvxc"<<ox<<"sfdf"<<oy<<endl;
  //structureJeu->windowMasque->getViewport()
	 switch(choix){
		case HAUT:
		  if(tmpRect.contains (ox, oy-velocite))y=velocite*-1;//oy-velocite)
		  break;
		case BAS:
		  if(tmpRect.contains ( ox, oy + sprite.getGlobalBounds().height+velocite))y=velocite;
		  //else cout<<"cxsvxc"<<oy + sprite.getGlobalBounds().height<<"   "<<velocite<<endl;
		  break;
		case GAUCHE:
		  if(tmpRect.contains ( ox-velocite , oy ))x=-1*velocite;
		  break;
		case DROITE:
		  if(tmpRect.contains ( ox+sprite.getGlobalBounds().width+velocite , oy ))
			 x=velocite;
		  break;
		case HAUT_GAUCHE:
		  if(tmpRect.contains( ox-diagonale , oy ))
			 x=-1*diagonale;
		  if(tmpRect .contains ( ox , oy-diagonale ))
			 y=-1*diagonale;
		  break;
		case HAUT_DROITE:
		  if(tmpRect.contains ( ox+sprite.getGlobalBounds().width+diagonale , oy ))
			 x=diagonale;
		  if(tmpRect.contains ( ox , oy-diagonale ))
			 y=-1*diagonale;
		  break;
		case BAS_GAUCHE:
		  if(tmpRect.contains ( ox-diagonale , oy ))
			 x=-1*diagonale;
		  if(tmpRect.contains ( ox , oy + sprite.getGlobalBounds().height+diagonale ))
			 y=diagonale;
		  break;
		case BAS_DROITE:
		  if(tmpRect.contains ( ox+sprite.getGlobalBounds().width+diagonale , oy ))
			 x=diagonale;
		  if(tmpRect.contains ( ox , oy + sprite.getGlobalBounds().height+diagonale ))
			 y=diagonale;
		  break;
	}
	sprite.move(x,y);//cout<<x<<"ffff"<<y<<endl;
}

VJoueur::~VJoueur(){
  
}
