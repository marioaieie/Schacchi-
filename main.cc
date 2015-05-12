#include <iostream>
using namespace std;

#include "scacchiera.hh"
#include "giocatore.hh"

int main()
{
	//	Inizializzazioni
	char c=0;
	scacchiera tavola;
	giocatore golia(true);
	giocatore franco(false);
	
	cout << "  __   __   __\n";
	cout << " |  |_|  |_|  |\n";
	cout << "  \\          /\n";
	cout << "   |        |\n";
	cout << "   |        |\n";
	cout << "   |        |\tScacchi++ v1.0\n";
	cout << "   |        |\n";
	cout << "   |        |\n";
	cout << "   |        |\n";
	cout << "  /__________\\" << endl;

	// Partita
	do{
		if ( franco.gioca(tavola) ) { break; };
		if ( golia.gioca(tavola) ) { break; };		
		cout << "\n\nInserisci x per uscire o un altro carattere per continuare: ";
		cin >> c;
	}while (c!='x') ;
	cout << "\n\nCreated by Nicola Baccichet e Mario Bonamigo." << endl;
}
