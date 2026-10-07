#include "../functions.hpp" // get enums
#include "../runner.hpp" // run level func

//for bounds detection
const int mapsize_R = 8; //rows
const int mapsize_C = 8; //cols

//map of level, consists of Cell enums, using vector cuz its easier to pass through functions/classes
const vector<vector<Cell>> map = { // [row][col]
    {Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W},
    {Cell::W, Cell::S, Cell::N, Cell::N, Cell::N, Cell::N, Cell::N, Cell::W},
    {Cell::W, Cell::N, Cell::N, Cell::N, Cell::X, Cell::N, Cell::N, Cell::W},
    {Cell::W, Cell::N, Cell::N, Cell::N, Cell::N, Cell::N, Cell::N, Cell::W},
    {Cell::W, Cell::N, Cell::N, Cell::N, Cell::F, Cell::N, Cell::N, Cell::W},
    {Cell::W, Cell::N, Cell::N, Cell::N, Cell::N, Cell::N, Cell::N, Cell::W},
    {Cell::W, Cell::N, Cell::N, Cell::N, Cell::N, Cell::N, Cell::G, Cell::W},
    {Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W, Cell::W},
};

int main() {
    runLevelAuto(
        mapsize_R, mapsize_C,
        map, "Test Level"
    );
    return 0;
}

//extra pointz: movement visualizer [V], OOP [V], automation A* [V]
//[V] Program harus mencetak arah setiap pergerakan agar jalur yang dipilih dapat diperiksa dengan mudah. Selain itu, 
//[V] program juga harus menampilkan status ketika bendera berhasil diambil dan ketika seluruh misi telah selesai. 