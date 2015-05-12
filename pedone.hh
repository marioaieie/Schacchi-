#ifndef PEDONE_HH
#define PEDONE_HH

#include "pezzo.hh"

class scacchiera;

class pedone : public pezzo {
	public:
		pedone( int X, int Y, bool colore ) : pezzo( X, Y, colore, 0 ) { }
		~pedone() {}
	private:
		void print(ostream& os) const { os << static_cast<char>( 'P' + 32*colore() ); }
		bool check_mossa( const int, const int, scacchiera& );
};
#endif
