/*
MIT License

Copyright (c) 2017 Yannick L.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */


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