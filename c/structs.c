#include <stdio.h>

void structObjectFunc(void);
void structPointerFunc(void);

int main(void){
    structObjectFunc();
    structPointerFunc();

}


void structObjectFunc(){
   struct object {
        int x;
        int y;
    };

    struct object myObject;
    myObject.x = 42; myObject.y = 15;

   printf(".x = %i, .y = %i\n", myObject.x, myObject.y);

}


void structPointerFunc(){
    struct object {
       int x;
       int y;
    } myObject;

   struct object *p = &myObject;

   p->x = 42;
   p->y = 123;

   printf(".x = %i, y = %i\n", p->x, p->y);
   printf(".X = %i, y = %i\n", myObject.x, myObject.y);
}


