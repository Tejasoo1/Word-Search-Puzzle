//The Word Search Code....

#include <bits/stdc++.h>
using namespace std;

bool solve(int i,int j,int ind,int n,int m,string &word,vector<vector<char>> &dp)
{
    if(ind == word.size()) //word has been found
      return true;

    if(i<0 || j<0 || i==n||j==m||dp[i][j]!=word[ind]||dp[i][j]=='.') //current cell is not containing the current index character of given word
      return false;                                                  //OR if we go out of the boundary of the grid. 
                                                                     //OR if the cell has been visited already    
                                                                     // Return false for above cases    
    char ch = dp[i][j]; //if current cell has the current index character                                           
    dp[i][j] = '.';     //mark as visited

    //choice 1
    bool up = solve(i-1,j,ind+1,n,m,word,dp);    //move up from current cell
    //choice 2
    bool down = solve(i+1,j,ind+1,n,m,word,dp);  //move down from current cell
    //choice 3
    bool right = solve(i,j+1,ind+1,n,m,word,dp); //move right from current cell
    //choice 4
    bool left = solve(i,j-1,ind+1,n,m,word,dp);  //move left from current cell

    dp[i][j] = ch; //Backtrack (mark as unvisited).

    return up||down||right||left;    //return true if word found,else return false
}

bool Wordsearch(vector<vector<char>> &board, string &word, int n, int m) 
{
    // Write your code here.
    for(int i=0; i<n; i++)            //Search the first character of the word first
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j]==word[0])  //if first character is found
            {
                if(solve(i,j,0,n,m,word,board)) //search the rest of the characters ahead.
                  return true;
            }
        }
    }

    return false;  //if word is not found.
}

//Driver code
int main()
{
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif

   
	vector<vector<char>> dp{
	  {'A','B','C','E'},
	  {'S','F','C','S'},
	  {'A','D','E','E'}	
	};

   cout<<"_________"<<endl; 
   for(vector<char> vec:dp)
   {
   	 for(char x : vec)
   	 {
      cout<<"|";
   	 	cout<< x <<"";
   	 }	
     cout<<"|"<<endl;
     cout<<"---------";
     cout<<endl;
   } 	

   cout<<endl;

   string word = "SEE";
   cout<<"The word to be searched in the puzzle is: "<< word <<endl;

   int n = dp.size();  //no. of rows
   int m = dp[0].size(); //no. of columns
  
  if(Wordsearch(dp,word,n,m))
    cout<<"Given word is present in the grid "<<endl;
  else
    cout<<"Given word is not present in the grid"<<endl;

}
