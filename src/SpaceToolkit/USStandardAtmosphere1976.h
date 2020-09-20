#ifndef USSTANDARDATMOSPHERE1976_H_
#define USSTANDARDATMOSPHERE1976_H_

#include "SpaceToolkit/Atmosphere.h"

namespace SpaceToolkit {
class USStandardAtmosphere1976 : Atmosphere {
 public:
  Temperature getAtmosphereTemperatureByHeight(Length h);
  Pressure getAtmospherePressureByHeight(Length h);
  Density getAtmosphereDensityByHeight(Length h);
};
}  // namespace SpaceToolkit
#endif  // USSTANDARDATMOSPHERE1976_H_
