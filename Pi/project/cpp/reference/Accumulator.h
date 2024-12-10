class Accumulator{
private :
    int value;
public :
    Accumulator(int value);
    Accumulator& add(int n);
    int get();
};