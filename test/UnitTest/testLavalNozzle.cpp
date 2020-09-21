#include "SpaceToolkit/LavalNozzle.h"
#include "SpaceToolkit/SpaceToolkitException.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using SpaceToolkit::LavalNozzle;
using SpaceToolkit::SpaceToolkitException;

// parameters and expected test results are taken from
// https://www.dglr.de/publikationen/2015/340191.pdf
TEST(LavalNozzleTest, TestThroatCalculation) {
  // SUT
  Force desiredThrust = 500_N;
  Number exhaustHeatCapacityRatio = 1.21;
  Pressure chamberPressure = 1500000_Pa;
  Pressure exitPressure = 101325_Pa;

  auto lavalNozzle = std::make_unique<LavalNozzle>(
      desiredThrust, exhaustHeatCapacityRatio, chamberPressure, exitPressure);

  ASSERT_NEAR(Area(0.000247_m2).getValue(),
              lavalNozzle->throatCrossSectionalArea().getValue(), 0.000005);
  ASSERT_NEAR(Length(0.017733_m).getValue(),
              lavalNozzle->throatDiameter().getValue(), 0.000005);
}

TEST(LavalNozzleTest, TestExitCalculation) {
  // SUT
  Force desiredThrust = 500_N;
  Number exhaustHeatCapacityRatio = 1.21;
  Pressure chamberPressure = 1500000_Pa;
  Pressure exitPressure = 101325_Pa;

  auto lavalNozzle = std::make_unique<LavalNozzle>(
      desiredThrust, exhaustHeatCapacityRatio, chamberPressure, exitPressure);

  ASSERT_NEAR(Area(0.000718_m2).getValue(),
              lavalNozzle->exitCrossSectionalArea().getValue(), 0.000005);
  ASSERT_NEAR(Length(0.030237_m).getValue(),
              lavalNozzle->exitDiameter().getValue(), 0.000005);
}
