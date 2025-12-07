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
        Player(){
            playerID=0;
            name="";
            age=0;
            role="";
            matches=0;
            runs=0;
            wickets=0;
        }
        
        void AddPlayer(int playerID, string name, int age, string role, int matches, int runs, int wickets){
            cout << "---Adding Player Details---" << endl;
            cout << "Enter Player ID: " << endl;
            cin  >> this->playerID;
            cout << "Enter Player's Name: " << endl;
            cin >> this->name;
            cout << "Enter Player's age: " << endl;
            cin >> this->age;
            cout << "Enter Player's Role: " << endl;
            cin >> this->role;
            cout << "Enter Number of Matches Played: " << endl;
            cin >> this->matches;
            cout << "Enter Total Runs Scored: " << endl;
            cin >> this->runs;
            cout << "Enter Total Wickets Taken: " << endl;
            cin >> this->wickets;
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

class Team{
    private:
        int TeamID;
        string teamname;
        string country;
        int listofplayers[11];
        public:
        Team(){
            TeamID=0;
            teamname="No name";
            country="No country";
            for(int i=0;i<11;i++){
                listofplayers[i]=0;
            }
        }
        void AddTeam(int TeamID, string teamname, string country, int listofplayers[11]){
            cout << "---Adding Team Details---" << endl;
            cout << "Enter Team ID: " << endl;
            cin >> TeamID;
            cout << "Enter Team Name: " << endl;
            cin >> teamname;
            cout << "Enter Country: " << endl;
            cin >> country;
            cout << "Enter Player IDs for 11 Players: " << endl;
            for(int i=0;i<11;i++){
                cin >> listofplayers[i];
            }
        }
        void addplayertoTeam(int playerID){
            cout << "---Adding Player to Team---" << endl;
            cout << "Enter Player ID to add: " << endl;
            cin >> playerID;
            for(int i=0;i<11;i++){
                if(listofplayers[i]==0){
                    listofplayers[i]=playerID;
                    cout << "Player ID " << playerID << " added to the team." << endl;
                    return;
                }
            }
            cout << "Team is already full. Cannot add more players." << endl;
        }
        void DisplayTeam(){
            cout << "---Team Details---" << endl;
            cout << "Team ID: " << TeamID << endl;
            cout << "Team Name: " << teamname << endl;
            cout << "Country: " << country << endl;
            cout << "Player IDs: ";
            for(int i=0;i<11;i++){
                cout << listofplayers[i] << " ";
            }
            cout << endl;
        }
        
};
class CricketBoard{
    private:
    int boardID;
    string boardName;
    string country;
    int listofteams;
    public:
    CricketBoard(){
        boardName="No name";
        country="No country";
        listofteams=0;
        boardID=0;
    }

    void AddBoard(int boardID, string boardName, string country, int listofteams){
        cout << "----Details----";
        cout << "Enter the Name of New Cricket Board: ";
        cin >> boardName;
        cout << "Enter the Id of your Cricket Board:";
        cin >> boardID;
        cout << "Enter the country of your Cricket Board: ";
        cin >> country;
        cout << "How much teams are under your Cricket Board: ";
        cin >> listofteams;
    }
    void DisplayBoard(){
        cout << "Your Board Name is: " << boardName << endl;
        cout << "Your Board ID is: " << boardID << endl;
        cout << "Your Board Country is: " << country << endl;
        cout << "Number of Teams associated with your Board is: " << listofteams << endl;
    }
};