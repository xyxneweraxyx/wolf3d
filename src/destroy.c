/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** Helper functions to destroy objects.
*/

#include "./../include/wolf3d.h"

// A supprimer plus tard du coup
static void free_map(char **map)
{
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}

int destroy_return_int(int RET_CODE, wolf_t *wolf)
{
    if (!wolf)
        return RET_CODE;
    if (wolf->buttonfml)
        buttonfml_destroy(wolf->buttonfml);
    if (wolf->setfml)
        setfml_destroy(wolf->setfml);
    if (wolf->map)
        free_map(wolf->map);
    if (wolf->classhandler)
        classhandler_destroy(wolf->classhandler);
    if (wolf->alloc)
        c_delete(wolf->alloc, true);
    return RET_CODE;
}

void *destroy_return_null(wolf_t *wolf)
{
    if (!wolf)
        return NULL;
    if (wolf->buttonfml)
        buttonfml_destroy(wolf->buttonfml);
    if (wolf->setfml)
        setfml_destroy(wolf->setfml);
    if (wolf->map)
        free_map(wolf->map);
    if (wolf->classhandler)
        classhandler_destroy(wolf->classhandler);
    if (wolf->alloc)
        c_delete(wolf->alloc, true);
    return NULL;
}