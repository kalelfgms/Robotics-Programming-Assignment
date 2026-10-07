#include "classes.hpp"
#include "functions.hpp"
#include "pathfinding.hpp"

void runLevel(int mapsize_R, int mapsize_C, const vector<vector<Cell>>& map, const vector<Direction>& movements, string botName) {
    int moves = movements.size();
    level lvl(
        botName, false, mapsize_R, mapsize_C, map, moves);

    vector<int> startpos = lvl.getPos(Cell::S); // get S position
    lvl.setPos( //start at S
        startpos[0], startpos[1], 
        startpos[0], startpos[1]
    );
    lvl.render("Start");

    lvl.running = true;
    for (int c = moves; c >= 0; c--){ // main movement loop
        if (c == 0) {lvl.running = false; break;}// out of moves, stop loop
        if (!lvl.running) {break;}

        lvl.moveTo(movements[moves-c]); 
    }
}

void runLevelAuto(int mapsize_R, int mapsize_C, const vector<vector<Cell>>& map, string botName) {
    vector<Direction> movements = pathfinding::autoSolve(map, mapsize_R, mapsize_C);

    if (movements.empty()) {
        print("< No Path >");
        return;
    }

    runLevel(mapsize_R, mapsize_C, map, movements, botName);
}