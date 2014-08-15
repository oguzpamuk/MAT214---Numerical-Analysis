/*
	* Sayisal Analiz HW06
	* 111044053
	* Oguzcan Pamuk
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*Analitik*/
double func(const double x);
/*Verilen fonksiyon(Turevli verilmis)*/
double funcDiff(const double x, const double y);
/*Euler Methodu*/
double eulerMethod(const int x_begin, const double y_begin, const double h, const int x_end);
/*Heun Methodu*/
double heunMethod(const int x_begin, const double y_begin, const double h, const int x_end);
/*Range Kutta 2 Methodu*/
double runge_kutta2Method(const int x_begin, const double y_begin, const double h, const int x_end);
/*Range Kutta 4 Methodu*/
double runge_kutta4Method(const int x_begin, const double y_begin, const double h, const int x_end);



int main()
{
	int i=0;

	printf("-----HW06-----\n");

	/******************************************/

	printf("----------------------------\n");

	printf("Analitik Method\n");
	printf("x=0 && x=10 araligi icin tum sonuclari\n");

	for(i=0;i<11;i++){
		printf("x=%d icin analitik :%5lf \n",i,func(i));
	}
		
	printf("----------------------------\n");

	printf("Euler Methodu\n");
	printf("h = 1   : %.5lf\n", eulerMethod(0, 1.0, 1, 10));
	printf("h = 0.5 : %.5lf\n", eulerMethod(0, 1.0, 0.5, 10));
	printf("h = 0.1 : %.5lf\n", eulerMethod(0, 1.0, 0.1, 10));

	printf("----------------------------\n");

	printf("Heun Methodu\n");
	printf("h = 1   : %.5lf\n", heunMethod(0, 1.0, 1, 10));
	printf("h = 0.5 : %.5lf\n", heunMethod(0, 1.0, 0.5, 10));
	printf("h = 0.1 : %.5lf\n", heunMethod(0, 1.0, 0.1, 10));
	
	printf("----------------------------\n");

	printf("Runge Kutta 2 Methodu\n");
	printf("h = 1   : %.5lf\n", runge_kutta2Method(0, 1.0, 1, 10));
	printf("h = 0.5 : %.5lf\n", runge_kutta2Method(0, 1.0, 0.5, 10));
	printf("h = 0.1 : %.5lf\n", runge_kutta2Method(0, 1.0, 0.1, 10));
	
	printf("----------------------------\n");

	printf("Runge Kutta 4 Methodu\n");
	printf("h = 1   : %.5lf\n", runge_kutta4Method(0, 1.0, 1, 10));
	printf("h = 0.5 : %.5lf\n", runge_kutta4Method(0, 1.0, 0.5, 10));
	printf("h = 0.1 : %.5lf\n", runge_kutta4Method(0, 1.0, 0.1, 10));

	printf("----------------------------\n");

	/******************************************/

	

	return 0;
}

/******************************************/
double func(const double x){
	return(exp(pow(x,3)-x));
}
/******************************************/
double funcDiff(const double x, const double y)
{
	return((y * pow(x, 2)) - y);
}
/******************************************/
double eulerMethod(const int x_begin, const double y_begin, const double h, const int x_end)
{
	double y_old = y_begin;
	int index = x_begin;
	double y_new = 0.0;

	while (index < x_end) {

		y_new = y_begin + (funcDiff(index, y_old) * h);
		y_old = y_new;
		++index;
	}

	return y_old;

}
/******************************************/
double heunMethod(const int x_begin, const double y_begin, const double h, const int x_end)
{
	double y_old = y_begin;
	int index = x_begin;
	double y_new_zero = 0.0;
	double y_new = 0.0;

	while (index < x_end) {

		y_new_zero = y_old + (funcDiff(index, y_old) * h);

		y_new = (y_old + (((funcDiff(index, y_old) + funcDiff(index + 1, y_new_zero)) / 2.0) * h));

		y_old = y_new;
		++index;
	}

	return y_old;

}
/******************************************/
double runge_kutta2Method(const int x_begin, const double y_begin, const double h, const int x_end)
{
	double y_old = y_begin;
	double index = x_begin;
	double y_new = 0.0;

	double k1 = 0.0, k2 = 0.0;

	while (index < x_end) {
		k1 = funcDiff(index, y_old);
		k2 = funcDiff(index + (0.5 * h), y_old + (0.5 * k1 * h));

		y_new = (y_old + ((1.0 / 2.0) * ((k1 + k2) * h)));

		y_old = y_new;

		++index;
	}
	
	return y_old;

}
/******************************************/
double runge_kutta4Method(const int x_begin, const double y_begin, const double h, const int x_end)
{
	double y_old = y_begin;
	double index = x_begin;
	double y_new = 0.0;

	double k1 = 0.0, k2 = 0.0, k3 = 0.0, k4 = 0.0;

	while (index < x_end) {
		k1 = funcDiff(index, y_old);
		k2 = funcDiff(index + (0.5 * h), y_old + (0.5 * k1 * h));
		k3 = funcDiff(index + (0.5 * h), y_old + (0.5 * k2 * h));
		k4 = funcDiff(index + h, y_old + (k3 * h));

		y_new = (y_old + ((1.0 / 6.0) * ((k1 + (2 * k2) + (2 * k3) + k4) * h)));

		y_old = y_new;

		++index;
	}
	
	return y_old;

}

/******************************************/
