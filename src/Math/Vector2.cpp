#include "../src/Math/Vector2.hpp"
template <typename T>
Vector2<T>::Vector2(T xValue, T yValue){
    this.x = xValue;
    this.y = yValue;
}
template <typename T>
T Vector2<T>::getX(){
    return this.x;
}
template <typename T>
T Vector2<T>::getY(){
    return this.y;
}