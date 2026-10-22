#include <iostream>
using namespace std;

//To add the 4 by 4 matrix with its values
int matrix[4][4] = {
    {4, 7, 1, 6},
    {6, 7, 3, 9},
    {3, 8, 1, 2},
    {7, 1, 7, 3}
};

//To set the target Cost
int targetCost = 25;

//To create the function
int countPaths(int row, int col, int cost) {
    cost += matrix[row][col];

    //To stop if the cost is more than 25
    if (cost > targetCost) {
        return 0;
    }

    //To check if it already reached 3 in 4th row and 4th column
    if (row == 3 && col == 3) {
        if (cost == targetCost) {
            return 1;
        }
        return 0;
    }

    //to set the value of the movement
    int right = 0;
    int down = 0;

    //to check if its posible to go right 
    if (col < 3) {
        right = countPaths(row, col + 1, cost);
    }

    //to move down if the value is less than 3
    if (row < 3) {
        down = countPaths(row + 1, col, cost);
    }

    //To sum up the total cost
    return right + down;
}

int main() {
    //To display the matrix
    cout << "Matrix:" << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    //To Display and label the answers
    cout << "\nTarget Cost: " << targetCost << endl;

    int result = countPaths(0, 0, 0);

    cout << "Number of valid paths: " << result << endl;

    return 0;
}
