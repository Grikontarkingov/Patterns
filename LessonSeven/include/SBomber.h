#pragma once

#include <vector>
#include <memory>

class SBomberImpl;
class FileLogger;

class SBomber
{
public:

    explicit SBomber(FileLogger* fileLogger);
    ~SBomber();
    
    bool GetExitFlag() const;

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:;

    std::unique_ptr<SBomberImpl> sBomberImpl;
    FileLogger* logger;
};