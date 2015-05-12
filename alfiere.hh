#ifndef ALFIERE_HH
#define ALFIERE_HH

#include "pezzo.hh"

class alfiere : public pezzo {
	public:
		alfiere( int X, int Y, bool colore ) : pezzo( X, Y, colore, 3 ) {}
		~alfiere() {}
	private:
		void print(ostream& os) const { os << static_cast<char>( 'A' + 32*colore() ); }
		bool regole(const int, const int) const;
};
#endif
