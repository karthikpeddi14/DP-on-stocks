// from prev question
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> next(2,vector<int>(k+1,0)), cur(2,vector<int>(k+1,0));

        for(int ind=n-1; ind>=0 ; ind--)
        {
            for(int buy=0 ; buy<2 ; buy++)
            {
                for(int cap=1; cap<=k ; cap++)
                {
                    if(buy) 
                    cur[buy][cap] = max(-prices[ind]+next[0][cap],next[1][cap]);
                    else
                    cur[buy][cap] = max(prices[ind]+next[1][cap-1],next[0][cap]);
                }
            }
            next = cur;
        }
        return next[1][k];
    }
};

// new - transno method
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2*k+1,0),cur(2*k+1,0);
        
        for(int ind=n-1 ; ind>=0 ; ind--)
        {
            for(int transno=0 ; transno<2*k ; transno++)
            {
                if(transno%2==0)
                cur[transno] = max(-prices[ind] + next[transno+1],next[transno]);
                else
                cur[transno] = max(prices[ind] + next[transno+1], next[transno]);
            }
            next = cur;
        }
        return next[0];
    }
};
