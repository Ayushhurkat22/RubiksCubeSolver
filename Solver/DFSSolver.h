//
// Created by Ayush Hurkat on 03-07-2024.
//
#include<bits/stdc++.h>
#include "../Model/RubiksCube.h"
#ifndef DFSSOLVER_H
#define DFSSOLVER_H

// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class DFSSolver {
private:

    vector<RubiksCube::MOVE> moves;
    int max_search_depth;

    //    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        //If Rubiks cube is solved: BASE CASE
        if (rubiksCube.isSolved()) return true;
        //If Depth Reached: PRUNING
        if (dep > max_search_depth) return false;
        //18 different operations that is 18 different edges
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;

    DFSSolver(T _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<RubiksCube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};

#endif //DFSSOLVER_H
