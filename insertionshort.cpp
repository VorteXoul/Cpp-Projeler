#include <iostream>

void insertionsort(int size){
    int *array= new int[size]; 
    for(int j=0;j<size;j++){
        std::cout << j  << ". Array : " ;
        std::cin >> array[j];
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<(size-1);j++){
            if( array[j+1] < array[j] ){
                int swap=array[j+1];
                array[j+1]=array[j];
                array[j]=swap;
            }
        }
        
    }
    std::cout << "----------" <<std::endl;
    std::cout << "Array Size : " << size << std::endl;
    for(int j=0;j<size;j++){
        std::cout << j << ". >> Array : " << array[j] << std::endl;
    }
    delete []array;
}

int main() {
    int size;
    std::cout << "Array Size : ";
    std::cin >>size; 
    insertionsort(size);
}
