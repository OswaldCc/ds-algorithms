#include <iostream>
#include <stdexcept>
using namespace std;

class DynamicArray{
	private:
		int* data;
		size_t current_size;
		size_t current_capacity;
		
		void resize(size_t new_capacity){
			int* new_data=new int[new_capacity];// this is our new contiguous block and we have a pointer to it.
			for(size_t i=0; i< current_size; ++i){
				new_data[i]=data[i];
			}
			delete[] data;
			data=new_data;
			current_capacity=new_capacity;
		}
    public:
    	DynamicArray(size_t initial_capacity=1){
			data=new int[initial_capacity];
			current_size=0;
			current_capacity=initial_capacity;	
		}
		~DynamicArray(){
			delete[] data;
		}
		size_t size() const{//const here is a qualifier 
			return current_size;
		}
		size_t capacity() const{
			return current_capacity;
		}
		void insertLast(int value){
			if(current_size == current_capacity){
				resize(current_size * 2);			
			}
			data[current_size++] = value;
		}
		int& operator[](size_t index){
			
		}
};

int main(){
	DynamicArray arr;
	arr.insertLast(10);
	cout<<arr.size()<<endl;
	cout<<arr.capacity();
}