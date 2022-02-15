
#include <iostream>
#include <random>

#include "Tank.h"
#include "MyTools.h"
#include "ScreenSingleton.h"
#include "Mediator.h"

using namespace std;
using namespace MyTools;

bool Tank::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void Tank::Draw()
{
	ScreenSingleton::getInstance().SetColor(CC_Cyan);
	ScreenSingleton::getInstance().GotoXY(x, y - 3);
	cout << "    #####";
	ScreenSingleton::getInstance().GotoXY(x-2, y - 2);
	cout << "#######   #";
	ScreenSingleton::getInstance().GotoXY(x, y - 1);
	cout << "    #####";
	ScreenSingleton::getInstance().GotoXY(x,y);
	cout << " ###########";

    if(GetRandomNumber(10) == 0){
        pMediator->AddMessageInQueue(x - 4, y - 5, GetRandomMessage());
    }
}

//Mediator* Tank::pMediator = nullptr;

void Tank::SetMediator(Mediator* mediator) {
    pMediator = mediator;
}

std::string Tank::GetRandomMessage() const{
    return allMessages[GetRandomNumber(allMessages.size())];
}


uint16_t Tank::GetRandomNumber(uint16_t upper) const {
    std::random_device rd;
    std::mt19937 mersenne(rd());

    return static_cast<uint16_t>(mersenne() % upper + 0);
}