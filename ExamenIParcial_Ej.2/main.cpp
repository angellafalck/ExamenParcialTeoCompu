#include "graph.h"

int main()
{
    //Nice Sheldon referrence ;)
    /* Piedra =1
    Papel = 2
    Tijera = 3
    Lagartija = 4
    Spock = 5
    */

   Graph a;

    a.loadText();
    a.print();
    int p1, p2;
    cout<<"player1: "<<endl;
    cin>>p1;
    cout<<"player2: "<<endl;
    cin>>p2;
    a.play(p1,p2);
    //a.contains(newStr);
    //if(a.contains(newStr)==true)
    //{
     //   cout<<""
    //}


    return 0;
}