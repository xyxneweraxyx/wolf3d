/*
** EPITECH PROJECT, 2025
** raycaster
** File description:
** A raycasting lib for wolf3d.
*/

#include "./../include/raycaster.h"

raycast_t *raycast_create(char **map, ray_twod_t origin)
{
    c_alloc_t *alloc = c_ini((uint16_t)10);
    raycast_t *raycast = NULL;

    if (!alloc)
        return NULL;
    raycast = c_alloc(sizeof(raycast_t), 1, alloc);
    if (!raycast)
        return NULL;
    raycast->result = NULL;
    raycast->alloc = alloc;
    raycast->origin.degree = 0;
    raycast->origin.wall = '1';
    raycast->origin.map = map;
    raycast->origin.origin = origin;
    raycast->render.degrees = 70;
    raycast->render.distance = 1;
    raycast->render.height = 0;
    raycast->calculations.degree_add = 1;
    return raycast;
}

void raycast_destroy(raycast_t *raycast)
{
    if (!raycast || !raycast->alloc)
        return;
    c_delete(raycast->alloc, true);
}