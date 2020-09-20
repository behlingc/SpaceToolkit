set(HEADERS
  SpaceToolkitException.h
  Atmosphere.h
  USStandardAtmosphere1976.h
)

set(SOURCE
  SpaceToolkitException.cpp
  USStandardAtmosphere1976.cpp
)

add_library(SpaceToolkit ${SOURCE} ${HEADERS})

target_include_directories(SpaceToolkit PUBLIC ../)

