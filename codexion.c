#include "codexion.h"
#include "coder.h"
#include "structurs_data.h"
#include "parser.h"
#include <stdlib.h>
#include <stdio.h>


t_input parser(int argc, char **argv)
{
    int     *integer_inputs;
    int     scheduler;
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


t_sim   *creat_sim(int argc, char **argv)
{
    t_sim       *sim;

    sim = malloc(sizeof(t_sim))
    if (sim == NULL)
        return NULL;
    sim->cfg = parser(argc, argv);
    sim->coders = create_coders(sim->cfg);
    if (sim->coders == NULL)
        return NULL;
    sim->dongles = create_dongles(sim->cfg);
    if (sim->dongles == NULL)
    {
        free(sim->coders);
        return NULL;
    }
    return &sim;
}


int main(int argc, char **argv)
{
    t_sim       *sim;

    sim = creat_sim(argc, argv);
    if (sim == NULL)
        return 0;

}
