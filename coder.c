#include "coder.h"
#include "structurs_data.h"
#include <unistd.h>
#include <stdlib.h>


t_coder *create_coders(t_input input)
{
    int     index;
    t_coder *arr_coders;

    index = 0;
    arr_coders = malloc(sizeof(t_coder) * input.number_of_coders);
    if (arr_coders == NULL)
        return NULL;
    while (index < input.number_of_coders)
    {
        arr_coders[index].id = index + 1;
        arr_coders[index].left_dongle = index;
        arr_coders[index].right_dongle = (index + 1) % input.number_of_coders;
        arr_coders[index].compile_count = 0;
        arr_coders[index].last_compile_start = 0;
        index++;
    }
    return arr_coders;
}


t_dongle *create_dongles(t_input input)
{
    int         index;
    t_dongle    *arr_dongles;

    index = 0;
    arr_dongles = malloc(sizeof(t_dongle) * input.number_of_coders);
    if (arr_dongles == NULL)
        return NULL;

    while (index < input.number_of_coders)
    {
        arr_dongles[index].is_taken = 0;
        pthread_mutex_init(&arr_dongles[index].mutex, NULL);
        arr_dongles[index].available_at = 0;
        index++;
    }
    return arr_dongles;
}




void debug()
{}


void compile()
{}


void refactor()
{}


