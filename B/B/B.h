#ifndef B_H
#define B_H

//条件编译指令
/*
	#ifndef如果没有定义 
	#ifdef 如果定义了
	_declspec(dllexport)  导出函数
	_declspec(dllimport)  导入函数
	#define DLLAPI _declspec(dllexport)   声明使用DLLAPI代替_declspec(dllexport)
*/
#ifdef _DLLAPI
	#define DLLAPI _declspec(dllexport)
#else
	#define DLLAPI _declspec(dllimport)
#endif


//声明导出函数  使用extern "C" 告诉编译器要使用C语言的方式去编译
extern "C" DLLAPI int sub(int a, int b);

extern "C" DLLAPI int sub(int a, int b);

#endif