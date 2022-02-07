#include "ILogVisitor.h"
#include "Bomb.h"
#include "Plane.h"
#include "MyTools.h"

void LogVisitor::Log(Bomb& bomb) const {
    MyTools::WriteToLog(std::string("Get Bomb Speed") + " was invoked", bomb.GetSpeed());
    MyTools::WriteToLog(std::string("Get Bomb DirectionX") + " was invoked", bomb.GetDirectionX());
    MyTools::WriteToLog(std::string("Get Bomb DirectionY") + " was invoked", bomb.GetDirectionY());
}

void LogVisitor::Log(Plane& plane) const {
    MyTools::WriteToLog(std::string("Get Plane Speed") + " was invoked", plane.GetSpeed());
    MyTools::WriteToLog(std::string("Get Plane DirectionX") + " was invoked", plane.GetDirectionX());
    MyTools::WriteToLog(std::string("Get Plane DirectionY") + " was invoked", plane.GetDirectionY());
}
