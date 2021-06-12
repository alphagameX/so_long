#include "../source/so_long.h"


void foreach_input(t_input input, t_game *game, int (*f)(t_game *, int))
{
    int i;

    i = 0;
    while(i < input.count)
    {
        f(game, input.list[i]);
        i++;
    }
}

int search_input(t_input input, int key)
{
    int i;

    i = 0;
    while(i < input.count)
    {
        if(input.list[i] == key)
            return (1);
        i++;
    }
    return (0);
}


void add_input(t_input *input, int key)
{
    int *new;
    int i;

    i = 0;
    new = malloc(sizeof(int) * (input->count + 1));
    if(!new)
        exit(1);
    while(i < input->count)
    {
        new[i] = input->list[i];
        i++;
    }
    new[i] = key;
    if(input->count > 0)
        free(input->list);
    input->count++;
    input->list = new;
}

void remove_input(t_input *input, int key)
{
    int *new;
    int i;
    int e;

    i = 0;
    e = 0;
    new = malloc(sizeof(int) * (input->count - 1));
    if(!new)
        exit(0);
    while(i < input->count)
    {
        if(input->list[i] != key)
        {
            new[e] = input->list[i];
            e++;
        }
        i++;
    }
    free(input->list);
    input->count--;
    input->list = new;
}

void print_input(t_input input)
{
    int i;

    i = 0;
    while(i < input.count)
    {
        printf("%d\n", input.list[i]);
        i++;
    }

    printf("input list: %d\n", input.count);
}