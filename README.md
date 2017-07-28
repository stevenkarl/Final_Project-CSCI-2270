# Final_Project-CSCI-2270
CSCI 2270 Final Project - Steven Karl

Phase 2: ReadMe File 

Project Summary: 
  For final project I utilized a graph to create map of 14 different cities in California where I grew up. It is a weighted graph so the distances between each city is taken into account. When the program opens there will be a main menu that contain these different functionalities: 
    cout << "======Main Menu======" << endl;
    cout << "1. Print the Graph: This shows you what cities a certain city is directly connected with" << endl;
    cout << "2. Move to a new city: This tells you the shortest path between the cities you wish to move between" << endl;
    cout << "3. Find out information about a city" << endl;
    cout << "4. Count the number of cities in the graph" << endl;
    cout << "5. Play a minigame: If your bored of the graph and want a little challenge" << endl;
    cout << "6. Leave a suggestion to make this program better" << endl;
    cout << "7. Quit the program: If you can't win a mini game" << endl;
 I would recommend starting off by printing out the graph because that will give you a list of the cities that exisit in the graph which you will need to know for the other menu options. The next option chioce 2, this functionality allows you to find the shortest path between any two cities in the graph. Choice 3 is an option that allows you to input a city name and then you will be told information about the specific city that you were interested in. Choice 4 is an option that will count the total number of cities(vertices)that are present in the graph. Choice 5 is an option that takes you away from the graph functionalities and allows you to play a minigame which is a series of riddles and trivia that you need to answer. For this minigame section I utilized a doubly linked list to store the data for the riddles. Lastly, there are choice 6 and choice 7; in choice 6 you can leave a suggestion to make the program better and in choice 7 you can exit the program if you are done testing the functionalities. My program is split into my main.cpp file and my Header.h file. The main file is where I handle the users inputs and the header file is where all of my functions are written and my graph class and list class are defined. 
 
 The Cities that are in my graph: 
    Oakland
    San Francisco
    Palo Alto
    San Jose
    Saratoga
    Los Gatos
    Santa Cruz
    Gilroy
    Monterey
    Salinas
    San Luis Obispo
    Santa Barbara
    Los Angeles
    San Diego


How to Run: 
  When my program opens there will be an introduction that will tell you about the program and the features that it has. From that point you will see a "Main Menu" similar to what we used for a lot of our assignments. The main menu is fairly descriptive and by following it you should be able to test all of the functions that are present. Each menu option will prompt you for what you need to enter next to test the function. The only thing that I think is important to mention is that you should probably utilize menu option # 1 first: Print the Graph. This is because it will tell you what cities are in the graph which is important for testing the other functionalities. 


Dependencies: 

There are no dependencies for my program. It was built in XCode though, and it works well in XCode. 

System Requirements: 
Is your program for Windows, Mac, Linux?

My program was made in XCode so it is for Mac. 


My Name: 
  Steven Karl 
    
Open Issues/Bugs: 
  At this point I have tested my code numerous times and I have solved all the bugs that I found. I have run it many times since and I haven't found any more up to this point. I don't think that there are any bugs at this point that I know of.




Phase 1: 
Final Project Summary: 
  For my final project I will be creating weighted graph of cities near where I lived in Japan while I studied abroad. I will have the distances between the cities so that you will be able to find the shortest and longest path between certain cities. You will also be able to add and delete cities from the graph. In addition it will also have prices for the distances between the cities so you can calculate the most costly and least costly route. For the prices I will use the cost of a train ride from one city to the next because that is mainly how I traveled while I was there. At the moment below are some of the functions that I think that I will need. I will have a header file as well as a main cpp file that will run the program. The program will be taking in user input for all the options in order to test out the graph and all its functions. For this project I will be using vectors as well as a graph class which stores all of the functionalities that the user can manipulate the graph with.
  Functions that will be included: 
    1) countShortestPath 
    2) countLongestPath
    3) addCity
    4) deleteCity
    5) deleteAll
    6) breadthFirstSearch
    7) DepthFirstSearch
    8) Dystirkira - algorithm 
    9) printGraph 
    10) Various riddle/question functions (about each city for fun)  
    11) insertVertex 
    12) insertEdge 
 
