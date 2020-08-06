#include <stdio.h>



int main(void){
 /* Address of
    el operador unario & se utiliza para obtener la direccion de memoria de  algun valor en memoria
    como en este caso, la direccion de una variable  llamada x, la forma en que se le,  p apunta a la direccion de  x
    
 */
 int x =3;
 int *p = &x;

 printf("%p = %p\n", (void *)&x, (void *)p);

 /* Dereference
    cuanto se tiene una varible que apunta a otra es conocida tambien como puntero, en este caso la  llamada
    dereference es  que al apuntar a la direccion de memoria es posible acceder al valor en el ejemplo q apunta
    a s  por lo que luego al usar *q en un print puedo obtener el valor de s, pero si modifico a  q el valor de s
    sera modificado indirectamente, esto haciendo uso de *q = 23 y esto es porque lo que almacena q es la direccion de s,
    por lo cual todo cambio que se haga desde  q  haciendo uso de *q =  valor, cambiara a el valor de la variable a quien apunte,
    pero si luego se hace uso de  p = 23, esto remplazara el valor  de la direccion de memoria por un nuevo valor 23, que sera tomado
    como una nueva direccion de memoria, que lo mas probable es que sea una direccion usada fuera de nuestro programa, por lo cual si
    se modifica nuestro programa puede hacer cosas que no queremos.
 */
 int s = 42;
 int *q = &s;

 printf("s = %d, q = %d\n", s, *q);

 *q = 23;

 printf("s = %d, p = %d\n", s, *q);


 /* Indexing
    la indexación es la forma en como se accede a el valor contenido en un array, por ejemplo  a[4],
    esta expressión señala que el array a en la posición 4 devuelva el valor que contenga, con la expression
    de Dereference es posible obtener el mismo resultado (*a + 4) con esta obtendremos el vaor que haya cuatro
    posiciones mas adelante de a, tanto a[4] como (*a +4) en ambos casos a contiene la direccion de memoria a la que apunta a

    los array son un conjunto contiguo de memoria, una variable normal tiene una dirección de memoria como podria
    ser OX0001 y esa memoria contendria el valor, se podria ver asi int a  = 4; en ejecucion el programa  0X0001  seria
    la memoria de la variable a  y que a su vez el valor que contiene es 4, esa memoria tendria 4bytes porque es lo que equivale
    el tener una variable de tipo entero, ahora bien un array contiene  la primera posicion de la memoria y de hay segun la cantidad
    de posiciones del array mantendria mas posiciones de memoria, por ejemplo un int array = {1,2,3} contendria
    3 posiciones de memoria contigua, es decir estaria inmediatamente al lado de la primera posicion de la memoria
    si fuera 0x001 para el valor 1, para el valor dos seria 0X002 y 0X003 para el tercer valor, ademas que cada posicion
    de la memoria equivaldria a 4bytes cada una, ya que es un array de  tipo int, por lo que  la cantidad de memoria usada seria 12btyes

   haciendo uso de la expresino (*array ) obtendria el valor de la posicion en memoria 1, si le sumo 1 se movera 4 bytes  hacia delante
   de la memoria  colocandose el en  el valor 2 del  array,  si fuera un array de  long  se moveria 8bytes , segun el tipo
   de dato se movera cierta cantidad de bytes.
 */

  int array[] = {1,2,3,4,5};
  int max  = 5;
  for(int i=0; i < max; i++){
     printf("i = %d , value = %d\n", i, array[i]);
     /* es posible acceder a el valor de un array usando la siguiente expressión i[array]
        la razon por la que no es usado, es porque  es mas dificil de entender.
     */
 }

  int *der = array;

  for(int i=0; i < max; i++){
     printf("i = %d, value = %d\n", i, (*der + i));

  }

}
