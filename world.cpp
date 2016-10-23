#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <ncurses.h>
#include "world.h"

World::World(WorldParameters wp) : seed(wp.seed), 
                                   water_chance(wp.water_chance) {
    // Initialize world grid to a square rect of side length wp.size
    grid.resize(wp.size);
    for (int i = 0; i < wp.size; i++) {
        grid[i].resize(wp.size);
    }

    // Initialize the random number generator
    srand(seed);

    // Randomly change a small number of cells into water cells
    generateWaterSeeds();

    // Grow bodies of water through n iterations
    growType(wp.water_iterations, WATER, 2, 1, 1);
    growType(wp.tree_iterations, TREE, 3, 2, 1);
}

void World::generateWaterSeeds() {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (rand() % water_chance == 0) {
                grid[i][j].cellType = WATER;
            }
        }
    }
}

bool World::cellIsType(int x, int y, CellType type) {
    if (x < 0 || x >= grid[0].size() ||
        y < 0 || y >= grid.size()) {

        return false;
    }

    return grid[y][x].cellType == type;
}

int World::numTypeInNeighborhood(int x, int y, 
                                 int neighborhoodSize, CellType type) {
    int numInNeighborhood = 0;

    for (int i = y - neighborhoodSize; i <= y+neighborhoodSize; i++) {
        for (int j = x - neighborhoodSize; j <= x+neighborhoodSize; j++) {
            if (cellIsType(j, i, type)) {
                numInNeighborhood++;
            }
        }
    }
    return numInNeighborhood;
}

void World::placeEntity(int x, int y, CellType type, int height, int width) {

}

void World::growType(int iterations, CellType type, int fuzziness, 
                     int height, int width) {
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < grid.size(); j++) {
            for (int k = 0; k < grid[0].size(); k++) {
                int searchRadius = fuzziness;
                int numAdjacentWaterCells = 
                    numTypeInNeighborhood(k, j, searchRadius, type);

                int numCellsInSearch = (2*searchRadius + 1) * 
                                       (2 * searchRadius + 1);
                if (rand() % numCellsInSearch < numAdjacentWaterCells) {
                    placeEntity(k, j, type, height, width);
                }
            }
        }
    }
}

void World::outputWorld() {
    std::string gridStr = "";
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            grid[i][j].outputCell();
        }
        printw("\n");
    }
}