#include <iostream>
#include <algorithm>


using namespace std;


void show(int list[],int size){
	for(int i=0; i < size; i++){
		cout << list[i] << " ";
	}
}

int main(){
	int list[] = {1,5,8,9,6,7,3,4,2,0};
	int size = sizeof(list) / sizeof(list[0]);
	show(list, size);

	sort(list, list + size);
	show(list, size);

	if(binary_search(list, list + size, 5))
		cout << "\n Element found";


}
