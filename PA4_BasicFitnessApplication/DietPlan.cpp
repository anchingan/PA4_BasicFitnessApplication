//
//  DietPlan.cpp
//  PA4_BasicFitnessApplication
//
//  Created by Chingan on 01/03/2018.
//  Copyright © 2018 Chingan. All rights reserved.
//

#include "DietPlan.hpp"

DietPlan::DietPlan() {
    
}

DietPlan::~DietPlan() {
    
}

void DietPlan::setGoalCalories() {
    int newGoal;
    cout << "Please input new goal calories:" <<endl;
    cin >> newGoal;
    if (newGoal >= 0) {
        this->mGoalCalories = newGoal;
        cout << "Goal calories is updated!" << endl;
    }
}
void DietPlan::setGoalCalories(int goal) {
    this->mGoalCalories = goal;
}
void DietPlan::setPlanName(const string &newPlanName) {
    this->mPlanName = newPlanName;
}
void DietPlan::setDate(const string &date) {
    this->mDate = date;
}

int DietPlan::getGoal() const { return this->mGoalCalories; }

string DietPlan::getPlanName() const { return mPlanName; }

string DietPlan::getDate() const { return this->mDate; }

// nonmember
ostream & operator << (ostream &out, const DietPlan &dietPlan) {
    out << dietPlan.getPlanName() << "\n" << dietPlan.getGoal() << "\n" << dietPlan.getDate() << endl;
    return out;
}

fstream & operator << (fstream &out, const DietPlan &dietPlan) {
    out << dietPlan.getPlanName() << "\n" << dietPlan.getGoal() << "\n" << dietPlan.getDate() << endl;
    return out;
}
