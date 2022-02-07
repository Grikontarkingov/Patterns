#pragma once

class Bomb;
class Plane;

class ILogVisitor {
public:
    virtual ~ILogVisitor() = default;
    virtual void Log(Bomb& bomb) const= 0;
    virtual void Log(Plane& plane) const = 0;
};

class LogVisitor : public ILogVisitor {
public:
    void Log(Bomb& bomb) const override;
    void Log(Plane& plane) const override;
};


