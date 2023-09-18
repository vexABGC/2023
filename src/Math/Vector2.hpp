template <typename T>
class Vector2{
    private: T x;
    private: T y;
    public: Vector2(T xValue, T yValue){
        this->x = xValue;
        this->y = yValue;
    }
    public: void add(T valueX, T valueY){
        this->x += valueX;
        this->y += valueY;
    }
    public: void add(T value){
        this->x += value;
        this->y += value;
    }
    public: void setX(T value){
        this->x = value;
    }
    public: void setY(T value){
        this->y = value;
    }
    public: T getX(){
        return this->x;
    }
    public: T getY(){
        return this->y;
    }
};