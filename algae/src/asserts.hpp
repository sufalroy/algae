#pragma once

#define ASSERTIONS_ENABLED

#ifdef ASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

#include <iostream>
#include <cstdint>

inline void report_assertion_failure(const char* expression, const char* message, const char* file, int32_t line)
{
    std::cerr << "[ERROR] Assertion Failure: " << expression << ", message: "
        << message << ", in file: " << file << ", line: " << line << std::endl;
}

#define ASSERT(expr)                                                 \
    {                                                                \
        if (!(expr) {                                                \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }

#define ASSERT_MSG(expr, message)                                         \
    {                                                                     \
        if (!(expr)) {                                                    \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }

#ifdef _DEBUG
#define ASSERT_DEBUG(expr)                                           \
    {                                                                \
        if (!(expr)) {                                               \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }
#else
#define ASSERT_DEBUG(expr)  // Does nothing at all
#endif

#else
#define ASSERT(expr)               // Does nothing at all
#define ASSERT_MSG(expr, message)  // Does nothing at all
#define ASSERT_DEBUG(expr)         // Does nothing at all
#endif