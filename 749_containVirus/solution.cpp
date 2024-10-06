#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// 0: uninfected
// 1: infected
// 2: will be infected the next day
// 11: infected, belonging to the set 1
// 21: infected, belonging to the set 2

class Solution {
    int numSet = 0;
    // the number of threatened cells per set and the 
    // number of walls to build per turn
    vector <int> numberThreatened;
    vector<int> numberWalls;

    // the virus in set1 have their indices stored in set1
    vector<vector<int>> setID;
public:

    void addToSet(vector<vector<int>>& isInfected, int i, int j, int m, int n) {
        int mySet = isInfected[i][j] / 10;
        int miniP1 = min(i+1,m-1);
        int minjP1 = min(j+1, n-1);
        // down
        if ((isInfected[miniP1][j] %2 != 0) && (isInfected[miniP1][j]/10 == 0)) {
            isInfected[miniP1][j] += mySet*10;
            setID[mySet-1].push_back(i*100+j);
        }
        
        // right
        if ((isInfected[i][minjP1] % 2 != 0) && (isInfected[i][minjP1]/10 == 0)) {
            isInfected[i][minjP1] += mySet*10;
            setID[mySet-1].push_back(i*100+j);
        }
    }

    void integrateToSet(vector<vector<int>>& isInfected, int i, int j, int m, int n) {
        int maxiM1 = max(i-1, 0);
        int maxjM1 = max(j-1,0);
        int minjP1 = min(j+1, n-1);
        // top
        if ((isInfected[maxiM1][j] %2 != 0) && (isInfected[maxiM1][j]/10 != 0))
            isInfected[i][j] = isInfected[maxiM1][j];
        // left
        if ((isInfected[i][maxjM1] %2 != 0) && (isInfected[i][maxjM1]/10 != 0))
            isInfected[i][j] = isInfected[i][maxjM1];
        // right
        if ((isInfected[i][minjP1] %2 != 0) && (isInfected[i][minjP1]/10 != 0))
            isInfected[i][j] = isInfected[i][minjP1];
        // down, not needed. Impossible for the cell below to be already in a set, but not 
        // the cell [i][j], isn't it?

        // not belonging to any set, we create one!
        if (isInfected[i][j] / 10 == 0) {
            this->numSet++;
            isInfected[i][j] += numSet*10;
            setID.push_back({i*100+j});
            numberThreatened.push_back(0);
            numberWalls.push_back(0);
        }
    }

    void calculateThreatenedCells(vector<vector<int>>& isInfected, int i, int j, int m, int n) {
        int maxiM1 = max(i-1, 0);
        int miniP1 = min(i+1, m-1);
        int maxjM1 = max(j-1,0);
        int minjP1 = min(j+1, n-1);
        int mySet = isInfected[i][j] / 10;

        // top
        if (isInfected[maxiM1][j] == 0) {
            this->numberThreatened[mySet-1]++;
            isInfected[maxiM1][j] = 2;
        }
        // right
        if (isInfected[i][minjP1] == 0){
            this->numberThreatened[mySet-1]++;
            isInfected[i][minjP1] = 2;
        }
        // left
        if (isInfected[i][maxjM1] == 0) {
            this->numberThreatened[mySet-1]++;
            isInfected[i][maxjM1] = 2;
        }
        // bottom
        if (isInfected[miniP1][j] == 0) {
            this->numberThreatened[mySet-1]++;
            isInfected[miniP1][j] = 2;
        }
    }

    void calculateWalls(vector<vector<int>>& isInfected, int i, int j, int m, int n) {
        int maxiM1 = max(i-1, 0);
        int miniP1 = min(i+1, m-1);
        int maxjM1 = max(j-1,0);
        int minjP1 = min(j+1, n-1);
        int mySet = isInfected[i][j] / 10;

        // top
        if (isInfected[maxiM1][j] == 2)
            this->numberWalls[mySet-1]++;
        // right
        if (isInfected[i][minjP1] == 2)
            this->numberWalls[mySet-1]++;
        // left
        if (isInfected[i][maxjM1] == 2)
            this->numberWalls[mySet-1]++;
        // bottom
        if (isInfected[miniP1][j] == 2)
            this->numberWalls[mySet-1]++;
    }

    int putWalls() {
        int maxThreatenedCells = 0;
        int id;
        for (int i = 0; i < this->numSet; ++i) {
            if (numberThreatened[i] > maxThreatenedCells) {
                maxThreatenedCells = numberThreatened[i];
                id = i;
            }
        }
        return numberWalls[id];
    }

    int containVirus(vector<vector<int>>& isInfected) {
        int numRow = isInfected.size();
        int numCol = isInfected[0].size();
        if (numRow == 1 && numCol == 1)
            return 0;

        int ret = 0;

        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < numCol; ++j) {
                if (isInfected[i][j] % 2 == 0)
                    continue;

                integrateToSet(isInfected,i,j,numRow,numCol);
                addToSet(isInfected,i,j,numRow,numCol);
                calculateThreatenedCells(isInfected,i,j,numRow,numCol);
                calculateWalls(isInfected,i,j,numRow,numCol);
            }
        }

        // put the walls
        ret += putWalls();
        // vector<int> setThreats;
        return ret;
    }
};

void printMat(vector<vector<int>>& virus) {
    for (int i = 0; i < virus.size(); ++i) {
        cout<<endl;
        for (int j = 0; j < virus[0].size(); ++j) {
            cout << virus[i][j] << " ";
        }
    }
    cout << endl;
}
int main() {
    Solution s = Solution();
    vector<vector<int>> virus1 = {{0,1,0,0,0,0,0,1},{0,1,0,0,0,0,0,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0}};
    cout << s.containVirus(virus1) << endl;
    
    printMat(virus1);

    // vector<vector<int>> virus2 = {{1,1,1},{1,0,1},{1,1,1}};
    // s.containVirus(virus2);
    // printMat(virus2);
}