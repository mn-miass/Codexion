#ifndef DATA
#define DATA

#include <pthread.h>

typedef struct s_input {
    int number_of_coders;
    int time_to_burnout;
    int time_to_compile;
    int time_to_debug;
    int time_to_refactor;
    int number_of_compiles_required;
    int dongle_cooldown;
    char *scheduler;
} t_input;



typedef struct s_coder{
    int     id;
    char    *name;
    int     left_dongle;
    int     right_dongle;
    int     compile_count;
    long    last_compile_start;
}t_coder;


typedef struct s_dongle{
    int             is_taken;
    long            available_at;
    pthread_mutex_t mutex;
}t_dongle;



#endif
