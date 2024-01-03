//include
#include <cstdint>
#include <ratio>

//distance ratios
typedef std::ratio<1,1> FeetRatio;
typedef std::ratio<1,12> InchesRatio;

//distance class declaration
template <typename DistanceType, typename Ratio>
class Distance{
    //instance variable
    private: DistanceType _distance;

    //constructor
    public: constexpr Distance(DistanceType distance) noexcept : _distance(distance){}
    public: constexpr Distance(){}

    //get method
    public: constexpr inline DistanceType getDistance() const noexcept {
        return _distance;
    }

    //converters
    constexpr inline Distance<DistanceType, InchesRatio> toInches() const noexcept{
        typedef std::ratio_divide<Ratio, InchesRatio> r;
        return Distance<DistanceType, InchesRatio>(_distance * r::num / r::den);
    }
    constexpr inline Distance<DistanceType, FeetRatio> toFeet() const noexcept{
        typedef std::ratio_divide<Ratio, FeetRatio> r;
        return Distance<DistanceType, FeetRatio>(_distance * r::num / r::den);
    }

    //operators
    public: constexpr inline bool operator==(const Distance &other) const noexcept {
        return _distance == other._distance;
    }
    public: constexpr inline bool operator!=(const Distance &other) const noexcept {
        return _distance != other._distance;
    }
    public: constexpr inline bool operator>(const Distance &other) const noexcept {
        return _distance > other._distance;
    }
    public: constexpr inline bool operator>=(const Distance &other) const noexcept {
        return _distance >= other._distance;
    }
    public: constexpr inline bool operator<(const Distance &other) const noexcept {
        return _distance < other._distance;
    }
    public: constexpr inline bool operator<=(const Distance &other) const noexcept {
        return _distance <= other._distance;
    }

    public: constexpr inline Distance operator+(const Distance &other) const noexcept {
        return _distance + other._distance;
    }
    public: constexpr inline Distance operator+() const noexcept {
        return _distance;
    }

    public: constexpr inline Distance operator-(const Distance &other) const noexcept {
        return _distance - other._distance;
    }
    public: constexpr inline Distance operator-() const noexcept {
        return -_distance;
    }

    public: constexpr inline Distance operator*(long double other) const noexcept {
        return _distance * other;
    }
    
    public: constexpr inline DistanceType operator/(const Distance &other) const noexcept {
        return _distance / other._distance;
    }
    public: constexpr inline Distance operator/(long double other) const noexcept {
        return _distance / other;
    }
};

//declare units
typedef Distance<long double, FeetRatio> Feet;
typedef Distance<long double, InchesRatio> Inches;

//declare and define literals
constexpr Feet operator "" _ft(long double distance){
    return Feet(distance);
}
constexpr Feet operator "" _ft(unsigned long long distance){
    return Feet(distance);
}

constexpr Inches operator "" _in(long double distance){
    return Inches(distance);
}
constexpr Inches operator "" _in(unsigned long long distance){
    return Inches(distance);
}