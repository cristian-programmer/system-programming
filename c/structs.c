#include <stdio.h>


/*
 En c se deben definir las funciones a utilizar si se desea poder hacer los llamados
 de las mismas en cualquier parte del archivo, de lo contrario el compilador producira un error si la funcino
 se llama primero y luego es escribe el cuerpo de la funcion, esto producira el error, pero si se crea el cuerpo
 y luego se llama no habra ningun problema, por ello la forma de solucionar este inconveniente es realizar la
 definicion de la funcion al principio del archivo fuente.
*/

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


/*
  El uso de el operador -> solo es posible cuando una estructura es usada como un puntero
  de lo contrario el compilador dara un error, ya que no es una valido.
*/

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


