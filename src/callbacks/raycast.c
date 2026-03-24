/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** Raycast callbacks to setfml.
*/

#include "./../../include/wolf3d.h"
#include "./callbacks.h"

static size_t raycast_function(setfml_t *setfml, void *userdata)
{
    raycast_t *ray = (raycast_t *)setfml->userdata;
    raycast_raycast(ray, setfml);
    return SETFML_SUCC;
}

static size_t handle_keys(setfml_t *setfml, void *userdata)
{
    raycast_t *ray = (raycast_t *)setfml->userdata;
    float speed = 0.02f;
    float rot_speed = 0.5f;

    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        ray->origin.origin.x += cosf(ray->origin.degree * DEG_TO_RAD) * speed;
        ray->origin.origin.y += sinf(ray->origin.degree * DEG_TO_RAD) * speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        ray->origin.origin.x -= cosf(ray->origin.degree * DEG_TO_RAD) * speed;
        ray->origin.origin.y -= sinf(ray->origin.degree * DEG_TO_RAD) * speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        ray->origin.degree -= rot_speed;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        ray->origin.degree += rot_speed;
    return SETFML_SUCC;
}

int connect_raycasts(wolf_t *wolf)
{
    entity_t *entity = classhandler_fetchentityname(wolf->classhandler,
        CLASS_PLAYERS, NULL);
    player_t *plr = NULL;
    raycast_t *raycast = NULL;

    if (!entity || !entity->data)
        return WOLF_FAIL;
    plr = (player_t *)entity->data;
    raycast = raycast_create(wolf->map, &(ray_twod_t){plr->pos.x+14, plr->pos.z+14});
    if (!raycast)
        return WOLF_FAIL;
    setfml_add(wolf->setfml, &(setfml_func_comp_t){NULL, &raycast_function},
        "raycast", LOOP_DRAW);
    setfml_add(wolf->setfml, &(setfml_func_comp_t){NULL, &handle_keys},
        "raycast", LOOP_DRAW);
    wolf->raycast = raycast;
    return WOLF_SUCC;
}