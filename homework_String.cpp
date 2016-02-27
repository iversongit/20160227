 ///
 /// @file    homework_String.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-27 02:47:00
 ///
#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;

class String{
	public:
		String();
		String(const char * pstr);
		String(const String & rhs);
		String & operator = (const String & rhs);
		~String();
		void print();
	private:
		char *pStr_;
};

String::String(){
	cout<<"String()"<<endl;
	int len = strlen("Default");
	pStr_ = new char[len + 1];
	strcpy(pStr_,"Default");
}

String::String(const char * pstr){
	cout<<"String(const char * pstr)"<<endl;
	int len = strlen(pstr);
	pStr_ = new char[len + 1];
	strcpy(pStr_,pstr);
}

String::String(const String & rhs){
	cout<<"String(const String & rhs)"<<endl;
	int len = strlen(rhs.pStr_);
	pStr_ = new char[len + 1];
	strcpy(pStr_,rhs.pStr_);
}

String & String::operator = (const String & rhs){
	if(this == &rhs){
		return *this;
	}
	cout<<"String & operator = (const String & rhs)"<<endl;
	delete[] pStr_;
	int len = strlen(rhs.pStr_);
	pStr_ = new char[len + 1];
	strcpy(pStr_,rhs.pStr_);
}

String::~String(){
	cout<<"~String()"<<endl;
	delete[] pStr_;
}

void String::print(){
	cout<<"*pStr_ :"<<pStr_<<endl;
}

int main(void){
	String str1;
	String str2 = "Hello,world";
	String str3 = "wangdao";
	str2 = str3;
	String str4 = str3;
	
	str1.print();
	str2.print();
	str3.print();
	str4.print();
	return 0;
}
