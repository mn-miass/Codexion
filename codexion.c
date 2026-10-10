#include "codexion.h"
#include "parser.h"
#include <stdlib.h>
#include <stdio.h>


t_input parser(int argc, char **argv)
{
    int *integer_inputs;
    char *scheduler;
    t_input input;

    integer_inputs = get_int_arguments(argv + 1, argc - 1);
    if (integer_inputs == NULL)
        get_error(9);
    scheduler = get_char_argument(argv[8]);
    if (scheduler == NULL)
    {
        free(integer_inputs);
        get_error(9);
    }
    input = fill_input_struct(integer_inputs, scheduler);
    return input;
}


int main(int argc, char **argv)
{
    t_input input;

    input = parser(argc, argv);
}
