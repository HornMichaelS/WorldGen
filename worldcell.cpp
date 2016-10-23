#include <iostream>
#include <ncurses.h>
#include "worldcell.h"

WorldCell::WorldCell() : cellType(GRASS) {}

char WorldCell::grassChar() const {
    char val;
    if (rand() % 2 == 0) {
        val = '`';
    } else {
        val = ',';
    }

    return val;
}

void WorldCell::outputCell() const {
    start_color();
    const short COLOR_DARK_GREEN = 8;
    const short COLOR_BROWN = 9;
    init_color(COLOR_DARK_GREEN, 0, 100, 0);
    init_color(COLOR_BROWN, 128, 128, 0);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_DARK_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BROWN, COLOR_BLACK);
    char grass[2];
    grass[0] = grassChar();
    grass[1] = 0;
    switch (cellType) {
        case GRASS:
            attron(COLOR_PAIR(1));
            printw(grass);
            attroff(COLOR_PAIR(1));
            break;
        case WATER:
            attron(COLOR_PAIR(2));
            printw("~");
            attroff(COLOR_PAIR(2));
            break;
        case TREE:
            attron(COLOR_PAIR(4));
            printw("|");
            attroff(COLOR_PAIR(4));
            break;
        case TREETOP:
            attron(COLOR_PAIR(3));
            printw("^");
            attroff(COLOR_PAIR(3));
            break;
    }
}