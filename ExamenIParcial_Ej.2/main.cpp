#include "graph.h"

int main()
{
    Graph a;
    int op=0;
    int op2;
    a.readFileEdge();
    a.readFileVertex();

    /*Difference between play with words and numbers is :
    with numbers the truth table is used to validate the winner,
    with words I used the edges vector to validate the winner!
    Have fun!
    */

    do 
    {
        a.print();
        string p1="", p2="",p1New="",p2New="";
        int j1=0,j2=0;
        cout<<"1. Play with words. \n2. Play with numbers. \n Your option: ";
        cin>>op2;

        switch(op2)
        {
            case 1:
                cout<<"Options: "<<RED<<"rock, "<<RESET<<YELLOW<<"paper, "<<RESET<<MAGENTA
                "scissors, "<<RESET<<GREEN<<"lizzard, "<<RESET<<BLUE<<"spock"<<RESET<<endl;
                cout<<"Player 1: ";
                cin>>p1;
                cout<<"Player 2: ";
                cin>>p2;
                p1New= a.lowerString(p1);
                p2New= a.lowerString(p2);
                a.gameValidation(p1New,p2New);
            break;
            case 2:
                cout<<"Options:\n"<<RED<<"Rock = 1\n"<<RESET<<YELLOW<<"Paper = 2\n"<<RESET<<MAGENTA
                "Scissors = 3\n"<<RESET<<GREEN<<"Lizzard = 4\n"<<RESET<<BLUE<<"Spock = 5\n"<<RESET<<endl;
                cout<<"Player 1: ";
                cin>>j1;
                cout<<"Player 2: ";
                cin>>j2;
                if((j1>=1 && j1<=5) && (j2>=1 && j2<=5) )
                {
                    a.play(j1,j2);
                }else
                    cout<<RED<<"Option not available!\n"<<RESET<<endl;
                
            break;


        }
        

        cout<<"\n"<<"Play again? 1.Yes. 0.No"<<endl;
        cin>>op;

    }while(op!=0);

    return 0;
}