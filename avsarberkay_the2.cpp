#include <iostream>
#include <string>
using namespace std;

// Berkay Avsar 27782


// Function to take absolute of negative values
double absolute(double value) {
    while (value < 0) {
        return value * (-1);
    }
    return value;
}
// Function to learn username
void getInput(string username) {
    double weight,speedWalk,minWalk,speedRun,minRun,speedCycling,minCycling,goal;
    bool inputCheck(double, double, double);
    void computeResults(double, double, double, double, double, double, double, double);
    cout << "Welcome " << username <<", please enter your weight(kg): ";
    cin >> weight;
    cout << username << ", please enter speed(km/h) and minutes spent in a week for the activities below." << endl;
    cout << "Walking: ";
    cin >> speedWalk >> minWalk;
    cout << "Running: ";
    cin >> speedRun >> minRun;
    cout << "Cycling: ";
    cin >> speedCycling >> minCycling;
    cout << username << ", please enter your weekly calorie burn goal: ";
    cin >> goal;
    if (inputCheck(speedWalk, weight, minWalk)) {
        if (inputCheck(speedRun, weight, minRun)) {
            if (inputCheck(speedCycling, weight, minCycling)) {
                computeResults(weight, goal, speedWalk, speedRun, speedCycling, minWalk, minRun, minCycling);
            }
        }
    }
}
// Second function to check inputs
bool inputCheck(double speed, double weight, double minute) {
    
    if (weight >= 30) {
        if (speed >= 4 && speed <= 30){
            if (minute >= 0 && minute <= 2000) {
                return true;
            }
            else {
                cout << "Minute out of range!" << endl;
                return false;
            }
        }
        else {
            cout << "Speed out of range!" << endl;
            return false;
        }
    }
    else {
        cout << "Weight out of range!" << endl;
        return false;
    }
}
// Third function to declare MET Values
double calculateMET(double speed, string exercise) {
    
    double MET = 0.0;
    if (exercise == "walking") {
        if (speed >= 4 && speed < 6.5) {
            MET = 4;
        }
        else if (speed >= 6.5) {
            MET = 6.5;
        }
    }
    else if (exercise == "running") {
        if (speed >= 4 && speed < 11) {
            MET = 9;
        }
        else if (speed >= 11) {
            MET = 12.5;
        }
    }
    else if (exercise == "cycling") {
        if (speed >= 4 && speed < 20) {
            MET = 6;
        }
        else if (speed >= 20 && speed < 25) {
            MET = 8;
        }
        else if (speed >= 25) {
            MET = 10.5;
        }
    }
    return MET;
}
// Fourth function to compute total calorie burned and its difference with the goal
void computeResults(double weight, double goal, double speedWalk, double speedRun, double speedCycling, double minWalk, double minRun, double minCycling) {
    void displayResults(double, double, double, double, double, double, double, double, double);
    double walkMET, runMET, cyclingMET;
    double walkCalorie, runCalorie, cycleCalorie, total, difference;
    walkMET = calculateMET(speedWalk, "walking");
    runMET = calculateMET(speedRun, "running");
    cyclingMET = calculateMET(speedCycling, "cycling");
    walkCalorie = (weight * walkMET) / 60 * minWalk;
    runCalorie = (weight * runMET) / 60 * minRun;
    cycleCalorie = (weight * cyclingMET) / 60 * minCycling;
    total = walkCalorie + runCalorie + cycleCalorie;
    difference = goal-total;
    displayResults(difference, total, weight, walkMET, runMET, cyclingMET, walkCalorie, runCalorie, cycleCalorie);
}
// Last function to display results
void displayResults(double difference, double total, double weight, double walkMET, double runMET, double cyclingMET, double walkCalorie, double runCalorie, double cycleCalorie ) {
    
    double remMinWalk = (difference * 60) / (weight * walkMET); // needed walk mins
    double remMinRun = (difference * 60) / (weight * runMET); // needed run mins
    double remMinCycle = (difference * 60) / (weight * cyclingMET); // needed cycling mins
    cout << "From walking, you burned " << walkCalorie << " calories." << endl;
    cout << "From running, you burned " << runCalorie << " calories." << endl;
    cout << "From cycling, you burned " << cycleCalorie << " calories." << endl;
    cout << "You burned " << total << " calories." << endl;
    
    
    
    if (difference < 0) {
        cout << "You have surpassed your goal! You can eat something worth " << absolute(difference) << " calories :)" << endl;
    }
    else if (difference > 0) {
        cout << "You did not reach your goal by " << absolute(difference) << " calories." << endl;
        cout << "You need to walk " << absolute(remMinWalk) << " minutes more to reach your goal or," << endl;
        cout << "You need to run " << absolute(remMinRun) << " minutes more to reach your goal or," << endl;
        cout << "You need to do cycling " << absolute(remMinCycle) << " minutes more to reach your goal." << endl;
    }
    else {
        cout << "Congratulations! You have reached your goal!" << endl;
    }
    
    
}


int main(){
    
    
    string name1, name2;
    cout << "Please enter your name: ";
    cin >> name1;
    getInput(name1);
    cout << endl;
    cout << "Please enter your name: ";
    cin >> name2;
    getInput(name2);
    
    
    
    
    
    
    return 0;
}

