#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "helper_parsing_functions.h"
#include "codexion.h"


void    error_display(char *s)
{
    write(2, s, ft_strlen(s));
    exit(0);
}


t_input    fill_input_struct(int *inputs, char *schedular)
{
    t_input input;

    input.number_of_coders = inputs[0];
    input.time_to_burnout = inputs[1];
    input.time_to_compile = inputs[2];
    input.time_to_debug = inputs[3];
    input.time_to_refactor = inputs[4];
    input.number_of_compiles_required = inputs[5];
    input.dongle_cooldown = inputs[6];
    input.scheduler = schedular;

    return input;
}


void    get_error(int index)
{
    if(index == 0)
        error_display("Number of coders must be positive integer");
    else if(index == 1)
        error_display("time to burnout must be positive integer");
    else if(index == 2)
        error_display("Time To Compile must be positive integer");
    else if(index == 3)
        error_display("Time To Debug must be positive integer");
    else if(index == 4)
        error_display("Time To Refactor must be positive integer");
    else if(index == 5)
        error_display("Number of compileres required must be positive integer");
    else if(index == 6)
        error_display("Dongle Cooldown must be positive integer");
    else if(index == 7)
        error_display("Scheduler must be one of the folowing fifo or edf");
    else if(index == 8)
        error_display("Allocation Failed");
}


int   *get_int_arguments(char **input, int num_of_inputs)
{
    int     i;
    int     *input_nums;

    input_nums = malloc(7 * sizeof(int));
    i = 0;
    if(!(num_of_inputs == 8))
        error_display("Number of ARGS Must be 8");
    while (i < num_of_inputs - 1)
    {
        if(str_is_num(input[i]))
            input_nums[i] = ft_atoi(input[i]);
        else
            return NULL;
        i++;
    }
    return input_nums;
}


char    *get_char_argument(char *s)
{
    char    *lower_s;
    int     index;

    lower_s = malloc(ft_strlen(s) + 1);
    index = 0;
    while(index < ft_strlen(s))
    {
        lower_s[index] = s[index] | 32;
        index++;
    }
    lower_s[index]= '\0';
    if (ft_strcmp(lower_s, "fifo") || ft_strcmp(lower_s, "edf"))
        return lower_s;
    get_error(7);
}
