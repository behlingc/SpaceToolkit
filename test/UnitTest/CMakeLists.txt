file (GLOB SRC
  *.cpp
)

add_executable (UnitTest ${SRC})

target_link_libraries (UnitTest
  gtest
  gmock
  SpaceToolkit
)

