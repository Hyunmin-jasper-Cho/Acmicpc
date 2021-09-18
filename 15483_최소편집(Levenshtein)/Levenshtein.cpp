/*
 Levenshtein Distance
 */

#include <iostream>
#define LM 1000

#define COPY 0
#define REPLACE 1
#define DELETE 1
#define INSERT 1

using namespace std;
int mat[LM + 1][LM + 1] = {0, };
string S, T;

void init_mat();

int main() {
    init_mat();
    
    int sl = (int) S.length(), tl = (int) T.length();
    for (int i = 1; i <= tl; ++i) {
        for (int j = 1; j <= sl; ++j) {
            if (T[i - 1] == S[j - 1]) {
                mat[i][j] = mat[i - 1][j - 1] + COPY;
            } else {
                mat[i][j] = min(mat[i - 1][j] + INSERT, min(mat[i - 1][j - 1] + REPLACE, mat[i][j - 1] + DELETE));
            }
        }
    } cout << mat[tl][sl] << '\n';
    
    return 0;
}

void init_mat() {
    cin >> S >> T;
    
    for (int i = 1; i <= LM; ++i) {
        mat[0][i] = mat[0][i - 1] + DELETE;
        mat[i][0] = mat[i - 1][0] + INSERT;
    }
}
