 ///
 /// @file    class_struct.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-26 20:45:06
 ///
 
#include <iostream>

/*
 *	struct与class的区别：
 *		struct内成员的默认访问权限为public
 *		而class内成员的默认访问权限为private
 * 
*/

struct A{
	int num;
};

class B{
	int num;	
};

int main(void){
	A aa;
	aa.num = 0;
	B bb;
//	bb.num = 1;
	return 0;
}
