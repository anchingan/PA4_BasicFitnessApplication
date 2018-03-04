//
//  main.cpp
//  PA4_BasicFitnessApplication
//
//  Created by Chingan on 01/03/2018.
//  Copyright © 2018 Chingan. All rights reserved.
//

#include <iostream>
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"
#include "FitnessAppWrapper.hpp"

#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::fstream;
using std::ofstream;
//using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
//
//    fstream infile;
//    infile.open("/Users/chingan/Documents/Cpts122/PA4_BasicFitnessApplication/dietPlans.txt");
//    string line = "";
    FitnessAppWrapper test;
    test.runApp();
//    test.loadWeeklyPlan(infile, test.getDiets());
//    DietPlan a = test.getDiets()[3];
//    cout << a << endl;
//    infile.close();
//
//    ofstream outfile;
//    outfile.open("/Users/chingan/Documents/Cpts122/PA4_BasicFitnessApplication/test.txt");
//    outfile << a << endl;
//    outfile.close();
    
    return 0;
}
