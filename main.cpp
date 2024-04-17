#include <iostream>
#include "vector.h"
#include "matrix.h"
#include <random>


int main(){
  srand(time(NULL));
    vector vec1={2,-2,-3};
    vector vec2={4,0,6};
    matrix<double> mat1=matrix<double>(3,3);
    mat1.fill();
    matrix<double> mat2=matrix<double>(3,3);
    mat2.fill();
    std::cout<<mat1<<std::endl;
    //matrix<double> m=mat1.inverse_matrix();
    //matrix<int> mat4=mat3.transpose();
    //matrix<int> res1=mat1+mat2;
    //matrix<int> res2=mat1-mat2;
    //matrix<double> res3=mat1*mat2;
    //int d=mat1.determinant();


    vector<int> vec_product=vec1*vec2;
    
    //std::cout<<m<<std::endl;
  // std::cout<<mat4<<std::endl;
   // std::cout<<"+: "<<res1<<std::endl;
   // std::cout<<"-: "<<res2<<std::endl;
    //std::cout<<"*: "<<res3<<std::endl;
    //std::cout<<d<<std::endl;
    std::cout<<vec_product<<std::endl;

    


    return 0;
}