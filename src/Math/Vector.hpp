#include "../src/Math/Distances.hpp"
#include "../src/Math/Angles.hpp"
#include "math.h"

template <typename A, typename B>
class DistanceVector{
    //instance variables
    private: Distance<A,B> x;
    private: Distance<A,B> y;

    //constructor
    public: DistanceVector(Distance<A,B> xValue, Distance<A,B> yValue){
        this->x = xValue;
        this->y = yValue;
    }
    public: DistanceVector(Angle<long double, RadiansRatio> angle, Distance<A,B> magnitude){
        this->x = magnitude * cosl(angle.getAngle());
        this->y = magnitude * sinl(angle.getAngle());
    }

    //set methods
    public: void setX(Distance<A,B> value){
        this->x = value;
    }
    public: void setY(Distance<A,B> value){
        this->y = value;
    }

    //get methods
    public: Distance<A,B> getX(){
        return this->x;
    }
    public: Distance<A,B> getY(){
        return this->y;
    }
    public: Angle<long double, RadiansRatio> getAngleRadians(){
        //check for vertical angles
        if (this->x.getDistance() == 0){
            if(this->y.getDistance() >= 0){
                return Angle<long double, RadiansRatio>(3.14159265358979 * 0.5);
            }else{
                return Angle<long double, RadiansRatio>(3.14159265358979 * 1.5);
            }
        }

        //calculate regular angle
        long double returnVal = fabsl(atanl(this->y/this->x));
        if(this->x.getDistance() > 0  && this->y.getDistance() >= 0){
            //Q1
            returnVal = 0 + returnVal;
        }
        if(this->x.getDistance() < 0  && this->y.getDistance() >= 0){
            //Q2
            returnVal = 3.14159265358979 - returnVal;
        }
        if(this->x.getDistance() < 0  && this->y.getDistance() < 0){
            //Q3
            returnVal = 3.14159265358979 + returnVal;
        }
        if(this->x.getDistance() > 0  && this->y.getDistance() < 0){
            //Q4
            returnVal = 2 * 3.14159265358979 - returnVal;
        }

        //return
        return Angle<long double, RadiansRatio>(returnVal);
    }
    public: Distance<A,B> getMagnitude(){
        A returnVal = this->x.getDistance() * this->x.getDistance();
        returnVal = returnVal + this->y.getDistance() * this->y.getDistance();
        returnVal = sqrtl(returnVal);
        return Distance<A, B>(returnVal);
    }

    //operators
    DistanceVector<A,B> operator+(const DistanceVector<A,B> &other) {
        return DistanceVector<A,B>(this->x + other.x, this->y + other.y);
    }
    DistanceVector<A,B> operator-(const DistanceVector<A,B> &other) {
        return DistanceVector<A,B>(this->x - other.x, this->y - other.y);
    }

    //converters
    public: DistanceVector<A,InchesRatio> toInches() {
        return DistanceVector<A,InchesRatio>(this->x.toInches(), this->y.toInches());
    }
    public: DistanceVector<A,FeetRatio> toFeet() {
        return DistanceVector<A,FeetRatio>(this->x.toFeet(), this->y.toFeet());
    }
};