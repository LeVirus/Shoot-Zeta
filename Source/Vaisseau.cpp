#include "Jeu.hpp"

using namespace std;

extern Jeu *memJeu;

Vaisseau::Vaisseau(){
  
}

void Vaisseau::initVaisseau( short inclinaison ){
  masqueCol=new lc::Polygone;
  Entite::initialiserEntite(inclinaison);

  masqueCol->setRotation( getAngleCentre() );//modifier rotation masque
  active=false;
  frameActuelle=0;
  frameExplode=0;
}

void Vaisseau::tirer(short choix){
  switch(choix){
	 case TJOUEUR:
		if( choixTypeTir & NORD)
			 memJeu->pushEntite( new TirJoueur( this, -90+angle )  );
		if( choixTypeTir & SUD)
			 memJeu->pushEntite( new TirJoueur( this, 90+angle )  );
		if( choixTypeTir & EST)
			 memJeu->pushEntite( new TirJoueur( this, 0+angle  ) );
		if( choixTypeTir & OUEST)
			 memJeu->pushEntite( new TirJoueur( this, 180+angle ) );
		if( choixTypeTir & NORD_OUEST)
			 memJeu->pushEntite( new TirJoueur( this, 225+angle  ) );
		if( choixTypeTir & SUD_OUEST)
			 memJeu->pushEntite( new TirJoueur( this, 135+angle  ) );
		if( choixTypeTir & SUD_EST)
			 memJeu->pushEntite( new TirJoueur( this, 45+angle  ) );
		if( choixTypeTir & NORD_EST)
		  memJeu->pushEntite( new TirJoueur( this, -45+angle  ) );
		break;
	 case TBANCHEE:
		if( choixTypeTir & NORD)
			 memJeu->pushEntite( new TirBanshee( this, -90+angle  ) );
		if( choixTypeTir & SUD)
			 memJeu->pushEntite( new TirBanshee( this, 90+angle  ) );
		if( choixTypeTir & EST)
			 memJeu->pushEntite( new TirBanshee( this, 0+angle  ) );
		if( choixTypeTir & OUEST)
			 memJeu->pushEntite( new TirBanshee( this, 180+angle  ) );
		if( choixTypeTir & NORD_OUEST)
			 memJeu->pushEntite( new TirBanshee( this, 225+angle  ) );
		if( choixTypeTir & SUD_OUEST)
			 memJeu->pushEntite( new TirBanshee( this, 135+angle  ) );
		if( choixTypeTir & SUD_EST)
			 memJeu->pushEntite( new TirBanshee( this, 45+angle  ) );
		if( choixTypeTir & NORD_EST)
		  memJeu->pushEntite( new TirBanshee( this, -45+angle  ) );
		break;
	 default:
		cout<<"error tir (vaisseau)"<<endl;
		return;
		break;
  }
}

Vaisseau::~Vaisseau(){}
