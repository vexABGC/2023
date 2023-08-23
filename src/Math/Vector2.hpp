template <typename T>
class Vector2{
    private: T x;
    private: T y;
    public: Vector2(T xValue, T yValue){
        this->x = xValue;
        this->y = yValue;
    }
    public: T getX(){
        return this->x;
    }
    public: T getY(){
        return this->y;
    }
};