#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h> 

#define RED_LOOP 6
#define GREEN_LOOP 3

static int counter = 0;

static void * primeira_thread_function(void* arg);
static void * segunda_thread_function(void* arg);

sem_t sem1;

int main(void)
{

	pthread_t thread_1, thread_2;

	sem_init(&sem1, 0 , 1);

	pthread_create(&thread_1, NULL, *primeira_thread_function, NULL);
	pthread_create(&thread_2, NULL, *segunda_thread_function, NULL);

        pthread_join(thread_1, NULL);
        pthread_join(thread_2, NULL);

        //printf("O valor contador %d \n", counter);
        return 0;

}

static void * primeira_thread_function(void* arg)
{
        for(int i = 0; i < RED_LOOP; i++)
        {
		
		sem_wait(&sem1);
                printf("Status do semáforo: Vermelho\n");
                sleep(2);
		sem_post(&sem1);
        }
}

static void * segunda_thread_function(void* arg)
{
        for(int i = 0; i < GREEN_LOOP; i++)
        {
		sem_wait(&sem1);
                printf("Status do semáforo: Verde\n");
                sleep(2);
                sem_post(&sem1);
        }
}