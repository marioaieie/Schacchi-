#include <cmath>
using namespace std;
#include "pezzo.hh"
#include "scacchiera.hh"

bool pezzo::check_mossa(const int x, const int y, scacchiera& board)
{
	if ( x>7 || y>7 || x<0 || y<0 ) {
		return false;						//caselle fuori dalla scacchiera
	} else {
		if ( X() == x && Y() == y) {	
			return false;					//casella arrivo e partenza uguali
		} else {

			if ( !regole(x,y) ) {	
					return false; 			//controllo se la mossa è possibile
			} else {
				int n = 0;				
				if (x-X() ==0){n=abs(y-Y());}
				else{n=abs(x-X());}
		

				int dx = (x-X())/n;			//calcolo la direzione dello spostamento
				int dy = (y-Y())/n;

				for (int i=1; i<n; i++){				//controllo che le caselle intermedie siano libere
					if (&board.trova(X()+i*dx,Y()+i*dy)){
						return false;
					};
				};
				if (&board.trova(x,y)) {				//controllo che la casella di destinazione non abbia un pezzo del mio stesso colore
					if ((board.trova(x,y)).colore() != colore() ) {
						return true;
					} else {
						return false;
					}
				} else {
					return true;
				};
			};
		};
	};	
}


bool pezzo::check_sposta(const int x, const int y, scacchiera& board)
{
	if (check_mossa(x,y,board)){
		int t1 = _X;
		int t2 = _Y;
		_X=x;	// Sposto le coordinate interne del pezzo
		_Y=y;
		bool result = board.scacco( t1, t2, x, y, !_colore );	// Controllo se il re del pezzo è sotto scacco
		_X = t1; // Riposiziono il pezzo al suo posto
		_Y = t2;
		return !result;
	} else {
		return false;
	};
}


bool pezzo::sposta(const int x, const int y, scacchiera& board)
{
	if (check_sposta(x,y,board)){
		if ( (y==7 || y==0) && _tipo == 0){ // Promozione del pedone
			board.promozione(_X, _Y,x,y,*this);			
		}
		_X=x;	// Sposto il pezzo
		_Y=y;
		_mosso=true;
		return true;
	} else {
		return false;
	};
}
