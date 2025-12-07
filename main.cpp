#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    int playerID;
    string name;
    int age;
    string role;
    int matches;
    int runs;
    int wickets;

public:
    Player() {
        playerID = 0;
        name = "";
        age = 0;
        role = "";
        matches = 0;
        runs = 0;
        wickets = 0;
    }

    int getPlayerID() {
        return playerID;
    }

    void AddPlayer() {
        cout << "---Adding Player Details---" << endl;
        cout << "Enter Player ID: ";
        cin >> playerID;
        cin.ignore();
        cout << "Enter Player's Name: ";
        getline(cin, name);
        cout << "Enter Player's Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Player's Role: ";
        getline(cin, role);
        cout << "Enter Number of Matches Played: ";
        cin >> matches;
        cout << "Enter Total Runs Scored: ";
        cin >> runs;
        cout << "Enter Total Wickets Taken: ";
        cin >> wickets;
    }

    void DisplayPlayer() {
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
        runs += addRuns;
        int addWickets;
        cout << "Enter Additional Wickets Taken: ";
        cin >> addWickets;
        wickets += addWickets;
        cout << "Updated Total Runs Scored: " << runs << endl;
        cout << "Updated Total Wickets Taken: " << wickets << endl;
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
        cout << "---Adding Team Details---" << endl;
        cout << "Enter Team ID: ";
        cin >> TeamID;
        cin.ignore();
        cout << "Enter Team Name: ";
        getline(cin, teamname);
        cout << "Enter Country: ";
        getline(cin, country);
        cout << "\nEnter 11 Players:\n";
        for (int i = 0; i < 11; i++) {
            cout << "\nPlayer " << (i + 1) << ":\n";
            listofplayers[i].AddPlayer();
        }
    }

    void addPlayerToTeam(Player p) {
        for (int i = 0; i < 11; i++) {
            if (listofplayers[i].getPlayerID() == 0) {
                listofplayers[i] = p;
                return;
            }
        }
        cout << "Team is full.\n";
    }

    void DisplayTeam() {
        cout << "---Team Details---" << endl;
        cout << "Team ID: " << TeamID << endl;
        cout << "Team Name: " << teamname << endl;
        cout << "Country: " << country << endl;
        for (int i = 0; i < 11; i++) {
            listofplayers[i].DisplayPlayer();
            cout << endl;
        }
    }
};

class CricketBoard {
private:
    int boardID;
    string boardName;
    string country;
    int listofteams;

public:
    CricketBoard() {
        boardID = 0;
        boardName = "No name";
        country = "No country";
        listofteams = 0;
    }

    void AddBoard() {
        cout << "----Adding Cricket Board Details----" << endl;
        cin.ignore();
        cout << "Enter Board Name: ";
        getline(cin, boardName);
        cout << "Enter Board ID: ";
        cin >> boardID;
        cin.ignore();
        cout << "Enter Country: ";
        getline(cin, country);
        cout << "Enter Number of Teams under this Board: ";
        cin >> listofteams;
    }

    void DisplayBoard() {
        cout << "---Cricket Board Details---" << endl;
        cout << "Board Name: " << boardName << endl;
        cout << "Board ID: " << boardID << endl;
        cout << "Country: " << country << endl;
        cout << "Number of Teams: " << listofteams << endl;
    }
};

int main() {
    Player p;
    p.AddPlayer();
    p.DisplayPlayer();
    p.UpdateStats();

    Team t;
    t.AddTeam();
    t.DisplayTeam();

    CricketBoard cb;
    cb.AddBoard();
    cb.DisplayBoard();

    return 0;
}
