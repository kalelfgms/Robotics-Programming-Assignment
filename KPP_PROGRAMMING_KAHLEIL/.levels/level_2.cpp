#include "../functions.hpp"
#include "../runner.hpp"

const int mapsize_R = 9; 
const int mapsize_C = 9; 
vector<vector<Cell>> map = { 
    {Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W}, // WWWWWWWWW
    {Cell::W, Cell::S, Cell::N, Cell::N, Cell::W, Cell::N, Cell::N, Cell::N, Cell::W}, // WSNNWNNNW
    {Cell::W, Cell::N, Cell::W, Cell::N, Cell::W, Cell::N, Cell::W, Cell::G, Cell::W}, // WNWNWNWGW
    {Cell::W, Cell::N, Cell::W, Cell::N, Cell::N, Cell::N, Cell::W, Cell::N, Cell::W}, // WNWNNNWNW
    {Cell::W, Cell::N, Cell::N, Cell::N, Cell::W, Cell::N, Cell::N, Cell::N, Cell::W}, // WNNNWNNNW
    {Cell::W, Cell::W, Cell::W, Cell::N, Cell::W, Cell::N, Cell::N, Cell::W, Cell::W}, // WWWNWNNWW
    {Cell::W, Cell::X, Cell::N, Cell::N, Cell::W, Cell::N, Cell::N, Cell::F, Cell::W}, // WXNNWNNFW
    {Cell::W, Cell::N, Cell::W, Cell::W, Cell::W, Cell::X, Cell::N, Cell::N, Cell::W}, // WNWWWXNNW
    {Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W}, // WWWWWWWWW
};

int main() {
    runLevelAuto(
        mapsize_R, mapsize_C,
        map, "Level 2"
    );
    return 0;
}
