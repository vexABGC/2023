//definition
template <typename T>
class Vector2 {
    private: T x;
    private: T y;
    public: Vector2(T x, T y){
        this.x = x;
        this.y = y;
    }
    public: T getX(){
        return this.x;
    }
    public: T getY(){
        return this.y;
    }
};

//example
Vector2<int> testVector = new Vector2<int>(0, 1);