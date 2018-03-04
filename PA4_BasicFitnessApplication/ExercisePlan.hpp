//
//  ExercisePlan.hpp
//  PA4_BasicFitnessApplication
//
//  Created by Ching-An Tsai on 01/03/2018.
//  Copyright © 2018 Chingan. All rights reserved.
//

#ifndef ExercisePlan_hpp
#define ExercisePlan_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ostream;
using std::fstream;
using std::cin;
using std::cout;
using std::endl;

class ExercisePlan {
public:
    // constructor
    ExercisePlan();
    ExercisePlan(int goalSteps, const string &planName, const string &date);
    // copy
    ExercisePlan(const ExercisePlan &newExercisePlan);
    
    void setGoalSteps();
    void setGoalSteps(int goalSteps);
    void setPlanName(const string &newPlanName);
    void setDate(const string &date);
    
    int getGoal() const;
    string getPlanName() const;
    string getDate() const;
    
    // destructor
    ~ExercisePlan();
    
private:
    int mGoalSteps;
    string mPlanName;
    string mDate;
};

ostream & operator << (ostream &out, const ExercisePlan &exercisePlan);
fstream & operator << (fstream &out, const ExercisePlan &exercisePlan);
#endif /* ExercisePlan_hpp */
