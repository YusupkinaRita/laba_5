#include <iostream>
#include "vector.h"


int main(){

    double* arr=new double[10]{
        1,2,3,4,5,6,7,8,9,10
    };

    vector<int> vec1={1,3,4,6,8};
    
    vector<int> vec2={1,3,4,6,8};


    vector<int> res1=vec1-vec2;

    vector<int> res2=vec1+vec2;
    vector<int> res3=vec1*3;
    double res4=vec1*vec2;
    //double res5=vec1_l;


    std::cout<<res1<<std::endl;
    std::cout<<res2<<std::endl;
    std::cout<<res3<<std::endl;
    std::cout<<res4<<std::endl;

    delete[]arr;


    return 0;
}