#include<iostream>


void BubbleSort(int * ptr , int num){

	int flag = 0; //this will check in case the list is already sorted
	for(int i = 0 ; i < num-1 ; ++i){

		for(int j = 0; j < num-1-i ; ++j){//i here because after each round we get the largest element in the end, so no need to go there again

			if(ptr[j] > ptr[j+1]){
				int temp = ptr[j];
				ptr[j] = ptr[j+1];
				ptr[j+1] = temp;
				flag = 1;
			}	

			if(flag == 0){
				return;
			}
		}

	} //runs for n-1 times 
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

	BubbleSort(array, sizeof(array)/sizeof(int));

	Print(array,sizeof(array)/sizeof(int));

}