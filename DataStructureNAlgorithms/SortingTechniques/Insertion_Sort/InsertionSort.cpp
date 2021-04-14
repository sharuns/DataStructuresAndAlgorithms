#include<iostream>

//More suitable for linked List , but for easy coding taking array, as in LL no shifting of ele needed
void InsertionSort(int * ptr , int num){
	
	for(int i = 1  ;  i < num  ; ++i){
		
		int  temp =  ptr[i];
		int j = i-1;
		while((j>-1) && (ptr[j] > temp)){

			ptr[j+1] = ptr[j];
			j--;
		}

		ptr[j+1] = temp;
	}

}

void Print(int * ptr , int num){

	std:: cout << "Array : " ;
	for(int  i  = {} ; i < num ; ++i){

		std::cout << ptr[i]  << " ";
	}
	std::cout << std::endl;
}


int main(){


	//test array
	int array[] = {75,32,46,7,8,4,74,2,33,4};

	InsertionSort(array, sizeof(array)/sizeof(int));

	Print(array,sizeof(array)/sizeof(int));

}