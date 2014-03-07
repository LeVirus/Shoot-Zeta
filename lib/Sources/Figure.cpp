#include "Figure.hpp"
#include "Polygone.hpp"
#include "Cercle.hpp"

namespace lc{

  Figure::Figure(){
	 angle=0;
	 p_centre.positionner(0, 0); 
	 p_origine.positionner(0, 0);
	 p_anglobHG.positionner(0, 0);
	 p_anglobTaille.positionner(0, 0);
  }

  void Figure::move(float x, float y){//virtual
	 p_centre.move(x, y); 
	 p_origine.move(x, y);
	 p_anglobHG.move(x, y);
  }

  void Figure::positionner(float x, float y){
	 move( x-p_origine.getX(), y-p_origine.getY() );
  }

  Point Figure::getPosition()const{
	 return p_origine;
  }

  void Figure::pivoter(float angleV){//virtual
	 short tmp=angleV/360;
	 angle+= angleV-tmp*360 ;
	 if(angle<0)angle=static_cast<float>(360)+angle;//transcrire angle en positif
	 Point::pivoter(p_origine, p_centre, angleV);
  }//sens horaire et autour de p_origine


  void Figure::setRotation(float angleV){
	 pivoter(angleV-angle);
  }

  float Figure::getAngle()const{
	 return angle;
  }

  void Figure::setOrigin(float x, float y){
	 p_origine.positionner(x, y); 
  }



  Point Figure::getCentre()const{
	 return p_centre;
  }


  Figure::~Figure(){
	 
  }

  bool Figure::checkCollision(const Point &a,const Polygone &b){
	 short cmpt=0;
	 Point A , B, C(0, 10000);
	 for(unsigned short i=0;i<b.getTab().size();i++){
		A = b.getTab()[i];
		if (i==b.getTab().size()-1)  // si c'est le dernier point, on relie au premier
			 B = b.getTab()[0];
		else           // sinon on relie au suivant.
			 B = b.getTab()[i+1];
		if( Figure::collisionSegments(a, C,A,B) )cmpt++;
	 }
	 if(cmpt%2==1)return true;
	 return false;
  }

  bool Figure::checkCollision(const Point &a,const Cercle &b){
	 return Point::distance(a, b.p_centre) <= b.getRayon();//Point::distance(b.p_origine, b.p_centre);
  }

  bool Figure::checkCollision(const Polygone &a,const Polygone &b){
	 if( !Figure::checkAnglobCollision(a,b) )return false;//verif collision boite englobante
	 Point tmpA, tmpB, tmpC, tmpD;
		for(unsigned short i=0;i<a.getTab().size();i++){
		  tmpA=a.getTab()[i];
		  if(i==a.getTab().size()-1)tmpB=a.getTab()[0];
		  else tmpB=a.getTab()[i+1];
		  for(unsigned short j=0;j<b.getTab().size();j++){
			 tmpC=b.getTab()[j];
			 if(j==b.getTab().size()-1)tmpB=b.getTab()[0];
			 else tmpD=b.getTab()[j+1];
			 if(Figure::collisionSegments(tmpA, tmpB, tmpC, tmpD))return true;
		  }
		}
		if( Figure::checkCollision(a.getTab()[0], b)  ||  Figure::checkCollision(b.getTab()[0], a)  )
		  return true;//verif si les 2 polygone ne sont pas inclus l'un dans l'autre
		return false;
	 
  }

  bool checkCollision(const Cercle &a,const Cercle &b){
	 return Point::distance(a.getCentre(), b.getCentre()) <= a.getRayon()+b.getRayon();
  }

  bool Figure::checkCollision(const Cercle &a,const Polygone &b){
	 if( !Figure::checkAnglobCollision(a,b) )return false;//verif collision boite englobante
	 short tmpA;
	 if( Figure::checkCollision(a.p_centre, b) )return true;//a optimiser
	 for(unsigned short i=0;i<b.getTab().size();i++){
		if(i==b.getTab().size()-1)tmpA=0;
		else tmpA=i+1;
		if( collisionSegmentsCercle( b.getTab()[i], b.getTab()[tmpA], a ) )
		  return true;
	 }
	 return false;
  }

  bool Figure::checkCollision(const Polygone &a,const Cercle &b){
	 return Figure::checkCollision(b,a);
  }

  bool Figure::CollisionDroiteCercle(const Point &a, const Point &b, const Cercle &c){
	 Point u, AC;
	 u.positionner( b.getX() - a.getX(), b.getY() - a.getY() );
	 AC.positionner( c.p_centre.getX() - a.getX(), c.p_centre.getY() - a.getY() );
	 float numerateur = u.getX()*AC.getY() - u.getY()*AC.getX();   // norme du vecteur v
	 if (numerateur <0)
		  numerateur = -numerateur ;   // valeur absolue ; si c'est négatif, on prend l'opposé.
	 float denominateur = sqrt(u.getX()*u.getX() + u.getY()*u.getY());  // norme de u
	 float CI = numerateur / denominateur;
	 if ( CI <  c.getRayon() )
		  return true;
	 else
		  return false;
  }
  
  bool Figure::collisionSegmentsCercle( const Point &a, const Point &b, const Cercle &c){
	 if ( !Figure::CollisionDroiteCercle(a,b,c) )return false;  // si on ne touche pas la droite, on ne touchera jamais le segment
	 Point AB,AC,BC;
	 AB.positionner( b.getX() - a.getX(), b.getY() - a.getY() );
	 AC.positionner( c.p_centre.getX() - a.getX(), c.p_centre.getY() - a.getY() );
	 BC.positionner( c.p_centre.getX() - b.getX(), c.p_centre.getY() - b.getY() );
	 float pscal1 = AB.getX()*AC.getX() + AB.getY()*AC.getY();  // produit scalaire
	 float pscal2 = (-AB.getX())*BC.getX() + (-AB.getY())*BC.getY();  // produit scalaire
	 if (pscal1>=0 && pscal2>=0)
		return true;   // I entre A et B, ok.
	 // dernière possibilité, A ou B dans le cercle
	 if ( Figure::checkCollision(a,c) )
		return true;
	 if ( Figure::checkCollision(b,c) )
		return true;
	 return false;
  }

  bool Figure::collisionSegments(const Point &a, const Point &b, const Point &c, const Point &d){
	 Point AB( b.getX()-a.getX() , b.getY()-a.getY() ),
	 CD( d.getX()-c.getX() , d.getY()-c.getY() );
	 float denom = AB.getX()*CD.getY() - AB.getY()*CD.getX(), t, u;
	 if (denom==0)
		  return false;   // erreur, cas limite
	 t = - (a.getX()*CD.getY()-c.getX()*CD.getY()-CD.getX()*a.getY()+CD.getX()*c.getY()) / denom;
	 if (t<0 || t>=1)
		  return false;
	 u = - (-AB.getX()*a.getY()+AB.getX()*c.getY()+AB.getY()*a.getX()-AB.getY()*c.getX()) / denom;
	 if (u<0 || u>=1)
		  return false;
	 return true;
  }

  Point Figure::getOrigin()const{
	 return p_origine;
  }

  bool Figure::checkAnglobCollision(const Figure &a,const Figure &b){
	 float tmpAX=a.p_anglobHG.getX(), tmpAW=tmpAX+a.p_anglobTaille.getX(),
	 tmpBX=b.p_anglobHG.getX(), tmpBW=tmpBX+b.p_anglobTaille.getX();
	 if( tmpAX > tmpBW  ||  tmpBX > tmpAW )return false;
	 
	 tmpAX=a.p_anglobHG.getY(), tmpAW=tmpAX+a.p_anglobTaille.getY(),
	 tmpBX=b.p_anglobHG.getY(), tmpBW=tmpBX+b.p_anglobTaille.getY();
	 if( tmpAX > tmpBW  ||  tmpBX > tmpAW )return false;
	 return true;
  }
  
}