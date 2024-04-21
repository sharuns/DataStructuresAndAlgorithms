/*
Check if given strings are rotations of each other or not
Input: S1 = ABCD, S2 = CDAB
Output: Strings are rotations of each other\
Input: S1 = ABCD, S2 = ACBD
Output: Strings are not rotations of each other
*/

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

//this funtion returns 1 in case of success 0 in case of failure
int isRotation(string &A, string &B)
{
	if(A.length() != B.length())
	{
		printf("Not rotations\n");
		return 0;
	}
	else
	{
	    A.append(A);
    //	cout << A << endl;
		
		if(A.find(B))
		{//ABCDABCD
			return 1;
		}
		else{
			return 0;
		}
		
	}
}

int main()
{
	string S1 = "ABCD";
	string S2 = "CDAB";

	if(isRotation(S1,S2))
	{
		printf("Is Rotation\n");
	}
	else
	{
		printf("Not a roation\n");
	}
	
	return 0;
	
}