 ///
 /// @file    computer.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-26 20:52:00
 ///
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer{
	public:
		Computer(const char * brand,int price);
		~Computer();
//静态成员函数不含this指针，不能直接使用非静态成员
//数据，但可以通过类名进行调用
		static void print(Computer & pc);
		static void totalprice();
	private:
		char * _brand;
		int _price;
		static int _totalprice;
};

int Computer::_totalprice = 0;
//类中的静态成员变量要在类外初始化
Computer::Computer(const char * brand,int price)
:_price(price)
{
	cout<<"Computer(int)"<<endl;
	_brand = new char[strlen(brand)+1];
	strcpy(_brand,brand);
	_totalprice += _price;
}

Computer::~Computer(){
	cout<<"~Computer()"<<endl;
	_totalprice -= _price;
	print(*this);
	delete[] _brand;
}

void Computer::print(Computer & pc){
	cout<<"品牌: "<<pc._brand<<endl;
	cout<<"单价: "<<pc._price<<endl;
	cout<<"总价: "<<_totalprice<<endl;
}

void Computer::totalprice(){
//	cout<<_brand<<endl;
	cout<<"总价："<<_totalprice<<endl;
}

int main(void){
	Computer pc1("mac",15000);
	cout<<"after buy pc1"<<endl;
	pc1.print(pc1);
	pc1.totalprice();

	Computer pc2("hp",10000);
	cout<<"after buy pc2"<<endl;
	pc2.print(pc2);
	pc2.totalprice();
		

//类中的静态成员变量位于全局/静态区，不占类或对象
//的存储空间

//	cout<<"pc1的存储空间："<<sizeof(pc1)<<endl;
//	cout<<"Computer的存储空间: "<<sizeof(Computer)<<endl;
	return 0;
}
