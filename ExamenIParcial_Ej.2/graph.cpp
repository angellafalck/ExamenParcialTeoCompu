#include "graph.h"


void Graph::readFileVertex()
{
    ifstream in("vertex.txt");

    if (!in) {
        cout << "Cannot open file.\n";
        return;
    }
    string fullStr;
    string formatStr;

    while(!in.eof())
    {
        in >> fullStr;
    }
    formatStr=fullStr;
    formatStr.erase(remove(formatStr.begin(), formatStr.end(), '{'), formatStr.end());
    formatStr.erase(remove(formatStr.begin(), formatStr.end(), '}'), formatStr.end());


    string a;
    for(stringstream sst(formatStr); getline(sst, a, ','); )
    {
       
        vertexVector.push_back(a);
     
    }
 
    //copy (vertexVector.begin(), vertexVector.end(), ostream_iterator<string>(cout));

    vertexNum=vertexVector.size();
    
}

void Graph::readFileEdge()
{
    ifstream in("edge.txt");

    if (!in) {
        cout << "Cannot open file.\n";
        return;
    }
    string fullStr;
    string formatStr;

    while(!in.eof())
    {
        in >> fullStr;
    }
    formatStr=fullStr;
    formatStr.erase(remove(formatStr.begin(), formatStr.end(), '{'), formatStr.end());
    formatStr.erase(remove(formatStr.begin(), formatStr.end(), '}'), formatStr.end());

    string a;
    for(stringstream sst(formatStr); getline(sst, a, '.'); )
    {
        edgeVector.push_back(a);
        
    }
    //cout<<edgeVector;
    //copy (edgeVector.begin(), edgeVector.end(), ostream_iterator<string>(cout));

    edgesNum=edgeVector.size();
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

        mMatrix[p2][p1] = 1;
        
    }
}

string Graph::lowerString(string str)
{
 
	for(int i=0;str[i]!='\0';i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;     
	}

    return str;
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


//same thing as contains
int Graph::getPosition(string str)
{
    for(int i=0; i<vertexNum; i++)
        if(mVertex[i]==str)
            return i;
    return -1;
}

void Graph::initAux(){
    aux.push_back('R');
    aux.push_back('P');
    aux.push_back('S');
    aux.push_back('L');
    aux.push_back('K');
    
}


void Graph::createMatrix(){
    initVertex();
    initEdge();
    initAux();

}

void Graph::print()
{

    createMatrix();
    
    cout << "**Truth Table**" << endl;
    for(int i=0; i<vertexNum;i++)
    {  
            if(i==0)
            {
                cout<<"  ";
                
            }
            if (aux[i]== 'R') {
                cout<<RED<<aux[i]<<" "<<RESET;
            }else if (aux[i]== 'P') {
                cout<<YELLOW<<aux[i]<<" "<<RESET;
            }else if (aux[i]== 'S') {
                cout<<MAGENTA<<aux[i]<<" "<<RESET;
            }else if (aux[i] == 'L') {
                cout<<GREEN<<aux[i]<<" "<<RESET;
            }else if (aux[i]== 'K') {
                cout<<BLUE<<aux[i]<<" "<<RESET;
            }else{
              cout<<aux[i]<<" ";  
            }
        
    }
    cout << endl;
    for (int i = 0; i < vertexNum; i++)
    {
        if (aux[i]== 'R') {
            cout<<RED<<aux[i]<<" "<<RESET;
        }else if (aux[i]== 'P') {
            cout<<YELLOW<<aux[i]<<" "<<RESET;
        }else if (aux[i]== 'S') {
            cout<<MAGENTA<<aux[i]<<" "<<RESET;
        }else if (aux[i] == 'L') {
            cout<<GREEN<<aux[i]<<" "<<RESET;
        }else if (aux[i]== 'K') {
            cout<<BLUE<<aux[i]<<" "<<RESET;
        }else{
            cout<<aux[i]<<" ";  
        }
        for (int j = 0; j < vertexNum; j++)
        {
            cout<<mMatrix[i][j] << " ";
        }
            
        cout << endl;
    }

}


bool Graph::validateUserInput(string str, string str2)
{
    bool result = false;
    if( (find(vertexVector.begin(), vertexVector.end(), str) != edgeVector.end()) &&
     (find(vertexVector.begin(), vertexVector.end(), str2) != edgeVector.end()) )
    {
        result = true;
    }
    return result;
}
void Graph::play(int j1, int j2)
{
    int pos1, pos2;
    pos1=j1-1;
    pos2=j2-1;

    if (mMatrix[pos2][pos1] == 1) {
        cout<<GREEN<<"Player 1 wins!\n"<<RESET;
        cout<<RED<<"Player 2 lose!\n"<<RESET;
    }else if(pos2==pos1)
    {
        cout<<BLUE<<"Sheldon says Draw!\n"<<RESET;
        return;
    }else if(mMatrix[pos2][pos1] == 0)
    {
        cout<<GREEN<<"Player 2 wins!\n"<<RESET;
        cout<<RED<<"Player 1 lose!\n"<<RESET;
    }

}
void Graph::gameValidation(string p1, string p2)
{
    bool first;
    bool second;
    string neatPair1;
    neatPair1="("+p1+","+p2+")";
    string neatPair2;
    neatPair2="("+p2+","+p1+")";

    if(contains(neatPair1))
    {
        first=true;
        second=false;
        
    }else if(contains(neatPair2)){
        first=false;
        second=true;
    }
    if(first)
    {
        cout<<GREEN<<"Player 1 wins!\n"<<RESET;
        cout<<RED<<"Player 2 lose!\n"<<RESET;
    }else if(second)
    {
        cout<<GREEN<<"Player 2 wins!\n"<<RESET;
        cout<<RED<<"Player 1 lose!\n"<<RESET;
    }
    else if ((!first) || (!second)){
        cout<<BLUE<<"Sheldon says Draw!\n"<<RESET;
    }

}

