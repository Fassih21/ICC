#include <iostream>
#include <ctime>
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
    Team listOfTeams[10];
    int teamCount;

public:
    CricketBoard() {
        boardID = 0;
        boardName = "No name";
        country = "No country";
        teamCount = 0;
    }

    void AddBoard() {
        cout << "----Adding Cricket Board----\n";
        cout << "Enter the Name of the Cricket Board: ";
        cin.ignore();
        getline(cin, boardName);
        cout << "Enter the ID of the Cricket Board: ";
        cin >> boardID;
        cin.ignore();
        cout << "Enter the country of the Cricket Board: ";
        getline(cin, country);
        teamCount = 0;
    }

    void addTeamToBoard(Team t) {
        if (teamCount < 10) {
            listOfTeams[teamCount] = t;
            teamCount++;
            cout << "Team added successfully.\n";
        } else {
            cout << "Cannot add more teams. Maximum reached.\n";
        }
    }

    void DisplayBoard() {
        cout << "----Cricket Board Details----\n";
        cout << "Board Name: " << boardName << endl;
        cout << "Board ID: " << boardID << endl;
        cout << "Board Country: " << country << endl;
        cout << "Number of Teams: " << teamCount << endl;

        for (int i = 0; i < teamCount; i++) {
            cout << "\nTeam " << (i + 1) << ":\n";
            listOfTeams[i].DisplayTeam();
        }
    }
};
class Match{
    public:
    int matchID;
    string Team1;
    string Team2;
    string venue;
    string date;
    string result;
   virtual void PlayMatch() {
    cout << "---Playing Match---" << endl;

    cout << "Enter Match ID: ";
    cin >> matchID;
    cin.ignore();

    cout << "Enter Team 1 Name: ";
    getline(cin, Team1);

    cout << "Enter Team 2 Name: ";
    getline(cin, Team2);

    cout << "Enter Venue: ";
    getline(cin, venue);

    cout << "Enter Date: ";
    getline(cin, date);

    int score1, score2;
    cout << "Enter score for " << Team1 << ": ";
    cin >> score1;
    cout << "Enter score for " << Team2 << ": ";
    cin >> score2;

    if (score1 > score2)
        result = Team1 + " won the match";
    else if (score2 > score1)
        result = Team2 + " won the match";
    else
        result = "The match is a draw";
}

void displayMatch() {
    cout << "\n---Match Details---" << endl;
    cout << "Match ID: " << matchID << endl;
    cout << "Team 1: " << Team1 << endl;
    cout << "Team 2: " << Team2 << endl;
    cout << "Venue: " << venue << endl;
    cout << "Date: " << date << endl;
    cout << "Result: " << result << endl;
    }
};

class T20Match : public Match {
    private:
    int overs;
    public:
    T20Match(){
        overs = 20;
    }
    int CalculateScore(int runs, int wickets){
        cout << "Calculating score for T20 Match with " << overs << " overs." << endl;
        int total = runs;
        for (int i = 0; i < overs; i++)
            total += rand() % 37;
        total -= wickets * 5;
        if (total < 0) total = 0;
        return total;
    }
       void PlayMatch() override {
        cout << "---Playing T20 Match---" << endl;

        cout << "Enter Match ID: ";
        cin >> matchID;
        cin.ignore();

        cout << "Enter Team 1 Name: ";
        getline(cin, Team1);

        cout << "Enter Team 2 Name: ";
        getline(cin, Team2);

        cout << "Enter Venue: ";
        getline(cin, venue);

        cout << "Enter Date: ";
        getline(cin, date);

        int score1, wickets1, score2, wickets2;
        cout << "Enter runs for " << Team1 << ": ";
        cin >> score1;
        cout << "Enter wickets lost: ";
        cin >> wickets1;

        cout << "Enter runs for " << Team2 << ": ";
        cin >> score2;
        cout << "Enter wickets lost: ";
        cin >> wickets2;

        score1 = CalculateScore(score1, wickets1);
        score2 = CalculateScore(score2, wickets2);

        if (score1 > score2)
            result = Team1 + " won the T20 match";
        else if (score2 > score1)
            result = Team2 + " won the T20 match";
        else
            result = "T20 Match Draw";
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