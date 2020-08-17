#include "Lista.h"

using namespace std;

int main(){
    Lista<float> miLista;

    miLista.insert(10.5);
    miLista.insert(42.2);
    miLista.insert(69.69);
    miLista.insert(420.69);
    miLista.erase();
    cout << "Size is " << miLista.getSize() << "\n";
    miLista.print();

    return 0;
}