#ifndef NIV
#define NIV

//#include "../Header/Jeu.hpp"

class Niveau{
  private:
	 sf::Texture textureNiveau, textEnnemie;
	 sf::Sprite spriteBackGround;
	 short num, deplacBGX, deplacBGY, freqMoveBG, cmpt;
  public:
	 Niveau(short numero);
	 const sf::Texture &getTextEnnemi()const;
	 void chargerNiveau();
	 void actionBG(/*short frame*/);
	 ~Niveau();
};

#endif
