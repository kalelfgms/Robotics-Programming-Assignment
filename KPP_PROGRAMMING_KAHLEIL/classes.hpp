#pragma once
#include "functions.hpp"

class level {
    private:
        string mapName;
        bool flagTaken;
        int map_R;
        int map_C;
        vector<vector<Cell>> map; // in current level, assign map here

        int totalMoves;
        int movesLeft;

        vector<int> startPos;
        vector<int> flagPos;
        vector<int> goalPos;

        //positional values
        int crnt_R;
        int crnt_C;
        int prev_R;
        int prev_C;

        vector<int> findInMap(const vector<vector<Cell>>& mapRef, const Cell& target){
            for (int row = 0; row < map_R; row++){
                for (int col = 0; col < map_C; col++){
                    if (mapRef[row][col] == target) return {row, col};
                }
            }
            return {-1, -1};
        }

    public:
        bool running = false;
        level(const string& a, bool b, int R, int C, const vector<vector<Cell>>& mapRef, int totalMovesIn)
            : mapName(a), flagTaken(b), map_R(R), map_C(C), map(mapRef),
              totalMoves(totalMovesIn), movesLeft(totalMovesIn) {
            startPos = findInMap(mapRef, Cell::S);
            flagPos  = findInMap(mapRef, Cell::F);
            goalPos  = findInMap(mapRef, Cell::G);
        }

        vector<int> getPos(const Cell& targetCell){
            switch (targetCell){
                case Cell::R: return {crnt_R, crnt_C};
                default:
                    return findInMap(map, targetCell);
            }
        }

        Cell getCell(int R, int C){
            return map[R][C];
        }

        const vector<vector<Cell>>& getMap() const {
            return map;
        }

        //   print layout
        //   [lvlname]
        //   ----------------------
        //   <status>
        //   <grid>
        //   ----------------------
        //   > last move <
        //   [Moves Left: x/y]
        //   ----------------------
        //   [Start/Flag/Goal positions]
        //   [Total Moves: y]

        void render(const string& lastMoveLabel){ // visualizerrrrrr
            print("[" + mapName + "]");
            printDivider();

            if (flagTaken) {
                print("< MISSION ACCOMPLISHED! >");
            } else {
                print("< FLAG NOT CAPTURED.... >");
            }

            printGrid(map_R, map_C, map);
            printDivider();

            print("> " + lastMoveLabel + " <");
            print("[Moves Left: " + to_string(movesLeft) + "/" + to_string(totalMoves) + "]");
            printDivider();

            print("[Start: " + posStr(startPos) + "]");
            print("[Flag : " + posStr(flagPos) + "]");
            print("[Goal : " + posStr(goalPos) + "]");
            print("[Total Moves: " + to_string(totalMoves) + "]");
        }

        void setPos(int new_R, int new_C, int old_R, int old_C){
            map[old_R][old_C] = Cell::T;
            prev_R = old_R;
            prev_C = old_C;

            map[new_R][new_C] = Cell::R;
            crnt_R = new_R;
            crnt_C = new_C;
        }

        bool cellCheck(int target_R, int target_C){
            bool canMove = true;
            Cell targetCell = getCell(target_R, target_C);

            //bounds check
            if (target_R >= map_R || target_R < 0 || target_C >= map_C || target_C < 0){
                running = false;
                canMove = false;
                return canMove;
            }else { //in bounds
                switch (targetCell){
                    case Cell::W:
                        running = false;
                        canMove = false;
                        return canMove;
                    case Cell::X:
                        running = false;
                        canMove = false;
                        return canMove;
                    case Cell::F:
                        running = true;
                        canMove = true;
                        flagTaken = true;
                        return canMove;
                    case Cell::G:
                        running = false;
                        canMove = true;
                        return canMove;
                    default:
                        return canMove;
                };
            }
            return canMove;
        }

        void moveTo(Direction dir){
            delay(movementDelay);
            if (running){ system("cls"); } // clears after every move, dont clear final move

            int dR = 0;
            int dC = 0;
            string label;
            switch (dir){
                case Direction::U:
                    dR = -1;
                    label = "Up";
                    break;
                case Direction::D:
                    dR = 1;
                    label = "Down";
                    break;
                case Direction::L:
                    dC = -1;
                    label = "Left";
                    break;
                case Direction::R:
                    dC = 1;
                    label = "Right";
                    break;
            }

            if (movesLeft > 0) movesLeft--; 

            if (cellCheck(crnt_R + dR, crnt_C + dC)) {
                setPos(
                    crnt_R + dR, crnt_C + dC,
                    crnt_R, crnt_C
                );
            }

            render(label);
        }


    };