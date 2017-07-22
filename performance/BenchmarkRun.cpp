//
// Created by yannick lamprecht on 10.07.17.
//

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
