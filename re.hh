#ifndef RE_HH
#define RE_HH

#include "pezzo.hh"

class scacchiera;

class re : public pezzo {
	public:
		re(int X, int Y, bool colore) : pezzo(X,Y,colore,5) {}
		~re() {}
	private:
		void print(ostream& os) const { os << static_cast<char>( 'K'+32*colore() );}
		bool check_mossa(const int, const int, scacchiera&);
};
#endif
