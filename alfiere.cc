using namespace std;
#include "alfiere.hh"

bool alfiere::regole(const int x, const int y) const
{
	if ( abs( x-X() ) == abs( y-Y() ) ) {
		return true;
	} else {
		return false;
	};
}

