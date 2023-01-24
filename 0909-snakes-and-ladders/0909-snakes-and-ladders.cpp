class Solution {
public:
    int n;
    const int leftToRight = 1, rightToLeft = -1;
    vector<int> getPosition(int val){
        if(val == 1) return {n-1, 0};
        if(val == n*n) return {0, 0};

        int row = val%n == 0? val/n : val/n +1;

        int fistElemOfRow = n*(row-1) + 1; 
        
        int direction = row&1? leftToRight : rightToLeft;

        int diff = val - fistElemOfRow;
        if(direction == leftToRight){
            return {n -row, diff};
        }

        return {n - row, n - 1 - diff};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();

        queue<int> q;
        q.push(1);

        int count = 0;
        vector<bool> visited(n*n+1, false);
        visited[1] = true;
        int ans = 1;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                int val = q.front();
                q.pop();

                for(int next = val+1; next<= min(val +6, n*n); next++){
                    int curr = next;
                    vector<int> pos = getPosition(curr);
                    int i = pos[0], j = pos[1];
                    int destination = board[i][j] !=-1 ? board[i][j] : curr;

                    if(destination == n*n) return ans;

                    if(!visited[destination]){
                        visited[destination] = true;
                        q.push(destination);
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};