#ifndef TORRE_HH
#define TORRE_HH

#include "pezzo.hh"

class torre : public pezzo {
	public:
		torre(int X, int Y, bool colore) : pezzo(X,Y,colore,1) {}
		~torre() {}
	private:
		void print(ostream& os) const { os << static_cast<char>( 'T'+32*colore() );}
		bool regole(const int, const int) const;
};
#endif
