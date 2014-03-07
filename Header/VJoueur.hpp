#ifndef VJ
#define VJ

class VJoueur: public Vaisseau{
  private:

  public:
	 VJoueur(short position, short inclinaison);
	 void deplacerJoueur(short choix);
	 virtual short getType();
	 //void tirer();
	 virtual void explode();
	 virtual void initialiser();
	 //virtual bool checkCollisions(Entite *b);
	 virtual void gestionBot();
	 //virtual void personnaliser();
	 virtual ~VJoueur();
};

#endif 