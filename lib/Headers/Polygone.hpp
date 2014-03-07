#ifndef POL
#define POL

#include "Figure.hpp"

namespace lc{

  class Polygone: public Figure{
	 private:
		std::vector<Point> tabSommet;
	 public:
		Polygone();
		Polygone(std::vector<Point> tab);
		void attribuerTab(std::vector<Point> tab);
		std::vector<Point> getTab()const;
		void afficher()const;
		virtual void move(float x, float y);
		virtual void pivoter(float angleV);
		virtual ~Polygone();
  };

}

#endif