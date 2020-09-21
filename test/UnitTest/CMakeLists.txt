set (SRC
  main.cpp
  testUSStandardAtmosphere1976.cpp
  testLavalNozzle.cpp
)

add_executable (UnitTest ${SRC})

target_link_libraries (UnitTest
  gtest
  gmock
  SpaceToolkit
)

