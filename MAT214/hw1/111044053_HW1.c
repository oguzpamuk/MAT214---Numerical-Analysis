/*
	*Author :Oguzcan Pamuk
	*Number :111044053
	*Sayisal Analiz HW01
	*Odev linux ortaminda hazirlanmistir
*/

#include <stdio.h>
#include <math.h>

/*Hocanin bize vermis oldugu denklem*/
double denklem(double root);
/*Bisection Methodu*/
double biSectionMethod(double root1,double root2);
/*Falseposition Methodu*/
double falsePositionMethod(double root1,double root2);
/*Hocanin vermis oldugu denklemin turevi*/
double denklemTurev(double root);
/*Newton-Raphson Methodu*/
double newtonRaphsonMethod(double root);
/*Secant Methodu*/
double secantMethod(double root1,double root2);
/*One-Point Iteration*/
double onePointIterationMethod(double root);
/*One-Point Yardimci Fonksiyon*/ 
double onePointHelper(double root);

int main()
{
	printf("Bisection : %f\n",biSectionMethod(1,9));
	printf("FalsePostion : %f\n",falsePositionMethod(1,9));
	printf("Newton-Raphson : %f\n",newtonRaphsonMethod(5));
	printf("Secant : %f\n",secantMethod(3,5));
	printf("One-Point Iteration : %f\n",onePointIterationMethod(4));

	return 0;
}
/*Bisection methodu*/
double biSectionMethod(double root1,double root2){
	/*Yontemde aritmetik ortalama gerekecek*/
	double ortalama=0.0;
	double tolerans=0.001;


	do{
		ortalama=(root1+root2)/2;
		/*printf("%f",ortalama);*/
		/*f(x)*f(ort)<0 'a gore koklerden birinin yerine
		  ortalama deger yazilir,bu sekilde yakinlasma saglanir*/
		if((denklem(root1)*denklem(ortalama))<0){
			root2=ortalama;
		}
		else{
			root1=ortalama;
		}
	/*ortalama degerimiz yeni bir aralik oldu,aralik degerini toleransla
	karsilastiriyoruz*/
	}while(fabs(denklem(root1)-denklem(root2))>tolerans);
	
	return ortalama;
}

/*Verilen Denklem*/
double denklem(double root){
	/*Yontemlerde verilen fonksiyondan deger istenirken kullanilacak*/
	return(((((-3000)*pow(1.2,root))+(175*root))/(pow(1.2,root)-1))+5000);
}
/*false position methodu*/
double falsePositionMethod(double root1,double root2){
	double deger=0.0;
	double tolerans=0.001;
	int counter=0,asama=150;
	do{
		deger=((denklem(root2)*root1)-(denklem(root1)*root2))/(denklem(root2)-denklem(root1));
		/*printf("%f",deger);*/
		if((denklem(root1)*denklem(deger))<0){
			root2=deger;
		}
		else{
			root1=deger;
		}
		/*Belli bir asamadan sonra deger sabitlenecek,oyuzden asama sayisi belirledim*/
		counter++;
		if(counter==asama)
			break;
	}while(fabs(denklem(root1)-denklem(root2))>tolerans);

	return deger;
}
/*Turev isteyen yontemde kullanilacak*/
double denklemTurev(double root){
	return((pow(1.2,root)*(721.965-31.9063*root)-175)/pow(pow(1.2,root)-1,2));
}

/*Newton-Raphson Methodu*/
double newtonRaphsonMethod(double root){
	/*eski kok icin gerekli*/
	double oldRoot=0.0;
	double tolerans=0.001;
	
	do{
		oldRoot=root;
		root=root-(denklem(root)/denklemTurev(root));
		/*printf("%f",root);*/

	}while(fabs(denklem(oldRoot)-denklem(root))>tolerans);

	return root;
}
/*Secant Methodu*/
double secantMethod(double root1,double root2){
	/*koklerden birini saklamak icin kullaniyoruz*/
	double temp=0.0;
	double tolerans=0.001;
	
	do{
		temp=root2;
		root2=root2-((denklem(root2)*(root1-root2))/(denklem(root1)-denklem(root2)));
		root1=temp;
		/*printf("%f",root2);*/

	}while(fabs(denklem(root2)-denklem(root1))>tolerans);

	return root2;
}
/*One-Point Helper*/
double onePointHelper(double root){
	/*Bu fonksiyon verilen denklemdeki koklerden birini cekmek
	  icin lazim f(x)=y x=g(y) gibi*/
	return(log10((5000-175*root)/2000)/log10(1.2));
}
/*One-Point Iteration*/
double onePointIterationMethod(double root){
	/*koklerden birini saklamak icin kullaniyoruz*/
	double temp=0.0;
	double tolerans=0.001;
	
	do{
		temp=root;
		/*printf("%f\n",root);*/
		root=onePointHelper(root);
		
	}while(fabs(denklem(root)-denklem(temp))>tolerans);

	return root;
}






