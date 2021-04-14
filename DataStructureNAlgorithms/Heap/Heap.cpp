#include<iostream>

//Heap are best to be implemented using Arrays

//Insert method is the most important in Heap DS
void InsertHeapEle(int * array, int index){

	//as this is in-place each element is inserted at the index it should be at the beganing
	if(index == 0){
		return ; //first element do nothing
	}

	while(index > 1){ //need a terminating condition

		int parent = index/2;
		if(array[index] > array[parent]){

			int temp = array[index];
			array[index] = array[parent];
			array[parent] = temp;
		}

		index = parent;
	}
}


//Create heap can be easily created using Insert method
void createHeap(int * array, int size){

for (int i = 2 ; i < size; ++i){

		InsertHeapEle(array,i); //This will create the heap as well

	}

}

void PrintHeap(int * array, int size){
for(int i = 1 ; i < size ; ++i ){

		std::cout << array[i] << " " ;
	}

 	std::cout << std::endl;

}

//In a heap always the root is the element that is deleted
//This is buggy due to the size constraint
void DeleteHeapEle(int * array, int * size){


	int temp = array[1]; //root that is to be deleted
	//inplace of root the last element in continous tree will come
	array[1] = array[(*size) -1];
	(*size) = (*size) -1;
	int parent = 1;

	while(parent < (*size)){

		int lchild = 2 * parent;
		int rchild = (2*parent)+1;

		if((lchild < (*size) ) && (rchild < (*size))){

			if(array[lchild] >	array[rchild]){
				if(array[lchild] > array[parent] ){
					int tempo = array[lchild];
					array[lchild] = array[parent];
					array[parent] = tempo;
				}

				parent = lchild;
				

			}else{
				if(rchild > parent ){
					int tempo = array[rchild];
					array[rchild] = array[parent];
					array[parent] = tempo;

				}
				parent = rchild;
				
			}

		}
		else{
			break;
		}
	}
}

void DeleteHeapEleForSort(int * array, int * size){


	int temp = array[1]; //root that is to be deleted
	//inplace of root the last element in continous tree will come
	array[1] = array[(*size) -1];
	array[(*size) -1] = temp;
	(*size) = (*size) -1;
	int parent = 1;

	while(parent < (*size)){

		int lchild = 2 * parent;
		int rchild = (2*parent)+1;

		if((lchild < (*size) )&& (rchild < (*size))){

			if(array[lchild] >	array[rchild]){
				if(array[lchild] > array[parent] ){
					int tempo = array[lchild];
					array[lchild] = array[parent];
					array[parent] = tempo;
				}

				parent = lchild;
				

			}else{
				if(rchild > parent ){
					int tempo = array[rchild];
					array[rchild] = array[parent];
					array[parent] = tempo;

				}
				parent = rchild;
				
			}

		}
		else{
			break;
		}
	}
}


void HeapSort(int * array, int size){
	int localSize = size; 
	createHeap(array,size);
	PrintHeap(array,size);

	for(int i  = 0 ; i < size-1 ; ++i){
		DeleteHeapEleForSort(array,&localSize);
		std::cout << localSize << std::endl;
		PrintHeap(array,8);
		std::cout << std::endl;
	}
}


int main(){

	int array[] = {0,1,2,45,2,5,4,3,77};
	int arraySize = 9;
	createHeap(array,arraySize);

	PrintHeap(array,arraySize);

	DeleteHeapEle(array,&arraySize);

	PrintHeap(array,arraySize);
	DeleteHeapEle(array,&arraySize);
	PrintHeap(array,arraySize);

	std::cout << "########################" << std:: endl;
	int arr[] = {0,1,45,2,5,4,3,77};
	int arrSize = 8;

	HeapSort(arr, arrSize);
	std::cout << "########################" << std:: endl;
	PrintHeap(arr,8);	
	

	//std::cout << "Hi"  << std::endl;

}

//Create a heap
//Insert method
//Delete method for heap

//Heapsort using the above apis

//Heapify theory

// Heap as Priority queue