#ifndef DATA
#define DATA

#include <pthread.h>


typedef long long t_ms;
typedef struct s_sim t_sim;

typedef struct s_input {
    int number_of_coders;
    int time_to_burnout;
    int time_to_compile;
    int time_to_debug;
    int time_to_refactor;
    int number_of_compiles_required;
    int dongle_cooldown;
    int edf;
} t_input;


typedef struct s_request{
    int                 id;
    unsigned long long  ticket;   //fr fifo
    t_ms                deadline; //for edf
}t_request;


typedef struct s_heap{
    t_request           *items;   //array of requests for one dongle
    int                 size;
    int                 capacity;
    int                 edf;
}t_heap;


typedef struct s_coder{
    pthread_t   thread;
    t_sim       *sim;
    int         id;
    int         first;  // first coder
    int         second;  // scond coder
    int         holding;  // how many coders are holdes 0 1 or 2
    int         completed;  // how many compiles are finished
    t_ms        last_compile_start;
}t_coder;


typedef struct s_dongle{
    pthread_mutex_t lock;
    int             owner;
    t_ms            ready_at;   //time of release + coolown
    t_request       storage[2];  // each dongle is connectd to 2 coders so each dongle nned an array of 2
    t_heap          queue;
}t_dongle;


struct s_sim{
    t_input					cfg;
    t_coder					*coders;
    t_dongle				*dongles;
    pthread_mutex_t			state;
    pthread_mutex_t			output;
    pthread_cond_t			state;
    pthread_t				monitor;
    int						locks_ready;
    int						cond_ready;
    int						dongles_ready;
    int						created;
    int						monitor_created;
    int						go;
    int						stop;
    t_ms					start;
    unsigned long long		next_ticket;

};

#endif
