#include "../source/so_long.h"

/*
* create new array
* t_sarray = new_sarray();
*/
t_sarray new_sarray()
{
    t_sarray array;
    array.buffer = NULL;
    array.count = 0;
    return array;
}

/*
* add string to array
* push_array(char* to t_sarray*);
*/
void push_sarray(char *new_line, t_sarray *array)
{
    char **new;
    int i;

    i = 0;
    new = malloc(sizeof(char *) * (array->count + 1));
    while(i < array->count)
    {
        new[i] = array->buffer[i];
        i++;
    }
    new[i] = new_line;
    array->buffer = new;
    array->count++;
}

/*
* print sarray
* print_sarray(t_sarray);
*/
void print_sarray(t_sarray array)
{
    int i;

    i = 0;
    while(i < array.count)
    {
        ft_putstr(array.buffer[i]);
        ft_putchar('\n');
        i++;
    }

   
}