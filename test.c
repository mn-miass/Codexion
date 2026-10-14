#include <stdio.h>
#include <unistd.h>
#include <pthread.h>



typedef struct s_test {
    int index;
    pthread_mutex_t mutex;
}t_test;


void *func(void *arg)
{
    t_test* coder;
    coder = arg;
    int i = 0;
    while (i < 10000)
    {
        pthread_mutex_lock(&coder->mutex);
        coder->index ++;
        pthread_mutex_unlock(&coder->mutex);
        i++;
    }
}



int main()
{
    t_test counter;

    counter.index = 0;
    pthread_mutex_init(&counter.mutex, NULL);
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, func, &counter);
    pthread_create(&t2, NULL, func, &counter);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("%d", counter.index);
}