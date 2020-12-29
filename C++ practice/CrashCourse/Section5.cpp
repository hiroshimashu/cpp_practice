//
//  Section5.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/24.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "Section5.hpp"
#include "stdexcept"

struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};


struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[cons] %ld -> %ld: %f\n", from, to, amount);
    }
};

struct ConsoleLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("%ld -> %ld: %f\n", from, to, amount);
    }
};

enum class LoggerType {
    Console,
    File
};

struct Bank {
    Bank(Logger& logger): logger { logger } { }
    void make_transfer(long from, long to, double amount) {
        logger.log_transfer(from, to, amount);
    }
    
    
private:
    Logger& logger;
};


