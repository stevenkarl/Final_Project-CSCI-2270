//
//  main.cpp
//  Steven_Karl_CSCI2270FinalProject
//
//  Created by Steven Karl on 7/23/17.
//  Copyright © 2017 Steven Karl. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Header.h"

using namespace std;


void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Print the Graph: This shows you what cities a certain city is directly connected with" << endl;
    cout << "2. Move to a new city: This tells you the shortest path between the cities you wish to move between" << endl;
    cout << "3. Find out information about a city" << endl;
    cout << "4. Count the number of cities in the graph" << endl;
    cout << "5. Play a minigame: If your bored of the graph and want a little challenge" << endl;
    cout << "6. Leave a suggestion to make this program better" << endl;
    cout << "7. Quit the program: If you can't win a mini game" << endl;
}

void openingStatement()
{
    cout << "Hello and welcome to this program. My name is Steven Karl and this is my final project.This project utilizes a graph to map out a few cities in California. The menu shown below tells you all of the things that you can accomplish with this program. Also this program utilize a doubley linked list in order to store the answer to the minigame that is playable by selecting choice 5 in the main menu. I hope that you enjoy this program and I hope that you have a good rest of your summer. I would suggest starting by using option # 1 to print out the graph so that you can see wht cities are actually in the Graph. Also Remember to capitalize the first letter of the cities that you type in. " << endl;
}
void closingStatement()
{
    cout << "Thank you for testing this program I had a lot of fun throughout the semester learning about Data Structures. I really wish that I could have had more time to work on this project, but I am happy with what I have created and I hope that you are too. Thanks and have a good summer" << endl;
}

void handleUserInput(List *charles, Graph *g)
{
    string choice = " ";
    int input;
    bool quit = false;
    openingStatement();
    while(quit == false){
        cout << "" << endl;
        displayMenu();
        cout << "" << endl;
        getline(cin, choice);
        input = stoi(choice);
        switch(input){
                
            case 1:{ // This is the case in which the user chooses 1 and wants to display the graphs vertices and connecting edges
                //just call the display edges function cause why not
                g->displayEdges();
                break;
            }
                
            case 2:{ // This is the case in which the user chooses 2 and wants to move to a new city
                string currentCity = "";
                string endCity = "";
                cout << "Enter your current city: " << endl;
                getline(cin, currentCity);
                cout << "Enter the city that you wish to move to: " << endl;
                getline(cin, endCity);
                //call the Dijkstra function that will tell you the path that you took and how far you traveled
                g->Dijkstra(currentCity, endCity);
                break;
            }
                
            case 3:{ //This is the case in which the user chooses 3 and wants to find out information about a city
                string cityInterestedIn = "";
                cout << "Enter in the city that you are interested in: " << endl;
                getline(cin, cityInterestedIn);
                //call the function that holds city information
                g->printVertexInformation(cityInterestedIn);
                
                break;
            }
                
            case 4:{ // This is the case in which the user chooses 4 and wants to count the number of total cities in the graph
                //call the count vertex fucntion that will traverse the graph and count the number of vertices
                cout << "The number of total cities represented in the graph are " << g->countTotalCities() << endl;;
                break;
            }
                
            case 5:{ // This is the case in which the user chooses 5 and is bored with the map and wants to play a mini game
                cout << endl;
                cout << "Welcome to the mini games section of this program, Get ready for some fun" << endl;
                cout << endl;
                cout << "Below are a few Random Riddles and trivia I hope you enjoy them" << endl;
                        int lives = 2;
                        bool life = true;
                        while(life == true){
                            string answer = "";
                            bool question1 = false;
                            cout << "You begin this section with 2 lives and you lose a life for every question you miss. All Riddles are one word answers" << endl;
                            cout << endl;
                            cout << "1st Question: What has hands but cannot clap?" << endl;
                            cout << endl;
                            cout << "Enter your answer here (Capitalize the first letter): " << endl;
                            cout << endl;
                            getline(cin, answer);
                            while(question1 == false){
                                if(charles->searchList(answer))
                                {
                                    cout << "Way to go you got the easiet one correct. Get ready it only gets harder from here" << endl;
                                    cout << endl;
                                    question1 = true;
                                }
                                else
                                {
                                    lives--;
                                    cout << "Good try, but sadly you lost 1 life. You now only have 1 left, and it only gets harder from here." << endl;
                                    cout << endl;
                                    question1 = true;
                                }
                            }
                            if(life == false)
                            {
                                break;
                            }
                            bool question2 = false;
                            string answer2 = "";
                            cout << "2nd Question: What is the name of Jon Snow's sword in Game of Thrones?" << endl;
                            cout << endl;
                            cout << "Enter your answer here (Capitalize the first letter): " << endl;
                            cout << endl;
                            getline(cin, answer2);
                            while(question2 == false)
                            {
                                if(charles->searchList(answer2))
                                {
                                    cout << "Well done you actually are impressing me...a little." << endl;
                                    cout << endl;
                                    question2 = true;
                                }
                                else
                                {
                                    lives--;
                                    if(lives == 0)
                                    {
                                        cout << "It looks like you got another one wrong too bad better luck next time" << endl;
                                        cout << endl;
                                        life = false;
                                    }
                                    else
                                    {
                                        cout << "Good try, sadly you lost a life you only have 1 life left" << endl;
                                        cout << endl;
                                    }
                                    question2 = true;
                                }
                            }
                            if(life == false)
                            {
                                break;
                            }
                            bool question3 = false;
                            string answer3 = "";
                            cout << "3rd Question: What has many keys but can't even open a single door?" << endl;
                            cout << endl;
                            cout << "Enter your answer here (Capitalize the first letter): " << endl;
                            cout << endl;
                            getline(cin, answer3);
                            while(question3 == false)
                            {
                                if(charles->searchList(answer3))
                                {
                                    cout << "You've done well so far but can you get this last one" << endl;
                                    cout << endl;
                                    question3 = true;
                                }
                                else
                                {
                                    lives--;
                                    if(lives == 0)
                                    {
                                        cout << "It looks like you got another one wrong too bad better luck next time" << endl;
                                        cout << endl;
                                        life = false;
                                    }
                                    else if(lives == 1)
                                    {
                                        cout << "Good luck your gonna need it for the next one" << endl;
                                        cout << endl;
                                    }
                                    else
                                    {
                                        cout << "Amazing you might actually make it to the end" << endl;
                                        cout << endl;
                                    }
                                    question3 = true;
                                }
                            }
                            if(life == false)
                            {
                                break;
                            }
                            bool question4 = false;
                            string answer4 = "";
                            cout << "4th Question: In the TV Show Rick and Morty what dimension is the main Rick and Morty from?" << endl;
                            cout << endl;
                            cout << "Enter your answer here (Capitalize the first letter) and no (-) needed: " << endl;
                            cout << endl;
                            getline(cin, answer4);
                            while(question4 == false)
                            {
                                if(charles->searchList(answer4))
                                {
                                    cout << "Amazing you made it to the end congratulations" << endl;
                                    cout << endl;
                                    question4 = true;
                                }
                                else
                                {
                                    lives--;
                                    if(lives == 0)
                                    {
                                        cout << "You were so close I'm sorry better luck next time" << endl;
                                        cout << endl;
                                        life = false;
                                    }
                                    else if(lives == 1)
                                    {
                                        cout << "You barely made it you won't be so lucky next time" << endl;
                                        cout << endl;
                                    }
                                    else
                                    {
                                        cout << "Amazing you made it to the end congratulations" << endl;
                                        cout << endl;
                                    }
                                    question4 = true;
                                }
                                life = false;
                            }
                        }
                break;//Case 5 breakpoint
            }
                
            case 6:{//This is the option that will be used if the user want to leave a suggestion
                string suggestion = "";
                cout << "Please enter a suggestion to make this program better: " << endl;
                cout << endl;
                getline(cin, suggestion);
                if(suggestion != "")
                {
                    cout << "Thank you for your suggestion, but honestly your opinion..." << endl;
                    cout << endl;
                }
                else
                {
                    cout << "Please leave a suggestion next time, that was just rude" << endl;
                    cout << endl;
                }
                break;
            }
                
            case 7:{ // This is the case in which the user chooses 6 and wishes to quit the program
                quit = true;
                charles -> deleteAllAnswers();
                cout << "" << endl;
                closingStatement();
                break;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////
int main(int argc, const char * argv[]) {
    
    
    Graph *g = new Graph;
    g->buildGraph();
    //g.Dijkstra("Oakland", "Saratoga");
    List *charles = new List();
    charles -> buildList();
    handleUserInput(charles, g);

    return 0;
}
