#include <iostream>
#include "Grafos.h"


int main()
{

    Graph a;
    a.addVertex();
    a.addEdge();
    int op=0;
    do 
    {
        cout<<"\n1. Print Graph\n2. Add a tag.\n3. View Matrix.\n0. Close\nYour option: ";
        cin>>op;
        switch(op)
        {
            case 1:
            a.print4();
            break;
            case 2:
            a.addTag();
            break;
            case 3:           
            a.print();
            break;
            default:
            break;
        }

    }while(op!=0);

    return 0;
    
}
