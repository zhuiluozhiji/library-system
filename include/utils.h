// utils.h
#pragma once
#include <iostream>
#include <chrono>
#include <ctime>

inline void printCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::cout << std::ctime(&t);
}