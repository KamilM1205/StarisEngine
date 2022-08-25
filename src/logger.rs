enum LoggingLevel {
    Debug,
    Info,
    Warning,
    Error
}

enum LoggingMode {
    Console,
    File,
    Both
}

struct Logger {
    level: LoggingLevel,
    mode: LoggingLevel
}

impl Logger {
    fn log(&self, message: &str) {

    }

    fn set_logging_level(&self, new_level: LoggingLevel) {
        &self.level = new_level;
    }

    fn set_logging_mode(&self, new_mode: LoggingMode) {
        &self.mode = new_mode;
    }

    fn debug(&self, string: &str) {
        if &self.mode == LoggingLevel::Debug {
            log(string);
        }
    }
    
    fn info(&self, string: &str) {
        if &self.mode >= LoggingLevel::Info {
            log(string);
        }
    }
    
    fn warning(&self, string: &str) {
        if &self.mode >= LoggingLevel::Warning {
            log(string);
        }
    }
    
    fn error(&self, string: &str) {
        if &self.mode >= LoggingLevel::Error {
            log(string);
        }
    }
}