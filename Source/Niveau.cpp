#include "Jeu.hpp"

using namespace std;

extern Jeu *memJeu;

Niveau::Niveau( short numero){
  num=numero;
  
  if(  !textureNiveau.loadFromFile("Images/backgroundA.jpg")  )//load background
	 std::cout<<"fail load niveau text"<<std::endl;
  textEnnemie.loadFromFile("Images/ennemisText.png");//creer objet image pour masquer une couleur
  //textEnnemie.createMaskFromColor((sf::Color::Black),0);
  spriteBackGround.setTexture(textureNiveau);
  spriteBackGround.setTextureRect(sf::IntRect(0, 0, 500, 400));
  deplacBGX=0;
  deplacBGY=0;
  freqMoveBG=0;
  spriteBackGround.setPosition (//placer angle haut gauche
	 memJeu->getWindow()->getDefaultView().getCenter().x - memJeu->getWindow()->getDefaultView().getSize ().x/2,
	 memJeu->getWindow()->getDefaultView().getCenter().y - memJeu->getWindow()->getDefaultView().getSize ().y/2);
  cmpt=0;
}

void Niveau::chargerNiveau(){
  Entite *tmp;
  string ligne;
  const char *nomLvl;
  short nombre, type, tmpPosition, tmpX, tmpY, securite=0, tmpAngle;
  switch(num){
	 case 0:
		nomLvl="Ressources/level1";
		//if( textureNiveau.loadFromFile("Images/textureA.png")  )std::cout<<"fail load im"<<std::endl;
		break;
		
	 default:
		std::cout<<"erreur num niveau"<<std::endl;
		return;
		break;
  }
  
  ifstream flux(nomLvl, ios::in);
  if(flux){
	 while(  getline(flux, ligne)  ){
		if(ligne=="END")break;
		securite++;
		if(securite>2){std::cout<<"erreur ddd"<<std::endl;break;}
		istringstream iss(ligne);
		iss>>nombre;
		iss>>type;//definiera le type de vaisseau a creer
		for(short i=0;i<nombre;++i){
		  iss>>tmpPosition;
		  iss>>tmpX;
		  iss>>tmpY;
		  iss>>tmpAngle;
		  tmp=new VBanshee( tmpPosition,tmpAngle  );
		  tmp->positionnerSprite(tmpX, tmpY);//X pour frame a declancher Y pour positionner au pixel
		  //de la bordure de l'ecran selectionné par position
		  memJeu->pushEntite(tmp);
		}
	 }
	 flux.close();  // on ferme le fichier
  }
  else std::cout<<"erreur flux"<<std::endl;
}

const sf::Texture &Niveau::getTextEnnemi()const{
  return textEnnemie;
}



void Niveau::actionBG(/*short frame*/){
  //if(frame%freqMoveBG!=0)return;
  cmpt++;
  if(deplacBGX>=-30  &&  cmpt==5){//pour acceleration TMP fun
	 cmpt=0;
	 deplacBGX--;
  }
  sf::Vector2<float> angleHG(memJeu->getWindow()->getDefaultView().getCenter().x - memJeu->getWindow()->getDefaultView().getSize ().x/2,
	 memJeu->getWindow()->getDefaultView().getCenter().y - memJeu->getWindow()->getDefaultView().getSize ().y/2);
  if( spriteBackGround.getPosition().x <= angleHG.x - spriteBackGround.getTextureRect().width )
	 spriteBackGround.setPosition (angleHG);//placer angle haut gauche
  
  memJeu->getWindow()->draw( spriteBackGround );
  spriteBackGround.move( spriteBackGround.getTextureRect().width,0 );
  memJeu->getWindow()->draw( spriteBackGround );
  spriteBackGround.move( -1 * spriteBackGround.getTextureRect().width + deplacBGX,0 );
}



Niveau::~Niveau(){
}