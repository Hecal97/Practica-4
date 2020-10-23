  
//Multiplicaciones y divisiones
#include <stdio.h>
#include <stdlib.h>
int main(){
	int a,b,resultado,operacion,temp,cuenta;
	
	printf("'a':\n");
    scanf("%d", &a);
    printf("'b':\n");
    scanf("%d", &b);
    
    printf(" 0 para multiplicacion, 1 para division a/b:\n");
    scanf("%d", &operacion);
    resultado = 0;
    if(operacion==0){
    while (b != 0)                        // El ciclo se ejecuta mientras "b" sea diferente de "0"
    {
    
        if (b & 1)                       // Al aplicar "b & 1" se puede determinar si b es número impar
        {
            resultado = resultado + a;   // Se añade el valor de "a" al resultado para considerar que "b" es impar 
         						
        }
        a <<= 1;                        // Se hace un corrimiento de 1 bit a la izquierda para multiplicar por "2" el valor de "a"
                                
        b >>= 1;                       // Se hace un corrimiento de 1 bit a la derecha para dividir entre "2" el valor de "b"
        
    }

    printf("Resultado: %d\n",resultado);
	}else{
		while(a >= b){                  //El ciclo se ejecuta mientras el dividendo "a" sea mayor o igual al divisor "b"
        temp = b;                       // Se inicializa el valor de temp con "b"
        cuenta = 1;                     //Se inicializa el valor de cuenta con "1"
        while(temp <= a)                //Se ejecuta mientras "temp" sea menor o igual a "a"
        {
            temp <<= 1;                  //En este ciclo se registra cuantas veces cabe el divisor "b" en el dividendo "a" y se registra en cuenta en multiplos de 2 al utilizar el corrimiento de 1 bit a la izquierda
            cuenta <<= 1;
        }
        resultado = resultado + (cuenta >> 1 );   //Se almacena el último valor válido de cuenta en el resultado, para obtener el último valor valido de cuenta se hace un corrimiento de 1 bit a la derecha
        a = a - (temp >> 1);                      //Se asigna el valor restante al dividendo "a" al restar el último valor acumulado de temp, para obtener el último valor válido de temp se hace un corrimiento de 1 bit a la derecha
    	}
    	
    printf("Resultado: %d\n",resultado);
    
	}
}
   
