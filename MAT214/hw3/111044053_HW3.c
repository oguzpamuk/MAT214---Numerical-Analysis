/*
	*Sayisal Analiz
	*HW03_111044053
	*Oguzcan PAMUK
*/

/*Program regresyon katsayilarini hesapla en iyi temsil eden lineer fonksiyonu buluyor*/
/*Her fonksiyonun ne gorev yaptigi fonksiyonlar uzerinde gosterilmistir*/
/*0<=r<=1 mantigiyla hareket edildiginde, 
  1 e en yakin fonksiyon en iyi temsil eden fonksiyon olur*/

#include <stdio.h>
#include <math.h>

#define SIZE 10
#define N 10


/*x ve y lerin ayri ayri toplamlarini bulmak icin kullaniyoruz*/
/*Ayrica ortalama alirken isimize yarayacak*/
double findSumXorY(double value[],int size);
/*st degiskenini bulan fonksiyon*/
double findST(double value[],int size);
/*x.y lerin toplami*/
double findSumXY(double valueX[],double valueY[],int size);
/*x elemanlarinin karelerinin toplamini bulan fonksiyon*/
double findSumX2(double valueX[],int size);
/*sr degiskenini bulan fonksiyon*/
double findSR(double valueX[],double valueY[],int size,double a0,double a1);
/*r degiskenini bulan fonksiyonlar 0<=r<=1 */
double findR1(double valueX[],double valueY[],int size,int n);
double findR2(double valueX[],double valueY[],int size,int n);
double findR3(double valueX[],double valueY[],int size,int n);
double findR4(double valueX[],double valueY[],int size,int n);
double findR5(double valueX[],double valueY[],int size,int n);
int main()
{
	/*verilen degerleri tutan array*/
	double valueX[]={2.5,3.5,5,6,7.5,10,12.5,15,17.5,20};
	double valueY[]={5,3.4,2,1.6,1.2,0.8,0.6,0.4,0.3,0.3};
	
	/*Ekran ciktilari*/
	printf("(a0+a1x)denklem 1 icin : %f\n",findR1(valueX,valueY,SIZE,N));
	printf("(A*XuzeriB)denklem 2 icin : %f\n",findR2(valueX,valueY,SIZE,N));
	printf("(A*e uzeri B*X)denklem 3 icin : %f\n",findR3(valueX,valueY,SIZE,N));
	printf("(A/BX+C)denklem 4 icin : %f\n",findR4(valueX,valueY,SIZE,N));
	printf("(a0+a1x...+a5xuzeri5)denklem 5 icin : %f\n",findR5(valueX,valueY,SIZE,N));

	printf("1 e en yakin fonksiyon en ideal fonksiyon olur\n");
	

	return 0;
}
/*x ve y lerin ayri ayri toplamlarini bulmak icin kullaniyoruz*/
double findSumXorY(double value[],int size){
	int i=0;
	double total=0;
	
	for(i=0;i<size;i++){
		total+=value[i];
	}
	return (total);
}
/*st degiskenini bulan fonksiyon*/
double findST(double value[],int size){
	int i=0;
	double total=0;
	double average=findSumXorY(value,size)/size;
	
	for(i=0;i<size;i++){
		total+=pow(value[i]-average,2);
	}

	return total;	
}
/*x.y lerin toplami*/
double findSumXY(double valueX[],double valueY[],int size){
	int i=0;
	double total=0;
	
	for(i=0;i<size;i++){
		total+=valueX[i]*valueY[i];
	}

	return total;	
}
/*x elemanlarinin karelerinin toplamini bulan fonksiyon*/
double findSumX2(double valueX[],int size){
	int i=0;
	double total=0;
	
	for(i=0;i<size;i++){
		total+=pow(valueX[i],2);
	}

	return total;	
}
/*sr degiskenini bulan fonksiyon*/
double findSR(double valueX[],double valueY[],int size,double a0,double a1){
	int i=0;
	double total=0.0;
	for(i=0;i<size;i++){
		total+=pow(valueY[i]-a0-(a1*valueX[i]),2);
	}
	
	return total;
}
/*r degiskenini bulan fonksiyonlar 0<=r<=1 */
/*1 denklem icin*/
double findR1(double valueX[],double valueY[],int size,int n){
	double detA=0.0;
	double a0,a1=0.0;
	double sr,st=0.0;

	/*determinant bulalim*/
	detA=findSumX2(valueX,size)*n-(findSumXorY(valueX,size)*findSumXorY(valueX,size));

	/*a0 i bulalim*/
	a0=(findSumXorY(valueY,size)*(findSumX2(valueX,size)/detA))-((findSumXorY(valueX,size)/detA)*findSumXY(valueX,valueY,size));
	
	/*a1 i bulalim*/
	a1=((-findSumXorY(valueX,size)/detA)*findSumXorY(valueY,size))+((n/detA)*findSumXY(valueX,valueY,size));
	
	sr=findSR(valueX,valueY,size,a0,a1);
	st=findST(valueY,size);

	return(sqrt((st-sr)/st));
}

/*2 denklem icin*/
double findR2(double valueX[],double valueY[],int size,int n){
	double detA=0.0;
	double a0,a1=0.0;
	double sr,st=0.0;
	int i=0;
	double tempY[SIZE];
	double tempX[SIZE];

	/*x ve y leri kendi fonksiyonumuza gore degistirelim*/
	for(i=0;i<size;i++){
		tempX[i]=log10(valueX[i]);
		tempY[i]=log10(valueY[i]);
	}

	/*determinant bulalim*/
	detA=findSumX2(tempX,size)*n-(findSumXorY(tempX,size)*findSumXorY(tempX,size));

	/*a0 i bulalim*/
	a0=(findSumXorY(tempY,size)*(findSumX2(tempX,size)/detA))-((findSumXorY(tempX,size)/detA)*findSumXY(tempX,tempY,size));
	
	/*a1 i bulalim*/
	a1=((-findSumXorY(tempX,size)/detA)*findSumXorY(tempY,size))+((n/detA)*findSumXY(tempX,tempY,size));
	
	sr=findSR(tempX,tempY,size,a0,a1);
	st=findST(tempY,size);

	return(sqrt((st-sr)/st));
}

/*3 denklem icin*/
double findR3(double valueX[],double valueY[],int size,int n){
	double detA=0.0;
	double a0,a1=0.0;
	double sr,st=0.0;
	int i=0;
	double tempY[SIZE];

	/*x ve y leri kendi fonksiyonumuza gore degistirelim*/
	for(i=0;i<size;i++){
		tempY[i]=log10(valueY[i]);
	}

	/*determinant bulalim*/
	detA=findSumX2(valueX,size)*n-(findSumXorY(valueX,size)*findSumXorY(valueX,size));

	/*a0 i bulalim*/
	a0=(findSumXorY(tempY,size)*(findSumX2(valueX,size)/detA))-((findSumXorY(valueX,size)/detA)*findSumXY(valueX,tempY,size));
	
	/*a1 i bulalim*/
	a1=((-findSumXorY(valueX,size)/detA)*findSumXorY(tempY,size))+((n/detA)*findSumXY(valueX,tempY,size));
	
	sr=findSR(valueX,tempY,size,a0,a1);
	st=findST(tempY,size);

	return(sqrt((st-sr)/st));
}

/*4 denklem icin*/
double findR4(double valueX[],double valueY[],int size,int n){
	double detA=0.0;
	double a0,a1=0.0;
	double sr,st=0.0;
	int i=0;
	double tempY[SIZE];

	/*x ve y leri kendi fonksiyonumuza gore degistirelim*/
	for(i=0;i<size;i++){
		tempY[i]=1/(valueY[i]);
	}
	/*determinant bulalim*/
	detA=findSumX2(valueX,size)*n-(findSumXorY(valueX,size)*findSumXorY(valueX,size));

	/*a0 i bulalim*/
	a0=(findSumXorY(tempY,size)*(findSumX2(valueX,size)/detA))-((findSumXorY(valueX,size)/detA)*findSumXY(valueX,tempY,size));
	
	/*a1 i bulalim*/
	a1=((-findSumXorY(valueX,size)/detA)*findSumXorY(tempY,size))+((n/detA)*findSumXY(valueX,tempY,size));
	
	sr=findSR(valueX,tempY,size,a0,a1);
	st=findST(tempY,size);

	return(sqrt((st-sr)/st));
}
/*5 denklem icin*/
double findR5(double valueX[],double valueY[],int size,int n){
	double detA=0.0;
	double a0,a1,a2,a3,a4,a5=0.0;
	double sr,st=0.0;
	int i=0;
	double tempX[SIZE];
	/*her seferinde xler degisecegi icin her bir basamakta yeni detA
	 buluyorum ve her degisken icin x x2 x3.. diye yeni notasyonu gonderiyorum*/

	/*determinant bulalim*/
	detA=findSumX2(valueX,size)*n-(findSumXorY(valueX,size)*findSumXorY(valueX,size));

	/*a0 i bulalim*/
	a0=(findSumXorY(valueY,size)*(findSumX2(valueX,size)/detA))-((findSumXorY(valueX,size)/detA)*findSumXY(valueX,valueY,size));
	
	/*a1 i bulalim*/
	a1=((-findSumXorY(valueX,size)/detA)*findSumXorY(valueY,size))+((n/detA)*findSumXY(valueX,valueY,size));
	
	/*sr bulalim*/
	sr=findSR(valueX,valueY,size,a0,a1);
	
	/*a2 i bulalim*/
	for(i=0;i<size;i++){
		tempX[i]=pow((valueX[i]),2);
	}

	/*determinant bulalim*/
	detA=findSumX2(tempX,size)*n-(findSumXorY(tempX,size)*findSumXorY(tempX,size));

	a1=((-findSumXorY(tempX,size)/detA)*findSumXorY(valueY,size))+((n/detA)*findSumXY(tempX,valueY,size));

	/*a3 i bulalim*/
	for(i=0;i<size;i++){
		tempX[i]=pow((valueX[i]),3);
	}

	/*determinant bulalim*/
	detA=findSumX2(tempX,size)*n-(findSumXorY(tempX,size)*findSumXorY(tempX,size));

	a3=((-findSumXorY(tempX,size)/detA)*findSumXorY(valueY,size))+((n/detA)*findSumXY(tempX,valueY,size));

	/*a4 i bulalim*/

	for(i=0;i<size;i++){
		tempX[i]=pow((valueX[i]),4);
	}

	/*determinant bulalim*/
	detA=findSumX2(tempX,size)*n-(findSumXorY(tempX,size)*findSumXorY(tempX,size));

	a4=((-findSumXorY(tempX,size)/detA)*findSumXorY(valueY,size))+((n/detA)*findSumXY(tempX,valueY,size));

	/*a5 i bulalim*/

	for(i=0;i<size;i++){
		tempX[i]=pow((valueX[i]),5);
	}

	/*determinant bulalim*/
	detA=findSumX2(tempX,size)*n-(findSumXorY(tempX,size)*findSumXorY(tempX,size));
	a5=((-findSumXorY(tempX,size)/detA)*findSumXorY(valueY,size))+((n/detA)*findSumXY(tempX,valueY,size));
	
	for(i=0;i<size;i++){
		sr+=pow(valueY[i]-a0-(a1*valueX[i])-(a2*pow(valueX[i],2))-(a3*pow(valueX[i],3))-
		    (a4*pow(valueX[i],4))-(a5*pow(valueX[i],5)),2);
	}
	
	st=findST(valueY,size);


	return(sqrt((sr-st)/sr));
}

