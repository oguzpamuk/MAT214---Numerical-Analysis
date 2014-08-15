/*
	*
	*Sayisal Analiz HW04
	*Author : Oguzcan Pamuk
	*Number : 111044053
	*
*/

#include<stdio.h>
/*Langrange Fonksiyonu*/
double langrange(double valueX[],double valueY[],double value);

int main()
{
	/*Sonuclar*/
	double lagrangeResult1,lagrangeResult2=0.0;
	/*Fonksiyonlarda kullanilacak x degeleri ve hocanin verdigi x-y degerleri*/
    double valueX[5]={40,50,60,70,80};	
    double valueY[5]={1.66,1.41,1.22,1.06,0.93};
    double x[2]={62,120};
	
	printf("--Lagrange Interpolasyon--\n");
	/*x=62 icin*/
    lagrangeResult1=langrange(valueX, valueY, x[0]);
    /*x=120 icin*/
    lagrangeResult2=langrange(valueX, valueY, x[1]);
	printf("1.deger: %f\n",lagrangeResult1);
	printf("2.deger: %f\n",lagrangeResult2);
	/*windows da sonuclari gorebilmek icin*/
    getchar();
	return 0;
}

/*Langrange Fonksiyonlari*/
double langrange(double valueX[],double valueY[],double value)
{
    /*counterlar tanimlandi*/
	int counter1,counter2=0;
	/*Langrange carpani*/
	double multiplier=1;
	/*Toplamlari saklar ve return edilir*/
    double total=0;

	for(counter1=0;counter1<5;counter1++)
	{
        for(counter2=0;counter2<5;counter2++)
            if(counter1!=counter2)
                multiplier*=(value-valueX[counter2])/(valueX[counter1]-valueX[counter2]);

        multiplier*=valueY[counter1];
        /*Carpimlar bulunduktan sonra total e atilir*/
        total+=multiplier;
        multiplier=1;
	}

    /*Carpimlarin toplami return ediliyor*/
	return total;
}

