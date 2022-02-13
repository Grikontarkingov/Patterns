#include <chrono>
#include <iostream>
#include "FileLogger.h"

FileLogger::FileLogger(const std::string& fileName) {
    logger.open(fileName);
    if (logger.is_open()) {
        logger << GetCurDateTime() << " - " << "Start logging" << std::endl;
    }
    else {
        throw std::runtime_error("Open file failure");
    }
}
FileLogger::~FileLogger() {
    if (logger.is_open()) {
        logger << GetCurDateTime() << " - " << "Finish logging" << std::endl;
        logger.close();
    }
}

void FileLogger::WriteToLog(const std::string &str) {
    if (logger.is_open()) {
        logger << GetCurDateTime() << " - " << str << std::endl;
    }
}

void FileLogger::WriteToLog(const std::string &str, int n) {
    if (logger.is_open()) {
        logger << GetCurDateTime() << " - " << str << n << std::endl;
    }
}

void FileLogger::WriteToLog(const std::string &str, double d) {
    if (logger.is_open()) {
        logger << GetCurDateTime() << " - " << str << d << std::endl;
    }
}

std::string FileLogger::GetCurDateTime() {
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char* buf = ctime(&time);
    return std::string(buf);
}