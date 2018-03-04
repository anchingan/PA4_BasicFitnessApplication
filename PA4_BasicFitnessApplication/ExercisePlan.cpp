//
//  ExercisePlan.cpp
//  PA4_BasicFitnessApplication
//
//  Created by Ching-An Tsai on 01/03/2018.
//  Copyright © 2018 Chingan. All rights reserved.
//

#include "ExercisePlan.hpp"

// constructor
ExercisePlan::ExercisePlan() {
    this->mGoalSteps = 0;
    this->mPlanName = "";
    this->mDate = "";
}

ExercisePlan::ExercisePlan(int goalSteps, const string &planName, const string &date) {
    if (goalSteps >= 0)
        this->mGoalSteps = goalSteps;
    else
        this->mGoalSteps = 0;
    this->mPlanName = planName;
    this->mDate = date;
}

// copy
ExercisePlan::ExercisePlan(const ExercisePlan &newExercisePlan) {
    
}

void ExercisePlan::setGoalSteps() {
    int newGoal;
    cout << "Please input new goal steps:" <<endl;
    cin >> newGoal;
    if (newGoal >= 0)
        this->mGoalSteps = newGoal;
    
}

void ExercisePlan::setGoalSteps(int goalSteps) {
    this->mGoalSteps = goalSteps;
    
}

void ExercisePlan::setPlanName(const string &newPlanName) {
    
}

void ExercisePlan::setDate(const string &date) {
    
}

int ExercisePlan::getGoal() const {
    return this->mGoalSteps;
}

string ExercisePlan::getPlanName() const {
    return this->mPlanName;
}

string  ExercisePlan::getDate() const {
    return this->mDate;
}


// destructor
ExercisePlan::~ExercisePlan() {
    // no need to delete
}

// nonmember
ostream & operator << (ostream &out, const ExercisePlan &exercisePlan) {
    out << exercisePlan.getPlanName() << "\n" << exercisePlan.getGoal() << "\n" << exercisePlan.getDate() << endl;
    return out;
}

fstream & operator << (fstream &out, const ExercisePlan &exercisePlan) {
    out << exercisePlan.getPlanName() << "\n" << exercisePlan.getGoal() << "\n" << exercisePlan.getDate() << endl;
    return out;
}

