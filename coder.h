#include <pthread.h>


typedef struct s_coder{
    int     id;
    char    *name;
    int     compile_count;
    int     last_compile_time;
}t_coder;


typedef struct s_dongle{
    int             is_taken;
    pthread_mutex_t mutex;
}t_dongle;
