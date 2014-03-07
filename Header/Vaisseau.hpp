#ifndef VAI
#define VAI


class Vaisseau: public Entite{
  protected:
	 short choixTir, frameActuelle, frameMove, frameShoot, choixTypeTir;
  public:
	 Vaisseau();
	 void initVaisseau( short inclinaison);
	 void tirer(short choix);
	 virtual void explode()=0;
	 virtual void initialiser()=0;
	 //virtual bool checkCollisions(Entite *b);
	 virtual void gestionBot()=0;
	 //virtual void personnaliser()=0;
	 virtual ~Vaisseau();
};





#endif 
