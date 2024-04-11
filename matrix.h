#pragma once
#include "vector.h"
#include <random>



template <typename T>

class matrix{
private:

    vector<T>* _vectors;
    size_t _size;
public:
    matrix()=delete;
    matrix(size_t rows, size_t cols){
        _size=rows;
        _vectors=new vector<T>[_size];
        for(size_t i=0;i<_size;i++){
            _vectors[i]=vector<T>(cols);
        }
    }

    ~matrix(){
        delete[]_vectors;
    }

    const vector<T>& operator[](int index)const{

        return _vectors[index];

    }


    vector<T>& operator[](int index){

        return _vectors[index];
    }

    void fill(){
        size_t s=_vectors[0].getsize();
        for(size_t i=0;i<_size;i++){
            for(size_t j=0;j<s;j++){
                _vectors[i][j]=rand()%10;
            
            }
        }
    }

    matrix transpose(){
        size_t s=_vectors[0].getsize();
        size_t size_col=_size;
        _size=s;
        matrix mat=matrix(_size, size_col);
        for(size_t i=0;i<_size;i++){
            for(size_t j=0;j<size_col;j++){
                mat[i][j]=_vectors[j][i];

            }
            
        }
        return mat;


    }

   matrix new_m(size_t x){
        size_t s=_size-1;
        matrix m=matrix(s,s);
        for(size_t i=0;i<s;i++){
            for(size_t j=0; j<s;j++){
                if(x!=j)
                    m[i][j]=2;//_vectors[i+1][j];
                else 
                    m[i][j]=2;//_vectors[i+1][j+1];
            }
        }
        std::cout<<m<<std::endl;
        return m;

   } 
   
    





    matrix operator+(const matrix& matr)const{
        size_t s=_vectors[0].getsize();
        size_t s1=matr._vectors[0].getsize();
        if(_size!=matr._size||s!=s1)
        throw "sizes are different";
        matrix mat=matrix(_size,s);
        for(size_t i=0; i<_size; i++){
            for(size_t j=0; j<s;j++){
                mat[i][j]=_vectors[i][j]+matr[i][j];
            
            }

        }
        return mat;
    }

    matrix operator-(const matrix& matr)const{
        size_t s=_vectors[0].getsize();
        size_t s1=matr._vectors[0].getsize();
        if(_size!=matr._size||s!=s1)
        throw "sizes are different";
        matrix mat=matrix(_size,s);
        for(size_t i=0; i<_size; i++){
            for(size_t j=0; j<s;j++){
                mat[i][j]=_vectors[i][j]-matr[i][j];
            
            }

        }
        return mat;
    }

    matrix operator*(const matrix& matr)const{
        size_t s=_vectors[0].getsize();
        size_t s1=matr._vectors[0].getsize();
        if(s!=matr._size)
        throw "sizes are different";
        matrix mat=matrix(_size,s1);
        for(size_t i=0; i<_size; i++){
            for(size_t j=0; j<s1;j++){
                for(int k=0; k<_size; k++){
                int temp = _vectors[i][k]*matr[k][j];
                mat[i][j] += temp;
                temp = 0;
                }
            
            }

        }
        return mat;
    }



    friend std::ostream& operator<<(std::ostream& os, const matrix& matr){
        for(size_t i=0; i<matr._size;i++){
            os<<matr._vectors[i]<<std::endl;
        }
        return os;
    }




};