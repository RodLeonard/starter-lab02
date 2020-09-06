set(SIMULATOR_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE SIMULATOR_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SIMULATOR_HEADERS ${SIMULATOR_INCLUDE}/*.h)

add_executable(Simulator ${SIMULATOR_SOURCE} ${SIMULATOR_HEADERS})
target_include_directories(Simulator PRIVATE ${SIMULATOR_INCLUDE})
target_link_libraries(Simulator NumericalIntegration)