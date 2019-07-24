template <typename T>
struct Eye {
    void open() { return static_cast<T *>(this)->open_eye();}
};

struct Cyclop : public Eye<Cyclop> {
    void open_eye() {};
};

template <typename T>
void look_for_banana(Eye<T> *eye){
    eye->open();
}

int main()
{
    Cyclop *cyclop = new Cyclop();
    
    look_for_banana(cyclop);
    
    delete cyclop;
    
    return 0;
}