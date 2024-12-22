set_cmake_minimum_required(version 3.5...)

project(FiresideLib 0.1)

add_subdirectory(src)

if (MAKE_TESTS)
  add_subdirectory(tests)
endif()