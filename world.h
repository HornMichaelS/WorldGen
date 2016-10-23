#ifndef _WORLD_
#define _WORLD_

#include <vector>
#include <string>
#include "WorldCell.h"

struct WorldParameters {
    int size;
    int seed;
    int water_iterations;
    int tree_iterations;
    double water_chance;
};

class World {
public:
    World(WorldParameters wp);

    // A function to print the world to a string
    void outputWorld();

private:
    // Private member variables
    std::vector< std::vector<WorldCell> > grid;
    int seed;
    int water_chance;

    // Private member functions
    void generateWaterSeeds();
    void growType(int iterations, CellType type, int fuzziness, int height, int width);
    void placeEntity(int x, int y, CellType type, int height, int width);
    bool cellIsType(int x, int y, CellType type);
    int numTypeInNeighborhood(int x, int y, 
                              int neighborhoodSize, CellType type);
};

#endif // _WORLD_