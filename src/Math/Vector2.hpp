template <typename T>
class Vector2 {
    private: T x;
    private: T y;
    public: Vector2(T xValue, T yValue){
        x = xValue;
        y = yValue;
    }
    public: T getX(){
        return x;
    }
    public: T getY(){
        return y;
    }
};