// dog

#include "Animal.h"

class Dog : public Animal
{
// private:
//     /* data */
public:
    Dog(string name, float weight, float height);
    string bark(string msg);
};

Dog::Dog(string name, float weight, float height)
{
    setLegCount(4);
    setSciName("Canis Familiaris");
    setName(name);
    setWeight(weight);
    setHeight(height);
}

string Dog::bark(string msg){
    return "Woof woof " + msg;
}