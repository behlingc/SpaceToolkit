set(HEADERS
  SpaceToolkitException.h
  Atmosphere.h
  USStandardAtmosphere1976.h
  LavalNozzle.h
)

set(SOURCE
  SpaceToolkitException.cpp
  USStandardAtmosphere1976.cpp
  LavalNozzle.cpp
)

add_library(SpaceToolkit ${SOURCE} ${HEADERS})

target_include_directories(SpaceToolkit PUBLIC ../)

