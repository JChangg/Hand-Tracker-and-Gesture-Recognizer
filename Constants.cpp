#include "Constants.h"
using namespace STATE;

std::string STATE::staticStateString(StaticState stat)
{
	std::string s;
	switch (stat)
	{
	case StaticState::OPEN:
		s = "OPEN";
		break;
	case StaticState::CLOSED:
		s = "CLOSED";
		break;
	case StaticState::SCROLL:
		s = "SCROLL";
		break;
	case StaticState::PINCH:
		s = "PINCH";
		break;
	case StaticState::POINTER:
		s = "POINTER";
		break;
	default:
		break;
	}
	return s;
}

std::string STATE::dynamicStateString(MoveState dynamic)
{
	std::string m;
	switch (dynamic)
	{
	case MoveState::MOVE:
		m = "MOVE";
		break;
	case MoveState::STATION:
		m = "STATION";
		break;
	case MoveState::START:
		m = "START";
		break;
	}
	return m;
}

