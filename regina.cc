#include <cmath>
using namespace std;
#include "regina.hh"

bool regina::regole(const int x, const int y) const
{
	int deltax = abs(x-X());
	int deltay = abs(y-Y());
	if ( deltax == deltay || deltax*deltay == 0) {
		if (deltax) return true;
		else return true;
	} else return false;
}
