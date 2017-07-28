//
//  Header.h
//  Steven_Karl_CSCI2270FinalProject
//
//  Created by Steven Karl on 7/23/17.
//  Copyright © 2017 Steven Karl. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct vertex;

struct adjVertex{// this is just an edge
    vertex *v;
    int weight;
};

struct vertex{
    string name;
    bool visited;
    int distance;
    vertex *previous;
    vector<adjVertex> adj;
};

class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(string v1, string v2, int weight);
    void addVertex(string name);
    void displayEdges();
    void buildGraph();
    void Dijkstra(string sourceVertex, string destinationVertex);
    //void breadthFirstSearch(string startingCity, string searchName);
    vertex * findVertex(string name);
    void printVertexInformation(string name);
    int countTotalCities();
    
protected:
private:
    //vector<edge> edges;
    vector<vertex> vertices;
    
};

Graph::Graph()
{
    
}

Graph::~Graph()
{
    //dtor
}

void Graph::addEdge(string v1, string v2, int weight)////////This is the function that is used to add edges connecting the vertices
{
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}

void Graph::addVertex(string n)// This adds vertices to the graph based on string city names
{
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == n)
        {
            found = true;
            cout << vertices[i].name << " found." << endl;
        }
    }
    if(found == false)
    {
        vertex v;
        v.name = n;
        v.distance = 0;
        v.visited = false;
        v.previous = nullptr;
        vertices.push_back(v);
    }
}

void Graph::displayEdges() //This is the function that is called when print graph is used to show the cities in the graph
{
    //loop through all vertices and adjacent vertices
    cout << "================================================="<<endl;
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name<<"-->";
        }
        cout<<endl;
    }
    cout << "================================================="<<endl;
}

void Graph::buildGraph()// this is the function that is used to build the graph/add the vertices and edges.
{
    //create the vertices
    addVertex("Oakland");
    addVertex("San Francisco");
    addVertex("Palo Alto");
    addVertex("San Jose");
    addVertex("Saratoga");
    addVertex("Los Gatos");
    addVertex("Santa Cruz");
    addVertex("Gilroy");
    addVertex("Monterey");
    addVertex("Salinas");
    addVertex("San Luis Obispo");
    addVertex("Santa Barbara");
    addVertex("Los Angeles");
    addVertex("San Diego");

    //create the edges
    addEdge("Oakland", "San Francisco", 15);
    addEdge("San Francisco", "Oakland", 15);
    addEdge("San Francisco", "Palo Alto", 30);
    addEdge("Palo Alto", "San Francisco", 30);
    addEdge("Palo Alto", "San Jose", 20);
    addEdge("San Jose", "Palo Alto", 20);
    addEdge("San Jose", "Saratoga", 13);
    addEdge("Saratoga", "San Jose", 13);
    addEdge("San Jose", "Los Gatos", 12);
    addEdge("Los Gatos", "San Jose", 12);
    addEdge("San Jose", "Gilroy", 35);
    addEdge("Gilroy", "San Jose", 35);
    addEdge("Los Gatos", "Saratoga", 6);
    addEdge("Saratoga", "Los Gatos", 6);
    addEdge("Saratoga", "Santa Cruz", 26);
    addEdge("Santa Cruz", "Saratoga", 26);
    addEdge("Los Gatos", "Santa Cruz", 22);
    addEdge("Santa Cruz", "Los Gatos", 22);
    addEdge("Santa Cruz", "Monterey", 43);
    addEdge("Monterey", "Santa Cruz", 43);
    addEdge("Gilroy", "Salinas", 30);
    addEdge("Salinas", "Gilroy", 30);
    addEdge("Monterey", "Salinas", 20);
    addEdge("Salinas", "Monterey", 20);
    addEdge("Monterey", "San Luis Obispo", 142);
    addEdge("San Luis Obsipo", "Monterey", 142);
    addEdge("Salinas", "San Luis Obispo", 125);
    addEdge("San Luis Obispo", "Salinas", 125);
    addEdge("San Luis Obispo", "Santa Barbara", 94);
    addEdge("Santa Barbara", "San Luis Obispo", 94);
    addEdge("Santa Barbara", "Los Angeles", 96);
    addEdge("Los Angeles", "Santa Barbara", 96);
    addEdge("Los Angeles", "San Diego", 120);
    addEdge("San Diego", "Los Angeles", 120);
}

void Graph::Dijkstra(string starting, string destination){// This is the function that is used to find the shortest path between 2 vertices(cities)
    
    vertex * start = nullptr;
    vertex * ending = nullptr;
    //search routine to find starting and destination
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].visited = false;
        vertices[i].distance = INT_MAX;
        vertices[i].previous = nullptr;
        if (vertices[i].name == starting) {
            start = &vertices[i];
        }
        if (vertices[i].name == destination) {
            ending = &vertices[i];
        }
    }
    if (start != nullptr && ending != nullptr)
    {
        start->visited = true;
        start->distance = 0;
        cout<<"pushing "<<start->name<<" into solved"<<endl;
        vector<vertex *> solved;
        vector<vertex *> path;
        solved.push_back(start);
        //path.push_back(start);
        adjVertex * v;
        vertex * u;
        vertex * minVertex = nullptr;
        vertex * prev = nullptr;
        while (ending->visited == false) {
            int minDistance = INT_MAX;
            for (int i = 0; i < solved.size(); i++) {
                u = solved[i];
                cout<<endl;
                cout<<"Inspecting route from "<<u->name<<endl;
                for (int j = 0; j < u->adj.size(); j++) {
                    v = &solved[i]->adj[j];
                    cout<<"-> to "<<v->v->name;
                    if (v->v->visited == false) {
                        cout<<", not yet solved,";
                        int dist = u->distance + v->weight;
                        if (dist < minDistance) {
                            cout<<" the minimum distance was "<<minDistance;
                            minDistance = dist;
                            minVertex = v->v;
                            prev = u;
                            cout<<" but there is a new minimum distance of "<<dist<<" between "
                            <<start->name <<" and "<<minVertex->name<<endl;
                        }else{cout<<" the minimum distance is "<<minDistance
                            <<" and there is not a new minimum distance "<<dist<<endl;}
                    }else{
                        cout<<" already solved, moving on"<<endl;
                    }
                }
                
            }
            solved.push_back(minVertex);
            cout<<endl;
            cout<<"pushing "<<minVertex->name<<" into solved ";
            minVertex->distance = minDistance;
            minVertex->previous = prev;
            minVertex->visited = true;
            cout<<minVertex->name;
            cout<<"(distance: "<<minVertex->distance
            <<", visited: "<<minVertex->visited
            <<", parent: "<<minVertex->previous->name<<")"<<endl;
            cout<<"destination "<<ending->name<<" solved? "<<ending->visited<<endl;
            cout<<endl;
        }
        cout<<"Shortest Path"<<endl;
        vertex * vert = ending;
        while (vert != nullptr) {
            path.push_back(vert);
            vert = vert->previous;
        }
        for (int i = 0; i < path.size(); i++) {
            if (i == path.size()-1)
                cout<<path[path.size()-1-i]->name;
            else
                cout<<path[path.size()-1-i]->name<<" - ";
            
        }
        cout<<endl;
        cout<<"Minimum Distance: "<<solved[solved.size()-1]->distance << " miles."<<endl;
    }else if (ending!=nullptr){
        cout<<"start not found"<<endl;
        exit(1);
    }else{
        cout<<"ending not found"<<endl;
        exit(1);
    }
}

vertex * Graph::findVertex(string name)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == name)
        {
            return &vertices[i];
        }
    }
    return nullptr;
}

void Graph::printVertexInformation(string name) //This is the function that is used to print out the information about each city.
{
    if(name == "Oakland")//city
    {
        cout << "The population of the city oakland is 420,005." << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is San Francisco." << endl;
    }
    if(name == "San Francisco")// city 2
    {
        cout << "The population of the city San Francisco is 864,816." << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is Oakland." << endl;
    }
    if(name == "Palo Alto")// city 3
    {
        cout << "The population of the city Palo Alto is 67,024." << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is San Jose." << endl;
    }
    if(name == "San Jose")// city 4
    {
        cout << "The population of the city San Jose is 1.025 Million." << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is Saratoga." << endl;
    }
    if(name == "Gilroy")//city 5
    {
        cout << "The population of the city Gilroy is 48,821." << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is San Jose." << endl;
    }
    if(name == "Los Gatos")// city 6
    {
        cout << "The population of the city Los Gatos is 30,391." << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is Saratoga." << endl;
    }
    if(name == "Saratoga")//city 7
    {
        cout << "The population of the city Saratoga is 29,926." << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is Los Gatos." << endl;
    }
    if(name == "Santa Cruz")//city 8
    {
        cout << "The population of the city Santa Cruz is 64,465." << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is Los Gatos." << endl;
    }
    if(name == "Salinas")// city 9
    {
        cout << "The population of the city Salinas is 157,218." << endl;
        cout << "This city is located in Central California and the next closest city in the graph is Monterey." << endl;
    }
    if(name == "Monterey")// city 10
    {
        cout << "The population of the city Monterey is 28,454." << endl;
        cout << "This city is located in Central California and the next closest city in the graph is Salinas." << endl;
    }
    if(name == "San Luis Obispo")// city 11
    {
        cout << "The population of the city San Luis Obispo is 47,536." << endl;
        cout << "This city is located in Southern California and the next closest city in the graph is Monterey." << endl;
    }
    if(name == "Santa Barbara")//city 12
    {
        cout << "The population of the city Santa Barbara is 91,930." << endl;
        cout << "This city is located in Southern California and the next closest city in the graph is San Luis Obispo." << endl;
    }
    if(name == "Los Angeles")//city 13
    {
        cout << "The population of the city Los Angeles is 3.976 Million." << endl;
        cout << "This city is located in Southern California and the next closest city in the graph is Santa Barbara." << endl;
    }
    if(name == "San Diego")// city 14
    {
        cout << "The population of the city San Diego is 1.407 Million." << endl;
        cout << "This city is located in Southern California and the next closest city in the graph is Los Angeles." << endl;
    }
}

int Graph::countTotalCities()//This is used to count the total number of cities in the graph at any time.
{
    int counter = 0;
    for(int i = 0; i < vertices.size(); i++)
    {
        counter = counter + 1;
    }
    return counter;
}

class List //This is the list class that is used for setting up the doubly linked list for the riddles
{
public:
    List();
    ~List();
    void addCity(string newCityName, string previousCityName);
    void buildList();
    bool searchList(string name);
    void deleteAllAnswers();

protected:
private:
    struct node
    {
        string key;
        node *next;
        node *previous;
        node(string cn)
        {
            key = cn;
            next = nullptr;
            previous = nullptr;
        }
    };
    node *head;
    node *tail;
    
};

List::List()
{
    head = new node("");
    tail = new node("");
}

List::~List()
{
    //dtor
}

void List::addCity(string newCityName, string previousCityName)//this is the function that adds a node to a linked list
{
    node *newCity = new node(newCityName);
    if (head->key == "")
    {
        head =  newCity;
        return;
    }
    if (previousCityName == "First")
    {//Case # 1 if they want to put the new city in front
        node *temp = head;
        head = newCity;
        
        newCity -> next = temp;
        head -> next = newCity -> next;
    }
    for (node *i = head; i != NULL; i = i -> next)
    {
        if (i-> key == previousCityName)
        {
            if (i->next == NULL)
            {//Case #2 if they want to put the new city at the end;
                i -> next = newCity;
                newCity -> previous = i;
            }
            else
            {                           //Case # 3 if they want to put the new city in the middle
                node *temp = i -> next;
                i -> next = newCity;
                newCity ->next = temp;
                newCity -> previous = i;
                temp -> previous = newCity;
            }
        }
    }
}

void List::buildList()//This is the function that is used to build the linked list for the riddles option in the menu
{
    node linus [5] = {node(""), node("Longclaw") , node("Piano"), node("C137"), node("Clock")};
    for (int i = 0; i < 4; i++)
    {
        addCity(linus[i+1].key, linus[i].key);
    }
    for (node *i = head; i != NULL; i = i->next)
    {
        if (i->next == NULL)
        {
            tail = i;
        }
    }
}

bool List::searchList(string name) //This function searches the linked list
{
    bool foundAnswer = false;
    for(node *i = head; i != nullptr; i = i -> next)
    {
        if(i->key == name)
        {
            foundAnswer = true;
        }
    }
    return foundAnswer;
}

void List::deleteAllAnswers()//This deletes all the nodes from the linked list when someone quits the program. 
{
    for(node *tmp = head; tmp != nullptr; tmp = tmp -> next)
    {
        delete tmp;
        cout<< "deleting node" << endl; //for all nodes in network
    }

}


#endif /* Header_h */
