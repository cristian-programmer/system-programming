#include <iostream>

using namespace std;

class Box {
    public:
        double getVolumen(void){
            return length * breadth * height; 
        }

        void setLength(double len) {
            length = len;    
        }

        void setBreadth(double bre){
            breadth = bre;
        }

        void setHeight(double hei){
            height = hei;
        }


    Box operator+(const Box& box){
        Box ibox;
        ibox.length = this->length + box.length;
        ibox.breadth = this->breadth + box.breadth;
        ibox.height = this->height + box.height;

        return ibox; 
    }

    private:
        double length;
        double breadth;
        double height;
};

int main(){
    Box box1;
    Box box2;
    Box box3;

    double volumen = 0.0;
    box1.setLength(10.0);
    box1.setBreadth(7.0);
    box1.setHeight(5.0);

    box2.setLength(12.0);
    box2.setBreadth(13.0);
    box2.setHeight(10.0);

    volumen = box1.getVolumen();
    cout << "Volumen B1: "<< volumen <<endl;

    volumen = box2.getVolumen();
    cout << "Volumen B2: "<< volumen <<endl;

    box3 = box1 + box2; // call function operator

    volumen = box3.getVolumen();
    cout << "Volumen B3: "<< volumen <<endl;   
}