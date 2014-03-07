#ifndef POI
#define POI

#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

namespace lc{

  class Point{
	 private:
		float x, y;
	 public:
		Point();
		Point(float xx, float yy);
		void move(float xx, float yy);
		void positionner(float xx, float yy);
		Point operator=(Point a);
		bool operator==(Point a);
		bool operator!=(Point a);
		Point operator-(Point a);
		void afficher()const;
		static float distance(const Point a, const Point b);
		float getX()const;
		float getY()const;
		static void pivoter(Point &origine, Point &a, float newAngle);
		~Point();
  };

}

#endif