#ifndef LOGGER_H_
#define LOGGER_H_
#include <string>
#include <fstream>

namespace SEngine {
    enum LoggingLevel{
        Debug,
        Error,
        Warning,
        Info
    };

    enum LoggingMode {
        Console,
        File,
        Both
    };
    
    class Logger {
        private:
            //enums
            LoggingLevel level;
            LoggingMode mode;
            
            std::ofstream log_file;
            
            //methods
            void log(std::string);


        public:
            Logger();
            ~Logger();

            //setters
            void set_logging_level(LoggingLevel);
            void set_logging_mode(LoggingMode);
            
            //methods
            void info(std::string);
            void warning(std::string);
            void error(std::string);
            void debug(std::string);

    };
}
#endif