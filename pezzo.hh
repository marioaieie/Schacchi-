#ifndef PEZZO_HH
#define PEZZO_HH

#include <cmath>
#include <iostream>

class scacchiera; 

class pezzo {

	private:
		bool _colore, _mosso;
		int _X,_Y, _tipo;

		// Stampa il nome del pezzo, sommando 32 al char nel caso di un pezzo nero per ottenere la lettera minuscola
		virtual void print(ostream& os) const = 0;

	public:
		pezzo( int X, int Y, bool colore, int tipo )  : _tipo(tipo), _colore(colore), _X(X), _Y(Y), _mosso(false) { }
		~pezzo() { }
		bool colore() const { return _colore; }
		int X() const { return _X; }
		int Y() const { return _Y; }

		// La variabile mosso è utilizzata per l'arrocco
		bool mosso() const { return _mosso; }

		// Restituisce la validità della "forma" del movimento
		virtual bool regole( const int, const int ) const { }

		// Controlla se il movimento è possibile
		virtual bool check_mossa( const int, const int, scacchiera& );
		
		// Invoca check_mossa e verifica se a causa del movimento il re del pezzo mosso resta sotto scacco
		bool check_sposta( const int, const int, scacchiera& );
		
		// Aggiorna le coordinate interne del pezzo dopo aver invocato check_sposta
		bool sposta ( const int, const int, scacchiera& );
		
		friend ostream& operator<<( ostream& os, const pezzo& figura ) { figura.print(os); return os; }
};
#endif
