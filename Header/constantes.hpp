#ifndef CST
#define CST

enum {VAISSEAU_J, VAISSEAU_E ,TIR_J, TIR_E, NONE};
enum {VJOUEUR, VBANCHEE ,TJOUEUR, TBANCHEE};
#define HAUT    		1
#define BAS     		2
#define GAUCHE  		3
#define DROITE  		6
#define HAUT_GAUCHE  HAUT+GAUCHE
#define HAUT_DROITE  HAUT+DROITE
#define BAS_GAUCHE  	BAS+GAUCHE
#define BAS_DROITE  	BAS+DROITE


#define PI    			3.14159265358979323846


#define NORD    		1
#define NORD_OUEST   2
#define OUEST  		4
#define SUD_OUEST  	8
#define SUD  			16
#define SUD_EST  		32
#define EST  			64
#define NORD_EST  	128

#define TRIPLE_AVANT	NORD_EST | EST | SUD_EST
#define TOUT	NORD_EST | EST | SUD_EST | SUD | SUD_OUEST | NORD_OUEST | NORD | OUEST


#define LARGEUR_FENETRE     500
#define HAUTEUR_FENETRE     400

# endif