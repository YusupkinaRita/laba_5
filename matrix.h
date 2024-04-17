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

    matrix new_m(size_t y , size_t x){
        size_t temp1=y;
        size_t temp2=x;
        size_t s=_size-1;
        matrix m=matrix(s,s);
        for(size_t i=0;i<s;i++){
            x=temp2;
            if(i==y){
            for(size_t j=0; j<s;j++){
                if(x==j){
                    m[i][j]=_vectors[i+1][j+1];
                    x++;    
                }
                else 
                    m[i][j]=_vectors[i+1][j];
            
            }
            y++;
            }
            else{
                for(size_t j=0; j<s;j++){
                if(x==j){
                    m[i][j]=_vectors[i][j+1];
                    x++;    
                }
                else 
                    m[i][j]=_vectors[i][j];
            
            }

            }
        }
        return m;
    }

    T determinant(){
        if(_size!=_vectors[0].getsize())
        throw "different sizes";
        int sign=1;
        if (_size==1)
        return _vectors[0][0];
        if (_size==2){
        
        return _vectors[0][0]*_vectors[1][1]-_vectors[0][1]*_vectors[1][0];
        }
        else{
        T det=0;
            for(size_t i=0;i<_size;i++){
                det+=sign*_vectors[0][i]*new_m(0,i ).determinant();
                sign = -sign;
            }

            return det;
        }
    
    }


    matrix inverse_matrix(){
        T det=determinant();
        if (det==0)
        throw "inverse matrix doesnt exist";
        matrix m=matrix(_size, _size);
        for(size_t i=0;i<_size;i++){
            for(size_t j=0;j<_size;j++){
                m[i][j]=new_m(i,j).determinant();
                if((i+j)%2==1&&m[i][j]!=0)
                m[i][j]*=-1;
            }

        }
        matrix m1=m.transpose();
        double x=1.0/det;
        return m1*x;

    }

    matrix operator*(T x){
        matrix m=matrix(_size,_size);
        for(size_t i=0; i<_size;i++){
            for(size_t j=0; j<_size;j++){
                m[i][j]=_vectors[i][j]*x;
            
            }
        }
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