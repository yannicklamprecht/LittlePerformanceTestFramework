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


#ifndef QTPLUGINTEST_TESTCASE_H
#define QTPLUGINTEST_TESTCASE_H


#include <string>
#include <ostream>
#include <list>
#include <vector>
#include <zconf.h>
#include <iostream>
#include "BenchmarkRun.h"
#include "util/Stopwatch.h"

namespace ysl {

    class TestCase {

    private:

        Stopwatch stopwatch = Stopwatch();

        std::vector<BenchmarkRun> benchmarkRuns;

        long long getElapsedMicros() {
            return stopwatch.getMicros();
        }


    protected:

        virtual void runTest(unsigned long cycle)=0;

        virtual std::string getName()=0;


        void startTimer() {
            stopwatch.startTimer();
        }

        void stopTimer() {
            stopwatch.stopTimer();
        }

        void resetTimer() {
            stopwatch.reset();
        }

        void defineBenchmarkPoint(unsigned long cycle, std::string benchmarkPointName) {
            benchmarkRuns.at(cycle).defineBenchmarkPoint(benchmarkPointName, getElapsedMicros());
        }

        void defineBenchmarkPoint(unsigned long cycle, std::string benchmarkPointName, int run) {
            benchmarkRuns.at(cycle).defineBenchmarkPoint(benchmarkPointName, run, getElapsedMicros());
        }


    public:


        virtual void setUp() {}

        virtual void tearDown() {}


        void runTestFully(unsigned long cycles) {
            benchmarkRuns = std::vector<BenchmarkRun>(cycles);

            for (unsigned long i = 0; i < cycles; i++) {
                benchmarkRuns.push_back(BenchmarkRun());
                std::cout << "Test in run " << (i + 1) << " started" << std::endl;
                runTest(i);
            }
        }


        void printStats(std::ostream &outputStream) {
            outputStream << "Benchmark " << getName() << ";microseconds/op" << std::endl;

            for (auto benchmark : benchmarkRuns) {
                benchmark.printStats(outputStream);
            }
        }
    };

}

#endif //QTPLUGINTEST_TESTCASE_H