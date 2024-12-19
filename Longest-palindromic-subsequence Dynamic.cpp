// A Dynamic Programming
#include<bits/stdc++.h>
using namespace std;

int max (int x, int y) { return (x > y)? x : y; }

int lps(char *str)
{
int n = strlen(str);
int i, j, cell;
int L[n][n]; // Create a table to store results of subproblems


// Strings of length 1 are palindrome of length 1 (one char)
//and fill the diagonal of the table by value = 1
for (i = 0; i < n; i++)
	L[i][i] = 1;

//cell = 2 for looping around the half part of the table above the diagonal (bottom-up manner)
	for (cell=2; cell<=n; cell++)
	{
		for (i=0; i<n-cell+1; i++)
		{
			j = i+cell-1;
		//if the string is two char only and they are both same
			if (str[i] == str[j] && cell == 2)
			L[i][j] = 2;
		//if a string is starting and ending  with same char, we add 2 to the pervious subsequence [1,n]
			else if (str[i] == str[j])
			L[i][j] = L[i+1][j-1] + 2;
		//if a string is starting and ending without same char, we compare between two subsequences ([0,n-1] , [1,n])
		//to find the max length for palindrome
			else
			L[i][j] = max(L[i][j-1], L[i+1][j]);
		}
	}

	return L[0][n-1];


}

int main()
{
	char seq[1000];
	cin>>seq;
	int n = strlen(seq);
	printf ("The length of the LPS is %d", lps(seq));
	getchar();
	return 0;
}
