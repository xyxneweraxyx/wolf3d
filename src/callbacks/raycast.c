/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** Raycast callbacks to setfml.
*/

#include "./../../include/wolf3d.h"
#include "./callbacks.h"

int connect_raycasts(wolf_t *wolf)
{
    entity_t *entity = classhandler_fetchentityname(wolf->classhandler,
        CLASS_PLAYERS, NULL);
    player_t *plr = NULL;
    raycast_t *raycast = NULL;

    if (!entity || !entity->data)
        return WOLF_FAIL;
    plr = (player_t *)entity->data;
    raycast = raycast_create(wolf->map, &(ray_twod_t){plr->pos.x, plr->pos.z});
    if (!raycast)
        return WOLF_FAIL;
    wolf->raycast = raycast;
    return WOLF_SUCC;
}