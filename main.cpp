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

class Team{
    private:
        int TeamID;
        string teamname;
        string country;
        int listofplayers[11];
        public:
        Team(int TID, string tname, string ctry, int lop[11]){
            TeamID=TID;
            teamname=tname;
            country=ctry;
            for(int i=0;i<11;i++){
                listofplayers[i]=lop[i];
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