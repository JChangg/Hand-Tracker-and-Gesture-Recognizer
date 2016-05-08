#ifndef HAND_EXCEPTION_H
#define HAND_EXCEPTION_H
#include <exception>

// General Exception for the application
class HandException : public std::exception
{
};


class TrackingException : public HandException
{
public:
	virtual const char* what() const throw();
};


#endif

