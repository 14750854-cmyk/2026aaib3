class Solution {
public: // 大資料結構 moves，裡面裝 中資料結構 vector<int> move，裡面裝小資料結構 int i, j
    string tictactoe(vector<vector<int>>& moves) {
        int a[3][3] = {0}; // 用 C語言的陣列，模擬井字遊戲的3x3共9個格子，先放 0
        string result[3] = {"Draw", "A", "B"}; // 結束的字串
        int who = 1; // 現在輪到誰 who 來下棋 1:A, 2:B

        for (vector<int> move : moves) { // 迴圈，逐一處理中資料結構
            int i = move[0], j = move[1];
            a[i][j] = who; // 現在輪到誰 who 來下棋

            // 檢查 8 種連線勝利條件
            if (a[0][0]==who && a[0][1]==who && a[0][2]==who) return result[who]; // 上橫
            if (a[1][0]==who && a[1][1]==who && a[1][2]==who) return result[who]; // 中橫
            if (a[2][0]==who && a[2][1]==who && a[2][2]==who) return result[who]; // 下橫

            if (a[0][0]==who && a[1][0]==who && a[2][0]==who) return result[who]; // 左直
            if (a[0][1]==who && a[1][1]==who && a[2][1]==who) return result[who]; // 中直
            if (a[0][2]==who && a[1][2]==who && a[2][2]==who) return result[who]; // 右直

            if (a[0][0]==who && a[1][1]==who && a[2][2]==who) return result[who]; // 斜線左上、右下
            if (a[2][0]==who && a[1][1]==who && a[0][2]==who) return result[who]; // 斜線左下、右上

            // 切換玩家 (1變2, 2變1)
            if (who == 1) who = 2;
            else who = 1;
        }

        // 註：圖片最後註解寫「這是錯的!!!」，因為遊戲未結束時可能為 "Pending"
        return "Draw"; // 最後離開迴圈，沒有人得勝，就平手 Draw
    }
};
