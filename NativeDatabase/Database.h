#pragma once

#include <string>

extern "C" __declspec(dllexport)
bool registerUser(const std::string& username, const std::string& email, const std::string& password);

extern "C" __declspec(dllexport)
bool userExists(const std::string& username);

extern "C" __declspec(dllexport)
bool loginUser(const std::string& username, const std::string& password);