//
//  FitnessAppWrapper.cpp
//  PA4_BasicFitnessApplication
//
//  Created by Ching-An Tsai on 02/03/2018.
//  Copyright © 2018 Chingan. All rights reserved.
//

#include "FitnessAppWrapper.hpp"

// need to delete
DietPlan * FitnessAppWrapper::getDiets() {
    return this->mDiets;
}

FitnessAppWrapper::FitnessAppWrapper() {
    mDiets = new DietPlan[7];
    mExercises = new ExercisePlan[7];
    mDietStream.open("/Users/chingan/Documents/Cpts122/PA4_BasicFitnessApplication/dietPlans.txt");
    mExerciseStream.open("/Users/chingan/Documents/Cpts122/PA4_BasicFitnessApplication/exercisePlans.txt");
    dietIsLoad = false;
    exerciseIsLoad = false;
}
FitnessAppWrapper::~FitnessAppWrapper() {

}

// starts the main application
void FitnessAppWrapper::runApp() {
    int option = 0;
    int day;
    while (option != 9) {
        displayMenu();
        cin >> option;
        switch (option) {
            case 1:
                loadWeeklyPlan(this->mDietStream, this->mDiets);
                this->dietIsLoad = true;
                break;
                
            case 2:
                loadWeeklyPlan(this->mExerciseStream, this->mExercises);
                this->exerciseIsLoad = true;
                break;
                
            case 3:
                if(!dietIsLoad)
                    cout << "Please load diet plan first!" << endl;
                else
                    storeWeeklyPlan(this->mDietStream, this->mDiets);
                break;
                
            case 4:
                if(!exerciseIsLoad)
                    cout << "Please load exercise plan first!" << endl;
                else
                    storeWeeklyPlan(this->mExerciseStream, this->mExercises);
                break;
                
            case 5:
                if(!dietIsLoad)
                    cout << "Please load diet plan first!" << endl;
                else
                    displayWeeklyPlan(this->mDiets);
                break;
                
            case 6:
                if(!exerciseIsLoad)
                    cout << "Please load exercise plan first!" << endl;
                else
                    displayWeeklyPlan(this->mExercises);
                break;
                
            case 7:
                cout << "Please input which day you want to edit(Sunday:0, Monday: 1...etc): ";
                cin >> day;
                if (day >= 0 && day <= 6){
                    this->mDiets[day].setGoalCalories();
                    storeWeeklyPlan(this->mDietStream, this->mDiets);
                } else
                    cout << "Wrong input!" << endl;
                break;
                
            case 8:
                cout << "Please input which day you want to edit(Sunday:0, Monday: 1...etc): ";
                cin >> day;
                if (day >= 0 && day <= 6){
                    this->mExercises[day].setGoalSteps();
                    storeWeeklyPlan(this->mExerciseStream, this->mExercises);
                } else
                    cout << "Wrong input!" << endl;
                break;
                
            case 9:
                break;
                
            default:
                cout << "Wrong input!" << endl;
                break;
        }
    }
}

void FitnessAppWrapper::loadDailyPlan (fstream &fileStream, DietPlan &plan) {
    string line = "";
    if (getline(fileStream, line)){
        plan.setPlanName(line);
        getline(fileStream, line);
        int goal = stoi(line);
        plan.setGoalCalories(goal);
        getline(fileStream, line);
        plan.setDate(line);
        getline(fileStream, line);
    } else
        return;
}

void FitnessAppWrapper::loadDailyPlan (fstream &fileStream, ExercisePlan &plan) {
    string line = "";
    if (getline(fileStream, line)){
        plan.setPlanName(line);
        getline(fileStream, line);
        int goal = stoi(line);
        plan.setGoalSteps(goal);
        getline(fileStream, line);
        plan.setDate(line);
        getline(fileStream, line);
    } else
        return;
}

void FitnessAppWrapper::loadWeeklyPlan (fstream &fileStream, DietPlan weeklyPlan[]) {
    if (fileStream.is_open()){
        for (int i = 0; i < 7; i++)
            loadDailyPlan(fileStream, weeklyPlan[i]);
        fileStream.close();
        cout << "DietPlan loaded!" << endl;
    } else {
        cout << "File is not open!" <<endl;
    }

}

void FitnessAppWrapper::loadWeeklyPlan (fstream &fileStream, ExercisePlan weeklyPlan[]) {
    if (fileStream.is_open()){
        for (int i = 0; i < 7; i++)
            loadDailyPlan(fileStream, weeklyPlan[i]);
        fileStream.close();
        cout << "ExercisePlan loaded!" << endl;
    } else {
        cout << "File is not open!" <<endl;
    }
}

void FitnessAppWrapper::displayDailyPlan(DietPlan &plan) {
    cout << plan << endl;
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan &plan) {
    cout << plan << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[]) {
    for (int i = 0; i < 7; i++)
        displayDailyPlan(weeklyPlan[i]);
}
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[]) {
    for (int i = 0; i < 7; i++)
        displayDailyPlan(weeklyPlan[i]);
}

void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, DietPlan &plan) {
    if (fileStream.is_open())
        fileStream << plan << endl;
    else
        cout << "Files is not open!" << endl;
}

void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, ExercisePlan &plan) {
    if (fileStream.is_open())
        fileStream << plan << endl;
    else
        cout << "Files is not open!" << endl;
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]) {
    fileStream.open("/Users/chingan/Documents/Cpts122/PA4_BasicFitnessApplication/dietPlans.txt");
    for (int i = 0; i < 7; i++)
        storeDailyPlan(fileStream, weeklyPlan[i]);
    fileStream.close();
    
    cout << "Diet Plan stored!" << endl;
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]) {
    fileStream.open("/Users/chingan/Documents/Cpts122/PA4_BasicFitnessApplication/exercisePlans.txt");
    for (int i = 0; i < 7; i++)
        storeDailyPlan(fileStream, weeklyPlan[i]);
    fileStream.close();
    
    cout << "Exercise Plan stored!" << endl;
}

void FitnessAppWrapper::displayMenu() {
    cout << "MENU" << endl;
    cout << "1. Load weekly diet plan from file." << endl;
    cout << "2. Load weekly exercise plan from file." << endl;
    cout << "3. Store weekly diet plan to file." << endl;
    cout << "4. Store weekly exercise plan to file." << endl;
    cout << "5. Display weekly diet plan to screen." << endl;
    cout << "6. Display weekly exercise plan to screen." << endl;
    cout << "7. Edit daily diet plan." << endl;
    cout << "8. Edit daily exercise plan." << endl;
    cout << "9. Exit." << endl;
    cout << "Please input your oprion: ";
}
