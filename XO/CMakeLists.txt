cmake_minimum_required(VERSION 3.5)

project(XO)

set(SOURCES main.cpp gamemodel.cpp view.cpp)

set(HEADERS gamemodel.h view.h)

add_executable(main ${SOURCES} ${HEADERS})

set_target_properties(
    main PROPERTIES
    CXX_STANDART 11
    CXX_REQUIRED ON
)

