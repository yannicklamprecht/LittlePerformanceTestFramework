//
// Created by yannick lamprecht on 09.07.17.
//

#include "Stopwatch.h"

void ysl::Stopwatch::startTimer() {
    startTime = std::chrono::high_resolution_clock::now();
}

void ysl::Stopwatch::stopTimer() {
    endTime = std::chrono::high_resolution_clock::now();
}

void ysl::Stopwatch::reset() {
    startTime = endTime = {};
}

long long int ysl::Stopwatch::getMicros() {
    return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
}