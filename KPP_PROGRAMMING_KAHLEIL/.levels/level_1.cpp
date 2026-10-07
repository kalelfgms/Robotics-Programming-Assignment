#include "../functions.hpp"
#include "../runner.hpp"

const int mapsize_R = 7; 
const int mapsize_C = 7; 
vector<vector<Cell>> map = { 
    {Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W},
    {Cell::W, Cell::S, Cell::W, Cell::N, Cell::N, Cell::N, Cell::W},
    {Cell::W, Cell::N, Cell::W, Cell::N, Cell::W, Cell::G, Cell::W},
    {Cell::W, Cell::N, Cell::N, Cell::N, Cell::W, Cell::N, Cell::W},
    {Cell::W, Cell::W, Cell::W, Cell::N, Cell::N, Cell::N, Cell::W},
    {Cell::W, Cell::X, Cell::N, Cell::N, Cell::F, Cell::N, Cell::W},
    {Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W},
};

int main() {
    runLevelAuto(
        mapsize_R, mapsize_C,
        map, "Level 1"
    );
    return 0;
}
