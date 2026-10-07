#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

enum class Cell {S, F, G, X, W, R, N, T};
enum class Direction {U, D, L, R};

string cellChar(Cell c){
    switch (c){
        case Cell::S: return " S"; // start
        case Cell::F: return " F"; // flag
        case Cell::G: return " G"; // goal
        case Cell::X: return " X"; // kill
        case Cell::W: return " #"; // wall
        case Cell::R: return " R"; // bot
        case Cell::N: return "  "; // empty
        case Cell::T: return " +"; // trail
        default: return "";
    }
}

int movementDelay = 600; // ms
void print(const string& text, bool newLine = true){
    if (newLine == false){
        cout<<text;
    }
    else if (newLine == true){
        cout<<text<<endl;
    }
}

void delay(int time){
    this_thread::sleep_for(chrono::milliseconds(time));
}

string posStr(const vector<int>& pos){
    if (pos.size() < 2 || pos[0] < 0 || pos[1] < 0) return "(none)";
    return "(" + to_string(pos[0]) + "," + to_string(pos[1]) + ")";
}

void printDivider(){
    print("=============================");
}

void printGrid(int R, int C, const vector<vector<Cell>>& mapRef){
    for (int row = 0; row < R; row++){
        for (int col = 0; col < C; col++){
            print(cellChar(mapRef[row][col]), false);
        }
        print("");
    }
}