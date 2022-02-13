#pragma once

#include <fstream>

class FileLogger {
public:
    explicit FileLogger(const std::string& fileName);
    ~FileLogger();

    void WriteToLog(const std::string &str);

    void WriteToLog(const std::string &str, int n);

    void WriteToLog(const std::string &str, double d);

private:
    std::string GetCurDateTime();

    std::ofstream logger;
};


