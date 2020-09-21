#ifndef PHYSICAL_UNIT_H
#define PHYSICAL_UNIT_H

#include <cmath>
#include <ratio>

namespace Physics {
template <typename TimeDim, typename LengthDim, typename MassDim,
          typename ElectricCurrentDim, typename TemperatureDim,
          typename AmountOfSubstanceDim, typename LuminousIntensityDim>

class PhysicalUnit {
 private:
  double value;

 public:
  constexpr PhysicalUnit() : value(0.0) {}
  constexpr PhysicalUnit(double val) : value(val) {}
  constexpr PhysicalUnit(long double val) : value(static_cast<double>(val)) {}

  constexpr PhysicalUnit const& operator+=(const PhysicalUnit& rhs) {
    value += rhs.value;
    return *this;
  }
  constexpr PhysicalUnit const& operator-=(const PhysicalUnit& rhs) {
    value -= rhs.value;
    return *this;
  }

  constexpr double Convert(const PhysicalUnit& rhs) const {
    return value / rhs.value;
  }

  constexpr double getValue() const { return value; }
};

#define PHYSICAL_UNIT_TYPE(_TimeDim, _LengthDim, _MassDim,                     \
                           _ElectricCurrentDim, _TemperatureDim,               \
                           _AmountOfSubstanceDim, _LuminousIntensityDim, name) \
  typedef PhysicalUnit<                                                        \
      std::ratio<_TimeDim>, std::ratio<_LengthDim>, std::ratio<_MassDim>,      \
      std::ratio<_ElectricCurrentDim>, std::ratio<_TemperatureDim>,            \
      std::ratio<_AmountOfSubstanceDim>, std::ratio<_LuminousIntensityDim>>    \
      name;
// dimensionless
PHYSICAL_UNIT_TYPE(0, 0, 0, 0, 0, 0, 0, Number);

// SI units
PHYSICAL_UNIT_TYPE(1, 0, 0, 0, 0, 0, 0, Time);
PHYSICAL_UNIT_TYPE(0, 1, 0, 0, 0, 0, 0, Length);
PHYSICAL_UNIT_TYPE(0, 0, 1, 0, 0, 0, 0, Mass);
PHYSICAL_UNIT_TYPE(0, 0, 0, 1, 0, 0, 0, ElectricCurrent);
PHYSICAL_UNIT_TYPE(0, 0, 0, 0, 1, 0, 0, Temperature);
PHYSICAL_UNIT_TYPE(0, 0, 0, 0, 0, 1, 0, AmountOfSubstance);
PHYSICAL_UNIT_TYPE(0, 0, 0, 0, 0, 0, 1, LuminousIntensity);

// Composite units
PHYSICAL_UNIT_TYPE(0, 2, 0, 0, 0, 0, 0, Area);
PHYSICAL_UNIT_TYPE(0, 3, 0, 0, 0, 0, 0, Volume);
PHYSICAL_UNIT_TYPE(-1, 1, 0, 0, 0, 0, 0, Speed);
PHYSICAL_UNIT_TYPE(-2, 1, 0, 0, 0, 0, 0, Acceleration);
PHYSICAL_UNIT_TYPE(-2, 1, 1, 0, 0, 0, 0, Force);
PHYSICAL_UNIT_TYPE(-2, -1, 1, 0, 0, 0, 0, Pressure);
PHYSICAL_UNIT_TYPE(0, -3, 1, 0, 0, 0, 0, Density);
PHYSICAL_UNIT_TYPE(0, 0, 1, 0, 0, -1, 0, MolarMass);
PHYSICAL_UNIT_TYPE(0, -1, 0, 0, 1, 0, 0, LapseRate);

// Constants
PHYSICAL_UNIT_TYPE(-2, 2, 1, 0, -1, -1, 0, GasConstant);

// Addition operator
template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>
operator+(
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& lhs,
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& rhs) {
  return PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                      _AmountOfSubstance, _LuminousIntensity>(lhs.getValue() +
                                                              rhs.getValue());
}

// Substraction operator
template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>
operator-(
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& lhs,
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& rhs) {
  return PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                      _AmountOfSubstance, _LuminousIntensity>(lhs.getValue() -
                                                              rhs.getValue());
}

// Multiplication operators
template <typename _Time1, typename _Length1, typename _Mass1,
          typename _ElectricCurrent1, typename _Temperature1,
          typename _AmountOfSubstance1, typename _LuminousIntensity1,
          typename _Time2, typename _Length2, typename _Mass2,
          typename _ElectricCurrent2, typename _Temperature2,
          typename _AmountOfSubstance2, typename _LuminousIntensity2>
constexpr PhysicalUnit<std::ratio_add<_Time1, _Time2>,
                       std::ratio_add<_Length1, _Length2>,
                       std::ratio_add<_Mass1, _Mass2>,
                       std::ratio_add<_ElectricCurrent1, _ElectricCurrent2>,
                       std::ratio_add<_Temperature1, _Temperature2>,
                       std::ratio_add<_AmountOfSubstance1, _AmountOfSubstance2>,
                       std::ratio_add<_LuminousIntensity1, _LuminousIntensity2>>
operator*(const PhysicalUnit<_Time1, _Length1, _Mass1, _ElectricCurrent1,
                             _Temperature1, _AmountOfSubstance1,
                             _LuminousIntensity1>& lhs,
          const PhysicalUnit<_Time2, _Length2, _Mass2, _ElectricCurrent2,
                             _Temperature2, _AmountOfSubstance2,
                             _LuminousIntensity2>& rhs) {
  return PhysicalUnit<std::ratio_add<_Time1, _Time2>,
                      std::ratio_add<_Length1, _Length2>,
                      std::ratio_add<_Mass1, _Mass2>,
                      std::ratio_add<_ElectricCurrent1, _ElectricCurrent2>,
                      std::ratio_add<_Temperature1, _Temperature2>,
                      std::ratio_add<_AmountOfSubstance1, _AmountOfSubstance2>,
                      std::ratio_add<_LuminousIntensity1, _LuminousIntensity2>>(
      lhs.getValue() * rhs.getValue());
}

template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>
operator*(
    const double& lhs,
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& rhs) {
  return PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                      _AmountOfSubstance, _LuminousIntensity>(lhs *
                                                              rhs.getValue());
}

template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>
operator*(
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& lhs,
    const double& rhs) {
  return PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                      _AmountOfSubstance, _LuminousIntensity>(lhs.getValue() *
                                                              rhs);
}

// Division operators
template <typename _Time1, typename _Length1, typename _Mass1,
          typename _ElectricCurrent1, typename _Temperature1,
          typename _AmountOfSubstance1, typename _LuminousIntensity1,
          typename _Time2, typename _Length2, typename _Mass2,
          typename _ElectricCurrent2, typename _Temperature2,
          typename _AmountOfSubstance2, typename _LuminousIntensity2>
constexpr PhysicalUnit<
    std::ratio_subtract<_Time1, _Time2>,
    std::ratio_subtract<_Length1, _Length2>,
    std::ratio_subtract<_Mass1, _Mass2>,
    std::ratio_subtract<_ElectricCurrent1, _ElectricCurrent2>,
    std::ratio_subtract<_Temperature1, _Temperature2>,
    std::ratio_subtract<_AmountOfSubstance1, _AmountOfSubstance2>,
    std::ratio_subtract<_LuminousIntensity1, _LuminousIntensity2>>
operator/(const PhysicalUnit<_Time1, _Length1, _Mass1, _ElectricCurrent1,
                             _Temperature1, _AmountOfSubstance1,
                             _LuminousIntensity1>& lhs,
          const PhysicalUnit<_Time2, _Length2, _Mass2, _ElectricCurrent2,
                             _Temperature2, _AmountOfSubstance2,
                             _LuminousIntensity2>& rhs) {
  return PhysicalUnit<
      std::ratio_subtract<_Time1, _Time2>,
      std::ratio_subtract<_Length1, _Length2>,
      std::ratio_subtract<_Mass1, _Mass2>,
      std::ratio_subtract<_ElectricCurrent1, _ElectricCurrent2>,
      std::ratio_subtract<_Temperature1, _Temperature2>,
      std::ratio_subtract<_AmountOfSubstance1, _AmountOfSubstance2>,
      std::ratio_subtract<_LuminousIntensity1, _LuminousIntensity2>>(
      lhs.getValue() / rhs.getValue());
}

template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr PhysicalUnit<std::ratio_subtract<std::ratio<0>, _Time>,
                       std::ratio_subtract<std::ratio<0>, _Length>,
                       std::ratio_subtract<std::ratio<0>, _Mass>,
                       std::ratio_subtract<std::ratio<0>, _ElectricCurrent>,
                       std::ratio_subtract<std::ratio<0>, _Temperature>,
                       std::ratio_subtract<std::ratio<0>, _AmountOfSubstance>,
                       std::ratio_subtract<std::ratio<0>, _LuminousIntensity>>
operator/(
    double x,
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& rhs) {
  return PhysicalUnit<std::ratio_subtract<std::ratio<0>, _Time>,
                      std::ratio_subtract<std::ratio<0>, _Length>,
                      std::ratio_subtract<std::ratio<0>, _Mass>,
                      std::ratio_subtract<std::ratio<0>, _ElectricCurrent>,
                      std::ratio_subtract<std::ratio<0>, _Temperature>,
                      std::ratio_subtract<std::ratio<0>, _AmountOfSubstance>,
                      std::ratio_subtract<std::ratio<0>, _LuminousIntensity>>(
      x / rhs.getValue());
}

template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>
operator/(
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& lhs,
    double x) {
  return PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                      _AmountOfSubstance, _LuminousIntensity>(lhs.getValue() /
                                                              x);
}

// Comparison operators
template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr bool operator==(
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& lhs,
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& rhs) {
  return (lhs.getValue() == rhs.getValue());
}

template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr bool operator>(
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& lhs,
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& rhs) {
  return (lhs.getValue() > rhs.getValue());
}

template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr bool operator<(
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& lhs,
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& rhs) {
  return (lhs.getValue() < rhs.getValue());
}

template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr bool operator<=(
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& lhs,
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& rhs) {
  return (lhs.getValue() <= rhs.getValue());
}

template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr bool operator>=(
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& lhs,
    const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                       _AmountOfSubstance, _LuminousIntensity>& rhs) {
  return (lhs.getValue() >= rhs.getValue());
}

// math operations
template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr PhysicalUnit<std::ratio_divide<_Time, std::ratio<2>>,
                       std::ratio_divide<_Length, std::ratio<2>>,
                       std::ratio_divide<_Mass, std::ratio<2>>,
                       std::ratio_divide<_ElectricCurrent, std::ratio<2>>,
                       std::ratio_divide<_Temperature, std::ratio<2>>,
                       std::ratio_divide<_AmountOfSubstance, std::ratio<2>>,
                       std::ratio_divide<_LuminousIntensity, std::ratio<2>>>
Psqrt(const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                         _AmountOfSubstance, _LuminousIntensity>& num) {
  return PhysicalUnit<std::ratio_divide<_Time, std::ratio<2>>,
                      std::ratio_divide<_Length, std::ratio<2>>,
                      std::ratio_divide<_Mass, std::ratio<2>>,
                      std::ratio_divide<_ElectricCurrent, std::ratio<2>>,
                      std::ratio_divide<_Temperature, std::ratio<2>>,
                      std::ratio_divide<_AmountOfSubstance, std::ratio<2>>,
                      std::ratio_divide<_LuminousIntensity, std::ratio<2>>>(
      sqrt(num.getValue()));
}

template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr PhysicalUnit<std::ratio_divide<_Time, std::ratio<2>>,
                       std::ratio_divide<_Length, std::ratio<2>>,
                       std::ratio_divide<_Mass, std::ratio<2>>,
                       std::ratio_divide<_ElectricCurrent, std::ratio<2>>,
                       std::ratio_divide<_Temperature, std::ratio<2>>,
                       std::ratio_divide<_AmountOfSubstance, std::ratio<2>>,
                       std::ratio_divide<_LuminousIntensity, std::ratio<2>>>
Ppow(const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                        _AmountOfSubstance, _LuminousIntensity>& base,
     const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                        _AmountOfSubstance, _LuminousIntensity>& exp) {
  return PhysicalUnit<std::ratio_divide<_Time, std::ratio<2>>,
                      std::ratio_divide<_Length, std::ratio<2>>,
                      std::ratio_divide<_Mass, std::ratio<2>>,
                      std::ratio_divide<_ElectricCurrent, std::ratio<2>>,
                      std::ratio_divide<_Temperature, std::ratio<2>>,
                      std::ratio_divide<_AmountOfSubstance, std::ratio<2>>,
                      std::ratio_divide<_LuminousIntensity, std::ratio<2>>>(
      pow(base.getValue(), exp.getValue()));
}

template <typename _Time, typename _Length, typename _Mass,
          typename _ElectricCurrent, typename _Temperature,
          typename _AmountOfSubstance, typename _LuminousIntensity>
constexpr PhysicalUnit<std::ratio_divide<_Time, std::ratio<2>>,
                       std::ratio_divide<_Length, std::ratio<2>>,
                       std::ratio_divide<_Mass, std::ratio<2>>,
                       std::ratio_divide<_ElectricCurrent, std::ratio<2>>,
                       std::ratio_divide<_Temperature, std::ratio<2>>,
                       std::ratio_divide<_AmountOfSubstance, std::ratio<2>>,
                       std::ratio_divide<_LuminousIntensity, std::ratio<2>>>
Pexp(const PhysicalUnit<_Time, _Length, _Mass, _ElectricCurrent, _Temperature,
                        _AmountOfSubstance, _LuminousIntensity>& x) {
  return PhysicalUnit<std::ratio_divide<_Time, std::ratio<2>>,
                      std::ratio_divide<_Length, std::ratio<2>>,
                      std::ratio_divide<_Mass, std::ratio<2>>,
                      std::ratio_divide<_ElectricCurrent, std::ratio<2>>,
                      std::ratio_divide<_Temperature, std::ratio<2>>,
                      std::ratio_divide<_AmountOfSubstance, std::ratio<2>>,
                      std::ratio_divide<_LuminousIntensity, std::ratio<2>>>(
      exp(x.getValue()));
}

// Unit definitions
// Time
constexpr Time second(1.0);
constexpr Time operator"" _s(long double x) {
  return static_cast<double>(x) * second;
}
constexpr Time operator"" _s(unsigned long long int x) {
  return static_cast<double>(x) * second;
}

// Length
constexpr Length metre(1.0);
constexpr Length operator"" _m(long double x) {
  return static_cast<double>(x) * metre;
}
constexpr Length operator"" _m(unsigned long long int x) {
  return static_cast<double>(x) * metre;
}

// Mass
constexpr Mass kg(1.0);
constexpr Mass operator"" _kg(long double x) {
  return static_cast<double>(x) * kg;
}
constexpr Mass operator"" _kg(unsigned long long int x) {
  return static_cast<double>(x) * kg;
}

// Electric current
constexpr ElectricCurrent ampere(1.0);
constexpr ElectricCurrent operator"" _A(long double x) {
  return static_cast<double>(x) * ampere;
}
constexpr ElectricCurrent operator"" _A(unsigned long long int x) {
  return static_cast<double>(x) * ampere;
}

// Thermodynamic temperature
constexpr Temperature kelvin(1.0);
constexpr Temperature operator"" _K(long double x) {
  return static_cast<double>(x) * kelvin;
}
constexpr Temperature operator"" _K(unsigned long long int x) {
  return static_cast<double>(x) * kelvin;
}

// Amount of substance
constexpr AmountOfSubstance mol(1.0);
constexpr AmountOfSubstance operator"" _mol(long double x) {
  return static_cast<double>(x) * mol;
}
constexpr AmountOfSubstance operator"" _mol(unsigned long long int x) {
  return static_cast<double>(x) * mol;
}

// Luminous intensity
constexpr LuminousIntensity candela(1.0);
constexpr LuminousIntensity operator"" _cd(long double x) {
  return static_cast<double>(x) * candela;
}
constexpr LuminousIntensity operator"" _cd(unsigned long long int x) {
  return static_cast<double>(x) * candela;
}

// Area
constexpr Area metre2 = metre * metre;
constexpr Area operator"" _m2(long double x) { return Area(x); };
constexpr Area operator"" _m2(unsigned long long int x) {
  return Area(static_cast<long double>(x));
};

// Volume
constexpr Volume metre3 = metre2 * metre;
constexpr Volume operator"" _m3(long double x) { return Volume(x); };
constexpr Volume operator"" _m3(unsigned long long int x) {
  return Volume(static_cast<long double>(x));
};

// Speed
constexpr Speed operator"" _mps(long double x) { return Speed(x); };
constexpr Speed operator"" _mps(unsigned long long int x) {
  return Speed(static_cast<double>(x));
};

// Acceleration
constexpr Acceleration operator"" _mps2(long double x) {
  return Acceleration(x);
};
constexpr Acceleration operator"" _mps2(unsigned long long int x) {
  return Acceleration(static_cast<double>(x));
};

// Force
constexpr Force newton(1.0);
constexpr Force operator"" _N(long double x) { return Force(x); };
constexpr Force operator"" _N(unsigned long long int x) {
  return Force(static_cast<double>(x));
};

// Pressure
constexpr Pressure pascal(1.0);
constexpr Pressure operator"" _Pa(long double x) { return Pressure(x); };
constexpr Pressure operator"" _Pa(unsigned long long int x) {
  return Pressure(static_cast<double>(x));
};

// Density
constexpr Density operator"" _kgpm3(long double x) { return Density(x); };
constexpr Density operator"" _kgpm3(unsigned long long int x) {
  return Density(static_cast<double>(x));
};

// Molar mass
constexpr MolarMass operator"" _kgpmol(long double x) { return MolarMass(x); };
constexpr MolarMass operator"" _kgppmol(unsigned long long int x) {
  return MolarMass(static_cast<double>(x));
};

// Lapse rate
constexpr LapseRate operator"" _Kpm(long double x) { return LapseRate(x); };
constexpr LapseRate operator"" _Kpm(unsigned long long int x) {
  return LapseRate(static_cast<double>(x));
};

// Physical constants
constexpr Number PI = std::atan(1) * 4;
constexpr GasConstant R =
    8.31432 * kg * metre2 /
    (second * second * mol * kelvin);  // universal gas constant
constexpr Acceleration g_0 =
    9.80665 * metre / (second * second);  // standard gravity
}  // namespace Physics
#endif  // PHYSICAL_UNIT_H
