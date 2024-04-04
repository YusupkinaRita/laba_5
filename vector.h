#include <iostream>
#include <math.h>

template<typename T>


class vector{
private:
T* _array;
size_t _size;

public:
    vector()=delete;
    vector(size_t size, T* array):_size(size), _array(new T[size]){
        for(int i=0;i<_size;i++){
            _array[i]=array[i];
        }

    }

    vector(size_t size):_size(size){
        _array=new T[size];
        for (int i=0; i<_size; i++){
            _array[i]=0;
        }
    }
    vector& operator=(const vector& tmp){
        if(tmp._size>_size){
            delete[]_array;
            _array=new T[tmp._size];

        }
        _size=tmp._size;
        for (size_t i=0; i<_size; i++){
            _array[i]=tmp._array[i];
        }
        return *this;
    }

    vector(const vector& tmp){
        _size=tmp._size;
        _array=new T[_size];
        for(size_t i=0; i<_size; i++){
            _array[i]=tmp._array[i];
        }

    }


    ~vector(){
        delete[] _array;
    }

    T& operator[](int i)const{

        return _array[i];
    }

    vector(std::initializer_list<T> list){
        _size=list.size();
        _array=new T[_size];
        int i=0;
        for(auto elem=list.begin();elem!=list.end();elem++, i++){
            _array[i]=*elem;
        }

    }



    vector operator+(const vector& vect)const{
        if(_size!=vect._size)
        throw "different sizes, cant add";
        vector vect1=vector(_size);
        for(int i=0; i<_size;i++){
            vect1._array[i]=vect._array[i]+_array[i];
        }
        
        return vect1;
        
    }

    vector operator-(const vector& vect)const{

       if(_size!=vect._size)
        throw "different sizes, cant substruct";
        vector vect1=vector(_size);
        for(int i=0; i<_size;i++){
            vect1[i]=vect._array[i]-_array[i];
        }

        return vect1;
    }

    vector operator*(double x)const{
        vector vect1=vector(_size);
        for(int i=0; i<_size;i++){
            vect1[i]=_array[i]*x;
        }

        return vect1;
        
    }

    double operator*(const vector& vect)const{
        double s=0;
        if(_size!=vect._size)
        throw "different sizes, cant substruct";
        for(int i=0;i<_size;i++){
            s+=_array[i]*_array[i];

        }
        return s;

    }



    double lenght(){
        double d=*this**this;
        return sqrt(d);

    }

    vector<double> normalise(){
        double l=lenght();
        for(int i=0;i<_size;i++){
            _array[i]=_array[i]/l;

        }
        return *this;

    }



    friend std::ostream& operator<<(std::ostream& os, const vector& vect){
        os<<"(";
        for(int i=0; i<vect._size;i++){
            os<<vect._array[i];

            if(i+1!=vect._size)
            os<<", ";

        }

        os<<")";
        return os;


    }









};