#include "Jeu.hpp"
using namespace std;

extern Jeu *memJeu;

Entite::Entite(){
  explose=false;
  masqueCol=NULL;
  longueur=0;
  largeur=0;
  colorDegat=0;
  frameInvuln=0;
}

void Entite::initialiserEntite(short inclinaison){
  angle=inclinaison;//positionner tir devant le vaisseau
  angleEnRadianDefault = static_cast<double>(angle) * PI / 180.0;
  multiplicateurXDefault = static_cast<float>(cos(angleEnRadianDefault)), 
  multiplicateurYDefault = static_cast<float>(sin(angleEnRadianDefault));
  //Entite::personnaliser();//charger le sprite
  angleCentre= atan(   static_cast<double> (sprite.getTextureRect().height) /
  static_cast<double> ( sprite.getTextureRect().width )   );
  angleCentre*=180.0/PI;//convertir en degre
}

void Entite::positionnerSprite(short x, short y){
  sprite.setPosition (x,y);
}

bool Entite::explosion(){
  return explose;
}

bool Entite::verifActiver(short frameAct){
  //if(sprite.getColor ()!= sf::Color::White)sprite.setColor(sf::Color::White);
  if( active )return true;
  if( sprite.getPosition().x>frameAct )return false;//si frame de declanchement pas encore atteint
  double x,y;
  switch(positionInitial){
	 case NORD:
		if(angle<10  ||  angle>170){
		  sprite.setPosition (1000,1000);//placer objet hors ecran pour le detruire
		  cout<<"erreur angle NORD"<<endl;
		  return true;
		}
		
		x=sprite.getPosition().y ;//placer au nord
		y=memJeu->getWindow()->getDefaultView().getCenter().y - 
		memJeu->getWindow()->getDefaultView().getSize ().y/2 - sprite.getGlobalBounds().height/2;
		break;
	 case SUD:
		if(angle>350  ||  angle<190){
		  sprite.setPosition (1000,1000);//placer objet hors ecran pour le detruire
		  cout<<"erreur angle SUD"<<endl;
		  return true;
		}
		
		x=sprite.getPosition().y;//placer au sud
		y=memJeu->getWindow()->getDefaultView().getCenter().y + 
		memJeu->getWindow()->getDefaultView().getSize ().y/2 + sprite.getGlobalBounds().height/2;
		break;
	 case OUEST:
		if( (angle<280  &&  angle>350)  ||  (angle<10  &&  angle>80) ){
		  sprite.setPosition (1000,1000);//placer objet hors ecran pour le detruire
		  cout<<"erreur angle OUEST"<<endl;
		  return true;
		}
		
		x=memJeu->getWindow()->getDefaultView().getCenter().x - 
		memJeu->getWindow()->getDefaultView().getSize ().x/2 - sprite.getGlobalBounds().width/2;
		y=sprite.getPosition().y;//placer a l'ouest
		break;
	 case EST:
		if(angle<100  ||  angle>260){
		  sprite.setPosition (1000,1000);//placer objet hors ecran pour le detruire
		  cout<<"erreur angle EST"<<endl;
		  return true;
		}
		
		x=memJeu->getWindow()->getDefaultView().getCenter().x + 
		memJeu->getWindow()->getDefaultView().getSize ().x/2 + sprite.getGlobalBounds().width/2;
		y=sprite.getPosition().y;//placer a l'est
		break;
	 default:
		break;
  }
  sprite.setPosition (x,y);
  //sprite.setPosition (200,150);//TMPיייייייייייייייייייייייייייי
  active=true;
  return true;
}

void Entite::initialiser(){
  float memX,memY;
  /*if(!memJeu)cout<<"erreur alloc Entite personnaliser"<<endl;
  switch(typeEntite){//generer image sprite
	 case VAISSEAU_J://vaisseau Joueur
		sprite.setTexture( memJeu->getTexture() );
		sprite.setTextureRect(sf::IntRect(220, 0, 80, 75));
		longueur=80;
		largeur=75;
		break;
	 case VAISSEAU_E://vaisseau Joueur TMP
		sprite.setTexture( memJeu->getNiveau().getTextEnnemi() );
		sprite.setTextureRect(sf::IntRect(187, 153, 30, 30));
		sprite.setScale (2, 2);
		longueur=60;
		largeur=60;
		break;
	 case TIR_J://tir Joueur
		sprite.setTexture( memJeu->getTexture() );
		sprite.setTextureRect(sf::IntRect(82, 202, 38, 13));
		longueur=38;
		largeur=13;
		break;
	 case TIR_E://tir Joueur TMP
		sprite.setTexture( memJeu->getNiveau().getTextEnnemi() );
		sprite.setTextureRect(sf::IntRect(290, 100, 15, 15));
		sprite.setScale (2, 2);
		longueur=30;
		largeur=30;
		break;
	 default://erreur
		sprite.setTexture( memJeu->getTexture() );
		sprite.setTextureRect(sf::IntRect(0, 0, 38, 13));
		longueur=38;
		largeur=13;
		break;
  }*/
  memX=sprite.getTextureRect().width/2;
  memY=sprite.getTextureRect().height/2;
  sprite.setOrigin(memX, memY);//if(!masqueCol)cout<<"erreur alloc entite"<<endl;
  masqueCol->setOrigin(memX, memY);//modifier origine masque
  sprite.setRotation(angle);
  if(masqueCol)masqueCol->pivoter(angle);
  //if(typeEntite==VAISSEAU_J)//TMPEEEEEEEEE
	 //sprite.move(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
}

bool Entite::checkCollisions(Entite *b){//temporaire
  if(frameInvuln>0){
	 frameInvuln--;
	 return false;
  }
  //if( !sprite.getGlobalBounds().intersects( b->getSprite().getGlobalBounds() ) )return false;
  //si collision des boites englobantes (SFML)
  if(!masqueCol  ||  !b->masqueCol){
	 cout<<"erreur alloc entite"<<endl;
	 return false;
  }//cout<<sprite.getPosition().x<<"   "<<sprite.getPosition().y<<endl;
  masqueCol->positionner(sprite.getPosition().x+ sprite.getOrigin().x,
									 sprite.getPosition().y+ sprite.getOrigin().y);
  b->masqueCol->positionner(b->sprite.getPosition().x+ b->sprite.getOrigin().x,
									 b->sprite.getPosition().y+ b->sprite.getOrigin().y);//positionner les masques
  return lc::Figure::checkCollision(*masqueCol, *b->masqueCol);
}

/*short Entite::getType(){
  return typeEntite;
}*/

sf::Sprite Entite::getSprite(){
  if(colorDegat>0){
	 colorDegat--;
	 if(colorDegat==0)sprite.setColor(sf::Color::White);//si compteur a 0 retablir
  }
  return sprite;
}

void Entite::recevoirDegats(Entite *a){
  if(!a)return;
  pointDeVie-=a->degatsCol;
  sprite.setColor(sf::Color::Yellow);
  colorDegat=4;
  frameInvuln=4;
  if(pointDeVie<1)explose=true;
}

bool Entite::dansEcran(){
  sf::FloatRect tmpRect(memJeu->getWindow()->getViewport( memJeu->getWindow()->getView () ));
  //necessaire a la conversion intrect vers floatrect
  return sprite.getGlobalBounds().intersects(tmpRect);
}

void Entite::deplacer(float pixels, float degre){
  double angleEnRadian;
  float multiplicateurX, multiplicateurY, deplacementEnX, deplacementEnY;
  if(degre==angle){
	 sprite.move(pixels * multiplicateurXDefault, pixels * multiplicateurYDefault);
	 return;
  }
  angleEnRadian = static_cast<double>(degre) * PI / 180.0;
  multiplicateurX = static_cast<float>(cos(angleEnRadian));
  multiplicateurY = static_cast<float>(sin(angleEnRadian));

	deplacementEnX = pixels * multiplicateurX;
	deplacementEnY = pixels * multiplicateurY;

	sprite.move(deplacementEnX, deplacementEnY);
}


double Entite::getAngleCentre(){
  return angleCentre;
}



Entite::~Entite(){
  if(masqueCol)delete masqueCol;
}