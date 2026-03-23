/*
** EPITECH PROJECT, 2025
** classhandler
** File description:
** Create and manage classes and entities with this simple lib.
*/

#include "./include/classhandler.h"

entity_t *classhandler_fetchentityname(classhandler_t *classhandler,
    const char *classname, const char *entityname)
{
    return NULL;
}

entity_t *classhandler_fetchentitycomp(classhandler_t *classhandler,
    const char *classname, bool (*comp)(entity_t *entity))
{
    return NULL;
}

entity_t **classhandler_fetchentitiescomp(classhandler_t *classhandler,
    const char *classname, bool (*comp)(entity_t *entity))
{
    return NULL;
}

entity_t *classhandler_fetchentityscore(classhandler_t *classhandler,
    const char *classname, float (*score)(entity_t *entity))
{
    return NULL;
}
