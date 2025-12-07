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
         int getPlayerID() {
        return playerID;
        }   
        
        void AddPlayer(int playerID, string name, int age, string role, int matches, int runs, int wickets){
            cout << "---Adding Player Details---" << endl;
            cout << "Enter Player ID: " << endl;
            cin  >> playerID;
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
       void UpdateStats() {
            cout << "---Updating Player Stats---" << endl;

            int addRuns;
            cout << "Enter Additional Runs Scored: ";
            cin >> addRuns;
            this->runs += addRuns;

            int addWickets;
            cout << "Enter Additional Wickets Taken: ";
            cin  >> addWickets;
            this->wickets += addWickets;

            cout << "Updated Total Runs Scored: " << this->runs << endl;
            cout << "Updated Total Wickets Taken: " << this->wickets << endl;
}

};

class Team {
private:
    int TeamID;
    string teamname;
    string country;
    Player listofplayers[11];

public:
    Team() {
        TeamID = 0;
        teamname = "";
        country = "";
    }

    void AddTeam() {
        cout << "---Adding Team Details---\n";

        cout << "Enter Team ID: ";
        cin >> TeamID;

        cout << "Enter Team Name: ";
        cin >> teamname;

        cout << "Enter Country: ";
        cin >> country;

        cout << "\nEnter 11 Players:\n";
        for (int i = 0; i < 11; i++) {
            cout << "\nPlayer " << (i+1) << ":\n";
            listofplayers[i].AddPlayer(0, "", 0, "", 0, 0, 0);
        }
    }

    void addplayertoTeam(Player p) {
        for (int i = 0; i < 11; i++) {
            if (listofplayers[i].getPlayerID() == 0) {
                listofplayers[i] = p;
                return;
            }
        }
        cout << "Team is full.\n";
    }

    void DisplayTeam() {
        cout << "---Team Details---\n";
        cout << "Team ID: " << TeamID << endl;
        cout << "Team Name: " << teamname << endl;
        cout << "Country: " << country << endl;

        for (int i = 0; i < 11; i++) {
            listofplayers[i].DisplayPlayer();
            cout << endl;
        }
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