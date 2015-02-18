
class ArrayWrapper{
friend std::ostream & operator << (std::ostream &o, const ArrayWrapper &);
public:
       
       ArrayWrapper();
       ArrayWrapper(int *array, int size, int capacity=10);
       ArrayWrapper(const ArrayWrapper &other);
       int getSize() const;
       int getCapacity() const;
       void changeCapacity(int newCapacity);
       int operator [] (int position) const;
       int & operator [] (int position);
       ArrayWrapper & operator=(const ArrayWrapper &ob);
       ~ArrayWrapper();
       
       
       
private:
       int * _array;
       int size;
       int capacity;        
};
