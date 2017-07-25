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
    void breadthFirstSearch(string startingCity, string searchName);
    vertex * findVertex(string name);
    void printVertexInformation(string name);
    void countTotalCities(string name);
    void deleteAllCities(string name);
    
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

void Graph::addEdge(string v1, string v2, int weight)
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

void Graph::addVertex(string n)
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

void Graph::displayEdges()
{
    //loop through all vertices and adjacent vertices
    cout << "================================================="<<endl;
    for(int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i].name << "-->" << endl;
        for(int j = 0; j < vertices.size();j++)
        {
            cout << vertices[i].adj[j].v -> name;
            cout << " (distance: "<< vertices[i].adj[j].v -> distance << " , visited: "<<vertices[i].adj[j].v -> visited <<" , parent: ";
            if(vertices[i].adj[j].v->previous == nullptr)
            {
                cout << " nullptr)"<< endl;
            }
            else
            {
                cout << vertices[i].adj[j].v -> previous -> name << ")"<<endl;
            }
        }
        cout << "================================================="<<endl;
    }
}

void Graph::buildGraph()
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

void Graph::Dijkstra(string starting, string destination)
{
    vertex * start = nullptr;
    vertex * ending = nullptr;
    //search to find starting and destination
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].visited = false;
        vertices[i].distance = INT_MAX;
        vertices[i].previous = nullptr;
        if (vertices[i].name == starting){
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
        vector<vertex *> solved;
        vector<vertex *> path;
        solved.push_back(start);
        adjVertex * v;
        vertex * u;
        vertex * minVertex;
        vertex * prev;
        while (ending->visited == false) {
            int minDistance = INT_MAX;
            for (int i = 0; i < solved.size(); i++) {
                u = solved[i];
                for (int j = 0; j < u->adj.size(); j++) {
                    v = &solved[i]->adj[j];
                    if (v->v->visited == false) {
                        int dist = u->distance + v->weight;
                        if (dist < minDistance) {
                            minDistance = dist;
                            minVertex = v->v;
                            prev = u;
                        }
                    }
                }
            }
            solved.push_back(minVertex);
            minVertex->distance = minDistance;
            minVertex->previous = prev;
            minVertex->visited = true;
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
        cout<<"Minimum Distance: " <<solved[solved.size()-1]->distance<<endl;
    }
    else if (ending!=nullptr)
    {
        exit(1);
    }
    else{
        exit(1);
    }
}

void Graph::breadthFirstSearch(string startingCity, string searchName)
{
    //label everything as not visited
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
    }
    vertex = findVertex(startingCity);
    vertex.visited = true;
    vertex.distance = 0;
    queue.enqueue(vertex);
    while(!queue.isEmpty)
    {
        n = queue.dequeue();
        for(int i = 0; i < n.adjacent.end(); i++)
        {
            if(!n.adjacent.visited)
            {
                n.adjacnet[i].v.distance = n.distance + 1;
                if(n.adjacent[i].v.key == searchName)
                {
                    return n.adjacent[i].v;
                }
                else
                {
                    n.adjacent[i].v.visited == true;
                    queue.enqueue(n.adjacent[i].v);
                }
            }
        }
    }
    return nullptr;
}

vertex * Graph::findVertex(string name)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == name)
        {
            return vertices[i]
        }
    }
    return nullptr;
}

void Graph::printVertexInformation(string name)
{
    if(name == "Oakland")//city
    {
        cout << "The population of the city oakland is 420,005" << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is San Francisco." << endl;
    }
    if(name == "San Francisco")// city 2
    {
        cout << "The population of the city San Francisco is 864,816" << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is Oakland." << endl;
    }
    if(name == "Palo Alto")// city 3
    {
        cout << "The population of the city Palo Alto is 67,024" << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is San Jose." << endl;
    }
    if(name == "San Jose")// city 4
    {
        cout << "The population of the city San Jose is 1.025 Million" << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is Saratoga." << endl;
    }
    if(name == "Gilroy")//city 5
    {
        cout << "The population of the city Gilroy is 48,821" << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is San Jose." << endl;
    }
    if(name == "Los Gatos")// city 6
    {
        cout << "The population of the city Los Gatos is 30,391" << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is Saratoga." << endl;
    }
    if(name == "Saratoga")//city 7
    {
        cout << "The population of the city Saratoga is 29,926" << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is Los Gatos." << endl;
    }
    if(name == "Santa Cruz")//city 8
    {
        cout << "The population of the city Santa Cruz is 64,465" << endl;
        cout << "This city is located in Northern California and the next closest city in the graph is Los Gatos." << endl;
    }
    if(name == "Salinas")// city 9
    {
        cout << "The population of the city Salinas is 157,218" << endl;
        cout << "This city is located in Central California and the next closest city in the graph is Monterey." << endl;
    }
    if(name == "Monterey")// city 10
    {
        cout << "The population of the city Monterey is 28,454" << endl;
        cout << "This city is located in Central California and the next closest city in the graph is Salinas." << endl;
    }
    if(name == "San Luis Obispo")// city 11
    {
        cout << "The population of the city San Luis Obispo is 47,536" << endl;
        cout << "This city is located in Southern California and the next closest city in the graph is Monterey." << endl;
    }
    if(name == "Santa Barbara")//city 12
    {
        cout << "The population of the city Santa Barbara is 91,930" << endl;
        cout << "This city is located in Southern California and the next closest city in the graph is San Luis Obispo." << endl;
    }
    if(name == "Los Angeles")//city 13
    {
        cout << "The population of the city Los Angeles is 3.976 Million" << endl;
        cout << "This city is located in Southern California and the next closest city in the graph is Santa Barbara." << endl;
    }
    if(name == "San Diego")// city 14
    {
        cout << "The population of the city San Diego is 1.407 Million" << endl;
        cout << "This city is located in Southern California and the next closest city in the graph is Los Angeles." << endl;
    }
}

int Graph::countTotalCities(string name)
{
    int counter = 0;
    for(int i = 0; i < vertices.size(); i++)
    {
        counter = counter + 1;
    }
    return counter;
}

void Graph::deleteAll()
{
    //loop through the vector and delete the resources I allocated
}




#endif /* Header_h */
