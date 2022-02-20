#include "graph.h"

//Probandop para poder split el texto en un vector
vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
//Print (operator overload)
template<typename T>
std::ostream& operator <<(std::ostream& out, const std::vector<T>&arr)
{
    //std::cout <<"{ ";
    bool first=true;
    for(auto& elem: arr)
    {
        if (first) first=false;
        else std::cout <<", ";

        std::cout<<elem;
    }
    //std::cout<<" }";
    return out;
}

string Graph::process(string const& s)
{
    std::string::size_type pos = s.find(',');
    if (pos != std::string::npos)
    {
        return s.substr(0, pos);
    }
    else
    {
        return s;
    }
}
void Graph::initVertex()
{
    for (int i = 0; i < vertexNum; i++) {
        mVertex[i] = vertexVector[i];
    }

}

void::Graph::initEdge()
{
    string edgeString;
    string edge1;
    string edge2;
    
    for (int i = 0; i < edgesNum; i++)
    {
        edgeString=edgeVector[i];
        edgeString.erase(remove(edgeString.begin(), edgeString.end(), '('), edgeString.end());
        edgeString.erase(remove(edgeString.begin(), edgeString.end(), ')'), edgeString.end());
        edge1=process(edgeString);
        edge2=edgeString.substr(edgeString.find(",") + 1); 

        p1 = getPosition(edge1);
        p2 = getPosition(edge2);

        if (p1==-1 || p2==-1)
        {   
            //if edge added doesn't exist the matrix ignores it
            //rlutil::setColor(rlutil::RED);
            cout << "Vertex doesn't exist in one edge assignated!" << endl;
            //rlutil::resetColor();
        }

        mMatrix[p1][p2] = 1;
        
    }
}

//same thing as contains
int Graph::getPosition(string str)
{
    for(int i=0; i<vertexNum; i++)
        if(mVertex[i]==str)
            return i;
    return -1;
}


void Graph::createMatrix(){
    initVertex();
    initEdge();
}

void Graph::print()
{
    createMatrix();

    cout << "**Matrix Graph**" << endl;
    for (int i = 0; i < vertexNum; i++)
    {
        for (int j = 0; j < vertexNum; j++)
        {
            cout << mMatrix[i][j] << " ";
        }
            
        cout << endl;
    }
}

void Graph::loadText()
{
    vertexVector.push_back("piedra");
    vertexVector.push_back("papel");
    vertexVector.push_back("tijera");
    vertexVector.push_back("lagartija");
    vertexVector.push_back("spock");

    edgeVector.push_back("(piedra,tijera)");
    edgeVector.push_back("(piedra,lagartija");
    edgeVector.push_back("(papel,piedra)");
    edgeVector.push_back("(papel,spock)");
    edgeVector.push_back("(tijera,papel)");
    edgeVector.push_back("(tijera,lagartija)");
    edgeVector.push_back("(lagartija,papel)");
    edgeVector.push_back("(lagartija,spock)");
    edgeVector.push_back("(spock,piedra)");
    edgeVector.push_back("(spock,tijera");
    /*
  //int x, y;
  ifstream in("juego.txt");

  if (!in) {
    cout << "Cannot open file.\n";
    return;
  }

    string fullStr;
    while(!in.eof())
    {
        in >> fullStr;
    }

    std::string s = fullStr;
    //cout<<s;
    string newStr;
    for(int i=2; i<37;i++)
    {
        newStr+=s[i];
        //cout<<s[i];
    }
    cout<<newStr<<endl;
    vertexVector.push_back(newStr);
    cout<<vertexVector;
    cout<<sizeof(vertexVector);
 */
  //in.close();
}

void Graph::printMatrix()
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
             //rock (R), paper (P), scissors (S), lizard (L), spock(K)
            if (gameRules[i][j] == 'R') {
                cout<<RED<<" "<<gameRules[i][j]<<" "<<RESET;
            }else if (gameRules[i][j] == 'P') {
                cout<<YELLOW<<" "<<gameRules[i][j]<<" "<<RESET;
            }else if (gameRules[i][j] == 'S') {
                cout<<MAGENTA<<" "<<gameRules[i][j]<<" "<<RESET;
            }else if (gameRules[i][j] == 'L') {
                cout<<GREEN<<" "<<gameRules[i][j]<<" "<<RESET;
            }else if (gameRules[i][j] == 'K') {
                cout<<BLUE<<" "<<gameRules[i][j]<<" "<<RESET;
            }else{
              cout<<" "<<gameRules[i][j]<<" ";  
            }
        }
        cout<<"\n";
    }

}

void Graph::winningComb(string x, string y)
{

}

bool Graph::contains(string elem)
{
    bool result = false;
    if( find(edgeVector.begin(), edgeVector.end(), elem) != edgeVector.end() )
    {
        result = true;
    }
    return result;
}

void Graph::play(int a, int b)
{
    cout<<a<<b;
    
    if(mMatrix[b][a] == 1)
    {
        cout<<"1"<<endl;
        //cout << mMatrix[b][a]<< endl;
    }else
    {
        cout<<"0"<<endl;
        //cout << "Jugador 2 GANA!!!!!" << endl;
    }

    //cout<<mMatrix[1][1];
    /*
    if ((mMatrix[a][b] == mMatrix[1][1]) || (mMatrix[a][b] == mMatrix[2][2]) || (mMatrix[a][b] || mMatrix[3][3]) 
    || (mMatrix[a][b] == mMatrix[4][4])|| (mMatrix[a][b] == mMatrix[5][5])) {
        cout << "Empate" << endl;
    }
    */
    /*
    if ((mMatrix[a][b] == gameRules[1][1]) || (gameRules[a][b] == gameRules[2][2]) || (gameRules[a][b] || gameRules[3][3]) 
    || (gameRules[a][b] == gameRules[4][4])|| (gameRules[a][b] == gameRules[5][5])) {
        cout << gameRules[a][b] << endl;
    }
    else if (gameRules[a][b] == 1) {
        cout << "Jugador 1 GANA!!!!!" << endl;
    }
    else {
        cout << "EMPATE!!!" << endl;
    }
    */
}

