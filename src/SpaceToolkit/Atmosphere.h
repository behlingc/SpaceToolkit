#ifndef ATMOSPHERE_H_
#define ATMOSPHERE_H_

#include "Physics/PhysicalUnit.h"

using namespace Physics;

namespace SpaceToolkit {
class Atmosphere {
 public:
  virtual Temperature getAtmosphereTemperatureByHeight(Length h) = 0;
  virtual Pressure getAtmospherePressureByHeight(Length h) = 0;
  virtual Density getAtmosphereDensityByHeight(Length h) = 0;
};
}  // namespace SpaceToolkit
#endif  // ATMOSPHERE_H_
