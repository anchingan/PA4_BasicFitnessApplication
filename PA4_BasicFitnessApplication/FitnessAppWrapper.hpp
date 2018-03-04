//
//  FitnessAppWrapper.hpp
//  PA4_BasicFitnessApplication
//
//  Created by Ching-An Tsai on 02/03/2018.
//  Copyright © 2018 Chingan. All rights reserved.
//

#ifndef FitnessAppWrapper_hpp
#define FitnessAppWrapper_hpp

#include <stdio.h>
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"
#include <fstream>

using std::fstream;
using std::ofstream;
using std::stoi;

class FitnessAppWrapper {
public:
    FitnessAppWrapper();
    ~FitnessAppWrapper();
    void runApp(); // starts the main application
    
    // This function reads one record from the given stream. These will be considered overloaded functions! Precondition: file is already open!
    void loadDailyPlan (fstream &fileStream, DietPlan &plan);
    void loadDailyPlan (fstream &fileStream, ExercisePlan &plan);
    
    // This function must read in all seven daily plans from the given stream. This function should call loadDailyPlan () directly. Precondition: file is already open!
    void loadWeeklyPlan (fstream &fileStream, DietPlan weeklyPlan[]);
    void loadWeeklyPlan (fstream &fileStream, ExercisePlan weeklyPlan[]);
    
    void displayDailyPlan(DietPlan &plan);
    void displayDailyPlan(ExercisePlan &plan);
    
    void displayWeeklyPlan(DietPlan weeklyPlan[]);
    void displayWeeklyPlan(ExercisePlan weeklyPlan[]);
    
    void storeDailyPlan(fstream &fileStream, DietPlan &plan);
    void storeDailyPlan(fstream &fileStream, ExercisePlan &plan);
    
    void storeWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
    void storeWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);
    
    void displayMenu();
    
    DietPlan * getDiets();

private:
    // [0]: Sunday, [6]: Saturday
    DietPlan *mDiets;
    ExercisePlan *mExercises;
    
    // input & output fstream
    fstream mDietStream;
    fstream mExerciseStream;
    
    // file loaded ststus
    bool dietIsLoad;
    bool exerciseIsLoad;
};


/*

 -      displayMenu (): displays nine menu options. These include:
 
 1.    Load weekly diet plan from file.
 
 2.    Load weekly exercise plan from file.
 
 3.    Store weekly diet plan to file.
 
 4.    Store weekly exercise plan to file.
 
 5.    Display weekly diet plan to screen.
 
 6.    Display weekly exercise plan to screen.
 
 7.    Edit daily diet plan.
 
 8.    Edit daily exercise plan.
 
 9.    Exit.   // Note: this must write the most recent weekly plans to the corresponding files.
 */

#endif /* FitnessAppWrapper_hpp */
