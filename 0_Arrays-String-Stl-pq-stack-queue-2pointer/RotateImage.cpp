//Link =  https://leetcode.com/problems/rotate-image/submissions/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }

        /*If 90* anticlock wise*/
        /* // Step 2: Reverse each column
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                std::swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }*/
    }
};


void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
}


/*For 270*/
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                std::swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }

        // Step 3: Reverse the entire matrix
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                std::swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};
