class Solution {
public:
    // Here every cell of dp table length of LCS .
    int LCS(string &text1, string &text2,int i,int j, vector<vector<int>> &dp)
    {
        if(i<0 || j<0) {
		   // Base Case
		    return 0;
        }
        if(dp[i][j]!=-1) {
		   // If we have already calculated the value then use it rather than calculating it. 
		    return dp[i][j];
		}
        if(text1[i]==text2[j])
        {
          return dp[i][j]=1+LCS(text1,text2,i-1,j-1,dp);
        }
        int not_match=0+max(LCS(text1,text2,i-1,j,dp),LCS(text1,text2,i,j-1,dp));
        return dp[i][j]= not_match;
    }

    int longestCommonSubsequence(string text1, string text2) {
    int m=text1.size();
    int n=text2.size();
    vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
	// We are creating 2D array where text1 is acts as row and text2 acts as column. Here every cell contain -1. Which mean these cell contain nothing 
    return LCS(text1,text2,m-1,n-1,dp);
    }
};
