#include "Cercle.hpp"


namespace lc{
  Cercle::Cercle(){
	 rayon=0.0f;
  }

  Cercle::Cercle(float x, float y, float rayonA){
	 rayon=rayonA;
	 p_centre.positionner(x+rayon, y+rayon); 
	 p_origine.positionner(x, y);
	 p_anglobHG=p_origine;
	 p_anglobTaille.positionner(rayon*2, rayon*2);
	 //p_anglHG.positionner(x-rayon, y-rayon);
  }

  Cercle::Cercle(Point a, float rayonA){
	 rayon=rayonA;
	 p_origine=a; 
	 p_centre.positionner(a.getX()+rayon, a.getY()+rayon);
	 p_anglobHG=p_origine;
	 p_anglobTaille.positionner(rayon*2, rayon*2);
	 //p_anglHG.positionner(a.m_x-rayon, a.m_y-rayon);
  }

  void Cercle::modifRayon(float taille){
	 rayon=taille;
	 p_anglobHG=p_origine;
	 p_anglobTaille.positionner(rayon*2, rayon*2);
	 //p_anglHG.positionner(a.m_x-rayon, a.m_y-rayon);
  }

  void Cercle::move(float x, float y){
	 Figure::move(x,y);
  }

  void Cercle::pivoter(float angleV){
	 Figure::pivoter(angleV);
	 p_anglobHG.positionner( p_centre.getX() - p_anglobTaille.getX()/2, 
									 p_centre.getY() - p_anglobTaille.getY()/2);
  }


  float Cercle::getRayon()const{
	 return rayon;
  }

  Cercle::~Cercle(){}

}