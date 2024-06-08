#include <iostream>
#include <stdexcept>
using namespace std;

class DynamicArray{
	private:
		int* data;
		size_t current_size;
		size_t current_capacity;
		
		void resize(size_t new_capacity){
			int* new_data=new int[new_capacity];
			for(size_t i=0; i< current_size; ++i){
				new_data[i]=data[i];
			}
			delete[] data;
			data=new_data;
			current_capacity=new_capacity;
		}
};

int main(){
	DynamicArray arr;
}