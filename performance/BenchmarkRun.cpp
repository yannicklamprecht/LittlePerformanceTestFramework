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

#include <iostream>
#include "BenchmarkRun.h"

void ysl::BenchmarkRun::defineBenchmarkPoint(std::string benchmarkPointName, long microsElapsed) {
    _stats.insert({benchmarkPointName,microsElapsed});
}

void ysl::BenchmarkRun::defineBenchmarkPoint(std::string benchmarkPointName, int run, long microsElapsed) {
    _stats[benchmarkPointName + std::to_string(run)] = microsElapsed;
}

std::list<std::string> ysl::BenchmarkRun::getStatsCommaSeparatedList() {
    std::list<std::string> stringList(_stats.size());

    for (auto keyValue : _stats) {
        stringList.push_back(keyValue.first + ";" + std::to_string(keyValue.second));
    }
    return stringList;
}

void ysl::BenchmarkRun::printStats(std::ostream &outputStream) {
    for (auto value : getStatsCommaSeparatedList()) {
        outputStream << value << std::endl;
    }
}
