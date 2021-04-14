#include<iostream>
//Selection Sort 


void SelectionSort(int * arr, int n){

	int j, k;

	for (int i = 0; i < n-1; ++i)
	{
		j = k = i;
		for(;j < n ; ++j){

			if(arr[j] < arr[k])
				k = j; //moving k to  the smallest element 
		}
		int temp = arr[i];
		arr[i] = arr[k]; //swap with the smallest ele
		arr[k] = temp;
	}
}



void Print(int * ptr, int n){

	std::cout << "Arr : " ;
	for(int i = 0 ; i < n ; ++i){

		std::cout << ptr[i] << " " ;
	}
	std::cout << std::endl;

}

int main(){

int arr[] = {234,563,7,78,58,3,3,24,5};
int siz = sizeof(arr)/sizeof(arr[0]);
Print(arr, siz );

SelectionSort(arr, siz);

Print(arr, siz);

}