/**
 * Lars Jensen
 * CS 124
 * Section C
 */

#include "Team.h"
#include "Node.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "SplayTree.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

/**
 * Main
 * @return 0 if completed correctly with no errors
 */
int main() {
    //create Team object and vector of teams and populate it w data from file
    Team baseballTeam;
    vector<Team> baseballTeams;
    getDataFromFile("../baseball 2.csv", baseballTeams);

    //declare depth variable that will store depth of a given search
    int depth;

    ///////////////////////////
    /// Binary Search Trees ///
    ///////////////////////////

    //create binary tree of integers
    BinarySearchTree<int> intBST;

    //create file to write out to
    ofstream f_out;
    f_out.open("../inorderbinarydepthtracker.txt");

    //insert 1-100 in order into a BST and record depths to file
    f_out << "Inserting 1-100 in Order:" << endl;
    f_out << "Number\tDepth" << endl;
    for (int i = 1; i < 101; i++){
        depth = 0;
        intBST.add(i);
        intBST.find(i, depth);
        if (f_out){
            f_out << left << setw(8) << std::to_string(i);
            f_out << std::to_string(depth) << endl;
        }
    }
    depth = 0;

    //search for 0
    cout << intBST.find(0, depth) << endl;
    f_out << left << setw(8) << std::to_string(0);
    f_out << std::to_string(depth) << endl;
    depth = 0;

    //search for 101
    cout << intBST.find(101, depth) << endl;
    f_out << left << setw(8) << std::to_string(101);
    f_out << std::to_string(depth) << endl;
    depth = 0;

    //search for 102
    cout << intBST.find(102, depth) << endl;
    f_out << left << setw(8) << std::to_string(102);
    f_out << std::to_string(depth) << endl;
    depth = 0;

    //close f_out
    f_out.close();

    //create new BST, this one randomly ordered
    BinarySearchTree<int> randomIntBST;

    //create vector of random nums and shuffle it
    vector<int> randomNums;
    for(int i = 0; i < 101; i++){
        randomNums.push_back(i);
    }

    //shuffling learned from https://www.techiedelight.com/shuffle-vector-cpp/
    shuffle(randomNums.begin(), randomNums.end(), default_random_engine());

    //create file to write out to
    f_out.open("../randombinarydepthtracker.txt");

    //insert 1-100 in order into a BST and record depths
    f_out << "Inserting 1-100 Randomly:" << endl;
    f_out << "Number\tDepth" << endl;
    for (int i = 0; i < 100; i++){
        depth = 0;
        randomIntBST.add(randomNums[i]);
        randomIntBST.find(randomNums[i], depth);
        if (f_out){
            f_out << left << setw(8) << std::to_string(randomNums[i]);
            f_out << std::to_string(depth) << endl;
        }
    }
    f_out.close();

    //create binary search tree of team objects
    BinarySearchTree<Team> teamBST;

    //write to file
    f_out.open("../teambinarydepthtracker.txt");
    //insert 1-100 in order into a BST and record depths
    f_out << "Inserting Teams:" << endl;
    f_out << "Team ID\t\tDepth" << endl;
    for (int i = 0; i < baseballTeams.size(); i++){
        depth = 0;
        teamBST.add(baseballTeams[i]);
        teamBST.find(baseballTeams[i], depth);
        if (f_out){
            f_out << left << setw(16) << baseballTeams[i].getTeamID();
            f_out << std::to_string(depth) << endl;
        }
    }
    f_out.close();

    /////////////////
    /// AVL Trees ///
    /////////////////

    //AVL Tree:
    AVLTree<int> intAVL;
    f_out.open("../inorderAVLdepthtracker.txt");

    //insert 1-100 in order
    for (int i = 1; i < 101; i++){
        intAVL.add(i);
    }

    //search for 1-100 in order and record depths to file
    f_out << "Inserting 1-100 in Order:" << endl;
    f_out << "Number\tDepth" << endl;
    for (int i = 1; i < 101; i++){
        depth = 0;
        intAVL.find(i, depth);
        if (f_out){
            f_out << left << setw(8) << std::to_string(i);
            f_out << std::to_string(depth) << endl;
        }
    }
    depth = 0;
    f_out.close();

    //shuffle 1-100 again using same vector
    shuffle(randomNums.begin(), randomNums.end(), default_random_engine());

    //insert 1-100 randomly into AVL tree
    AVLTree<int> randomIntAVL;
    for (int i = 0; i < 100; i++){
        randomIntAVL.add(randomNums[i]);
    }

    f_out.open("../randomAVLdepthtracker.txt");

    //search for all numbers and record depths
    f_out << "Inserting 1-100 Randomly:" << endl;
    f_out << "Number\tDepth" << endl;
    for (int i = 0; i < 100; i++) {
        depth = 0;
        randomIntAVL.find(randomNums[i], depth);
        if (f_out) {
            f_out << left << setw(8) << std::to_string(randomNums[i]);
            f_out << std::to_string(depth) << endl;
        }
    }
    depth = 0;
    f_out.close();

    //create AVL tree of team objects
    AVLTree<Team> teamAVL;
    for (int i = 0; i < baseballTeams.size(); i++){
        teamAVL.add(baseballTeams[i]);
    }

    //write to file
    f_out.open("../teamAVLdepthtracker.txt");

    //search for teams in the AVL tree and record depths
    f_out << "Inserting Teams:" << endl;
    f_out << "Team ID\t\tDepth" << endl;
    for (int i = 0; i < baseballTeams.size(); i++){
        depth = 0;
        teamAVL.find(baseballTeams[i], depth);
        if (f_out){
            f_out << left << setw(16) << baseballTeams[i].getTeamID();
            f_out << std::to_string(depth) << endl;
        }
    }
    f_out.close();

    ///////////////////
    /// Splay Trees ///
    ///////////////////

    //create splay tree and file to write to
    SplayTree<int> intSplay;
    f_out.open("../inorderintSplaydepthtracker");

    //insert 1-100
    for (int i = 1; i < 101; i++){
        intSplay.add(i);
    }

    //search for 1-100 in the splay and record depths
    f_out << "Inserting 1-100 in Order:" << endl;
    f_out << "Number\tDepth" << endl;
    for (int i = 1; i < 101; i++){
        depth = 0;
        intSplay.find(i, depth);
        if (f_out){
            f_out << left << setw(8) << std::to_string(i);
            f_out << std::to_string(depth) << endl;
        }
    }
    depth = 0;
    f_out.close();

    //shuffle 1-100 again using same vector
    shuffle(randomNums.begin(), randomNums.end(), default_random_engine());

    //insert 1-100 randomly into Splay tree
    SplayTree<int> randomIntSplay;
    for (int i = 0; i < 100; i++){
        randomIntSplay.add(randomNums[i]);
    }

    //search for numbers inserted and record their depths to file
    f_out.open("../randomSplaydepthtracker.txt");
    f_out << "Inserting 1-100 Randomly:" << endl;
    f_out << "Number\tDepth" << endl;
    for (int i = 0; i < 100; i++) {
        depth = 0;
        randomIntSplay.find(randomNums[i], depth);
        if (f_out) {
            f_out << left << setw(8) << std::to_string(randomNums[i]);
            f_out << std::to_string(depth) << endl;
        }
    }
    depth = 0;
    f_out.close();

    //2 splay trees of team objects
    SplayTree<Team> teamSplay1;
    SplayTree<Team> teamSplay2;

    //insert teams into trees
    for (int i = 0; i < baseballTeams.size(); i++){
        teamSplay1.add(baseballTeams[i]);
        teamSplay2.add(baseballTeams[i]);
    }

    //open file to write to
    f_out.open("../teamsplaydepthtracker.txt");

    //insert teams in order into Splay tree and record depths
    f_out << "Inserting Teams:" << endl;
    f_out << "Team ID\t\tDepth" << endl;
    for (int i = 0; i < baseballTeams.size(); i++){
        depth = 0;
        teamSplay1.find(baseballTeams[i], depth);
        if (f_out){
            f_out << left << setw(16) << baseballTeams[i].getTeamID();
            f_out << std::to_string(depth) << endl;
        }
    }
    f_out.close();

    //in Splay tree 2, search for the objects in a random order,
    //and repeat each search five times

    //create vector of # of team items, and shuffle it
    vector<int> randomTeamNums;
    for (int i = 0; i < baseballTeams.size(); i++){
        randomTeamNums.push_back(i);
    }
    shuffle(randomTeamNums.begin(), randomTeamNums.end(), default_random_engine());

    //create file to write to
    f_out.open("../teamsplayrandomdepthtracker.txt");

    //search splay tree in random order, repeating each search 5 times, and record depths
    f_out << "Inserting Teams:" << endl;
    f_out << "Team ID\t\tDepth" << endl;
    for (int i = 0; i < baseballTeams.size(); i++){
        //repeat search 5 times
        for (int k = 0; k < 5; k++ ) {
            depth = 0;
            teamSplay2.find(baseballTeams[randomTeamNums[i]], depth);
            if (f_out){
                f_out << left << setw(16) << baseballTeams[randomTeamNums[i]].getTeamID();
                f_out << std::to_string(depth) << endl;
            }
        }
    }
    f_out.close();

    return 0;
}
