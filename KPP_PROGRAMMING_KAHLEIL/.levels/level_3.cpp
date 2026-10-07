#include "../functions.hpp"
#include "../runner.hpp"

const int mapsize_R = 11; 
const int mapsize_C = 11; 
vector<vector<Cell>> map = { 
    {Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W}, // WWWWWWWWWWW
    {Cell::W, Cell::S, Cell::N, Cell::N, Cell::W, Cell::N, Cell::N, Cell::N, Cell::N, Cell::N, Cell::W}, // WSNNWNNNNNW 
    {Cell::W, Cell::N, Cell::W, Cell::N, Cell::W, Cell::N, Cell::W, Cell::W, Cell::W, Cell::N, Cell::W}, // WNWNWNWWWNW
    {Cell::W, Cell::N, Cell::W, Cell::N, Cell::N, Cell::N, Cell::W, Cell::G, Cell::W, Cell::N, Cell::W}, // WNWNNNWGWNW
    {Cell::W, Cell::N, Cell::N, Cell::N, Cell::W, Cell::N, Cell::W, Cell::N, Cell::W, Cell::N, Cell::W}, // WNNNWNWNWNW
    {Cell::W, Cell::W, Cell::W, Cell::N, Cell::W, Cell::N, Cell::N, Cell::N, Cell::W, Cell::N, Cell::W}, // WWWNWNNNWNW
    {Cell::W, Cell::N, Cell::N, Cell::N, Cell::W, Cell::W, Cell::W, Cell::N, Cell::W, Cell::N, Cell::W}, // WNNNWWWNWNW
    {Cell::W, Cell::N, Cell::W, Cell::N, Cell::N, Cell::X, Cell::N, Cell::N, Cell::W, Cell::N, Cell::W}, // WNWNNXNNWNW
    {Cell::W, Cell::N, Cell::W, Cell::N, Cell::W, Cell::W, Cell::W, Cell::N, Cell::W, Cell::F, Cell::W}, // WNWNWWWNWFW
    {Cell::W, Cell::X, Cell::N, Cell::N, Cell::N, Cell::N, Cell::X, Cell::N, Cell::N, Cell::N, Cell::W}, // WXNNNNXNNNW
    {Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W}, // WWWWWWWWWWW
};

int main() {
    runLevelAuto(
        mapsize_R, mapsize_C,
        map, "Level 3"
    );
    return 0;
}
