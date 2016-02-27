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
	private:
//常量数据成员的初始化必须在初始化列表里进行
//不能在构造函数中以赋值的形式进行
		const int _x;
		const int _y;
};

Point::Point(int x,int y)
:_x(x)
,_y(y)
{
	cout<<"Point(int,int)"<<endl;
//	_x = x;
//	_y = y;
}

Point::Point(const Point & rhs)
:_x(rhs._x)
,_y(rhs._y)
{
	cout<<"Point(const Point & rhs)"<<endl;
}

Point::~Point(){
	cout<<"~Point()"<<endl;
}

void Point::print(){
	cout<<"("<<_x<<" , "<<_y<<")"<<endl;
}


int main(void){
	Point xx(2,2);
	xx.print();
	cout<<"---------------"<<endl;
	Point yy = xx;
	yy.print();
	return 0;
}
