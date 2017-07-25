//
//  main.cpp
//  Steven_Karl_CSCI2270FinalProject
//
//  Created by Steven Karl on 7/23/17.
//  Copyright © 2017 Steven Karl. All rights reserved.
//
///1) in order to call buildGraph in the main function do I need to create an object like weve done before
///2) For my print vertex information I was basically going to have the user enter a city name and then it would print out like 2 or three facts about the city and then that would be it. How should I write that function should I store the decription in the vertex itself or should I just do it hardcode style
///3) for the riddles if im going to store the answers in a linked list how should I go about doing that basically I was thinking it would just be 4 answers in a linked list and you would loop through it and say... if the string they input == the key/value of the linked list then they get it correct
// fix what you can if there is shit thats wrong with my code

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Header.h"

using namespace std;


void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Print the Graph" << endl;
    cout << "2. Move to a new city" << endl;
    cout << "3. Find out information about a city" << endl;
    cout << "4. Count the number of cities in the graph" << endl;
    cout << "5. Play a minigame: If your bored of the graph and want a little challenge" << endl;
    cout << "6. Leave a suggestion to make this program better" << endl;
    cout << "7. Quit the program: If you can't win a mini game" << endl;
}

void handleUserInput()
{
    string choice = " ";
    int input;
    bool quit = false;
    while(quit == false){
        displayMenu();
        getline(cin, choice);
        input = stoi(choice);
        switch(input){
                
            case 1:{ // This is the case in which the user chooses 1 and wants to display the graphs vertices and connecting edges
                //just call the display edges function cause why not
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
                break;
            }
                
            case 3:{ //This is the case in which the user chooses 3 and wants to find out information about a city
                string cityInterestedIn = "";
                cout << "Enter in the city that you are interested in: " << endl;
                getline(cin, cityInterestedIn);
                //call the function that holds city information
                
                break;
            }
                
            case 4:{ // This is the case in which the user chooses 4 and wants to count the number of total cities in the graph
                //call the count vertex fucntion that will traverse the graph and count the number of vertices
                break;
            }
                
            case 5:{ // This is the case in which the user chooses 5 and is bored with the map and wants to play a mini game
                cout << "Welcome to the mini games section of this program, Get ready for some fun" << endl;
                cout << "Random Riddles and trivia" << endl;
                        int lives = 2;
                        bool life = true;
                        while(life != false){
                            string answer = "";
                            bool question1 = false;
                            cout << "Welcome to the Riddles section of the minigames, you begin this game with 2 lives and you lose a life for every question you miss" << endl;
                            cout << "1st Question: What has hands but cannot clap?" << endl;
                            cout << "Enter your answer here: " << endl;
                            getline(cin, answer);
                            while(question1 == false){
                                if(answer == "Clock" || answer == "clock")
                                {
                                    cout << "Way to go you got the easiet one correct. Get ready it only gets harder from here" << endl;
                                    question1 = true;
                                }
                                else
                                {
                                    lives--;
                                    cout << "Good try, but sadly you lost 1 life. You now only have 1 left, and it only gets harder from here." << endl;
                                    question1 = true;
                                }
                            }
                            bool question2 = false;
                            string answer2 = "";
                            cout << "2nd Question: What is the name of Jon Snow's sword in Game of Thrones?" << endl;
                            cout << "Enter your answer here: " << endl;
                            getline(cin, answer2);
                            while(question2 == false)
                            {
                                if(answer2 == "Longclaw" || answer2 == "longclaw")
                                {
                                    cout << "Well done you actually are impressing me...a little." << endl;
                                    question2 = true;
                                }
                                else
                                {
                                    lives--;
                                    if(lives == 0)
                                    {
                                        cout << "It looks like you got another one wrong too bad better luck next time" << endl;
                                        life = false;
                                    
                                    }
                                    else
                                    {
                                        cout << "Good try, sadly you lost a life you only have 1 life left" << endl;
                                    }
                                    question2 = true;
                                }
                            }
                            bool question3 = false;
                            string answer3 = "";
                            cout << "3rd Question: What has many keys but can't even open a single door?" << endl;
                            cout << "Enter your answer here: " << endl;
                            getline(cin, answer3);
                            while(question3 == false)
                            {
                                if(answer3 == "Piano" || answer3 == "piano")
                                {
                                    cout << "You've done well so far but can you get this last one" << endl;
                                    question3 = true;
                                }
                                else
                                {
                                    lives--;
                                    if(lives == 0)
                                    {
                                        cout << "It looks like you got another one wrong too bad better luck next time" << endl;
                                        life = false;
                                    }
                                    else if(lives == 1)
                                    {
                                        cout << "Good luck your gonna need it for the next one" << endl;
                                    }
                                    else
                                    {
                                        cout << "Amazing you might actually make it to the end" << endl;
                                    }
                                    question3 = true;
                                }
                            }
                            bool question4 = false;
                            string answer4 = "";
                            cout << "4th Question: In the TV Show Rick and Morty what dimension is the main Rick and Morty from?" << endl;
                            cout << "Enter your answer here(no (-) please: " << endl;
                            getline(cin, answer4);
                            while(question4 == false)
                            {
                                if(answer4 == "C137" || answer4 == "c137")
                                {
                                    cout << "Amazing you made it to the end congratulations" << endl;
                                    question4 = true;
                                }
                                else
                                {
                                    lives--;
                                    if(lives == 0)
                                    {
                                        cout << "You were so close I'm sorry better luck next time" << endl;
                                        life = false;
                                    }
                                    else if(lives == 1)
                                    {
                                        cout << "You barely made it you won't be so lucky next time" << endl;
                                    }
                                    else
                                    {
                                        cout << "Amazing you made it to the end congratulations" << endl;
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
                getline(cin, suggestion);
                if(suggestion != "")
                {
                    cout << "Thank you for your suggestion" << endl;
                }
                else
                {
                    cout << "Please leave a suggestion next time, that was just rude" << endl;
                }
                break;
            }
                
            case 7:{ // This is the case in which the user chooses 6 and wishes to quit the program
                quit = true;
                cout << "Thank you for trying out this program" << endl;
                // call the deleteAll function to delete the graph
                
                break;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////
int main(int argc, const char * argv[]) {
    
    //buildGraph();
    handleUserInput();

    return 0;
}