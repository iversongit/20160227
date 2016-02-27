 ///
 /// @file    nullpointercall.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-27 01:08:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Nullpointer{
	public:
		static void test1();
		void test2();
		void test3(int x);
		void test4();
	#if 0
		Nullpointer()
		:_x(0)
		{
			cout<<"Nullpointer"<<endl;
		}
	#endif
	private:
		static int _xx;
		int _x;
};

int Nullpointer::_xx = 0;

void Nullpointer::test1(){
	cout<<"test1 static _xx:"<<_xx<<endl;
}

void Nullpointer::test2(){
	cout<<"test2() :"<<endl;
}

void Nullpointer::test3(int x){
	cout<<"test3(int) :"<<x<<endl;
}

//对于静态成员函数而言，没有this指针的概念
//而对于非静态成员函数而言，第一个参数是隐藏的this
//指针
void Nullpointer::test4(){
	cout<<"test4() :"<<_x<<endl;
}

int main(void){
	Nullpointer p;
	p.test1();
	p.test2();
	p.test3(3);
	p.test4();
	cout<<"----------------------"<<endl;
	Nullpointer *p1 = NULL;
	p1->test1();
	p1->test2();
	p1->test3(3);
	p1->test4();
	return 0;
}
