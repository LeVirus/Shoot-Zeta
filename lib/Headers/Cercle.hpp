#ifndef CER
#define CER

#include "Figure.hpp"


namespace lc{
  class Cercle: public Figure{
	 private:
		float rayon;
	 public:
		Cercle();
		Cercle(float x, float y, float rayonA);
		Cercle(Point a, float rayonA);
		virtual void move(float x, float y);
		virtual void pivoter(float angleV);
		void modifRayon(float taille);
		float getRayon()const;
		virtual ~Cercle();
  };
}

#endif
