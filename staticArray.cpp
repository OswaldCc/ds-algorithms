#include <iostream>
using namespace std;


int main(){
	int numbers[5]={10,23,40,65,-1};
	
	for(int i=0; i<5; i++){
		cout<<"Element at index "<<i<<numbers[i]<<endl;
	}
	return 0;
}