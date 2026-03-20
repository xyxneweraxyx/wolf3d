/*
** EPITECH PROJECT, 2025
** raycaster
** File description:
** A raycasting lib for wolf3d.
*/

#include "./../include/raycaster.h"
#include "./private.h"

static void ini_vals(raycast_t *raycast, ray_exec_t *data)
{
    data->map_x = str_len(raycast->origin.map[0]);
    data->map_y = 0;
    for (; raycast->origin.map[data->map_y]; data->map_y++);
    if (raycast->result)
        c_free(raycast->result, raycast->alloc);
    raycast->result = NULL;
    data->degree_begin = raycast->origin.degree - raycast->render.degrees / 2;
    data->degree_end = raycast->origin.degree + raycast->render.degrees / 2;
    printf("%f %f\n", data->degree_begin, data->degree_end);
}

static void calculate_dx_dy_2(ray_exec_t *data, float degree)
{
    if (number_in_range_f(degree, 180, .1)) {
        data->dx = -1;
        data->dy = 0;
        return;
    }
    if (degree > 180 && degree < 270) {
        data->dx = -1;
        data->dy = -1;
        return;
    }
    if (number_in_range_f(degree, 270, .1)) {
        data->dx = 0;
        data->dy = -1;
        return;
    }
    if (degree > 270 && degree < 360) {
        data->dx = 1;
        data->dy = -1;
        return;
    }
}

static void calculate_dx_dy_1(ray_exec_t *data, float degree)
{
    if (number_in_range_f(degree, 0, .1)) {
        data->dx = 1;
        data->dy = 0;
        return;
    }
    if (degree > 0 && degree < 90) {
        data->dx = 1;
        data->dy = 1;
        return;
    }
    if (number_in_range_f(degree, 90, .1)) {
        data->dx = 0;
        data->dy = 1;
        return;
    }
    if (degree > 90 && degree < 180) {
        data->dx = -1;
        data->dy = 1;
        return;
    }
}

static void calculate_dx_dy(ray_exec_t *data, float degree)
{
    calculate_dx_dy_1(data, degree);
    calculate_dx_dy_2(data, degree);
}

static size_t single_raycast(raycast_t *raycast, ray_exec_t *data, float degree)
{
    calculate_dx_dy(data, degree);
    printf("degrees %f dx dy %d %d\n", degree, (int)data->dx, (int)data->dy);
    return RAYCAST_SUCC;
}

size_t raycast_raycast(raycast_t *raycast)
{
    ray_exec_t data;

    if (!raycast || !raycast->origin.map || !raycast->origin.map[0])
        return RAYCAST_FAIL;
    ini_vals(raycast, &data);
    for (float degree = data.degree_begin;
        degree <= data.degree_end;
        degree += raycast->calculations.degree_add) {
        printf("%d\n", (int)degree % 360);
        data.degree_modulo = (((int)degree) % 360) + (degree - (int)degree);
        printf("real %f modulo %d modulo add %f modulo end %f\n", degree, ((int)degree % 360), (degree - (int)degree), data.degree_modulo);
        if (single_raycast(raycast, &data, data.degree_modulo))
            return RAYCAST_FAIL;
    }
    return RAYCAST_SUCC;
}