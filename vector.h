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
        T*new_arr=new T[_size];
        for(int i=0; i<_size;i++){
            new_arr[i]=vect._array[i]+_array[i];
        }
        return vector(_size, new_arr);
        delete[] new_arr;
    }

    vector operator-(const vector& vect)const{

        T*new_arr=new T[_size];
        for(int i=0; i<_size;i++){
            new_arr[i]=vect._array[i]-_array[i];
        }
        return vector(_size, new_arr);
        delete[] new_arr;
    }

    vector operator*(double x)const{
        T*new_arr=new T[_size];
        for(int i=0; i<_size;i++){
            new_arr[i]=_array[i]*x;
        }

        return vector(_size, new_arr);
         delete[] new_arr;
    }

    double operator*(const vector& vect)const{
        double s=0;
        for(int i=0;i<_size;i++){
            s+=_array[i]*_array[i];

        }
        return s;

    }

    double operator_l()const{
        double s=0;
        for(int i=0;i<_size;i++){
            s+=_array[i]*_array[i];

        }
        return sqrt(s);

    }

    vector operator_n()const{
        double s=0;
        T*new_arr=new T[_size];
        for(int i=0;i<_size;i++){
            s+=_array[i]*_array[i];

        }
        s=sqrt(s);
        for(int i=0;i<_size;i++){
            new_arr[i]=_array[i]/s;

        }
        
        return vector(_size, new_arr);
        delete[] new_arr;

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