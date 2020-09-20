#include "SpaceToolkit/SpaceToolkitException.h"
#include "SpaceToolkit/USStandardAtmosphere1976.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using SpaceToolkit::SpaceToolkitException;
using SpaceToolkit::USStandardAtmosphere1976;

TEST(USStandardAtmosphere1976Test, TestTemperaturesAtLevelBorders) {
  // SUT
  auto usStandardAtmosphere1976 = std::make_unique<USStandardAtmosphere1976>();

  // Atmosphere level 0 : 0 ... 11 km
  ASSERT_NEAR(Temperature(288.15_K).getValue(),
              usStandardAtmosphere1976->getAtmosphereTemperatureByHeight(0_m)
                  .getValue(),
              0.05);

  // Atmosphere level 1 : 11 ... 20 km
  ASSERT_NEAR(
      Temperature(216.65_K).getValue(),
      usStandardAtmosphere1976->getAtmosphereTemperatureByHeight(11000_m)
          .getValue(),
      0.05);

  // Atmosphere level 2 : 20 ... 32 km
  ASSERT_NEAR(
      Temperature(216.65_K).getValue(),
      usStandardAtmosphere1976->getAtmosphereTemperatureByHeight(20000_m)
          .getValue(),
      0.05);

  // Atmosphere level 3 : 32 ... 47 km
  ASSERT_NEAR(
      Temperature(228.65_K).getValue(),
      usStandardAtmosphere1976->getAtmosphereTemperatureByHeight(32000_m)
          .getValue(),
      0.05);

  // Atmosphere level 4 : 47 ... 51 km
  ASSERT_NEAR(
      Temperature(270.65_K).getValue(),
      usStandardAtmosphere1976->getAtmosphereTemperatureByHeight(47000_m)
          .getValue(),
      0.05);

  // Atmosphere level 5 : 51 ... 71 km
  ASSERT_NEAR(
      Temperature(270.65_K).getValue(),
      usStandardAtmosphere1976->getAtmosphereTemperatureByHeight(51000_m)
          .getValue(),
      0.05);

  // Atmosphere level 5 : 71 ... 85 km
  ASSERT_NEAR(
      Temperature(214.65_K).getValue(),
      usStandardAtmosphere1976->getAtmosphereTemperatureByHeight(71000_m)
          .getValue(),
      0.05);

  // Atmosphere upper end at 85 km
  ASSERT_NEAR(
      Temperature(186.65_K).getValue(),
      usStandardAtmosphere1976->getAtmosphereTemperatureByHeight(85000_m)
          .getValue(),
      0.05);
}

TEST(USStandardAtmosphere1976Test, TestPressuresAtLevelBorders) {
  // SUT
  auto usStandardAtmosphere1976 = std::make_unique<USStandardAtmosphere1976>();

  // Atmosphere level 0 : 0 ... 11 km
  ASSERT_NEAR(
      Pressure(101325_Pa).getValue(),
      usStandardAtmosphere1976->getAtmospherePressureByHeight(0_m).getValue(),
      0.05);

  // Atmosphere level 1 : 11 ... 20 km
  ASSERT_NEAR(Pressure(22632.1_Pa).getValue(),
              usStandardAtmosphere1976->getAtmospherePressureByHeight(11000_m)
                  .getValue(),
              0.05);

  // Atmosphere level 2 : 20 ... 32 km
  ASSERT_NEAR(Pressure(5474.89_Pa).getValue(),
              usStandardAtmosphere1976->getAtmospherePressureByHeight(20000_m)
                  .getValue(),
              0.05);

  // Atmosphere level 3 : 32 ... 47 km
  ASSERT_NEAR(Pressure(868.019_Pa).getValue(),
              usStandardAtmosphere1976->getAtmospherePressureByHeight(32000_m)
                  .getValue(),
              0.05);

  // Atmosphere level 4 : 47 ... 51 km
  ASSERT_NEAR(Pressure(110.906_Pa).getValue(),
              usStandardAtmosphere1976->getAtmospherePressureByHeight(47000_m)
                  .getValue(),
              0.05);

  // Atmosphere level 5 : 51 ... 71 km
  ASSERT_NEAR(Pressure(66.9389_Pa).getValue(),
              usStandardAtmosphere1976->getAtmospherePressureByHeight(51000_m)
                  .getValue(),
              0.05);

  // Atmosphere level 5 : 71 ... 85 km
  ASSERT_NEAR(Pressure(3.95642_Pa).getValue(),
              usStandardAtmosphere1976->getAtmospherePressureByHeight(71000_m)
                  .getValue(),
              0.05);

  // Atmosphere upper end at 85 km
  ASSERT_NEAR(Pressure(0.363413_Pa).getValue(),
              usStandardAtmosphere1976->getAtmospherePressureByHeight(85000_m)
                  .getValue(),
              0.05);
}

TEST(USStandardAtmosphere1976Test, TestDensityAtLevelBorders) {
  // SUT
  auto usStandardAtmosphere1976 = std::make_unique<USStandardAtmosphere1976>();

  // Atmosphere level 0 : 0 ... 11 km
  ASSERT_NEAR(
      Density(1.2250_kgpm3).getValue(),
      usStandardAtmosphere1976->getAtmosphereDensityByHeight(0_m).getValue(),
      0.05);

  // Atmosphere level 1 : 11 ... 20 km
  ASSERT_NEAR(Density(0.36391_kgpm3).getValue(),
              usStandardAtmosphere1976->getAtmosphereDensityByHeight(11000_m)
                  .getValue(),
              0.05);

  // Atmosphere level 2 : 20 ... 32 km
  ASSERT_NEAR(Density(0.08803_kgpm3).getValue(),
              usStandardAtmosphere1976->getAtmosphereDensityByHeight(20000_m)
                  .getValue(),
              0.05);

  // Atmosphere level 3 : 32 ... 47 km
  ASSERT_NEAR(Density(0.01322_kgpm3).getValue(),
              usStandardAtmosphere1976->getAtmosphereDensityByHeight(32000_m)
                  .getValue(),
              0.05);

  // Atmosphere level 4 : 47 ... 51 km
  ASSERT_NEAR(Density(0.00143_kgpm3).getValue(),
              usStandardAtmosphere1976->getAtmosphereDensityByHeight(47000_m)
                  .getValue(),
              0.05);

  // Atmosphere level 5 : 51 ... 71 km
  ASSERT_NEAR(Density(0.00086_kgpm3).getValue(),
              usStandardAtmosphere1976->getAtmosphereDensityByHeight(51000_m)
                  .getValue(),
              0.05);

  // Atmosphere level 5 : 71 ... 85 km
  ASSERT_NEAR(Density(0.000064_kgpm3).getValue(),
              usStandardAtmosphere1976->getAtmosphereDensityByHeight(71000_m)
                  .getValue(),
              0.05);

  // Atmosphere upper end at 85 km
  ASSERT_NEAR(Density(0.00000678282_kgpm3).getValue(),
              usStandardAtmosphere1976->getAtmosphereDensityByHeight(85000_m)
                  .getValue(),
              0.05);
}

TEST(USStandardAtmosphere1976Test, TestInputHeightOutOfRange) {
  // SUT
  auto usStandardAtmosphere1976 = std::make_unique<USStandardAtmosphere1976>();

  // temperature calculation - negative height 0.1 meter beyond sea level
  ASSERT_THROW(
      usStandardAtmosphere1976->getAtmosphereTemperatureByHeight(-1 * 0.1_m),
      SpaceToolkitException);

  // temperature calculation - above atmosphere end at 85000.1 meter beyond sea
  // level
  ASSERT_THROW(
      usStandardAtmosphere1976->getAtmosphereTemperatureByHeight(85000.1_m),
      SpaceToolkitException);

  // pressure calculation - negative height 0.1 meter beyond sea level
  ASSERT_THROW(
      usStandardAtmosphere1976->getAtmospherePressureByHeight(-1 * 0.1_m),
      SpaceToolkitException);

  // pressure calculation -  above atmosphere end at 85000.1 meter beyond sea
  // level
  ASSERT_THROW(
      usStandardAtmosphere1976->getAtmospherePressureByHeight(85000.1_m),
      SpaceToolkitException);

  // density calculation - negative height 0.1 meter beyond sea level
  ASSERT_THROW(
      usStandardAtmosphere1976->getAtmosphereDensityByHeight(-1 * 0.1_m),
      SpaceToolkitException);

  // density calculation -  above atmosphere end at 85000.1 meter beyond sea
  // level
  ASSERT_THROW(
      usStandardAtmosphere1976->getAtmosphereDensityByHeight(85000.1_m),
      SpaceToolkitException);
}
