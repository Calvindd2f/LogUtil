#include "LogUtil.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

std::vector<std::string> logLines;

std::string GetTimestamp() {
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y:", &tm);
    return buffer;
    }

std::string GetAgentInstallationDirectory() {
    std::string folderPath = "C:\\Program Files";
    std::string text = folderPath + "\\OrchestratorAgent";
    return text;
    }

void Log(const char* type, const char* shortDescription, bool detailedDescription) {
    std::string timestamp = GetTimestamp();
    std::string message = timestamp + "\t" + type + "\t";

    if (std::string(type) == "Error") {
        message += "\t";
        }

    std::string logMessage = message + shortDescription;
    if (detailedDescription) {
        logMessage += " For more information please see log file";
        }
    std::cout << logMessage << std::endl;

    if (detailedDescription) {
        logMessage = message + shortDescription + "\r\n";
        logMessage += "Detail description: Detailed description provided.\r\n";
        }
    logLines.push_back(logMessage);

    std::string agentInstallationDirectory = GetAgentInstallationDirectory();
    try {
        if (fs::exists(agentInstallationDirectory)) {
            std::ofstream logFile(agentInstallationDirectory + "\\LogFile_Installer.txt", std::ios::app);
            for (const auto& line : logLines) {
                logFile << line;
                }
            logLines.clear();
            }
        }
    catch (const fs::filesystem_error&) {
        // Handle errors if necessary
        }
    }

extern "C" __declspec(dllexport) bool LogInfo(const char* shortMessage, bool detailedDescription) {
    Log("Informational", shortMessage, detailedDescription);
    return true;
}

extern "C" __declspec(dllexport) bool LogError(const char* shortMessage, bool detailedDescription) {
    Log("Error", shortMessage, detailedDescription);
    return true;
    }

extern "C" __declspec(dllexport) bool LogWarning(const char* shortMessage, bool detailedDescription) {
    Log("Warning", shortMessage, detailedDescription);
    return true;
    }

extern "C" __declspec(dllexport) bool LogVerbose(const char* shortMessage, bool detailedDescription) {
    Log("Verbose", shortMessage, detailedDescription);
    return true;
    }

extern "C" __declspec(dllexport) bool LogDebug(const char* shortMessage, bool detailedDescription) {
    Log("Debug", shortMessage, detailedDescription);
    return true;
    }

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
        }
    return TRUE;
    }
