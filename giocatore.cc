#include <iostream>
using namespace std;
#include "giocatore.hh"

bool giocatore::gioca( scacchiera& board )
{
	// Visualizzazione scacchiera
	cout << "\n\nGiocatore " << board.bn(_colore) << endl;
	cout << endl;
	board.stampa();

	// Selezione del pezzo da muovere
	do {
	
		// Controllo sulla validità della casella di partenza
		do {
			cout << "\nCasella di partenza (A..H 1..8): ";
			cin >> x_char >> y_char;
			Yin= y_char -49;
			Xin= x_char - 65;
		} while (!board.check_P(Xin,Yin,_colore));
		
		// Controllo sulla validità della casella di arrivo
		cout << "Casella di arrivo (A..H 1..8): ";
		cin >> x_char >> y_char;
		Yfin= y_char -49;
		Xfin= x_char - 65;
	} while (!board.muovi(Xin,Yin,Xfin,Yfin));
	
	// Controllo scacco e scacco matto
	if ( board.matto(_colore) ) {	// Controllo se il giocatore può muovere
		board.stampa();
		if (board.scacco(_colore)){	// Controllo se il giocatore è sotto scacco
			cout << "Scacco Matto!!! Il giocatore " << board.bn( _colore ) << " vince." << endl;
		} else {
			cout << "Stallo! La partita è patta." << endl;
		};
		return true;
	} else {
		if (board.scacco(_colore)){
			cout << "Scacco al Re!" << endl;
		};
	};
	return false;
}
