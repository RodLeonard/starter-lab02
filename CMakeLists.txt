cmake_minimum_required (VERSION 3.10) #CMake will fail if below this version

set(CMAKE_CXX_STANDARD 20) #CMake will include necessary compiler flags to enable c++20, if possible

#Defaults to placing all executables in the bin folder, and all libraries in the lib folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

#For integration with vcpkg. This line ensures any packages installed by vcpkg will be found by
#a CMake find_package call.
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

enable_testing()

project(ELCT350)

add_subdirectory(NumericalIntegration)
add_subdirectory(Simulator)
add_subdirectory(tests)