
add_test(NAME ztest-Simulator COMMAND Simulator 0.1 1 testOutput.csv)
file(GLOB CORE_TESTS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach(testSrc ${CORE_TESTS})
  get_filename_component(testName ${testSrc} NAME_WE)
  set(testName "ztest-${testName}")
  add_executable(${testName} ${testSrc})
  target_link_libraries(${testName} NumericalIntegration)
  add_test(NAME ${testName} COMMAND ${testName})
  set_property(TARGET ${testName} PROPERTY FOLDER "Unit Tests")
  if(WIN32)
    set_property(TARGET ${testName} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${testName}>)
  endif(WIN32)
endforeach(testSrc)
