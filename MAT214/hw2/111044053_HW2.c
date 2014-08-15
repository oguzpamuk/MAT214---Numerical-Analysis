//Programa yuksek sayida size verince calismasi yavasliyor
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// default values
#define MATRIX_SIZE 5
#define VALUE_MIN 1
#define VALUE_MAX 5
// functions
double compute_determinant(int **matrix,int size);
void matrix_create(int **matrix, int min_val, int max_val);
void matrix_print(int **matrix);
// main function
int main(int argc, char *argv[])
{
	// variables
	int ** matrix;
	int row, column;
	int i=0,size=MATRIX_SIZE;
	// Dynamic memory kullandim buyüzden kodda kucuk degisiklikler yaptim
	// matrix yeri aciyoruz
     	matrix=(int**)malloc((size+1)*sizeof(int*));  
   	for (i=0;i<size+1;i++){
       		matrix[i]=(int*)malloc((size+1)*sizeof(int));
	}
	// generate different numbers
	srand(time(NULL));
	// create a matrix with random numbers
	matrix_create(matrix, VALUE_MIN, VALUE_MAX);
	// print matrix
	matrix_print(matrix);
	// calculate determinant of matrix
	printf("Determinant of NxN Matrix:\t%f", compute_determinant(matrix,MATRIX_SIZE));
	getchar();
	return 0;
}
// compute determinent of matrix

double compute_determinant(int **matrix,int size) {

    //Fonksiyon recursive yontemle problemi parcalayarak devam ediyor
    //size 2 ise direk bulup return ediyor 
    //determinant yontemlerinden kofaktor bulmadan yararlanilarak yazildi
    //fonksiyon recursive ozelligi de gosterdigi icin bazi yerlerde initialize yerine
    //for dongusunun ozelliginden yararlanilarak deger verilmistir

    //counter
    int i,j,k,m,n;
    //sonuc 
    double result = 0;
    //dynamic array 
    int *temp,**array ;
    //kofaktor carpani
    int multiplier;
    
    //iceride kullanacagimiz dynamic array icin yer aciyoruz
    array=(int**)malloc((size+1)*sizeof(int*));  
    for (n=0;n<size+1;n++){ 
       array[n]=(int*)malloc((size+1)*sizeof(int));
    }
    //kofaktorlerin sonuclari bu arrayde toplanip en son carpiliyor
    temp=(int*)malloc((size+1)*sizeof(int)); 
    
    //size 2 ise direk hesaplayip donduruyor
    if(size==2){
        result=0;
        result=(matrix[1][1]*matrix[2][2])-(matrix[1][2]*matrix[2][1]);
        return result;
    }
    //size 2 den buyuk ise
    else{

        for(i=1;i<=size;i++){     
            int x=1,y=1;
            for(j=1;j<=size;j++){
                for(k=1;k<=size;k++){

                    if(j!=1 && k!=i){
                        array[x][y] = matrix[j][k];
                        y++;
                        if(y > size-1){
                            x++;
                            y=1;
                        }
                    }
                }
            }
	    // (-1) uzeri (row+col) gorevi goruyor cift ise +1 tek ise -1
            for(m=1,multiplier=1;m<=(1+i);m++){
                multiplier=(-1)*multiplier;
	    }
            
            temp[i]=multiplier*compute_determinant(array,size-1);
        }
	
	//sonuc isleminin bulundugu asama
	//kofaktorlerin sonucunu tutan temp ile ilk satir elemanlari carpilarak sonuc bulunuyor
        for(j=1,result=0;j<=size;j++){
            result=result+(matrix[1][j]*temp[j]);
        }
         return result ;
    }
}
// print matrix
void matrix_print(int **matrix) {
	int row, column;

	for(row = 1; row <= MATRIX_SIZE; row++) {
		for(column = 1; column <= MATRIX_SIZE; column++) {
			printf("%d\t", matrix[row][column]);
		}
		printf("\n");
	}
}
// create matrix
void matrix_create(int **matrix, int min_val, int max_val) {
	int row, column;
	srand(time(NULL));

	for(row = 1; row <= MATRIX_SIZE; row++) {
		for(column = 1; column <= MATRIX_SIZE; column++) {
			matrix[row][column] = (rand() % (max_val-min_val+1)) + min_val;
		}
	}
}
