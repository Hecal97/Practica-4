#include <stdio.h>
int decimalToBinaryNumber(int x, int n);    //Funci�n prototipo
int generateGrayarr(int n);                 //Funci�n prototipo


int main(){
	int n;
	printf("Ingrese el numero para generar su secuencia en Grey Code: \n");
	scanf("%d", &n);
    generateGrayarr(n);
}

int decimalToBinaryNumber(int x, int n) 
{ 
    int* binaryNumber = new int(x);                     
    int i = 0; 
    while (x > 0) {  
		//printf("xwhile = %d\n", x);                    
        binaryNumber[i] = x % 2;                         //4. Se toma el valor de "x" generado previamente y se asigna a la posici�n i actual el residuo de "x % 2"
		//printf("binaryNumber i = %d\n", x%2) ;   
        x = x / 2;                                       //5. Se divide entre dos para evaluar el siguiente valor mientras x sea mayor a 0
        i++;                                             //6. Se incrementa "i" en 1 para avanzar a la siguiente posici�n del arreglo 
    } 
  
    for (int j = 0; j < n - i; j++){                     //7. En este ciclo for se asignan los 0s a la izquierda del arreglo de bits para completar la representaci�n del n�mero en binario
        printf("0");
	}
  
    for (int j = i - 1; j >= 0; j--){                    //8. Este ciclo for toma e imprime los valores del arreglo de la posici�n MAYOR a la MENOR, por ejemplo, si el arreglo es {0,1}, este ciclo lo imprime como 10
        printf("%d", binaryNumber[j]);                   //9. De esta forma se logra generar los patrones de bits de 0 a 2^n-1, donde cada patr�n sucessivo difiere en 1 bit
	}
        
} 
  
 
int generateGrayarr(int n) 
{ 
    int N = 1 << n;                         //1. N se inicializa con 1*2^n, donde n es el n�mero que se ingres� del cual se desea saber su secuencia en Grey Code
    for (int i = 0; i < N; i++) {           
  
        int x = i ^ (i >> 1);               //2. El valor de x que se genere de esta l�nea es el que nos permite que cada arreglo de bits tenga un bit diferente al arreglo pasado por el XOR que produce un toggle
		//printf("x = %d\n",x);               
  
        
        decimalToBinaryNumber(x, n);        //3. Se ejecuta la funci�n de decimal a binario proporcionando los valores de "x" y "n"
  
        printf("\n");
    } 
} 
