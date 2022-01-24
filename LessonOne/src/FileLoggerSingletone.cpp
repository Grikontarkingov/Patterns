#include "FileLoggerSingletone.h"


IFileLoggerSingletone& getInternalInstanceLogger() {
    static FileLoggerSingletone theInstance;
    return theInstance;
};

IFileLoggerSingletone& FileLoggerSingletone::getInstance() {
    return FileLoggerSingletoneProxy::getInstance();
}

void FileLoggerSingletone::OpenLogFile(const std::string &FN) {
    logOut.open(FN, std::ios_base::out);
}
void FileLoggerSingletone::CloseLogFile() {
    if (logOut.is_open()) {
        logOut.close();
    }
}

void FileLoggerSingletone::WriteToLog(const std::string &str) {
    if (logOut.is_open()) {
        logOut << GetCurDateTime() << " - " << str << std::endl;
    }
}
void FileLoggerSingletone::WriteToLog(const std::string &str, int n) {
    if (logOut.is_open()) {
        logOut << GetCurDateTime() << " - " << str << n << std::endl;
    }
}
void FileLoggerSingletone::WriteToLog(const std::string &str, double d) {
    if (logOut.is_open()) {
        logOut << GetCurDateTime() << " - " << str << d << std::endl;
    }
}

std::string FileLoggerSingletone::GetCurDateTime() {
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char* buf = ctime(&time);
    return std::string(buf);
}



IFileLoggerSingletone& FileLoggerSingletoneProxy::getInstance() {
    static FileLoggerSingletoneProxy theInstance;
    return theInstance;
}

void FileLoggerSingletoneProxy::OpenLogFile(const std::string &FN) {
    getInternalInstanceLogger().OpenLogFile(FN);
}
void FileLoggerSingletoneProxy::CloseLogFile() {
    getInternalInstanceLogger().CloseLogFile();
}

void FileLoggerSingletoneProxy::WriteToLog(const std::string &str) {
    getInternalInstanceLogger().WriteToLog(InsertCount(str));
}
void FileLoggerSingletoneProxy::WriteToLog(const std::string &str, int n) {
    getInternalInstanceLogger().WriteToLog(InsertCount(str), n);
}
void FileLoggerSingletoneProxy::WriteToLog(const std::string &str, double d) {
    getInternalInstanceLogger().WriteToLog(InsertCount(str), d);
}

std::string FileLoggerSingletoneProxy::InsertCount(const std::string& str){
    std::string final;
    ++m_count;
    final += std::to_string(m_count) + ": " + str;
    return final;
}