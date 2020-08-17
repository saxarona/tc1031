#include "Dog.h"
#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

int main(){
    vector<Animal*> animals;

    animals.push_back(new Dog* {"Mina", 10.2, 40});
    animals.push_back(new Dog* {"Chucho", 13, 39.8});

    for (int i=0; i<animals.size(); i++){
        cout << (*animals[i]).getName() << "\n";
        if (typeid(*animals[i]) == typeid(Dog)){
            cout << (*animals[i])->bark("maldita vida") << "\n";
        }    
    }

    
    return 0;
}