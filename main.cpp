#include <iostream>
#include "vector.h"
#include "matrix.h"


int main(){

    double* arr=new double[10]{
        1,2,3,4,5,6,7,8,9,10
    };

    vector<double> vec1={1,3,4,6,8};
    
    vector<double> vec2={1,3,4,6,8};
    matrix<int> mat1=matrix<int>(3,3);
    mat1.fill();
    matrix<int> mat2=matrix<int>(3,3);
    mat2.fill();
    matrix<int> mat3=matrix<int>(3,4);
    mat3.fill();
    std::cout<<mat3<<std::endl;
    matrix<int> mat4=mat3.transpose();
    matrix<int> res1=mat1+mat2;
    matrix<int> res2=mat1-mat2;
    matrix<int> res3=mat1*mat2;

    std::cout<<mat1<<std::endl;
    std::cout<<mat2<<std::endl;
    std::cout<<mat4<<std::endl;
    std::cout<<"+: "<<res1<<std::endl;
    std::cout<<"-: "<<res2<<std::endl;
    std::cout<<"*: "<<res3<<std::endl;
    


    return 0;
}