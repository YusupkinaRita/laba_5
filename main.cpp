#include <iostream>
#include "vector.h"


int main(){


    vector<double> vec1={1,3,4,6,8, 6};
    std::cout<<vec1<<std::endl;
    
    vector<double> vec2={1,3,4,6,8};
    vector<double> res2(5);
    try
    {
        res2=vec1-vec2;
    }
    catch(const char* s){
        std::cout<<"hyfnnjununuy";
    }


    vector<double> res1=vec1+vec2;
    vector<double> res3=vec1*3;
    double res4=vec1*vec2;
    double res5=vec1.lenght();
    vector<double> res6=vec1.normalise();


    std::cout<<res1<<std::endl;
    //std::cout<<"-: "<<res2<<std::endl;
    std::cout<<"*: "<<res3<<std::endl;
    std::cout<<"vectors *: "<<res4<<std::endl;
    std::cout<<"lenght: "<<res5<<std::endl;
    std::cout<<"norm: "<<res6<<std::endl;

    


    return 0;
}