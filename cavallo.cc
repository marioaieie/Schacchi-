#include <cmath>
using namespace std;
#include "cavallo.hh"
#include "scacchiera.hh"

bool cavallo::check_mossa( const int x, const int y, scacchiera& board )
{
	if ( x>7 || y>7 || x<0 || y<0 ) {
		return false;					// Casella fuori dalla scacchiera
	} else {
		if ( X() == x && Y() == y) {	
			return false;				// Casella arrivo e partenza uguali
		} else {
			int deltax = abs( x - X() );
			int deltay = abs( y - Y() );
			// Controllo se la mossa è possibile
			if ( !( ( deltax == 2 && deltay == 1 ) || ( deltax == 1 && deltay == 2 ) ) ) {
				return false;
			} else {
				// Controllo che la casella di destinazione non abbia un pezzo del mio stesso colore
				if (&board.trova(x,y)) {
					if ((board.trova(x,y)).colore() != colore() ) {
						return true;
					} else {
						return false;
					};
				} else {
					return true;
				};
			};
		};
	};	
}
