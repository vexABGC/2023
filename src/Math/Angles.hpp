//include
#include <cstdint>
#include <ratio>

//Angle ratios
typedef std::ratio<1,1> RadiansRatio;
typedef std::ratio<355,180*113> DegreesRatio;
typedef std::ratio<355*2,113> RevolutionsRatio;
typedef std::ratio<355,180*113> TicksRatio;

//Angle class declaration
template <typename AngleType, typename Ratio>
class Angle{
    //instance variable
    private: AngleType _Angle;

    //constructor
    public: constexpr Angle(AngleType Angle) noexcept : _Angle(Angle){}
    public: constexpr Angle(){}

    //get method
    public: constexpr inline AngleType getAngle() const noexcept {
        return _Angle;
    }

    //converters
    constexpr inline Angle<AngleType, RadiansRatio> toRadians() const noexcept{
        typedef std::ratio_divide<Ratio, RadiansRatio> r;
        return Angle<AngleType, RadiansRatio>(_Angle * r::num / r::den);
    }
    constexpr inline Angle<AngleType, DegreesRatio> toDegrees() const noexcept{
        typedef std::ratio_divide<Ratio, DegreesRatio> r;
        return Angle<AngleType, DegreesRatio>(_Angle * r::num / r::den);
    }
    constexpr inline Angle<AngleType, RevolutionsRatio> toRevolutions() const noexcept{
        typedef std::ratio_divide<Ratio, RevolutionsRatio> r;
        return Angle<AngleType, RevolutionsRatio>(_Angle * r::num / r::den);
    }
    constexpr inline Angle<AngleType, TicksRatio> toTicks() const noexcept{
        typedef std::ratio_divide<Ratio, TicksRatio> r;
        return Angle<AngleType, TicksRatio>(_Angle * r::num / r::den);
    }

    //operators
    public: constexpr inline bool operator==(const Angle &other) const noexcept {
        return _Angle == other._Angle;
    }
    public: constexpr inline bool operator!=(const Angle &other) const noexcept {
        return _Angle != other._Angle;
    }
    public: constexpr inline bool operator>(const Angle &other) const noexcept {
        return _Angle > other._Angle;
    }
    public: constexpr inline bool operator>=(const Angle &other) const noexcept {
        return _Angle >= other._Angle;
    }
    public: constexpr inline bool operator<(const Angle &other) const noexcept {
        return _Angle < other._Angle;
    }
    public: constexpr inline bool operator<=(const Angle &other) const noexcept {
        return _Angle <= other._Angle;
    }

    public: constexpr inline Angle operator+(const Angle &other) const noexcept {
        return _Angle + other._Angle;
    }
    public: constexpr inline Angle operator+() const noexcept {
        return _Angle;
    }

    public: constexpr inline Angle operator-(const Angle &other) const noexcept {
        return _Angle - other._Angle;
    }
    public: constexpr inline Angle operator-() const noexcept {
        return -_Angle;
    }

    public: constexpr inline Angle operator*(long double other) const noexcept {
        return _Angle * other;
    }
    public: constexpr inline Angle operator/(long double other) const noexcept {
        return _Angle / other;
    }
};

//declare units
typedef Angle<long double, RadiansRatio> Radians;
typedef Angle<long double, DegreesRatio> Degrees;
typedef Angle<long double, RevolutionsRatio> Revolutions;
typedef Angle<long double, TicksRatio> Ticks;

//declare and define literals
constexpr Radians operator "" _rad(long double Angle){
    return Radians(Angle);
}
constexpr Radians operator "" _rad(unsigned long long Angle){
    return Radians(Angle);
}

constexpr Degrees operator "" _deg(long double Angle){
    return Degrees(Angle);
}
constexpr Degrees operator "" _deg(unsigned long long Angle){
    return Degrees(Angle);
}

constexpr Revolutions operator "" _rev(long double Angle){
    return Revolutions(Angle);
}
constexpr Revolutions operator "" _rev(unsigned long long Angle){
    return Revolutions(Angle);
}

constexpr Ticks operator "" _tck(long double Angle){
    return Ticks(Angle);
}
constexpr Ticks operator "" _tck(unsigned long long Angle){
    return Ticks(Angle);
}