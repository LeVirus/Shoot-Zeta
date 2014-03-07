#ifndef TIRJ
#define TIRJ


class Vaisseau;


class TirJoueur: public Tir{
  private:

  public:
	 //cible tir joueur !cible tir ennemis
	 TirJoueur( Vaisseau *Vaiss, short angle);
	 virtual void initialiser();
	 virtual short getType();
	 //virtual bool checkCollisions(Entite *b);
	 virtual void gestionBot();
	 virtual void explode();
	 virtual ~TirJoueur();
};

#endif   
