#ifndef VB
#define VB

class VBanshee: public Vaisseau{
  private:
  public:
	 VBanshee(short position, short inclinaison);
	 virtual short getType();
	 virtual void explode();
	 virtual void initialiser();
	 virtual void gestionBot();
	 virtual ~VBanshee();
};

#endif 