#ifndef TIR
#define TIR


class Vaisseau;


class Tir: public Entite{
  private:
	 //bool allieouennemi;
	 Vaisseau *memoV;
	 //short X, Y;
  public:
	 //cible tir joueur !cible tir ennemis
	 Tir();
	 void initTir(Vaisseau *Vaiss, short inclinaison);
	 virtual void initialiser()=0;
	 virtual void gestionBot()=0;
	 virtual void explode()=0;
	 virtual ~Tir();
};

#endif  
