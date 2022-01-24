#pragma once

#include <ctime>
#include <chrono>
#include <string>
#include <fstream>


class IFileLoggerSingletone {
public:
    ~IFileLoggerSingletone() = default;
    virtual void OpenLogFile(const std::string &FN) = 0;
    virtual void CloseLogFile() = 0;
    virtual void WriteToLog(const std::string &str) = 0;
    virtual void WriteToLog(const std::string &str, int n) = 0;
    virtual void WriteToLog(const std::string &str, double d) = 0;
};

class FileLoggerSingletone : public IFileLoggerSingletone{
public:
    FileLoggerSingletone(const FileLoggerSingletone&) = delete;
    FileLoggerSingletone(FileLoggerSingletone&&) = delete;
    FileLoggerSingletone& operator=(const FileLoggerSingletone&) = delete;
    FileLoggerSingletone& operator=(FileLoggerSingletone&&) = delete;

    static IFileLoggerSingletone& getInstance();

    void OpenLogFile(const std::string &FN) override;
    void CloseLogFile() override;

    void WriteToLog(const std::string &str) override;
    void WriteToLog(const std::string &str, int n) override;
    void WriteToLog(const std::string &str, double d) override;

private:
    FileLoggerSingletone() {}
    ~FileLoggerSingletone() = default;

    friend IFileLoggerSingletone& getInternalInstanceLogger();

    std::string GetCurDateTime();

    std::ofstream logOut;
};

class FileLoggerSingletoneProxy : IFileLoggerSingletone {
public:
    void OpenLogFile(const std::string &FN) override;
    void CloseLogFile() override;

    void WriteToLog(const std::string &str) override;
    void WriteToLog(const std::string &str, int n) override;
    void WriteToLog(const std::string &str, double d) override;

    static IFileLoggerSingletone& getInstance();

private:
    FileLoggerSingletoneProxy() {}
    ~FileLoggerSingletoneProxy() {}

    FileLoggerSingletoneProxy(const FileLoggerSingletone&) = delete;
    FileLoggerSingletoneProxy(FileLoggerSingletone&&) = delete;
    FileLoggerSingletoneProxy& operator=(const FileLoggerSingletone&) = delete;
    FileLoggerSingletoneProxy& operator=(FileLoggerSingletone&&) = delete;

    std::string InsertCount(const std::string& str);

    int m_count = 0;
};