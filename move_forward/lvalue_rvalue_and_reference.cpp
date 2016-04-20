#include<iostream>
using namespace std;

template<typename T>
int function(T && t){
	cout << "function(t) = "<<t<<endl;
	return t;
}

int test(int &&t){
	return t;
}
 
int main(int argc, char ** argv){
	int lvalue = 1;
	cout<<"lvalue="<<lvalue<<endl;

	int && a = 1; // compile successfully, because we can assign pure-rvalue (pvalue) to rvalue-reference
	cout<<"after int &&a = 1, a ="<<a<<endl;

 	//int & b = 1; //this will have compile error, because rvalue can not assign to non const lvalue-referrence
	//cout<<"after int &b = 1, b = "<<b<<endl;

	int const & c = 1;
	cout<<"after int const& c =1, c="<<c<<endl;

	//int && d = lvalue; // this will hvae compile error, because lvalue can not assign to rvalue-reference direcly
	//cout<<"after int &&d = lvalue, d ="<<endl;

	auto func = [](int && t)->int{ return t;}; 
	
	// compile error
        // because lvalue can as the real-prama when the function parama type is rvalue-reference
	//cout<<"func=[](int && t){ return t;}, func(lvalue)="<<func(lvalue)<<endl;

        //int& lvalue_reference = lvalue;
	//cout << func(lvalue_reference)<<endl;//compile error
	
	//cout << func(c) <<endl; // compile error even if using const lvalue-reference as the real parama
	cout << "int & is lavlue reference?"<<is_lvalue_reference<int &>::value<<endl;
	cout << "int && is rvalue reference?"<<is_rvalue_reference<int &&>::value<<endl;
	//cout <<func(a)<<endl; //compile error

	function(lvalue);
	//func(lvalue);
	//func(a);  //compile error , cann't use rvalue-reference in the lamada function
	func(move(lvalue));

	cout<<"function(lvalue)="<<function(lvalue)<<endl;
	cout<<"function(const lvalue reference) ="<<function(c)<<endl;
	cout<<"function(prvalue-reference) = "<<function(a)<<endl;;
	
	//test(lvalue);
	//test(a);// compile error
	test(move(lvalue));	
	test(move(a));
}
