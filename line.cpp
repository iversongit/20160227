 ///
 /// @file    line.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-27 01:25:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point{
	public:
		Point();
		Point(int x,int y);
		Point(const Point & rhs);
		~Point();
		void print();

	private:
		int _x;
		int _y;
};

Point::Point()
:_x(6)
,_y(6)
{
	cout<<"Point()"<<endl;
}

Point::Point(int x,int y)
:_x(x)
,_y(y)
{
	cout<<"Point(int,int)"<<endl;
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

class Line{
	public:
		Line(int x1,int x2,int y1,int y2);
		Line(const Line & rhs);
		void draw();
	private:
		Point _p1;
		Point _p2;
};
/*
 *如果不显式初始化Point对象_p1及_p2,系统
  会自动调用Point的默认构造函数去创建_p1,_p2
*/
Line::Line(int x1,int x2,int y1,int y2)
:_p1(x1,y1) //显式调用对象的有参构造函数
,_p2(x2,y2)
{
	cout<<"Line(int,int,int,int)"<<endl;
}

Line::Line(const Line & rhs)
:_p1(rhs._p1) //显式调用对象的拷贝构造函数
,_p2(rhs._p2)
{
	cout<<"Line(const Line & rhs)"<<endl;
}

void Line::draw(){
	_p1.print();
	cout<<" to ";
	_p2.print();
}
int main(void){
	Line line1(1,2,1,2);
	line1.draw();

	Line line2 = line1;
	line2.draw();

	return 0;
}
