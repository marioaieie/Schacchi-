#include <cmath>
using namespace std;
#include "re.hh"
#include "scacchiera.hh"

bool re::check_mossa(const int x, const int y, scacchiera& board)
{
	if ( x>7 || y>7 || x<0 || y<0 ) {
		return false;						//caselle fuori dalla scacchiera
	} else {
		if ( X() == x && Y() == y) {	
			return false;					//casella arrivo e partenza uguali
		} else {
			int dx = (x-X());
			int dy = (y-Y());
			if ( abs(dx) <2 && abs(dy)<2 ) {
				if (&board.trova(x,y)) {				//controllo che la casella di destinazione non abbia un pezzo del mio stesso colore
					if ((board.trova(x,y)).colore() != colore() ) {
						return true;
					} else {
						return false;
					}
				} else {
					return true;
				};
			} else {
				// Controlli per l'arrocco
				
				if (dy == 0 && !mosso()){	// Il re non si è mosso
					int t=0;					
					switch(dx){	// Pozione relativa della torre
						case 2:
							t=3;
							break;
						case -2:
							t=-4;
							break;
						default:
							return false;
					};

					// La torre è al suo posto (evito di invocare il metodo di un puntatore vuoto)
					if ( &board.trova( X()+t,Y() ) ){
					
						// La torre non si è mossa e le caselle sono vuote
						if ( !(board.trova( X()+t,Y() )).mosso() && !(&board.trova( dx/2+X(), Y() )) && !(&board.trova( dx+X(), Y() )) ){

							// Il re non è sotto scacco e lo sposto nella casella adiacente (che quindi non è sotto scacco)
							if ( !board.scacco(!colore()) && board.muovi( X(), Y(), X()+dx/2, Y() ) ) {

								// Sposto il re nella casella finale per vedere se è sotto scacco
								if ( board.muovi( X(), Y(), X()+dx/2, Y() ) ) {
									board.muovi( X(), Y(), X()-dx/2, Y() );	// Riporto il re alla posizione iniziale
									board.muovi( X(), Y(), X()-dx/2, Y() );
									board.muovi( X()+t, Y(), X()+dx/2, Y() ); // Sposto la torre
									return true;
								};
							};
						};
					};											
				};
				return false;
			};
		};
	};	
}
