/*
** EPITECH PROJECT, 2025
** raycaster
** File description:
** A raycasting lib for wolf3d.
*/

#include "./../include/raycaster.h"
#include "./private.h"

int str_len(const char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i;
}
