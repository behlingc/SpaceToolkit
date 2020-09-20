#ifndef LAVALNOZZLE_H_
#define LAVALNOZZLE_H_

#include "Physics/PhysicalUnit.h"

using namespace Physics;

namespace SpaceToolkit {
class LavalNozzle {
 public:
  LavalNozzle(Force desiredThrust, Number exhaustHeatCapacityRatio,
              Pressure chamberPressure, Pressure exitPressure);
  Area throatCrossSectionalArea();
  Area exitCrossSectionalArea();
  Length throatDiameter();
  Length exitDiameter();

 private:
  Force m_desiredThrust;
  Number m_exhaustHeatCapacityRatio;
  Pressure m_chamberPressure;
  Pressure m_exitPressure;

  Number GAMMA();
};
}  // namespace SpaceToolkit
#endif  // LAVALNOZZLE_H_
