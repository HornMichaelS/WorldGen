#ifndef _WORLDCELL_
#define _WORLDCELL_

#include <iostream>

enum CellType {WATER, GRASS, TREE, TREETOP};

class WorldCell {
public:
    WorldCell();

    void outputCell() const;

    CellType cellType;
private:
    char grassChar() const;
};

#endif // _WORLDCELL_