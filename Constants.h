#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>
#include <iostream>
namespace STATE
{
	enum class MoveState
	{
		MOVE, STATION, START
	};


	enum class StaticState
	{
		CLOSED	= 0, 
		POINTER	= 1,
		PINCH	= 2,
		SCROLL	= 3,
		OPEN	= 4
	};

	std::string staticStateString(StaticState stat);
	std::string dynamicStateString(MoveState dynamic);

};
#endif // !CONSTANTS_H

