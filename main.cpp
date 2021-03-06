#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <chrono>
#include <stdlib.h>
#include <cctype>
#include "edgeList.h"
#include "adjacencyList.h"

using namespace std;
using namespace std::chrono;

int main() {
	cout << "Hello! Welcome to Fast Flying Fairies, a COVID-19 conscious service to help you find the least crowded flight(s) to certain destinations in the U.S!" << endl;
	bool x = true;
	string choice;
	string origin;
	string destination;

    edgeList eList;
    Graph adjList;
    eList.readFile(); //data is put into the edge list
    adjList.readFile(); //data is put into the adjacency list

    time_point<std::chrono::system_clock> start,end; //for timing purposes
    duration<double> elapsed_seconds;

	while (x == true) {
		cout << "What do you need help with?" << endl;
		cout << "1. List of all airports available in our service" << endl;
		cout << "2. Find airport route version 1" << endl;
        cout << "3. Find airport route version 2" << endl;
		cout << "4. End the program" << endl;
		cin >> choice;
        
		if (choice == "1") { //prints out all the airports
			eList.printGraph(); 
		}

		else if (choice == "2") { //return the route & passenger to seat ratio with each edge, edge list
			cout << "Nice! Enter your origin location" << endl;
			cin >> origin;
			cout << "Now enter your destination" << endl;
			cin >> destination;
			cout << "Processing..." << endl;

            start = system_clock::now();
            eList.edgeListDijkstras(eList,origin, destination);
            end = system_clock::now();
            elapsed_seconds = end-start;
            cout << "Route to destination took " << elapsed_seconds.count() << " seconds using an edge list" << endl << endl;
			//complete the graph algorithm to find the shortest route to destination
		}

        else if (choice == "3") { //return the route & passenger to seat ratio with each edge, adjacency list
			cout << "Nice! enter your origin location" << endl;
			cin >> origin;
			cout << "Now enter your destination" << endl;
			cin >> destination;
			cout << "Processing..." << endl;
			
            start = system_clock::now();
            adjList.adjListDijkstras(adjList, origin, destination);
            end = system_clock::now();
            elapsed_seconds = end-start;
            cout << "Route to destination took " << elapsed_seconds.count() << " seconds using an adjacency list" << endl << endl;
			//complete the graph algorithm to find the shortest route to destination
		}

		else if (choice == "4") {
			cout << "Thanks for using us!" << endl;
			x = false;
		}

		else {
			cout << "Sorry! Not a choice, please try again"<< endl;
		}
		
	}

	return 0;
}