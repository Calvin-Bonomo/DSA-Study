cmake_minimum_required(VERSION 3.5)

project(FiresideLib VERSION 0.1 LANGUAGES C)

add_subdirectory(src)

add_library(${PROJECT_NAME} PUBLIC ${FIRESIDE_LIB_SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${FIRESIDE_LIB_INCLUDE_DIRS})

if (MAKE_TESTS)
  add_subdirectory(tests)
endif()