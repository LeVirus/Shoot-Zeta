#ifndef ENT
#define ENT

#include "../lib/Headers/Cercle.hpp"
#include "../lib/Headers/Polygone.hpp"
class Entite{
  protected:
	 bool active, explose;
	 sf::Sprite sprite;
	 double angle, angleEnRadianDefault, angleCentre;
	 float multiplicateurXDefault, multiplicateurYDefault, valeurDiagonale;
	 short velocite, diagonale, positionInitial, frameExplode;
	 short largeur, longueur, degatsCol, pointDeVie;
	 unsigned short colorDegat, frameInvuln;
	 lc::Polygone *masqueCol;
  public:
	 Entite();
	 void recevoirDegats(Entite *a);
	 void initialiserEntite(short inclinaison);
	 void positionnerSprite(short x, short y);
	 bool verifActiver(short frameAct);
	 bool explosion();
	 virtual void initialiser();
	 virtual void gestionBot()=0;
	 bool checkCollisions(Entite *b);
	 virtual short getType()=0;
	 virtual void explode()=0;
	 sf::Sprite getSprite();
	 bool dansEcran();
	 void deplacer(float pixels, float degre);
	 double getAngleCentre();
	 virtual ~Entite();
};

#endif  
