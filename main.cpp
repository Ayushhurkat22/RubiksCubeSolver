#include <iostream>
#include "Model/RubiksCube3dArray.cpp"

int main()
{
    RubiksCube3dArray object3DArray;
    object3DArray.print();

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
    return 0;
}
