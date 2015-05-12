#ifndef GIOCATORE_HH
#define GIOCATORE_HH
#include "scacchiera.hh"
class giocatore {
	private:
		bool _colore;
		int Xin,Yin,Xfin,Yfin;
		char x_char,y_char;

	public:
		giocatore(const bool colore) : _colore(colore) {} 
		~giocatore() {}
		bool gioca(scacchiera&);
};
#endif
