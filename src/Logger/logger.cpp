#include <iostream>
#include <fstream>
#include <sengine/logger.h>
#include <ctime>

//https://stackoverflow.com/questions/16357999/current-date-and-time-as-string
std::string get_time() {
    
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    std::string str(buffer);

    return str;
}

namespace SEngine {
    
    Logger::Logger() {
        this->log_file = std::ofstream(get_time() + "_log.txt");
        this->level = LoggingLevel::Debug;
        this->mode = LoggingMode::Both;
        debug("Logger initialized");
    }
    
    void Logger::set_logging_level(LoggingLevel new_level) {
        this->level = new_level;
    }

    void Logger::set_logging_mode(LoggingMode new_mode) {
        this->mode = new_mode;
    }

    void Logger::debug(std::string debug_info) {
        if (this->level == LoggingLevel::Debug) {
            log(get_time() + "Debug: " + debug_info);
        }
    }

    void Logger::error(std::string error_info) {
        if (this->level <= LoggingLevel::Errors) {
            log(get_time() + "Warning: " + error_info);
        }
    }

    void Logger::warning(std::string warning_info) {
        if (this->level <= LoggingLevel::Warnings) {
            log(get_time() + "Warning: " + warning_info);
        }
    }
    
    
    void Logger::info(std::string info) {
        if (this->level <= LoggingLevel::Info) {
            log(get_time() + "Info: " + info);
        }
    }

    void Logger::log(std::string log_string) {
        switch (this->mode) {
            case Both:
                this->log_file << log_string << "\n";
                std::cout << log_string << "\n";
                break;
            case File:
                this->log_file << log_string << "\n";
                break;
            case Console:
                std::cout << log_string << "\n";
                break;
        }
    }
}