#include "logger.hpp"

// TODO: temporary
#include <iostream>
#include <string>
#include <cstring>
#include <stdarg.h>

b8 initializeLogger(){
    // TODO: create log file.
    return TRUE;
}

void shutdowLogger(){
    // TODO: cleanup logging/write queued entries.
}

PRIAPI void logOutput(logLevel level, const char* message, ...){
    const char* levelStrings[6] = {"[FATAL]: ","[ERROR]: ","[WARN]: ","[INFO]: ","[DEBUG]: ","[TRACE]: "};

    char outMessage[32000];
    memset(outMessage, 0, sizeof(outMessage));

    __builtin_va_list argPtr;
    va_start(argPtr, message);
    vsnprintf(outMessage, 32000, message, argPtr);
    va_end(argPtr);

    char finalMessage[32000];
    // Calculate the available space in the finalMessage buffer for the outMessage
    u64 availableSpace = sizeof(finalMessage) - strlen(levelStrings[level]) - 2; // "-2" accounts for "%s\n"
    snprintf(finalMessage, sizeof(finalMessage), "%s%.*s\n", levelStrings[level], static_cast<int>(availableSpace), outMessage);


    printf("%s", finalMessage);
}