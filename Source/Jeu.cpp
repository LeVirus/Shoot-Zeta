#include "Jeu.hpp"

using namespace std;

extern Jeu *memJeu;

Jeu::Jeu(){
  memJeu=this;
  largeurFenetre=500; 
  longueurFenetre=400;
  if(  !texture.loadFromFile( "Images/textureA.png" )  )std::cout<<"fail load im"<<std::endl;
  frame=0;
  window.create(sf::VideoMode(largeurFenetre, longueurFenetre), "shoot", sf::Style::Default);
  joueur=new VJoueur( EST, 0);//liaison des donnees dans la structure destinees aux classe inferieure
  joueur->positionnerSprite(70, 150);
  //mem.windowMasque=new sf::Rect<float>( 0, 0, largeurFenetre, longueurFenetre );
}

/*void Jeu::deplacerCamera(){
  camera.move(1,0);
  joueur->deplacer(EST, 1);
  if( chaineEntites.empty() )return;
  for(itEntite=chaineEntites.begin();itEntite!=chaineEntites.end();itEntite++){
	 if( (*itEntite)->estActif() )(*itEntite)->getSprite().move(1,0);
  }
}*/
  
const Niveau& Jeu::getNiveau()const{
  return *actuel;
}

sf::RenderWindow* Jeu::getWindow(){
  return &window;
}

void Jeu::lancerJeu(){
	frame=0;
	compteurFrameLvl=0;
	short stock;
	camera=window.getDefaultView();
	window.setFramerateLimit(60);	
	
	//sf::Event event;
	actuel=new Niveau(0);
	actuel->chargerNiveau();
	window.setView(camera);
	window.display();
	while ( window.isOpen() ){
	  //sf::Clock temps;
	  stock=0;
		//window.pollEvent(event);
		if (/* event.type == sf::Event::Closed  ||*/  sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ){
		  window.close();
		  break;
		}
		window.clear(sf::Color::Black);
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up ) )stock+=HAUT;
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down ) )stock+=BAS;
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left ) )stock+=GAUCHE;
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right ) )stock+=DROITE;
		joueur->deplacerJoueur(stock);
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::X ) ){
		  if(frame==0)joueur->tirer(TJOUEUR);//pour tirer une frame sur 3
		}
		actuel->actionBG();//bouger background
		actionEntites();
		window.draw( joueur->getSprite() );
		window.display();
		if(frame==3){
		  frame=-1;
		  compteurFrameLvl++;
		}
		frame++;
	  //std::cout << 1000.0 / temps.getElapsedTime().asMilliseconds() << std::endl;
	}
}

void Jeu::actionEntites(){
  //bool done=false;
  
  if( chaineEntites.empty() )return;
  //sf::Sprite tmp=joueur->getSprite();
  itEntite=chaineEntites.begin();
  do{//std::cout<<"erreur ddd"<<std::endl;
	 if( itEntite==chaineEntites.end() )return;
	 //if( (*itEntite)->dansEcran()  /*&&  !(*itEntite)->estActif()*/ )(*itEntite)->activer();
	 if( !(*itEntite)->verifActiver(compteurFrameLvl) ){//si entité non activé
		itEntite++;
		continue;
	 }
	 /*if( (*itEntite)->getType()!=NONE )*/(*itEntite)->gestionBot();
	 if( !(*itEntite)->dansEcran() ){
		delete (*itEntite);
		itEntite=chaineEntites.erase(itEntite);//erase renvoie la position suivante de la liste
		continue;
	 }
	// if( frame==0  ||  frame==2 ){//verif collision une frame sur 3
		if( (*itEntite)->getType()==VAISSEAU_E ||  (*itEntite)->getType()==TIR_E){
		  if( (*itEntite)-> explosion() || (*itEntite)->checkCollisions(joueur) ){
			 //verif collision entre joueur et tir ou vaisseau ennemis 
				(*itEntite)->explode();
		  }
		}
		else if((*itEntite)->getType()==TIR_J){
		  for(itAux=chaineEntites.begin();itAux!=chaineEntites.end();itAux++){//parcour liste
			 if(  (*itAux)->getType()==VAISSEAU_E  &&  !(*itAux)->explosion()  ){
				  if(  (*itEntite)->checkCollisions( (*itAux) )  ){
					 //verif collision entre tir joueur et vaisseau ennemi 
					 (*itAux)->recevoirDegats(*itEntite);//itAux::vaisseau ennemis
					 //window.draw( (*itAux)->getSprite() );
					 //maj du sprite de lexplosion sur le vaisseau ennemi
					 (*itEntite)->explode();//itAux::tir joueur
					 break;
				  }
			 }
		  }
		}
	 //}
	 //if((*itEntite)->getType()==VAISSEAU_E)
	 window.draw( (*itEntite)->getSprite() );
	 //if(  )
	 itEntite++;
  }while(true);
  
  /*if(frame==2  ||  frame==5){
		  deplacerCamera();
		  window.setView(camera);
  }*/
}

const sf::Texture &Jeu::getTexture(){
  return texture;
}


void Jeu::pushEntite(Entite *a){
  chaineEntites.push_front(a);
}

void Jeu::viderListe(){
  if( chaineEntites.empty() )return;
  for(itEntite=chaineEntites.begin();itEntite!=chaineEntites.end();itEntite++){
	 delete (*itEntite);
  }
  chaineEntites.clear();
}



Jeu::~Jeu(){
  delete joueur;
  if(! chaineEntites.empty() )viderListe();
  //delete actuel; a ajouter
}