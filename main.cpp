#include <iostream>
#include "vector.h"
#include "matrix.h"
#include <random>


int main(){
  srand(time(NULL));

    vector<double> vec1={1,3,4,6,8};
    matrix<double> mat1=matrix<double>(3,3);
    mat1.fill();
    matrix<int> mat2=matrix<int>(3,3);
    mat2.fill();
    std::cout<<mat1<<std::endl;
    matrix<double> m=mat1.inverse_matrix();
    //matrix<int> mat3=matrix<int>(3,3);
    //std::cout<<mat3<<std::endl;
    //matrix<int> mat4=mat3.transpose();
    //matrix<int> res1=mat1+mat2;
    //matrix<int> res2=mat1-mat2;
    matrix<double> res3=mat1*0.5;
    //int d=mat1.determinant();

    std::cout<<m<<std::endl;
    //std::cout<<m<<std::endl;
  // std::cout<<mat4<<std::endl;
   // std::cout<<"+: "<<res1<<std::endl;
   // std::cout<<"-: "<<res2<<std::endl;
    std::cout<<"*: "<<res3<<std::endl;
    


    return 0;
}