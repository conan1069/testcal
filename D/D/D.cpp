#include "D.h"
#include "../../A/A/A.h"
#include "../../B/B/B.h" //隐式调用 需要将相关.dll文件拖至此exe文件下
#include "../../C/C/C.h" 
#include <Windows.h> //LoadLibrary是Windows.h库里的
#include <stdio.h>  

typedef int (*PMUL)(int a, int b); //定义指针指向mul

double chu(double a, double b){	
	return a / b;
}

int main(){

	printf("请输入两个整数：");
	int a, b;
	double shang = 0.0;
	scanf("%d%d", &a, &b);

	int sum = add(a, b);
	int cha = sub(a, b);

	//加载乘法.dll文件  动态加载
	//L:表示使用宽字符串  
	HMODULE hDll = LoadLibrary(L"../../C/Debug/C.dll");
	if (hDll == NULL){
		printf("加载乘法DLL文件失败。\n");
		return 0;
	}
	//获取模块中函数地址（指针）  返回一个函数指针
	PMUL pMul = (PMUL)GetProcAddress(hDll, "mul");

	//调用 乘法 接口
	int ji = pMul(a, b);
	
	printf("%d + %d = %d\n", a, b, sum);
	printf("%d - %d = %d\n", a, b, cha);
	printf("%d * %d = %d\n", a, b, ji);
	
	//除数为0时给提示
	if (b == 0){
		printf("除法有错误By Zero！\n");
	}
	else{
		shang = chu(a, b);
		printf("%d / %d = %lf\n", a, b, shang);
	}

	//释放库
	FreeLibrary(hDll);

	system("pause");
	return 0;
}