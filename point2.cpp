 ///
 /// @file    point1.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-26 22:47:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point{
	public:
		Point(int x,int y);
		Point(const Point & rhs);
		~Point();
		void print();
		void setX(int x);
	private:
//常量类型的数据成员的初始化必须在初始化列表里进行
//不能在构造函数中以赋值的形式进行
//		const int _x;
//		const int _y;

//引用类型的数据成员的初始化必须在初始化列表里进行
//不能再构造函数中以赋值的形式进行
		int _x;
		int _y;
		int & _ref1;
		int & _ref2;
};

Point::Point(int x,int y)
:_x(x)
,_y(y)
,_ref1(_x)
,_ref2(_y)
{
	cout<<"Point(int,int)"<<endl;
//	_ref1 = x;
//	_ref2 = y;
}

Point::Point(const Point & rhs)
:_x(rhs._x)
,_y(rhs._y)
,_ref1(rhs._ref1)
,_ref2(rhs._ref2)
{
	cout<<"Point(const Point & rhs)"<<endl;
}

Point::~Point(){
	cout<<"~Point()"<<endl;
}

void Point::print(){
	cout<<"("<<_x<<" , "<<_y<<" , " <<_ref1<<" , "<<_ref2<<")"<<endl;
}

void Point::setX(int x){
	_x = x;
}

int main(void){
	Point xx(4,5);
	xx.print();
	cout<<"---------------"<<endl;
	Point yy = xx;
	yy.print();
	cout<<"******after reset x*********"<<endl;
	xx.setX(10);
	xx.print();
	yy.print();
	return 0;
}
