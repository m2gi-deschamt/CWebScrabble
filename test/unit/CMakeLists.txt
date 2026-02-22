cmake_minimum_required(VERSION 3.5)
project(CWebScrabble_unit_test CXX)

aux_source_directory(. TEST_UNIT_SRC)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.16.0 
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME} ${TEST_UNIT_SRC})

# ##############################################################################
# If you include the drogon source code locally in your project, use this method
# to add drogon 
# target_link_libraries(${PROJECT_NAME} PRIVATE drogon)
#
# and comment out the following lines

target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main game)