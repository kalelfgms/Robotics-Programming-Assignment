#pragma once
#include "functions.hpp"
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <utility>
using namespace std;

//pake algo A*

namespace pathfinding {
    inline int manhattan(int r1, int c1, int r2, int c2) {
        return abs(r1 - r2) + abs(c1 - c2);
    }

    inline bool isBlocked(const vector<vector<Cell>>& map, int r, int c, int R, int C) {
        if (r < 0 || r >= R || c < 0 || c >= C) return true;
        Cell cell = map[r][c];
        return cell == Cell::W || cell == Cell::X;
    }

    inline pair<int, int> findCell(const vector<vector<Cell>>& map, int R, int C, Cell target) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (map[r][c] == target) return {r, c};
            }
        }
        return {-1, -1};
    }

    struct OpenItem {
        int f;
        int r, c;
    };
    struct OpenItemCmp {
        bool operator()(const OpenItem& a, const OpenItem& b) const {
            return a.f > b.f; 
        }
    };

    inline vector<Direction> findPath(const vector<vector<Cell>>& map, int R, int C, pair<int, int> start, pair<int, int> goal) {
        vector<Direction> path;
        if (start.first < 0 || goal.first < 0) return path;
        if (start == goal) return path;

        vector<vector<int>> gScore(R, vector<int>(C, INT_MAX));
        vector<vector<pair<int, int>>> parent(R, vector<pair<int, int>>(C, {-1, -1}));
        vector<vector<bool>> closed(R, vector<bool>(C, false));

        priority_queue<OpenItem, vector<OpenItem>, OpenItemCmp> open;

        gScore[start.first][start.second] = 0;
        open.push({manhattan(start.first, start.second, goal.first, goal.second), start.first, start.second});

        static const int dR[4] = {-1, 1, 0, 0};
        static const int dC[4] = {0, 0, -1, 1};

        bool found = false;
        while (!open.empty()) {
            OpenItem cur = open.top();
            open.pop();
            if (closed[cur.r][cur.c]) continue;
            closed[cur.r][cur.c] = true;

            if (cur.r == goal.first && cur.c == goal.second) { found = true; break; }

            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dR[i];
                int nc = cur.c + dC[i];
                if (isBlocked(map, nr, nc, R, C)) continue;
                if (closed[nr][nc]) continue;

                int tentative = gScore[cur.r][cur.c] + 1;
                if (tentative < gScore[nr][nc]) {
                    gScore[nr][nc] = tentative;
                    parent[nr][nc] = {cur.r, cur.c};
                    int h = manhattan(nr, nc, goal.first, goal.second);
                    open.push({tentative + h, nr, nc});
                }
            }
        }

        if (!found) return path;

        vector<pair<int, int>> cells;
        pair<int, int> cur = goal;
        while (!(cur == start)) {
            cells.push_back(cur);
            cur = parent[cur.first][cur.second];
        }
        cells.push_back(start);
        reverse(cells.begin(), cells.end());

        for (size_t i = 1; i < cells.size(); i++) {
            int dr = cells[i].first - cells[i - 1].first;
            int dc = cells[i].second - cells[i - 1].second;
            if (dr == -1) path.push_back(Direction::U);
            else if (dr == 1) path.push_back(Direction::D);
            else if (dc == -1) path.push_back(Direction::L);
            else if (dc == 1) path.push_back(Direction::R);
        }
        return path;
    }

    inline vector<Direction> autoSolve(const vector<vector<Cell>>& map, int R, int C) {
        vector<Direction> full;

        pair<int, int> start = findCell(map, R, C, Cell::S);
        pair<int, int> flag = findCell(map, R, C, Cell::F);
        pair<int, int> goal = findCell(map, R, C, Cell::G);

        pair<int, int> from = start;
        if (flag.first != -1) {
            vector<Direction> leg1 = findPath(map, R, C, start, flag);
            full.insert(full.end(), leg1.begin(), leg1.end());
            from = flag;
        }

        vector<Direction> leg2 = findPath(map, R, C, from, goal);
        full.insert(full.end(), leg2.begin(), leg2.end());

        return full;
    }

}