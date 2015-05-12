#ifndef SCACCHIERA_HH
#define SCACCHIERA_HH

#include "pedone.hh"
#include "alfiere.hh"
#include "cavallo.hh"
#include "torre.hh"
#include "re.hh"
#include "regina.hh"


class scacchiera {
	private:
		pezzo *griglia[8][8], *kn, *kb;
	public:
		scacchiera();
		~scacchiera();
		void stampa()const;
		
		// Controlla la validità della casella di partenza
		bool check_P(const int, const int, const bool) const;
		
		// Sposta il pezzo dopo aver controllato che la casella di arrivo sia valida e la mossa possibile
		bool muovi(const int, const int, const int, const int);
		
		// Restituisce il pezzo nelle coordinate x,y
		const pezzo& trova(const int x, const int y) const { return *griglia[x][y]; }
		
		// Converte false in Bianco e true in nero
		string bn(const bool) const;
		
		// Promozione del pedone arrivato alla fine della scacchiera
		void promozione (const int,const int,const int, const int, pezzo&);
		
		// Sposta un pezzo e verifica se il colore passato fa scacco, a patto di aver già spostato le coordinate interne del pezzo
		bool scacco(const int,const int,const int,const int, const bool);

		// Verifica se il colore dà scacco
		bool scacco(const bool);
		
		// Verifica se il colore può muovere
		bool matto(const bool);
};
#endif
