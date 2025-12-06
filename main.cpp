#include<iostream>
#include<string>
using namespace std;
class Player{
    private:
        int playerID;
        string name;
        int age;
        string role;
        int matches;
        int runs;
        int wickets;
        public:

        Player(int ID, string n, int a, string r, int m, int ru, int w){
            playerID=ID;
            name=n;
            age=a;
            role=r;
            matches=m;
            runs=ru;
            wickets=w;
        }
        void AddPlayer(int playerID, string name, int age, string role, int matches, int runs, int wickets){
            cout << "---Adding Player Details---" << endl;
            cout << "Enter Player ID: " << endl;
            cin >> playerID;
            cout << "Enter Player's Name: " << endl;
            cin >> name;
            cout << "Enter Player's age: " << endl;
            cin >> age;
            cout << "Enter Player's Role: " << endl;
            cin >> role;
            cout << "Enter Number of Matches Played: " << endl;
            cin >> matches;
            cout << "Enter Total Runs Scored: " << endl;
            cin >> runs;
            cout << "Enter Total Wickets Taken: " << endl;
            cin >> wickets;
        }
        void DisplayPlayer(){
            cout << "---Player Details---" << endl;
            cout << "Player ID: " << playerID << endl;
            cout << "Player's Name: " << name << endl;
            cout << "Player's Age: " << age << endl;
            cout << "Player's Role: " << role << endl;
            cout << "Number of Matches Played: " << matches << endl;
            cout << "Total Runs Scored: " << runs << endl;
            cout << "Total Wickets Taken: " << wickets << endl;
        }
        void UpdateStats(int runs, int wickets){
            cout << "---Updating Player Stats---" << endl;
            cout << "Enter Additional Runs Scored: " << endl;
            int addRuns;
            cin >> addRuns;
            runs += addRuns;
            cout << "Enter Additional Wickets Taken: " << endl;
            int addWickets;
            cin >> addWickets;
            wickets += addWickets;
            cout << "Updated Total Runs Scored: " << runs << endl;
            cout << "Updated Total Wickets Taken: " << wickets << endl;
        }
};