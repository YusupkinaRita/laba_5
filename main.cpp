#include <iostream>
#include "vector.h"
#include "matrix.h"


int main(){

    matrix<int> mat1=matrix<int>(3,3);
    mat1.fill();
    // matrix<int> mat2=matrix<int>(3,3);
    // mat2.fill();
    // matrix<int> mat3=matrix<int>(3,3);
    // mat3.fill();

    matrix<int> m=matrix<int>(3,3);
    m=mat1.new_m(1);

    // //std::cout<<mat3<<std::endl;
    // matrix<int> mat4=mat3.transpose();
    //matrix<int> res1=mat1+mat2;
    //matrix<int> res2=mat1-mat2;
    //matrix<int> res3=mat1*mat2;
    //int d=mat1.determinant();

    //std::cout<<mat1<<std::endl;
    std::cout<<m<<std::endl;
    //std::cout<<mat2<<std::endl;
    //std::cout<<mat4<<std::endl;
    //std::cout<<"+: "<<res1<<std::endl;
   // std::cout<<"-: "<<res2<<std::endl;
    //std::cout<<"*: "<<res3<<std::endl;
    


    return 0;
}