#include <stdio.h>
int decimalToBinaryNumber(int x, int n);    //Función prototipo
int generateGrayarr(int n);                 //Función prototipo


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
        binaryNumber[i] = x % 2;                         //4. Se toma el valor de "x" generado previamente y se asigna a la posición i actual el residuo de "x % 2"
		//printf("binaryNumber i = %d\n", x%2) ;   
        x = x / 2;                                       //5. Se divide entre dos para evaluar el siguiente valor mientras x sea mayor a 0
        i++;                                             //6. Se incrementa "i" en 1 para avanzar a la siguiente posición del arreglo 
    } 
  
    for (int j = 0; j < n - i; j++){                     //7. En este ciclo for se asignan los 0s a la izquierda del arreglo de bits para completar la representación del número en binario
        printf("0");
	}
  
    for (int j = i - 1; j >= 0; j--){                    //8. Este ciclo for toma e imprime los valores del arreglo de la posición MAYOR a la MENOR, por ejemplo, si el arreglo es {0,1}, este ciclo lo imprime como 10
        printf("%d", binaryNumber[j]);                   //9. De esta forma se logra generar los patrones de bits de 0 a 2^n-1, donde cada patrón sucessivo difiere en 1 bit
	}
        
} 
  
 
int generateGrayarr(int n) 
{ 
    int N = 1 << n;                         //1. N se inicializa con 1*2^n, donde n es el número que se ingresó del cual se desea saber su secuencia en Grey Code
    for (int i = 0; i < N; i++) {           
  
        int x = i ^ (i >> 1);               //2. El valor de x que se genere de esta línea es el que nos permite que cada arreglo de bits tenga un bit diferente al arreglo pasado por el XOR que produce un toggle
		//printf("x = %d\n",x);               
  
        
        decimalToBinaryNumber(x, n);        //3. Se ejecuta la función de decimal a binario proporcionando los valores de "x" y "n"
  
        printf("\n");
    } 
} 
