#ifndef __LOG_H__
#define __LOG_H__

#include <iostream>
#include <string>

typedef int DltContext;

enum DltLogLevelType {
    DLT_LOG_FATAL = 0, 
    DLT_LOG_ERROR, 
    DLT_LOG_WARN,
    DLT_LOG_INFO, 
    DLT_LOG_DEBUG, 
    DLT_LOG_VERBOSE
};

#define DLT_DECLARE_APP(app)
#define DLT_DECLARE_CONTEXT(ctx)
#define DLT_REGISTER_APP(id, desc)
#define DLT_REGISTER_CONTEXT(ctx, id, desc)
#define DLT_UNREGISTER_CONTEXT(ctx)
#define DLT_UNREGISTER_APP(app)

#define DLT_STRING(val) val
#define DLT_INT(val) val
#define DLT_UINT(val) val
#define DLT_FLOAT(val) val
#define DLT_BOOL(val) (val ? "true" : "false")

inline const char* dlt_level_to_str(int level) {
    switch(level) {
        case DLT_LOG_FATAL: return "[FATAL] ";
        case DLT_LOG_ERROR: return "[ERROR] ";
        case DLT_LOG_WARN:  return "[WARN ] ";
        case DLT_LOG_INFO:  return "[INFO ] ";
        case DLT_LOG_DEBUG: return "[DEBUG] ";
        default:            return "[VERB ] ";
    }
}

// C++ Helper functions to unpack a variadic chain into std::cout
inline void dlt_console_print() {
    std::cout << std::endl;
}

template<typename T, typename... Args>
inline void dlt_console_print(T first, Args... args) {
    std::cout << first;
    dlt_console_print(args...);
}

// Redefine DLT_LOG to capture all trailing arguments and stream them
#define DLT_LOG(ctx, level, ...) \
    do { \
        std::cout << dlt_level_to_str(level); \
        dlt_console_print(__VA_ARGS__); \
    } while(0)
#endif // __LOG_H__
