#include <iostream>
#include <algorithm> /*header of STL*/

using namespace std;

const int tam = 10;

void show(int list[]){
	for(int i=0; i < tam; i++){
		cout << list[i] << " ";
	}
}


int main(){
	int  list[tam] = {1,5,8,9,6,7,3,4,2,0};
	cout << "\n el array antes de orderarse es: ";
	show(list);
	sort(list, list + tam);
	cout << "\n el array despues de ordenarse: ";
	show(list);
	return 0;
}


