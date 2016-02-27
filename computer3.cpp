 ///
 /// @file    computer.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-26 20:52:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Computer{
	public:
		Computer(int price);
		~Computer();
//const成员函数不能修改对象的数据成员，只能读
		void print() const;
	private:
		int _price;
		static int _totalprice;
};

int Computer::_totalprice = 0;
//类中的静态成员变量要在类外初始化
Computer::Computer(int price)
:_price(price)
{
	cout<<"Computer(int)"<<endl;
	_totalprice += _price;
}

Computer::~Computer(){
	cout<<"~Computer()"<<endl;
	_totalprice -= _price;
	print();
}

void Computer::print() const
{
//	_price = 5;
	cout<<"单价: "<<_price<<endl;
	cout<<"总价: "<<_totalprice<<endl;
}

int main(void){
	Computer pc1(5000);
	cout<<"after buy pc1"<<endl;
	pc1.print();

	Computer pc2(10000);
	cout<<"after buy pc2"<<endl;
	pc2.print();

//类中的静态成员变量位于全局/静态区，不占类或对象
//的存储空间

//	cout<<"pc1的存储空间："<<sizeof(pc1)<<endl;
//	cout<<"Computer的存储空间: "<<sizeof(Computer)<<endl;
	return 0;
}
