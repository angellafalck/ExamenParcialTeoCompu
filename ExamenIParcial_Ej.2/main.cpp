#include "graph.h"

int main()
{
    Graph a;
    int op=0;
    a.readFileEdge();
    a.readFileVertex();
    do 
    {
        a.print();
        cout<<"Options: "<<RED<<"rock, "<<RESET<<YELLOW<<"paper, "<<RESET<<MAGENTA
        "scissors, "<<RESET<<GREEN<<"lizzard, "<<RESET<<BLUE<<"spock"<<RESET<<endl;
        string p1, p2,p1New,p2New;
        cout<<"Player 1: ";
        cin>>p1;
        cout<<"Player 2: ";
        cin>>p2;
        p1New= a.lowerString(p1);
        p2New= a.lowerString(p2);
        
        a.gameValidation(p1New,p2New);
        

        cout<<"\n"<<"Play again? 1.Yes. 0.No"<<endl;
        cin>>op;

    }while(op!=0);

    return 0;
}