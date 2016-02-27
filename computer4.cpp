 ///
 /// @file    computer0.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-26 02:04:25
 ///
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer{
public:
	void setBrand(char * brand);
	void setPrice(int price);
	void print();
	Computer();
	Computer(const char * brand,int price);
#if 0
	Computer(const Computer & rhs)
	:_brand(rhs._brand)
	,_price(rhs._price)
	{
		cout<<"Computer(const Computer & rhs)(low)"<<endl;
	}
#endif

	Computer(const Computer & rhs)
	:_price(rhs._price)
	{
		cout<<"Computer(const Computer & rhs)(deep)"<<endl;
		int len = strlen(rhs._brand);
		_brand = new char(len + 1);
		strcpy(_brand,rhs._brand);
	}
	~Computer();
	
	Computer & operator = (const Computer & rhs){
		if(this == &rhs){
			return *this;
		}
		cout<<"Computer & operator = (const Computer & rhs)"<<endl;
		delete[] _brand;
		int len = strlen(rhs._brand);
		_brand = new char(len + 1);
		strcpy(_brand,rhs._brand);
		_price = rhs._price;
		return *this;
	}
private:
	char *_brand;
	int _price;
};

void Computer::setBrand(char * brand){
	strcpy(_brand,brand);
}

void Computer::setPrice(int price){
	_price = price;
}

void Computer::print(){
	cout<<"品牌："<<_brand<<endl;
	cout<<"价格："<<_price<<endl;
}
	
Computer::Computer(){
	cout<<"Computer()"<<endl;
	int len = strlen("lenove");
	_brand = new char[len + 1];
	strcpy(_brand,"lenove");
	_price = 3000;
}

Computer::Computer(const char * brand,int price){
	cout<<"Computer(char,int)"<<endl;
	int len = strlen(brand);
	_brand = new char[len + 1];
	strcpy(_brand,brand);
	_price = price;
}

Computer::~Computer(){
	cout<<"~Computer()"<<endl;
	delete [] _brand;
}
Computer pcc;
int test0(void){
	Computer pc1;
//	pc1.setBrand("dell");
//	pc1.setPrice(5000);
	pc1.print();
	{
		Computer com;
		com.print();
	
	}

	cout<<"----------------"<<endl;
	Computer pc2("ibm",10000);
	pc2.print();

	cout<<"----------------"<<endl;
	Computer *pc3 = new Computer("xp",1000);
	pc3->print();
	delete pc3;
	return 0;
}

int test1(void){
	Computer pc1;
	pc1.print();
	cout<<"---------------"<<endl;
	Computer pc2 = pc1;
	pc2.print();
	return 0;
}

int main(void){
	Computer pc1("alien",20000);
	pc1.print();
	Computer pc2;
	pc2.print();
	pc2 = pc1;
	pc2.print();
	return 0;
}
