#include "Polygone.hpp" 

using namespace std;

namespace lc{

  Polygone::Polygone(){

  }

  Polygone::Polygone(std::vector<Point> tab){//
	 angle=0;
	 attribuerTab(tab);
  }

  void Polygone::attribuerTab(std::vector<Point> tab){
	 if( !tabSommet.empty() )tabSommet.clear();
	 if( !tab.empty() ){
		tabSommet=tab;
		//fonction pour copier des elements d'un container a un autre
		float tmpX=tabSommet[0].getX(), tmpY=tabSommet[0].getY(), 
		tmpXX=tabSommet[0].getX(), tmpYY=tabSommet[0].getY();
		for(unsigned short i=0;i<tabSommet.size();i++){
		  if(i>0){
			 if( tabSommet[i].getX() < tmpX )tmpX=tabSommet[i].getX();//trouver le sommet le plus a droite
			 if( tabSommet[i].getY() < tmpY )tmpY=tabSommet[i].getY();//trouver le sommet le plus haut
			 if( tabSommet[i].getX() > tmpXX )tmpXX=tabSommet[i].getX();//trouver le sommet le plus a gauche
			 if( tabSommet[i].getY() > tmpYY )tmpYY=tabSommet[i].getY();//trouver le sommet le plus bas
		  }
		}
		p_anglobHG.positionner(tmpX,tmpY);
		p_anglobTaille.positionner(tmpXX-tmpX, tmpYY-tmpY);
		p_origine=p_anglobHG;
		p_centre.positionner(p_anglobHG.getX()+p_anglobTaille.getX()/2, 
									 p_anglobHG.getY()+p_anglobTaille.getY()/2);  
	 }
  }
  
  void Polygone::afficher()const{
	 for(unsigned short i=0;i<tabSommet.size();i++){
		tabSommet[i].afficher();
	 }
  }

  void Polygone::move(float x, float y){
	 Figure::move(x,y);
	 for(unsigned short i=0;i<tabSommet.size();i++){
		tabSommet[i].move(x, y);
	 }
  }

  void Polygone::pivoter(float angleV){
	 if(tabSommet.size()<3)return;
	 Figure::pivoter(angleV);
	 float tmpX=tabSommet[0].getX(), tmpY=tabSommet[0].getY(), 
	 tmpXX=tabSommet[0].getX(), tmpYY=tabSommet[0].getY();
	 for(unsigned short i=0;i<tabSommet.size();i++){
		Point::pivoter(p_origine, tabSommet[i], angleV);
		if(i>0){
		  if( tabSommet[i].getX() < tmpX )tmpX=tabSommet[i].getX();//trouver le sommet le plus a droite
		  if( tabSommet[i].getY() < tmpY )tmpY=tabSommet[i].getY();//trouver le sommet le plus haut
		  if( tabSommet[i].getX() > tmpXX )tmpXX=tabSommet[i].getX();//trouver le sommet le plus a gauche
		  if( tabSommet[i].getY() > tmpYY )tmpYY=tabSommet[i].getY();//trouver le sommet le plus bas
		}
	 }
	 p_anglobHG.positionner(tmpX,tmpY);
	 p_anglobTaille.positionner(tmpXX-tmpX, tmpYY-tmpY);
  }

  std::vector<Point> Polygone::getTab()const{
	 return tabSommet;
  }

  Polygone::~Polygone(){
	 
  }
  
}