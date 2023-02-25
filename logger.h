#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <mutex>
using namespace std;

enum LogLevel {
	SUCCESSFULLY_DONE,
	WARNING,
	ERROR,
};

string TimeStamp()
{
    char str[32]{};

    time_t a = time(nullptr);

    struct tm time_info;

    if (localtime_s(&time_info, &a) == 0) strftime(str, sizeof(str), "%H:%M:%S", &time_info);

    return str;
}

//This logger class creates a log file and writes log messages in it.
class Logger {
private:
    mutex log_mutex;
	ofstream log_file;
public:
	Logger() {
		log_file.open("LogFile.txt", ios_base::app);
	}
	~Logger() {
		log_file.close();
	}
	void log(LogLevel level,string& message) {
        lock_guard<mutex> lock(log_mutex);
        switch (level) {
        case LogLevel::SUCCESSFULLY_DONE:
            log_file << "[SUCCESSFULLY DONE] ";
            log_file << quoted(TimeStamp()) << " ";
            break;
        case LogLevel::WARNING:
            log_file << "[WARNING] ";
            log_file << quoted(TimeStamp()) << " ";
            break;
        case LogLevel::ERROR:
            log_file << "[ERROR] ";
            log_file << quoted(TimeStamp()) << " ";
            break;
        }
        log_file << message << std::endl;
	}
};


//In this case we see the log messages in Console
//class Logger {
//public:
//    Logger() {}
//    ~Logger(){}
//
//    void log(LogLevel level, const std::string& message) {
//
//        switch (level) {
//        case LogLevel::SUCCESSFULLY_DONE:
//            cout << "[SUCCESSFULLY DONE] ";
//            cout << quoted(TimeStamp()) << " ";
//            cout << message << endl;
//            break;
//        case LogLevel::WARNING:
//            cout << "[WARNING] ";
//            cout << quoted(TimeStamp()) << " ";
//            cout << message << endl;
//            break;
//        case LogLevel::ERROR:
//            cout << "[ERROR] ";
//            cout << quoted(TimeStamp()) << " ";
//            cout << message << endl;
//            break;
//        }
//
//    }
//};

