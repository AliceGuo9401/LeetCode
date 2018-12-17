#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> intVect(9, 0);                                                                        //intVect包含了9个0
    vector<vector<int>> rows(9, intVect);
    vector<vector<int>> colunms(9, intVect);
    int i(0), j(0);
    for (int m = 0; m <3; ++m) {
        for(int n = 0; n < 3; ++n) {
            vector<int> intVector(9, 0);
            for (i = m * 3; i < m * 3 + 3; ++i) {                                                     //3×3的子框
                for (j = n * 3; j < n * 3 + 3; ++j) {
                    if (board[i][j] != '.') {
                        int temp = board[i][j] - '1';
                        if (++intVector[temp] > 1 || ++rows[i][temp] > 1 || ++colunms[temp][j] > 1)   /**/
                            return false;
                    }
                }
            }
        }
    }
    return true;
}
int main() {
    vector<vector<char >> board {{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
                                 {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
                                 {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
                                 {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
                                 {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
                                 {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
                                 {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
                                 {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
                                 {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};
    bool isvalid = isValidSudoku(board);
    cout << isvalid;
    return 0;
}
