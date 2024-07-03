#include <iostream>
#include "Model/RubiksCube3dArray.cpp"
#include "Model/RubiksCube1dArray.cpp"
#include "Model/RubiksCubeBitboard.cpp"
#include "Solver/DFSSolver.h"

int main()
{
    RubiksCube3dArray object3DArray;
    object3DArray.print();

    /* MODEL TESTING
    if(object3DArray.isSolved())
    {
        cout<<"SOLVED\n";
    }
    else
    {
        cout<<"NOT SOLVED\n";
    }

    // cout<<"\n";
    // cout<<"Move L called ->\n";
    object3DArray.l();
    object3DArray.print();
    if(object3DArray.isSolved())
    {
        cout<<"SOLVED\n";
    }
    else
    {
        cout<<"NOT SOLVED\n";
    }

    object3DArray.lPrime() ;
    object3DArray.print();
    if(object3DArray.isSolved())
    {
        cout<<"SOLVED\n";
    }
    else
    {
        cout<<"NOT SOLVED\n";
    }
    // object3DArray.print();
    //
    // cout<<"\n";
    // cout<<"Random Shuffle Function called ->\n";
    // object3DArray.randomShuffleCube(3);
    // object3DArray.print();

    cout<<"\n";
    cout<<"Random Shuffle Function called ->\n";
    vector<RubiksCube::MOVE> movesToShuffle = object3DArray.randomShuffleCube(3);
    cout<<"Series of moves applied: ";
    for(auto move: movesToShuffle)
    {
        cout<<object3DArray.getMove(move) <<" ";
    }
    cout<<"\n";
    object3DArray.print();

    if(object3DArray.isSolved())
    {
        cout<<"SOLVED\n";
    }
    else
    {
        cout<<"NOT SOLVED\n";
    }
    */

    RubiksCube3dArray cube1;
    RubiksCube3dArray cube2;

    /* Testing Comparision Operator

    if(cube1==cube2) cout<<"Cubes are equal\n";
    else cout<<"Cubes are not equal\n";

    cube2.l();

    if(cube1==cube2) cout<<"Cubes are equal\n";
    else cout<<"Cubes are not equal\n";

    cube2.lPrime();

    if(cube1==cube2) cout<<"Cubes are equal\n";
    else cout<<"Cubes are not equal\n";
    */

    /* Testing Assignment Operator
    cube1.print();
    cube2.l();
    cube2.print();
    cube2 = cube1;

    cout<<"After assigning cube1 to cube 2:";
    cube2.print();
    */


    /* Testing Hash Function
    cube2.l();
    unordered_map<RubiksCube3dArray,bool, Hash3d> mp1;

    mp1[cube1]=true;
    if(mp1[cube1])
    {
        cout<<"Cube 1 is present\n";
    }
    else
    {
        cout<<"Cube 1 is not present\n";
    }

    if(mp1[cube2])
    {
        cout<<"Cube 2 is present\n";
    }
    else
    {
        cout<<"Cube 2 is not present\n";
    }
    */

    /*
     DFS SOLVER TESTING
    */

    cout<<"Random Shuffle Function called ->\n";
    vector<RubiksCube::MOVE> movesToShuffle = object3DArray.randomShuffleCube(6);
    cout<<"Series of moves applied: ";
    for(auto move: movesToShuffle)
    {
        cout<<object3DArray.getMove(move) <<" ";
    }
    cout<<"\n";
    object3DArray.print();

    DFSSolver<RubiksCube3dArray, Hash3d> dfssolver(object3DArray,7);
    vector<RubiksCube::MOVE> movesToSolve=dfssolver.solve();
    dfssolver.rubiksCube.print();
    for(auto move: movesToSolve) cout<<object3DArray.getMove(move)<<" ";
    cout<<"\n";
    return 0;
}
