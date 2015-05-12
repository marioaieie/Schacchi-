#ifndef REGINA_HH
#define REGINA_HH

#include "pezzo.hh"

class regina : public pezzo {
	public:
		regina(int X, int Y, bool colore) : pezzo(X,Y,colore,4) {}
		~regina() {}
	private:
		void print(ostream& os) const { os << static_cast<char>( 'Q'+32*colore() );}
		bool regole(const int, const int) const;
};
#endif
