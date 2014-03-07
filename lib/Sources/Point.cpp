#include "Point.hpp"

using namespace std;

namespace lc{

  Point::Point(){
	 x=0;
	 y=0;
  }

  Point::Point(float xx, float yy){
	 x=xx;
	 y=yy;
  }

  void Point::move(float xx, float yy){
	 x+=xx;
	 y+=yy;
  }

  void Point::positionner(float xx, float yy){
	 x=xx;
	 y=yy;
  }

  Point Point::operator=(Point a){
	 x = a.x;
	 y = a.y;
	 return *this;
  }

  bool Point::operator==(Point a){
	 if(fabs(a.x - x) < std::numeric_limits<float>::epsilon()  &&  
  fabs(a.y - y) < std::numeric_limits<float>::epsilon())
	 return true; //si a == b (a et b flottant)
	 return false;
  }

  bool Point::operator!=(Point a){
	 bool tmp=*this==a;
	 return !tmp;
  }

  Point Point::operator-(Point a){
	 Point tmp(x-a.x,y-a.y);
	 return tmp;
  }

  /*void Point::afficher(){
	 std::cout<<x<<"  "<<y<<std::endl;
  }*/

  float Point::distance(Point a, Point b){
	 return sqrt( (a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y) );
  }

  void Point::pivoter(Point &origine, Point &a, float newAngle)
  {
	 if(origine==a  ||  fabs(newAngle) < std::numeric_limits<float>::epsilon() )return;
	 float x=a.x, y=a.y;
	 double angleEnRadian = static_cast<double> (newAngle) * M_PI / 180.0;
	 float cosinusAlpha = static_cast<float>(cos(angleEnRadian));
	 float sinusAlpha = static_cast<float>(sin(angleEnRadian));
	 a.x = cosinusAlpha * (x - origine.x) - sinusAlpha * (y - origine.y) + origine.x;
	 a.y = sinusAlpha * (x - origine.x) + cosinusAlpha * (y - origine.y) + origine.y;
  }
  
  void Point::afficher()const{
	 cout<<"x::"<<x<<"y::"<<y<<endl;
  }

  float Point::getX()const{
	 return x;
  }

  float Point::getY()const{
	 return y;
  }



  Point::~Point(){}
  
}