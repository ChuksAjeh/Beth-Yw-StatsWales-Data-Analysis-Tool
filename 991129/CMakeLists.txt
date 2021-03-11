cmake_minimum_required(VERSION 3.17)
project(991129)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(991129
        bin/catch.o
        datasets/areas.csv
        datasets/complete-popu1009-area.csv
        datasets/complete-popu1009-pop.csv
        datasets/complete-popu1009-popden.csv
        datasets/econ0080.json
        datasets/envi0201.json
        datasets/popu1009.json
        datasets/tran0152.json
        "tests/output1. bethyw -d invalidataset.txt"
        "tests/output10. bethyw -d complete-pop -a W06000024 -m area.json"
        "tests/output2. bethyw --dir invalidir.txt"
        "tests/output3. bethyw -a doesnotexist -j.json"
        "tests/output4. bethyw -d popden.txt"
        "tests/output5. bethyw -d popden -j.json"
        "tests/output6. bethyw -d biz -j.json"
        "tests/output7. bethyw -d aqi -j.json"
        "tests/output8. bethyw -d trains -j.json"
        "tests/output9. bethyw -d complete-popden -j.json"
        tests/test1.cpp
        tests/test10.cpp
        tests/test11.cpp
        tests/test12.cpp
        tests/test2.cpp
        tests/test3.cpp
        tests/test4.cpp
        tests/test5.cpp
        tests/test6.cpp
        tests/test7.cpp
        tests/test8.cpp
        tests/test9.cpp
        tests/testall.cpp
        area.cpp
        area.h
        areas.cpp
        areas.h
        bethyw.cpp
        bethyw.h
        build.bat
        CHANGELOG
        datasets.h
        input.cpp
        input.h
        lib_catch.hpp
        lib_catch_main.cpp
        lib_cxxopts.hpp
        lib_cxxopts_argv.hpp
        lib_json.hpp
        LICENCE
        main.cpp
        measure.cpp
        measure.h
        README.md)
