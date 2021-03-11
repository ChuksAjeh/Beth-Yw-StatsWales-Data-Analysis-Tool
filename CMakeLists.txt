cmake_minimum_required(VERSION 3.17)
project(CSC371_Coursework_Framework_v1_0_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(991129)

add_executable(CSC371_Coursework_Framework_v1_0_2
        991129/datasets/areas.csv
        991129/datasets/complete-popu1009-area.csv
        991129/datasets/complete-popu1009-pop.csv
        991129/datasets/complete-popu1009-popden.csv
        991129/datasets/econ0080.json
        991129/datasets/envi0201.json
        991129/datasets/popu1009.json
        991129/datasets/tran0152.json
        991129/tests/test1.cpp
        991129/tests/test10.cpp
        991129/tests/test11.cpp
        991129/tests/test12.cpp
        991129/tests/test2.cpp
        991129/tests/test3.cpp
        991129/tests/test4.cpp
        991129/tests/test5.cpp
        991129/tests/test6.cpp
        991129/tests/test7.cpp
        991129/tests/test8.cpp
        991129/tests/test9.cpp
        991129/tests/testall.cpp
        991129/area.cpp
        991129/area.h
        991129/areas.cpp
        991129/areas.h
        991129/bethyw.cpp
        991129/bethyw.h
        991129/build.bat
        991129/CHANGELOG
        991129/datasets.h
        991129/input.cpp
        991129/input.h
        991129/lib_catch.hpp
        991129/lib_catch_main.cpp
        991129/lib_cxxopts.hpp
        991129/lib_cxxopts_argv.hpp
        991129/lib_json.hpp
        991129/LICENCE
        991129/main.cpp
        991129/measure.cpp
        991129/measure.h
        991129/README.md)
