#include "SpaceToolkit/USStandardAtmosphere1976.h"
#include "SpaceToolkit/SpaceToolkitException.h"

using SpaceToolkit::SpaceToolkitException;
using SpaceToolkit::USStandardAtmosphere1976;

// standard atmosphere data at sea level
constexpr Temperature T_0 = 288.15_K;
constexpr Pressure P_0 = 101325_Pa;
constexpr Density Rho_0 = 1.2250_kgpm3;

constexpr MolarMass M_a =
    0.0289644_kgpmol;  // molar mass of the atmosphere up tp 85 km

Temperature USStandardAtmosphere1976::getAtmosphereTemperatureByHeight(
    Length h) {
  Temperature ret = 0_K;

  if (h >= 0_m && h <= 11000_m)
    ret = -1 * 0.0065_Kpm * h + T_0;
  else if (h > 11000_m && h <= 20000_m)
    ret = 216.65_K;
  else if (h > 20000_m && h <= 32000_m)
    ret = 0.001 * kelvin / metre * h + 196.65_K;
  else if (h > 32000_m && h <= 47000_m)
    ret = 0.0028 * kelvin / metre * h + 139.05_K;
  else if (h > 47000_m && h <= 51000_m)
    ret = 270.65_K;
  else if (h > 51000_m && h <= 71000_m)
    ret = -1 * 0.0028 * kelvin / metre * h + 413.45_K;
  else if (h > 71000_m && h <= 85000_m)
    ret = -1 * 0.002 * kelvin / metre * h + 356.65_K;
  else
    throw SpaceToolkitException("errInputParameterOutOfRange", __FILE__,
                                __LINE__);

  return ret;
}

Pressure USStandardAtmosphere1976::getAtmospherePressureByHeight(Length h) {
  Pressure ret = 0_Pa;

  if (h >= 0_m && h <= 11000_m) {
    Length h_b = 0_m;
    LapseRate L_b = -1 * 0.0065_Kpm;
    Pressure P_b = P_0;
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = P_b * Ppow(T_b / (T_b + L_b * (h - h_b)), g_0 * M_a / (R * L_b));
  } else if (h > 11000_m && h <= 20000_m) {
    Length h_b = 11000_m;
    Pressure P_b = getAtmospherePressureByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = P_b * Pexp(-1 * g_0 * M_a * (h - h_b) / (R * T_b));
  } else if (h > 20000_m && h <= 32000_m) {
    Length h_b = 20000_m;
    LapseRate L_b = 0.001_Kpm;
    Pressure P_b = getAtmospherePressureByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = P_b * Ppow(T_b / (T_b + L_b * (h - h_b)), g_0 * M_a / (R * L_b));
  } else if (h > 32000_m && h <= 47000_m) {
    Length h_b = 32000_m;
    LapseRate L_b = 0.0028_Kpm;
    Pressure P_b = getAtmospherePressureByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = P_b * Ppow(T_b / (T_b + L_b * (h - h_b)), g_0 * M_a / (R * L_b));
  } else if (h > 47000_m && h <= 51000_m) {
    Length h_b = 47000_m;
    Pressure P_b = getAtmospherePressureByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = P_b * Pexp(-1 * g_0 * M_a * (h - h_b) / (R * T_b));
  } else if (h > 51000_m && h <= 71000_m) {
    Length h_b = 51000_m;
    LapseRate L_b = -1 * 0.0028_Kpm;
    Pressure P_b = getAtmospherePressureByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = P_b * Ppow(T_b / (T_b + L_b * (h - h_b)), g_0 * M_a / (R * L_b));
  } else if (h > 71000_m && h <= 85000_m) {
    Length h_b = 71000_m;
    LapseRate L_b = -1 * 0.002_Kpm;
    Pressure P_b = getAtmospherePressureByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = P_b * Ppow(T_b / (T_b + L_b * (h - h_b)), g_0 * M_a / (R * L_b));
  } else {
    throw SpaceToolkitException("errInputParameterOutOfRange", __FILE__,
                                __LINE__);
  }

  return ret;
}

Density USStandardAtmosphere1976::getAtmosphereDensityByHeight(Length h) {
  Density ret = 0_kgpm3;

  if (h >= 0_m && h <= 11000_m) {
    Length h_b = 0_m;
    LapseRate L_b = -1 * 0.0065_Kpm;
    Density Rho_b = Rho_0;
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = Rho_0 * Ppow(T_b / (T_b + L_b * (h - h_b)),
                       (Number)1.0 + g_0 * M_a / (R * L_b));
  } else if (h > 11000_m && h <= 20000_m) {
    Length h_b = 11000_m;
    Density Rho_0 = getAtmosphereDensityByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = Rho_0 * Pexp(-1 * g_0 * M_a * (h - h_b) / (R * T_b));
  } else if (h > 20000_m && h <= 32000_m) {
    Length h_b = 20000_m;
    LapseRate L_b = 0.001_Kpm;
    Density Rho_0 = getAtmosphereDensityByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = Rho_0 * Ppow(T_b / (T_b + L_b * (h - h_b)),
                       (Number)1.0 + g_0 * M_a / (R * L_b));
  } else if (h > 32000_m && h <= 47000_m) {
    Length h_b = 32000_m;
    LapseRate L_b = 0.0028_Kpm;
    Density Rho_0 = getAtmosphereDensityByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = Rho_0 * Ppow(T_b / (T_b + L_b * (h - h_b)),
                       (Number)1.0 + g_0 * M_a / (R * L_b));
  } else if (h > 47000_m && h <= 51000_m) {
    Length h_b = 47000_m;
    Density Rho_0 = getAtmosphereDensityByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = Rho_0 * Pexp(-1 * g_0 * M_a * (h - h_b) / (R * T_b));
  } else if (h > 51000_m && h <= 71000_m) {
    Length h_b = 51000_m;
    LapseRate L_b = -1 * 0.0028_Kpm;
    Density Rho_0 = getAtmosphereDensityByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = Rho_0 * Ppow(T_b / (T_b + L_b * (h - h_b)),
                       (Number)1.0 + g_0 * M_a / (R * L_b));
  } else if (h > 71000_m && h <= 85000_m) {
    Length h_b = 71000_m;
    LapseRate L_b = -1 * 0.002_Kpm;
    Density Rho_0 = getAtmosphereDensityByHeight(h_b);
    Temperature T_b = getAtmosphereTemperatureByHeight(h_b);
    ret = Rho_0 * Ppow(T_b / (T_b + L_b * (h - h_b)),
                       (Number)1.0 + g_0 * M_a / (R * L_b));
  } else {
    throw SpaceToolkitException("errInputParameterOutOfRange", __FILE__,
                                __LINE__);
  }

  return ret;
}
