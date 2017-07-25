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

struct adjVertex{
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
                    //another vertex for edge in other direction
                    //adjVertex av2;
                    //av2.v = &vertices[i];
                    //av2.weight = weight;
                    //vertices[j].adj.push_back(av2);
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
    //create the graph
    Graph g;
    //create the vertices
    g.addVertex("Oakland");
    g.addVertex("San Francisco");
    g.addVertex("Palo Alto");
    g.addVertex("San Jose");
    g.addVertex("Saratoga");
    g.addVertex("Los Gatos");
    g.addVertex("Santa Cruz");
    g.addVertex("Gilroy");
    g.addVertex("Monterey");
    g.addVertex("Salinas");
    g.addVertex("San Luis Obispo");
    g.addVertex("Santa Barbara");
    g.addVertex("Los Angeles");
    g.addVertex("San Diego");

    //create the edges
    g.addEdge("Oakland", "San Francisco", 15);
    g.addEdge("San Francisco", "Oakland", 15);
    g.addEdge("San Francisco", "Palo Alto", 30);
    g.addEdge("Palo Alto", "San Francisco", 30);
    g.addEdge("Palo Alto", "San Jose", 20);
    g.addEdge("San Jose", "Palo Alto", 20);
    g.addEdge("San Jose", "Saratoga", 13);
    g.addEdge("Saratoga", "San Jose", 13);
    g.addEdge("San Jose", "Los Gatos", 12);
    g.addEdge("Los Gatos", "San Jose", 12);
    g.addEdge("San Jose", "Gilroy", 35);
    g.addEdge("Gilroy", "San Jose", 35);
    g.addEdge("Los Gatos", "Saratoga", 6);
    g.addEdge("Saratoga", "Los Gatos", 6);
    g.addEdge("Saratoga", "Santa Cruz", 26);
    g.addEdge("Santa Cruz", "Saratoga", 26);
    g.addEdge("Los Gatos", "Santa Cruz", 22);
    g.addEdge("Santa Cruz", "Los Gatos", 22);
    g.addEdge("Santa Cruz", "Monterey", 43);
    g.addEdge("Monterey", "Santa Cruz", 43);
    g.addEdge("Gilroy", "Salinas", 30);
    g.addEdge("Salinas", "Gilroy", 30);
    g.addEdge("Monterey", "Salinas", 20);
    g.addEdge("Salinas", "Monterey", 20);
    g.addEdge("Monterey", "San Luis Obispo", 142);
    g.addEdge("San Luis Obsipo", "Monterey", 142);
    g.addEdge("Salinas", "San Luis Obispo", 125);
    g.addEdge("San Luis Obispo", "Salinas", 125);
    g.addEdge("San Luis Obispo", "Santa Barbara", 94);
    g.addEdge("Santa Barbara", "San Luis Obispo", 94);
    g.addEdge("Santa Barbara", "Los Angeles", 96);
    g.addEdge("Los Angeles", "Santa Barbara", 96);
    g.addEdge("Los Angeles", "San Diego", 120);
    g.addEdge("San Diego", "Los Angeles", 120);
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
        if(vertice[i].name == name)
        {
            return &vertices[i];
        }
    }
    return nullptr;
}

void Graph::printVertexInformation(string name)
{
    vertex = 
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




#endif /* Header_h */
