#include <iostream>
#include <string>
#include <unistd.h>
#include <ncurses.h>
#include "world.h"

using namespace std;

template<typename T>
void prompt(string msg, T &value) {
    cout << msg;

    string user_response;
    cin >> value;
}

int main() {
    ios_base::sync_with_stdio(false);
    WorldParameters wp;

    prompt("World size: ", wp.size);
    prompt("Seed value: ", wp.seed);
    prompt("Water probability is 1 out of: ", wp.water_chance);
    prompt("Water body size: ", wp.iterations);

    int last_iteration = wp.iterations;

    initscr();
    start_color();

    for (int i = 0; i < last_iteration; i++) {
        wp.iterations = i;
        World myWorld(wp);
        myWorld.outputWorld();
        refresh();
        move(0, 0);
        usleep(80*1000);
    }

    getch();

    endwin();

    return 0;
}