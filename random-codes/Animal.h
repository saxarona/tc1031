// Animal class
#include <string>

using namespace std;

class Animal
{
private:
    string name;
    string scientific_name;
    int legs;
    float weight;
    float height;

public:
    Animal();
    string getName();
    string getSciName();
    int getLegCount();
    float getWeight();
    float getHeight();

    void setName(string common_name);
    void setSciName(string sci_name);
    void setLegCount(int legs_no);
    void setWeight(float w);
    void setHeight(float h);
};

Animal::Animal(/* args */)
{
}

string Animal::getName(){
    return name;
}

string Animal::getSciName(){
    return scientific_name;
}

int Animal::getLegCount(){
    return legs;
}

float Animal::getWeight(){
    return weight;
}

float Animal::getHeight(){
    return height;
}

void Animal::setName(string common_name){
    name = common_name;
}

void Animal::setSciName(string sci_name){
    scientific_name = sci_name;
}

void Animal::setLegCount(int legs_no){
    legs = legs_no;
}

void Animal::setWeight(float w){
    height = w;
}

void Animal::setHeight(float h){
    height = h;
}