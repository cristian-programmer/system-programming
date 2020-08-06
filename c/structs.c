#include <stdio.h>

int main(void){
    struct object {
	int x;
	int y;
    };

    struct object myObject;
    myObject.x = 42; myObject.y = 15;

   printf(".x = %i, .y = %i\n", myObject.x, myObject.y);

}
