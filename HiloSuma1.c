// se compila así­:
// gcc HiloSuma1.c -o HiloSuma1 -l pthread
// se ejecuta: ./HiloSuma1

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //Se ocupa la librería de hilos
	 
void *print_message_function1( void *ptr );
void *print_message_function2( void *ptr );

int Total = 0; //Los dos hilos van a usar la misma variable
int Limite = 100;

void main() {
     pthread_t thread1, thread2;  //Se declaran los dos hilos
     char *message1 = "Thread - Hilo 1";
     char *message2 = "Thread - Hilo 2";
     int  iret1, iret2;
 
    /* Crear un hilo independiente para ejecutar cada método */

     iret1 = pthread_create( &thread1, NULL, print_message_function1, (void*) message1);
     iret2 = pthread_create( &thread2, NULL, print_message_function2, (void*) message2);
  
     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL);
 
     printf("Thread 1 returns: %d\n",iret1);
     printf("Thread 2 returns: %d\n",iret2);
     exit(0);
}
	 
void *print_message_function1( void *ptr ) {
     char *message;
     message = (char *) ptr;
     int i;

     for (i=0; i<Limite; i++) {   //Probar hasta 100 y luego cambiar este valor
        Total += 1; //Este hilo suma
     }
     printf("%s %d \n", message, Total);
}

void *print_message_function2( void *ptr ) {
     char *message;
     message = (char *) ptr;
     int i;

     for (i=0; i<Limite; i++) {
        Total -= 1; //Este hilo resta
     }
     printf("%s %d \n", message, Total);
}