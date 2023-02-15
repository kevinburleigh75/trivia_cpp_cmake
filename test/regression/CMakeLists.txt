add_executable(test__regression
  test__regression.cc
)
target_link_libraries(test__regression PRIVATE Catch2::Catch2WithMain)

