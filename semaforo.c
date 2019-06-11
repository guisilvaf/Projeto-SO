#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>

static int counter = 0;

sem_t semaforo;
<<<<<<< HEAD

void* processando(void* arg)
{
        int *idThread;
        idThread = arg;

        printf("\nThread %i está processando...\n", *idThread);
        int timeSleep = rand() % 10;
        printf("\nTempo da thread %i a dormir: %d segundos\n", timeSleep, *idThread);
        sleep(timeSleep);
}

=======

void* processando(void* arg)
{
        int *idThread;
        idThread = arg;

        printf("\nThread %i está processando...\n", *idThread);
        int timeSleep = rand() % 10;
        //printf("Tempo da thread %i a dormir: %d segundos\n", timeSleep, *idThread);
        sleep(timeSleep);
}

>>>>>>> f3d14ae2c7edb3d768afe43f0815f602ea6c0789
void* regiaoNcritica(void* arg)
{
        int *idThread;
        idThread = arg;
        printf("\nThread %i não está na região crítica...\n", *idThread);
        processando(arg);
}



void* regiaoCritica(void* arg)
{
        int *idThread;
        idThread = arg;
        printf("\nThread %i está entrando na região crítica...\n", *idThread);
        processando(arg);
        printf("\nThread %i está saindo da região crítica...\n", *idThread);
}


void* roda(void* arg)
<<<<<<< HEAD
{     
       	int *idThread;
     	idThread = arg;	
       
       	regiaoNcritica(arg);


	printf("\nthread %i está esperando para entrar na região crítica.\n", *idThread);

        sem_wait(&semaforo);

        regiaoCritica(arg);

=======
{       
        regiaoNcritica(arg);

        sem_wait(&semaforo);

        regiaoCritica(arg);

>>>>>>> f3d14ae2c7edb3d768afe43f0815f602ea6c0789
        sem_post(&semaforo);
}


int main()
{

<<<<<<< HEAD
        int numeroPermissoes = 5;
        int numeroProcessos = 10;
=======
        int numeroPermissoes = 0;
        int numeroProcessos = 6;
>>>>>>> f3d14ae2c7edb3d768afe43f0815f602ea6c0789
        
        sem_init(&semaforo, 0 , 1);
        
        pthread_t thread_semaforo[numeroProcessos];
        int arg[numeroProcessos];

        for(int i = 0; i < numeroProcessos; i++)
        {
                arg[i] = i + 1;
                pthread_create(&thread_semaforo[i], NULL, roda, (void *)&arg[i]);
        }

        for(int k = 0; k < numeroProcessos; k++)
        {
                pthread_join(thread_semaforo[k], NULL);
        }


        printf("\n");
        
        return 0;
}
