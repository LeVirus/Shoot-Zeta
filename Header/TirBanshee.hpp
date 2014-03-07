#ifndef TIRB
#define TIRB


class Vaisseau;


class TirBanshee: public Tir{
  private:
  public:
	 //cible tir joueur !cible tir ennemis
	 TirBanshee( Vaisseau *Vaiss, short angle);
	 virtual void initialiser();
	 virtual short getType();
	 //virtual bool checkCollisions(Entite *b);
	 virtual void gestionBot();
	 virtual void explode();
	 virtual ~TirBanshee();
};

#endif   
