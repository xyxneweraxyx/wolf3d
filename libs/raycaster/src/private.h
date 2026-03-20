/*
** EPITECH PROJECT, 2025
** raycaster
** File description:
** A raycasting lib for wolf3d.
*/

#ifndef RAYCAST_PRIVATE
    #define RAYCAST_PRIVATE

    #include "./../include/raycaster.h"

// Typedefs

typedef struct ray_exec_s {

    size_t map_x; // X size of the currently stored map.
    size_t map_y; // Y size of the currently stored map.

    float degree_begin; // The beginning point of the degrees for the raycast.
    float degree_end; // The end point of the degrees for the raycast.

    float degree_modulo; // The degrees with a modulo 360 applied.

    int8_t dx; // The amount added when analyzing a new square on the x axis.
    int8_t dy; // The amount added when analyzing a new square on the y axis.

} ray_exec_t;

// Functions

/// Math functions

// Returns 1 if a float number is between base - range and base + range.
size_t number_in_range_f(float number, float base, float range);

// Returns 1 if an int number is between base - range and base + range.
size_t number_in_range_i(int number, int base, int range);

/// String functions
int str_len(const char *str);

#endif