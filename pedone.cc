using namespace std;
#include "pedone.hh"
#include "scacchiera.hh"

bool pedone::check_mossa(const int x, const int y, scacchiera& board )
{
	if ( x>7 || y>7 || x<0 || y<0 ) {
		return false;						//caselle fuori dalla scacchiera
	} else {
		if ( X() == x && Y() == y) {	
			return false;					//casella arrivo e partenza uguali
		} else {
			int deltax = x-X();
			int deltay = y-Y();
			int dir = pow(-1,colore());	
			if( (deltax == 0  && !(&board.trova(x,y))) ){	// Controllo che il movimento sia in verticale e la casella di destinazione sia libera
				if ( deltay == 1*dir ) {
					return true;	// Movimento ordinario di 1 casella
				} else {
					if ( !(mosso()) && deltay == 2*dir && !(&board.trova(x,y-(1)*dir)) ){		
						return true;	// Movimento di 2 caselle		
					} else {
						return false;
					};
				};
			} else {
				if (&board.trova(x,y)){
					if ( abs(deltax)==1 && deltay == 1*dir && (&board.trova(x,y))->colore() != colore() ){
						return true;	// Il pedone mangia in diagonale
					} else {
						return false;
					};
				} else {
					return false;
				};
			};

		};
	};	
}
