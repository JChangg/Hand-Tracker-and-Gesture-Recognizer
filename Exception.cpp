#include "Exception.h"
const char* TrackingException::what() const throw()
{
	return "Error: Lost track of hand.";
}