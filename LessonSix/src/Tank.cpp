
#include <iostream>
#include <random>

#include "Tank.h"
#include "MyTools.h"
#include "ScreenSingleton.h"
#include "Mediator.h"

using namespace std;
using namespace MyTools;

Tank::Tank() {
    vecAllMessagesOfTank.push_back("We all gonna die!");
    vecAllMessagesOfTank.push_back("Shoot down the plane!");
    vecAllMessagesOfTank.push_back("What a quiet day today...");
    vecAllMessagesOfTank.push_back("Planes don't exist!");
}

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
        pMediator->SetMessageInQueue(GetMessage());
    }
}

void Tank::SetStaticMediator(Mediator* mediator) {
    pMediator = mediator;
}

std::string Tank::GetMessage() const{
    return vecAllMessagesOfTank[GetRandomNumber(vecAllMessagesOfTank.size())];
}


uint16_t Tank::GetRandomNumber(uint16_t upper) const {
    std::random_device rd;
    std::mt19937 mersenne(rd());

    return static_cast<uint16_t>(mersenne() % upper + 0);
}