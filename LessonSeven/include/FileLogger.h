#pragma once

#include <fstream>

class FileLogger {
public:
    explicit FileLogger(const std::string& fileName);
    ~FileLogger();

    static void WriteToLog(const std::string &str);

    static void WriteToLog(const std::string &str, int n);

    static void WriteToLog(const std::string &str, double d);

private:
    static std::string GetCurDateTime();

    static std::ofstream logger;
};


