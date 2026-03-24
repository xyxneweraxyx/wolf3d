/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** Main header file of wolf3d
*/

#ifndef WOLF3D_H
    #define WOLF3D_H

    // Standard includes
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <math.h>

    // Custom includes
    #include "./../libs/c_alloc/c_alloc.h"
    #include "./../libs/linkedlist/linkedlist.h"
    #include "./../libs/str/str.h"
    #include "./../libs/buttonfml/buttonfml.h"
    #include "./../libs/setfml/setfml.h"
    #include "./../libs/raycaster/include/raycaster.h"
    #include "./../libs/classhandler/include/classhandler.h"

    // Return codes
    #define WOLF_SUCC 0
    #define WOLF_FAIL 84

// Typedefs

typedef enum gamestate_e {
    GAME_MENU,
    GAME_SETTINGS,
    GAME_PLAY,
    GAME_PAUSED,
} gamestate_t;

typedef struct wolf_s {
    c_alloc_t *alloc;
    setfml_t *setfml;
    buttonfml_t *buttonfml;
    char **map;
    gamestate_t state;
} wolf_t;

// Functions

int connect_callbacks(wolf_t *wolf);
int destroy_return_int(int RET_CODE, wolf_t *wolf);
void *destroy_return_null(wolf_t *wolf);

#endif