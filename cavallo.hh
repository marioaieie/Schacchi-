#ifndef CAVALLO_HH
#define CAVALLO_HH

#include "pezzo.hh"

class scacchiera;

class cavallo : public pezzo {
	public:
		cavallo( int X, int Y, bool colore ) : pezzo( X, Y, colore, 2 ) {}
		~cavallo() {}
	private:
		void print(ostream& os) const { os << static_cast<char>( 'C' + 32*colore() ); }
		bool check_mossa( const int, const int, scacchiera& );
};
#endif
