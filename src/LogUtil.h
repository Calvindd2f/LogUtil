#ifndef LOGUTIL_H
#define LOGUTIL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

    // Function declarations
    bool LogInfo(const char* shortMessage, bool detailedDescription);
    bool LogError(const char* shortMessage, bool detailedDescription);
    bool LogWarning(const char* shortMessage, bool detailedDescription);
    bool LogVerbose(const char* shortMessage, bool detailedDescription);
    bool LogDebug(const char* shortMessage, bool detailedDescription);

#ifdef __cplusplus
    }
#endif

#endif // LOGUTIL_H
