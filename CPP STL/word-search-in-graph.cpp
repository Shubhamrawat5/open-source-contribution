//PROBLEM : https://leetcode.com/problems/word-search/
// Asked in Intuit Interview

class Solution {
public:
    
    bool dfs(vector<vector<char>>& board,int count, int i, int j, int m, int n, string& word)
    {
        if(word.size()==count) return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[count]) return false;
        
        char c = board[i][j];
        board[i][j] = ' ';
        bool res = dfs(board, count+1, i+1,j,m,n,word) || dfs(board,count+1,i-1,j,m,n,word) || dfs(board, count+1,i,j+1,m,n,word) || dfs(board, count+1,i,j-1,m,n,word);
        board[i][j] = c;
        return res;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false; 
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dfs(board,0, i, j, m, n,word)) return true;
            }
        }
        return false;
    }
};
