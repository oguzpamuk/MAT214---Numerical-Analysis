/*
	*Course   : Sayisal Analiz HW05
	*Author   : Oguzcan PAMUK
	*Number   : 111044053
	*File 	  : pamuk_oguzcan_111044053.c
*/


#include <stdio.h>
#include <math.h>

/*Analitik integral alinirken e sayisina ihtiyac var*/
#define E 2.7182818284
/*Hocanin vermis oldugu fonksiyon*/
/*Okunakli olabilmesi icin f(x) formatini kullaniyorum*/
double f(double x);
/********************************/
/* I= taban * ortalama yukseklik esasina dayanir,trapez adiylada adlandirilir */
/* Tek Bolgeli yamuk kurali */
double yamukKurali(double a,double b);
/********************************/
/* ikinci dereceden Newton-Gregory ileri fark polinomu integre edilerek
   elde edilir. 
   f(x)=h/3 * [f0 + 4f1 + f2 ] formulune dayanir */
double simpsonBirBoluUcKurali(double a,double b);
/********************************/
/* f(x)=3h/8 * [f0 + 3f1 + 3f2 + f3] formulune dayanir 
   ard arda uc serit uzerinde integral alinmasi olarak bilinir */
double simpsonUcBoluSekizKurali(double a,double b);
/********************************/
/* Yamuk kuralinin a - b araliginda n adet parcaya ayrilarak uygulanan seklidir */
double cokBolgeliYamukKurali(double a,double b,int n);
/********************************/
/*Simpson 1/3 kuralinin n adet parcaya ayrilarak uygulanan seklidir*/
double cokBolgeliSimpsonKurali(double a,double b,int n);
/********************************/
/* integralin analitik sonucu 
   http://integrals.wolfram.com/index.jsp?expr=%2815.3%29^%282.5*x%29&random=false 
   buradan dogrulama yapabilirsiniz */
double analitikSonuc(double a,double b);
/*Hata hesabı = ( gercek deger - yaklasik deger / gercek deger ) *100 */
double hataHesabi(double gercekDeger,double yaklasikDeger);
int main()
{
	/*Ekran ciktilari*/
	printf("---------SONUCLAR---------\n");
	printf("Analitik sonuc : %f\n",analitikSonuc(0,1));
	printf("Hata hesabi yuzde olarak verilmistir\n");
	printf("--------------------------\n");
	printf("Yamuk kuralina gore integral sonucu : %f\n",yamukKurali(0,1));
	printf("Yamuk kurali icin hata hesabi : %f\n",hataHesabi(analitikSonuc(0,1),yamukKurali(0,1)));
	printf("--------------------------\n");
	printf("Cok Bolgeli Yamuk Kurali\n");
	printf("n=2 icin : %f\n",cokBolgeliYamukKurali(0,1,2));
	printf("n=2 icin hata hesabi :%f\n",hataHesabi(analitikSonuc(0,1),cokBolgeliYamukKurali(0,1,2)));
	printf("n=4 icin : %f\n",cokBolgeliYamukKurali(0,1,4));
	printf("n=4 icin hata hesabi :%f\n",hataHesabi(analitikSonuc(0,1),cokBolgeliYamukKurali(0,1,4)));
	printf("n=10 icin : %f\n",cokBolgeliYamukKurali(0,1,10));
	printf("n=10 icin hata hesabi :%f\n",hataHesabi(analitikSonuc(0,1),cokBolgeliYamukKurali(0,1,10)));
	printf("n=20 icin : %f\n",cokBolgeliYamukKurali(0,1,20));
	printf("n=20 icin hata hesabi :%f\n",hataHesabi(analitikSonuc(0,1),cokBolgeliYamukKurali(0,1,20)));
	printf("--------------------------\n");
	printf("Simpson 1/3 kuralina gore integral sonucu : %f\n",simpsonBirBoluUcKurali(0,1));
	printf("Simpson 1/3 icin hata hesabi :%f\n",hataHesabi(analitikSonuc(0,1),simpsonBirBoluUcKurali(0,1)));
	printf("Simpson 3/8 kuralina gore integral sonucu : %f\n",simpsonUcBoluSekizKurali(0,1));
	printf("Simpson 3/8 icin hata hesabi :%f\n",hataHesabi(analitikSonuc(0,1),simpsonUcBoluSekizKurali(0,1)));
	printf("--------------------------\n");
	printf("Cok Bolgeli Simpson 1/3 Kurali\n");
	printf("n=2 icin : %f\n",cokBolgeliSimpsonKurali(0,1,2));
	printf("n=2 icin hata hesabi :%f\n",hataHesabi(analitikSonuc(0,1),cokBolgeliSimpsonKurali(0,1,2)));
	printf("n=4 icin : %f\n",cokBolgeliSimpsonKurali(0,1,4));
	printf("n=4 icin hata hesabi :%f\n",hataHesabi(analitikSonuc(0,1),cokBolgeliSimpsonKurali(0,1,4)));
	printf("n=10 icin : %f\n",cokBolgeliSimpsonKurali(0,1,10));
	printf("n=10 icin hata hesabi :%f\n",hataHesabi(analitikSonuc(0,1),cokBolgeliSimpsonKurali(0,1,10)));
	printf("n=20 icin : %f\n",cokBolgeliSimpsonKurali(0,1,20));
	printf("n=20 icin hata hesabi :%f\n",hataHesabi(analitikSonuc(0,1),cokBolgeliSimpsonKurali(0,1,20)));

    getchar();
	return 0;
}
	/*Hocanin vermis oldugu fonksiyon*/
	double f(double x){
		return(pow(15.3,(2.5*x)));
	}
	/********************************/

	double yamukKurali(double a,double b){
				
		/* a yada b hangisinin buyuk girilecegini bilmedigimiz icin
		   mutlak deger aliyoruz */		
		return (fabs((a-b)*(f(a)+f(b))/2));	
	}

	/********************************/
	double simpsonBirBoluUcKurali(double a,double b){
		/* formulde verilen h ifadesi */
		double h=fabs(a-b)/2;

		return (fabs(1.0/3.0 * h *(f(a) + 4*f((a+b)/2) + f(b))));
	}

	/********************************/
	double simpsonUcBoluSekizKurali(double a,double b){
		/* formulde verilen h ifadesi */
		double h=fabs(a-b)/3;
		/* formulde verilen f1 ifadesinin parametresi */
		double x1=a+h;
		/* formulde verilen f2 ifadesinin parametresi */
		double x2=b-h;

		return(fabs(3.0/8.0 * h *(f(a)+ 3*f(x1) + 3*f(x2) + f(b))));
	}
	
	double cokBolgeliYamukKurali(double a,double b,int n){

		/*Counter*/
		int i=0;
		/* formulde verilen h ifadesi */
		double h=fabs(a-b)/n;
		/* n tane aralık delta h'a gore bolunur 
                   aralik x olursa her bir aralik arasinda h kadar mesafe olur */
		double x=a+h;
		/* dongu toplamini veren ifade */
		double total=0.0;

		/*Formuldeki dongu ifadesi,n-1 defa doner*/

		for(i=0;i<n-1;i++){
			total=total+(2*f(x));
			/*islem bittikten sonra araligi h kadar arttiriyoruz*/
			x+=h;		
		}

		return(((total+(f(a)+f(b)))*fabs(a-b))/(2*n));
	}
	/********************************/
	double cokBolgeliSimpsonKurali(double a,double b,int n){
		/* formulde verilen h ifadesi */
		double h=fabs(a-b)/n;
		/*Counter*/
		int i=0;
		/* n tane aralık delta h'a gore bolunur 
                   aralik x olursa her bir aralik arasinda h kadar mesafe olur */
		double x=a+h;
		/* sonuclar toplami */
		double total=0.0;

		/*Formule gore i=1 ve x=a+h icin*/
		i=1;
		while(i<n){
	 		total=total+(4*f(x));
		  	x+=(2*h);
			i+=2;
		}
		/*Formule gore i=2 ve x=2*h icin*/
		i=2;
		x=2*h;
		while(i<n){
	   		total=total+(2*f(x));
			x+=(2*h);
			i+=2;
		}

		return (((total+(f(a)+f(b)))*fabs(a-b))/(3*n));
	}
	/********************************/
	double analitikSonuc(double a,double b){
		/*Sadece verilen fonksiyona ozgu sonuc uretir*/
		return(fabs(((0.146635)*pow(E,(6.81963*b)))-((0.146635)*pow(E,(6.81963*a)))));
	}
	/********************************/
	double hataHesabi(double gercekDeger,double yaklasikDeger){
		/*Hatayi yüzle carparak yüzdesini veriyoruz*/
		return(fabs(((gercekDeger-yaklasikDeger)/gercekDeger)*100));
	}


