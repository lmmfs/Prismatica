#pragma once

#include "../../defines.hpp"


#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUB_ENABLED 1
#define LOG_TRACE_ENABLED 1

#if PRIREALSE == 1
#define LOG_DEBUB_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

enum logLevel{
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
};

b8 initializeLogger();
void shutdowLogger();

PRIAPI void logOutput(logLevel level, const char* message, ...);

#ifndef PRIFATAL
//logs fatal-level message.
#define PRIFATAL(message, ...) logOutput(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);
#endif

#ifndef PRIERROR
//logs error-level message.
#define PRIERROR(message, ...) logOutput(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
//logs warn-level message.
#define PRIWARN(message, ...) logOutput(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
#define PRIWARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
//logs info-level message.
#define PRIINFO(message, ...) logOutput(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
#define PRIINFO(message, ...)
#endif

#if LOG_DEBUB_ENABLED == 1
//logs debug-level message.
#define PRIDEBUG(message, ...) logOutput(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
#define PRIDEBUG(message, ...)
#endif


#if LOG_TRACE_ENABLED == 1
//logs trace-level message.
#define PRITRACE(message, ...) logOutput(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
#define PRITRACE(message, ...)
#endif