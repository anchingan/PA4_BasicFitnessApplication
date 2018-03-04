//
//  DietPlan.hpp
//  PA4_BasicFitnessApplication
//
//  Created by Chingan on 01/03/2018.
//  Copyright © 2018 Chingan. All rights reserved.
//

#ifndef DietPlan_hpp
#define DietPlan_hpp

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

using std::string;
using std::ostream;
using std::fstream;
using std::cout;
using std::cin;
using std::endl;

class DietPlan {
public:
    DietPlan();
    ~DietPlan();
    
    void setGoalCalories();
    void setGoalCalories(int goal);
    void setPlanName(const string &newPlanName);
    void setDate(const string &date);
    
    int getGoal() const;
    string getPlanName() const;
    string getDate() const;
    
private:
    int mGoalCalories;
    string mPlanName;
    string mDate;
};
ostream & operator << (ostream &out, const DietPlan &dietPlan);

fstream & operator << (fstream &out, const DietPlan &dietPlan);

#endif /* DietPlan_hpp */
