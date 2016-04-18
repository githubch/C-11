#include<iostream>
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Max_(a,b) ({ \
        auto _a = (a); \
	auto _b = (b); \
	(_a > _b) ? _a:_b;})\

 
int main(int argc, char ** argv){
    int a = 2;
    int b = 3;
    std::cout <<"Max(a, b)="<<Max(a,b)<<std::endl;
    std::cout <<"3 * Max(a, b) should equal 9, and the result is "<<3*Max(a, b)<<std::endl;
    auto result = [=](){ return 4 * Max(a, b);};
    std::cout<<result()<<std::endl;
    std::cout <<"4 * Max(2, 3) should equal 12, and the result is "<<[=](){return 4*Max(a,b);}()<<std::endl;
    std::cout <<"5 * Max(2, 3) should equal 15, and the result is "<<[=]()->float{return 5*Max(a, b)*1.0;}()<<std::endl;
    int m = 2;
    int n = 3;
    std::cout <<"Max_(m, n)="<<Max_(m++, n++)<<std::endl;
    std::cout <<"m="<<m<<std::endl;
    std::cout <<"n="<<n<<std::endl;
}
