using namespace std;
#include "scacchiera.hh"

scacchiera::scacchiera()
{
	//inizializzo a zero i puntatori delle caselle
	for (int i=0; i<8; i++){
		for (int j=0; j<8; j++){
			griglia[i][j]=0;
		};
	};

	//posiziono le pedine sulla scacchiera
	for (int i=0; i<8; i++) { griglia[i][1] = new pedone(i,1,false); };
	griglia[0][0] = new torre(0,0,false);
	griglia[1][0] = new cavallo(1,0,false);
	griglia[2][0] = new alfiere(2,0,false);
	griglia[3][0] = new regina(3,0,false);
	griglia[4][0] = kb = new re(4,0,false);
	griglia[5][0] = new alfiere(5,0,false);
	griglia[6][0] = new cavallo(6,0,false);
	griglia[7][0] = new torre(7,0,false);

	for (int i=0; i<8; i++) { griglia[i][6] = new pedone(i,6,true); };
	griglia[0][7] = new torre(0,7,true);
	griglia[1][7] = new cavallo(1,7,true);
	griglia[2][7] = new alfiere(2,7,true);
	griglia[3][7] = new regina(3,7,true);
	griglia[4][7] = kn = new re(4,7,true);
	griglia[5][7] = new alfiere(5,7,true);
	griglia[6][7] = new cavallo(6,7,true);
	griglia[7][7] = new torre(7,7,true);
}


scacchiera::~scacchiera()
{
	for (int i=0; i<8; i++){
		for (int j=0; j<8; j++){
			delete griglia[i][j];
		};
	};
}


//controllo della casella di partenza
bool scacchiera::check_P(const int x, const int y, const bool colore) const
{
	if (x>7 || y>7 || x<0 || y<0){	
		cout << "Non stiamo giocando a tennis, la casella selezionata è fuori dalla scacchiera." << endl;
		return false;
	} else{
		if (!griglia[x][y]){	
			cout << "La casella selezionata è vuota." << endl;
			return false;
		} else {
			if (griglia[x][y]->colore()!=colore)
			{	
				cout <<"Il pezzo selezionato " << *griglia[x][y] << " " << bn(griglia[x][y]->colore()) << " appartiene all'altro giocatore."<< endl;
				return false;
			} else {
				return true;
			};
		};
	};
}


//stampa della scacchiera
void scacchiera::stampa() const
{
	for ( int i=7; i>-1; i-- ){
		cout << i+1 << "   ";
		for ( int j=0; j<8; j++ ){
			if ( griglia[j][i] )
			{
				cout << *griglia[j][i] << " ";
			}
			else
			{
				cout << "_ ";
			}
		};
		cout << endl;
	};
	cout << "\n" << "    A B C D E F G H\n" << endl;
}


//movimento pezzi
bool scacchiera::muovi(const int x1, const int y1, const int x2, const int y2)
{
	if (!griglia[x1][y1]->sposta(x2,y2,*this)){	// Muovo il pezzo se può farlo
		cout << "Mossa non valida." << endl;
		return false;
	}
	else{
		// Controllo se c'è un pezzo nella casella di arrivo (sono sicuro che non è del mio colore)
		if (griglia[x2][y2]){
			cout << "Il pezzo " << *griglia[x2][y2]<< " " << bn(griglia[x2][y2]->colore()) << " è stato mangiato." << endl;
			delete griglia[x2][y2];
		}
		griglia[x2][y2] = griglia[x1][y1];	// Aggiorno la matrice di puntatori
		griglia[x1][y1] = 0;
	return true;
	}
}


bool scacchiera::scacco(bool colore) {

	int xk,yk =0;
	
	// Prendo le coordinate del re giusto
	if (colore){
		xk = kb->X();
		yk = kb->Y();
	} else{
		xk = kn->X();
		yk = kn->Y();
	};
	
	// Cerco i pezzi del colore giusto
	for (int i=0; i<8; i++){
		for (int j=0; j<8; j++){
			if (griglia[i][j]){
				if (griglia[i][j]->colore()==colore){
					// Verifico se il pezzo può mangiare il re
					if (griglia[i][j]->check_mossa(xk, yk, *this)) {
						return true;
					};
				};
				
			};
		};
	};
	return false;
}

bool scacchiera::scacco (const int x1, const int y1, const int x2, const int y2, const bool colore)
{
	// Sposto il pezzo (Le coordinate interne del pezzo devono essere già cambiate)
	pezzo* temp = griglia[x2][y2];
	griglia[x2][y2] = griglia[x1][y1];
	griglia[x1][y1] = 0;
	
	// Verifico se il re sia sotto scacco
	bool result = scacco(colore);
	
	// Riporto il pezzo nella coordinata di partenza
	griglia[x1][y1] = griglia[x2][y2];
	griglia[x2][y2] = temp;
	return result;	
}

bool scacchiera::matto (const bool colore)
{
	// Cerco un pezzo dell'altro colore
	for (int i=0; i<8; i++){
		for (int j=0; j<8; j++){
			if (griglia[i][j]) {
				if (griglia[i][j]->colore() != colore ) {
					
					// Verifico che il pezzo trovato non si possa muovere
					for (int k=0; k<8; k++){
						for (int l=0; l<8; l++){
							if (griglia[i][j]->check_sposta(k,l,*this)) {
								return false;
							};
						};
					};
					
				};
			};
		};
	};
	return true;
}


void scacchiera::promozione (int x1, int y1, int x2, int y2, pezzo& ped_new)
{
	bool color = ped_new.colore();
 	delete &ped_new;
	char Type = 0;
	bool test=false;
	do {
		cout << "Scegli il simbolo del pezzo in cui promuovere il pedone: " << endl;
		cin >> Type;
		switch (Type){
			case 'p':
			case 'P':
				griglia[x1][y1] =new pedone(x2, y2, color);
				test = false;
				break;
			case 't':
			case 'T':
				griglia[x1][y1] =new torre(x2, y2, color);
				test = false;
				break;
			case 'c':
			case 'C':
				griglia[x1][y1] =new cavallo(x2, y2, color);
				test = false;
				break;
			case 'a':
			case 'A':
				griglia[x1][y1] =new alfiere(x2, y2, color);
				test = false;
				break;
			case 'q':
			case 'Q':
				griglia[x1][y1] =new regina(x2, y2, color);
				test = false;
				break;
			default:
				test = true;
		}
	} while (test);
	return;
}





string scacchiera::bn(const bool colore) const
{
	if (colore) {return "Nero";}
	else {return "Bianco";};
}
