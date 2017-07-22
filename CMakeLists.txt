cmake_minimum_required(VERSION 3.8)
project(PerfTest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES performance/util/Stopwatch.cpp performance/util/Stopwatch.h performance/BenchmarkRun.cpp performance/BenchmarkRun.h performance/TestCase.h)
add_library(PerfTest SHARED ${SOURCE_FILES})