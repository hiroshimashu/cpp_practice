//
//  Section5.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/24.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "Section5.hpp"
#include "stdexcept"




enum class LoggerType {
    Console,
    File
};

struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("%ld -> %ld: %f\n", from, to, amount);
    }
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld, %ld, %f \n", from, to, amount);
    }
};

struct Bank {
    Bank() : type { LoggerType::Console } { }
    void set_logger(LoggerType new_type) {
        type = new_type;
    }
    void make_transger(long from, long to, double amount) {
        switch (type) {
            case LoggerType::Console: {
                consoleLogger.log_transfer(from, to, amount);
                break;
            } case LoggerType::File: {
                fileLogger.log_transfer(from, to, amount);
                break;
            } default: {
                throw std::logic_error("Unknown Logger type encoutered.");
            }
        }
    }
    
private:
    LoggerType type;
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
};

int main() {
    Bank bank;
    bank.make_transger(1000, 2000, 39.95);
}




