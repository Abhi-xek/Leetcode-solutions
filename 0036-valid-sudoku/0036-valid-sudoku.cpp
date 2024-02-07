class Solution {
// private:
//     bool traverse(int rows ,int n, int col, int m, vector<vector<char>>& b){
//         unordered_set<char>st; 
//         for(int i = rows; i<=n; i++){
//             for(int j = col; j<=m; j++){
//                   if(b[i][j] == '.') continue;

//                 if(st.find(b[i][j]) != st.end()) return false;

//                 st.insert(b[i][j]);
//             }
//         }
//         return true;
//     }
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        // //validating rows
        // for(int rows = 0; rows < 9; rows++){
        //     unordered_set<char>st;

        //     for(int col = 0; col < 9; col++){
        //         if(b[rows][col] == '.') continue;

        //         if(st.find(b[rows][col]) != st.end()) return false;

        //         st.insert(b[rows][col]);
        //     }
        // }

        // //validating col
        // for(int col = 0; col < 9; col++){
        //     unordered_set<char>st;
        //     for(int rows = 0; rows < 9; rows++){
        //         if(b[rows][col] == '.') continue;

        //         if(st.find(b[rows][col]) != st.end()) return false;

        //         st.insert(b[rows][col]);
        //     }
        // }

        // //validating each sub boxes
        // for(int row = 0; row < 9; row+=3){
        //     int er = row + 2; 
        //     for(int col = 0; col < 9; col += 3){
        //         int ec = col + 2; 
        //         if(!traverse(row, er, col, ec, b)) return false;
        //     }
        // }

        // return true;

        unordered_set<string>st;

        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(b[i][j] == '.') continue;

                string row = string(1, b[i][j]) + "_row_" + to_string(i);
                string col = string(1, b[i][j]) + "_col_" + to_string(j);
                string box = string(1, b[i][j]) + "_box_" + to_string(i/3) + to_string(j/3);

                if(st.find(row) != st.end() || st.find(col) != st.end() ||st.find(box) != st.end()) return false;
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return true;
    }
};