#include <iostream>

using namespace std;

class nodo
{
public:
    int item;
    nodo* next;

    nodo(int a,nodo * siguiente)
    {
        item = a;
        next = siguiente;
    }
};

class lista
{
private:
    nodo* cabeza;
    nodo* p;
public:
    lista()
    {
        cabeza = NULL;
        p = NULL;
    }
    void insertaInicio(int n)
    {
        //create a new node
        cabeza = new nodo(n, p);
        //set next pointer to head
        p = cabeza;

    }
    void borraInicio()
    {
        nodo * aux;
        aux = cabeza->next; 
        delete cabeza;
        cabeza = aux;
    }
    int regresaItem()
    {
        return cabeza->item;
    }
};

class pila
{
private:
    //sz (with getters and setters) used to keep track of the size of the stack
    //(incremented in push, decremented in pop)
    int sz;
    lista lisst;
public:
    pila()
    {
        sz = 0;
    }
    int size()
    {
        return sz;
    }
    void setsize(int size)
    {
        sz = size;
    }
    void push(int n)
    {
        lisst.insertaInicio(n);
        sz++;

    }
    int pop()
    {
        int tam;
        tam = lisst.regresaItem();
        lisst.borraInicio();
        sz--;
        return tam;
    }
    void imprimePila()
    {
        //a lengthy way to print the stack
        //was abit unusual as the pop function
        //was removing elements from the stack,
        //when all that was necessary was to print them.
        //this was a workaround that just copied the stack,
        //printed (and removed) elements from original stack,
        //but set the empty to stack to the copy,
        //to leave it unchanged.
        //feel free to find a better way for this
        lista copy;
        cout << '[';
        int lsize = this->size();
        int arr[3] = {};
        int ind = 2;
        while (this->size() != 0){
            int item = this->pop();
            arr[ind] = item;
            cout<< item;
            cout << ',';
            ind--;
        }
        for (int i = ind; i < 3; i++){
            copy.insertaInicio(arr[i]);
        }
        cout <<  ']';
        lisst = copy;
        this->setsize(lsize);
    }
};
//the stacks are instantiated globally so they can be printed at every
//recursive step from algoritmoDeTorres()
pila ORIGEN, AUX, META;

void algoritmoDeTorres(int numDiscos, pila &origen, pila &aux, pila &meta)
{
    //if statement used to rearrange discs ONLY if there are any (if numdiscos is more than 0)
    if (numDiscos > 0){
        //move (numDiscos - 1) discs from origen to aux, so they are out of the way
        algoritmoDeTorres(numDiscos - 1, origen, meta, aux);

        //move the exposed disc from origen to meta
        int item;
        item = origen.pop();
        //lista laux;
        //laux.insertaInicio(item);
        //commented this list out since the item
        //is added to the list of stack its being added to in the push call
        meta.push(item);

        ORIGEN.imprimePila();
        AUX.imprimePila();
        META.imprimePila();
        cout << endl;

        //now move the (numDiscos - 1) discs that we left on aux onto meta
        algoritmoDeTorres(numDiscos - 1, aux, origen, meta);
    }
}

int main()
{
    ORIGEN.push(3);
    ORIGEN.push(2);
    ORIGEN.push(1);

    ORIGEN.imprimePila();
    AUX.imprimePila();
    META.imprimePila();
    cout << endl;

    algoritmoDeTorres(ORIGEN.size(), ORIGEN, AUX, META);
    //objects not allocated with 'new' don't need to be explicitly destroyed
    //ORIGEN.destruirPila();
    //AUX.destruirPila();
    //META.destruirPila();

    return 0;
}