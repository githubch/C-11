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
    int m = 2;
    int n = 3;
    std::cout <<"Max_(m, n)="<<Max_(m++, n++)<<std::endl;
    std::cout <<"m="<<m<<std::endl;
    std::cout <<"n="<<n<<std::endl;
}
