#include "maze.h"
#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>

using namespace std;

DisjointSets Maze::getSets() const {
    return maze;
}

void Maze::printMaze() const
{
    cout << setw(3) << " ";
    for (int j=0; j<ncols; j++) {
        cout << setw(6) << "______";
    }
    for (int i=0; i<nrows; i++) {
        cout << endl;
        cout << setw(3) << "|";
        for (int j=0; j<ncols-1; j++) {
            int val = i*nrows+j;
            cout << setw(3) << val<<setw(3);
            if (find(noWalls.begin(),noWalls.end(),pair<int,int>(val,val+1)) != noWalls.end())
                cout << " ";
            else
                cout <<" | ";
        }
        int val = i*nrows+ncols-1;
        cout << setw(3) << val<<setw(3) << "|";
        cout <<endl;
        cout << setw(3) << " ";
        for (int j=0; j<ncols; j++) {
            int val = i*nrows+j;
            if (i<nrows-1) {
                if (find(noWalls.begin(), noWalls.end(), pair<int, int>(val, val + ncols)) != noWalls.end())
                    cout << setw(6) << " ";
                else
                    cout << setw(6) << "______";
            } else
                cout << setw(6) << "______";
        }

    }
    cout <<endl << endl;
}



// a implementar

Maze::Maze(int rows, int cols) {
    this->maze = DisjointSets(rows * cols);
    this->nrows = rows;
    this->ncols = cols;
    this->noWalls = {};
}

vector<int> Maze::getNeighbours(int x) const {
    vector<int> res;
    return res;
}

void Maze::buildRandomMaze() {
    int r1 = this->getSets().find(0);
    int r2 = this->getSets().find(1);
    this->getSets().unionSets(r1,r2);
    noWalls.push_back(make_pair(12, 17));
}

