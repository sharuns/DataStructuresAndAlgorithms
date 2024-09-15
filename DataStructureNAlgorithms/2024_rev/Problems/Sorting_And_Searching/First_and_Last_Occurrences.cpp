/*
Given a sorted array arr containing n elements with possibly some duplicate, the task is to find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.

We can iterate through the arr once from front and once from back and hence reducing the number of elements traversed

*/


#include<iostream>
#include<vector>

using namespace std;

 vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int> Res = {-1,-1};
        int first = -1;
        int last = -1 ;
        
		//first occurrence from front
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i] == x)
            {
                first = i;
                break;
            }
        }
        
		//element is not present , no point in traversing again 
		if(first == -1)
		{
			return Res;
		}
		
		//first occurrence from ending, means the last occurrence 
        for(int i = n-1 ; i >=0  ; i--)
        {
            if(arr[i] == x)
            {
                last = i;
                break;
            }
        }
        
        Res[0] = first;
        Res[1] = last;
        
        return Res;
    }

int main()
{
    
    int arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 };
    vector<int> Res = find(arr, 9,5);
    cout << Res[0] << " " << Res[1] << endl;
    
} 