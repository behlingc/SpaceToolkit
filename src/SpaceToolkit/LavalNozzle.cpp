#include "SpaceToolkit/LavalNozzle.h"
#include <iostream>

using namespace SpaceToolkit;

LavalNozzle::LavalNozzle(Force desiredThrust, Number exhaustHeatCapacityRatio,
                         Pressure chamberPressure, Pressure exitPressure)
    : m_desiredThrust(desiredThrust),
      m_exhaustHeatCapacityRatio(exhaustHeatCapacityRatio),
      m_chamberPressure(chamberPressure),
      m_exitPressure(exitPressure) {}

Area LavalNozzle::throatCrossSectionalArea() {
  Force F_th = m_desiredThrust;
  Number kappa = m_exhaustHeatCapacityRatio;
  Pressure p_c = m_chamberPressure;
  Pressure p_e = m_exitPressure;

  return (F_th /
          (p_c * GAMMA() *
           Psqrt(2 * (kappa / (kappa - Number(1.0)) *
                      (Number(1.0) -
                       Ppow(p_e / p_c, (kappa - Number(1.0)) / kappa))))));
}

Area LavalNozzle::exitCrossSectionalArea() {
  Force F_th = m_desiredThrust;
  Number kappa = m_exhaustHeatCapacityRatio;
  Pressure p_c = m_chamberPressure;
  Pressure p_e = m_exitPressure;
  Area A_t = throatCrossSectionalArea();

  return A_t * GAMMA() * Ppow(p_e / p_c, -1 / kappa) /
         Psqrt(2 * kappa / (kappa - Number(1.0)) *
               (Number(1.0) - Ppow(p_e / p_c, (kappa - Number(1.0)) / kappa)));
}

Length LavalNozzle::throatDiameter() {
  Area A_t = throatCrossSectionalArea();
  return Psqrt(4 * A_t / PI);
}

Length LavalNozzle::exitDiameter() {
  Area A_e = exitCrossSectionalArea();
  return Psqrt(4 * A_e / PI);
}

// see https://www.dglr.de/publikationen/2015/340191.pdf for this constant
Number LavalNozzle::GAMMA() {
  Number kappa = m_exhaustHeatCapacityRatio;
  return Psqrt(kappa * (Ppow(2 / (kappa + Number(1.0)),
                             (kappa + Number(1.0)) / (kappa - Number(1.0)))));
}
