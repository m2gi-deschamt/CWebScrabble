cmake_minimum_required(VERSION 3.5)
project(CWebScrabble_integration_test CXX)

aux_source_directory(. TEST_INT_SRC)

enable_testing()

add_executable(${PROJECT_NAME} ${TEST_INT_SRC})

# ##############################################################################
# If you include the drogon source code locally in your project, use this method
# to add drogon 
# target_link_libraries(${PROJECT_NAME} PRIVATE drogon)
#
# and comment out the following lines

target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon game)

ParseAndAddDrogonTests(${PROJECT_NAME})