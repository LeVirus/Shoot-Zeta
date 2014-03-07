#ifndef AST
#define AST

class Asteroide: public Bloc{
  private:
	 //short X, Y;
  public:
	 //cible tir joueur !cible tir ennemis
	 Asteroide(short inclinaison);
	 virtual void initialiser();
	 virtual void gestionBot();
	 virtual ~Asteroide();
}

#endif