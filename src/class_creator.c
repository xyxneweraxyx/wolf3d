/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** Class creator at initialization.
*/

#include "./../include/wolf3d.h"

int create_players(wolf_t *wolf)
{
    class_t *class = classhandler_classcreate(wolf->classhandler,
        sizeof(player_t), CLASS_PLAYERS);
    entity_t *player = NULL; // que 1 pour l'instant

    if (!class)
        return WOLF_FAIL;
    player = classhandler_entitycreate(wolf->classhandler,
        CLASS_PLAYERS, PARAMS_DEFAULT_NAME);
    if (!player)
        return WOLF_FAIL;
    if (player_setdefault(player)) // -1
        return WOLF_FAIL;
    return WOLF_SUCC;
}

int create_classes(wolf_t *wolf)
{
    classhandler_t *classhandler = classhandler_init();

    if (!classhandler)
        return destroy_return_int(WOLF_FAIL, wolf);
    wolf->classhandler = classhandler;
    if (!classhandler ||
        create_players(wolf) == WOLF_FAIL)
        return destroy_return_int(WOLF_FAIL, wolf);
    return WOLF_SUCC;
}