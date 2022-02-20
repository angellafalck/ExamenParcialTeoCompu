#include "Grafos.h"

void Graph::addVertex(){
    int op=0;
    string element;
    cout<<"\n1. Add the vertex manually.\n2. Read from file.\nYour option: ";
    cin>>op;
    switch(op){
        case 1:
            cout<<"How many elements in a vertex would you like to add: ";
            cin>>vertexNum;
            for(int i=0; i<vertexNum; i++)
            {
                cout<<"Add element: ";
                cin>>element;
                if(contains(element)){
                    i-=1;
                }else{
                    vertexVector.push_back(element);
                }
                
            }
        print2();
        break;
        case 2:
        readFileVertex();
        print2();
        break;
        default:
            cout<<"Not valid";  

    }

}

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
        if(contains(a)){
            cout<<"";   
        }else{
            vertexVector.push_back(a);
        }
    }
 
    //copy (vertexVector.begin(), vertexVector.end(), ostream_iterator<string>(cout));

    vertexNum=vertexVector.size();
    
}

void Graph::addEdge(){
    int op=0;
    string element;
    string comp;

    cout<<"\n1. Add the edges manually.\n2. Read from file.\nYour option: ";
    cin>>op;
    switch(op){
        case 1:
            cout<<"How many edges would you like to add: ";
            cin>>edgesNum;
            for(int i=0; i<edgesNum; i++)
            {
                cout<<"Add a neat pair with format (i,j): ";
                cin>>element;

                if(validations(element)){
                    rlutil::setColor(rlutil::GREEN);
                    cout<<"Edge correct!"<<endl;
                    rlutil::resetColor();
                }else
                {
                    i-=1;
                    rlutil::setColor(rlutil::RED);
                    cout<<"Edge not correct!!"<<endl;
                    rlutil::resetColor();
                }
                
            } 
        print3();
        break;
        case 2:
        readFileEdge();
        print3();
        break;
        default:
        cout<<"Not valid";

    }
}

void Graph::readFileEdge()
{
    ifstream in("edges.txt");

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
        if(validations(a)){
            cout<<"";   
        }else{
            edgeVector.push_back(a);
        }
    }
 
    //copy (edgeVector.begin(), edgeVector.end(), ostream_iterator<string>(cout));

    edgesNum=edgeVector.size();
}

bool Graph::startsWith(string mainStr, string toMatch)
{
    //string::find returns 0 if toMatch is found at starting
    if(mainStr.find(toMatch) == 0)
        return true;
    else
        return false;
}

bool Graph::endsWith(string a, string b)
{
    //string::find returns 0 if toMatch is found at ending
    if (b.size() > a.size()) return false;
    return std::equal(a.begin() + a.size() - b.size(), a.end(), b.begin());
}


bool Graph::validations(string element)
{
    //0 true, 1 false
    //Validates element starts and ends with () and that it has no spaces
    if(startsWith(element,"(") && endsWith(element,")") && element.find((' ') != string::npos) && edgeValidation(element))
    {
        edgeVector.push_back(element);
        return true;
    }else{
        return false;
    }
}

bool Graph::edgeValidation(string edgeString)
{
    string edge1;
    string edge2;

    edgeString.erase(remove(edgeString.begin(), edgeString.end(), '('), edgeString.end());
    edgeString.erase(remove(edgeString.begin(), edgeString.end(), ')'), edgeString.end());
    edge1=process(edgeString);
    edge2=edgeString.substr(edgeString.find(",") + 1); 

    p1 = contains(edge1);
    p2 = contains(edge2);

    if(contains(edge1)==0 || contains(edge2)==0 )
    {
        rlutil::setColor(rlutil::RED);
        cout << "Edge not correct!" << endl;
        rlutil::resetColor();
        return false;
    }
    return true;
}

void Graph::changeTagEdge(string tag)
{
    string edgeString;
    string edge1;
    string edge2;
    string newTag;
    
    if(!contains(tag))
    {
        rlutil::setColor(rlutil::RED);
        cout<<"Element already exists!"<<endl;
        rlutil::resetColor();
        
    }else{
        for (int i=0; i<edgeVector.size(); i++)
            temp.push_back(edgeVector[i]); 
        edgeVector.clear();

        for (int i = 0; i < edgesNum; i++)
        {
            edgeString=temp[i];
            edgeString.erase(remove(edgeString.begin(), edgeString.end(), '('), edgeString.end());
            edgeString.erase(remove(edgeString.begin(), edgeString.end(), ')'), edgeString.end());
            edge1=process(edgeString);
            edge2=edgeString.substr(edgeString.find(",") + 1); 

            p1 = contains(edge1);
            p2 = contains(edge2);

            if(contains(edge1)==0)
            {
                newTag="("+tag+",";
            }else if(contains(edge1)==1)
            {
                newTag="("+edge1+",";
            }
            if(contains(edge2)==0)
            {
                newTag+=tag+")";
            }else if(contains(edge2)==1)
            {
                newTag+=edge2+")";
            }

            edgeVector.push_back(newTag);
    
        }
        temp.clear();
    }

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


//If element exists in vector
bool Graph::contains(string elem)
{
    bool result = false;
    if( find(vertexVector.begin(), vertexVector.end(), elem) != vertexVector.end() )
    {
        result = true;
    }
    return result;
}

//If element exists in vector
bool Graph::containsEdge(string elem)
{
    bool result = false;
    if( find(edgeVector.begin(), edgeVector.end(), elem) != edgeVector.end() )
    {
        result = true;
    }
    return result;
}

//Matrix

void Graph::initVertex()
{
    //print2();
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
            rlutil::setColor(rlutil::RED);
           cout << " " << endl;
            rlutil::resetColor();
        }

        mMatrix[p1][p2] = 1;
        mMatrix[p2][p1] = 1;
        
    }
}

//same think as contains
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
    for(int i=0; i<vertexNum;i++)
    {  
            if(i==0)
            {
                cout<<"  ";
                
            }
            cout<<mVertex[i]<< " ";
        
    }
    cout << endl;
    for (int i = 0; i < vertexNum; i++)
    {
        cout<<mVertex[i]<<" ";
        for (int j = 0; j < vertexNum; j++)
        {
            cout<<mMatrix[i][j] << " ";
        }
            
        cout << endl;
    }
}


void Graph::createGraph()
{
    std::copy(edgeVector.begin(), edgeVector.end(), std::back_inserter(vertexVector));
 
}

void Graph::print2(){
    rlutil::setColor(rlutil::CYAN);
    cout<<"\n" << "V = ";
    cout<<"{ " ;

    for(int i=0; i < vertexVector.size(); i++)
        cout<< vertexVector.at(i) << " , ";
    cout << "\b\b";
   
    cout<<" } "<<"\n";
    rlutil::resetColor();

}

void Graph::print3(){
    rlutil::setColor(rlutil::GREEN);
    cout<<"\n" << "E = ";
    cout<<"{ " ;

    for(int i=0; i < edgeVector.size(); i++)
        cout<< edgeVector.at(i) << " , ";
    cout << "\b\b";
   
    cout<<" } "<<"\n";
    rlutil::resetColor();
}


void Graph::addTag()
{
    print2();
    print3();
    string elem;
    string tag;
    cout<<"Which element would you like to add tag: ";
    cin>>elem;
    if(contains(elem))
    {
        cout<<"Add tag: ";
        cin>>tag;

        if(contains(tag))
        {
            rlutil::setColor(rlutil::RED);
            cout<<"Element already exists!"<<endl;
            rlutil::resetColor();
        }else{
            replace(vertexVector.begin(), vertexVector.end(), elem, tag);
            changeTagEdge(tag);
        }
        
    }else{
        rlutil::setColor(rlutil::RED);
        cout<<"Element doesn't exists!"<<endl;
        rlutil::resetColor();
    }
    tag.clear();
    print2();
    print3();
}

void Graph::print4(){
    rlutil::setColor(rlutil::MAGENTA);
    cout<<"\n";
    cout << "G = ";
    cout<<"{ ";
    cout<<"{ " ;
    for(int i=0; i < vertexVector.size(); i++)
        cout<< vertexVector.at(i) << ", ";
    cout << "\b\b";
    cout<<" } , ";
    cout<<"{ " ;
    for(int i=0; i < edgeVector.size(); i++)
        cout<< edgeVector.at(i) << ", ";
    cout << "\b\b";
    cout<<" } ";
    cout<<" } ";
    cout<<"\n";
    rlutil::resetColor();
}

