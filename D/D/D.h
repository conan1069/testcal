#ifndef D_H
#define D_H


double chu(double a, double b);


double chu(double a, double b){
	//以防除数和被除数为0
	if (a==0 || b == 0){
		return 0.0;
	}
	return a / b;
}

#endif