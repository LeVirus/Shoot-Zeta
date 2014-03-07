#ifndef FIG
#define FIG

#include "Point.hpp"


namespace lc{
class Cercle;
class Polygone;



  class Figure{
	 protected:
		Point p_centre, p_origine, p_anglobHG, p_anglobTaille;
		float angle;//horaire
	 public:
		Figure();
		virtual void move(float x, float y);
		virtual void pivoter(float angleV);
		void positionner(float x, float y);
		Point getPosition()const; //angleHG
		void setRotation(float angleV);
		float getAngle()const; 
		void setOrigin(float x, float y);//relatif a p_anglHG
		Point getOrigin()const;
		Point getCentre()const;
		static bool checkCollision(const Point &a,const Polygone &b);
		static bool checkCollision(const Point &a,const Cercle &b);
		
		static bool checkCollision(const Cercle &a,const Cercle &b);
		static bool checkCollision(const Polygone &a,const Polygone &b);
		static bool checkCollision(const Polygone &a,const Cercle &b);
		static bool checkCollision(const Cercle &a,const Polygone &b);
		
		static bool checkAnglobCollision(const Figure &a,const Figure &b);
		static bool CollisionDroiteCercle(const Point &a, const Point &b, const Cercle &c);
		static bool collisionSegmentsCercle(const Point &a, const Point &b, const Cercle &c);
		static bool checkCollisionPolyCercle(const Polygone &a, const Cercle &b);//a=cercle b=polynome
		static bool collisionSegments(const Point &a, const Point &b, const Point &c, const Point &d);
		virtual ~Figure();
  };

}

#endif