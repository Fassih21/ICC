#include <iostream>
#include <ctime>
#include <string>
#include <list> 
#include <fstream>
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

    Match() {
        matchID = 0;
        Team1 = "";
        Team2 = "";
        venue = "";
        date = "";
        result = "";
    }

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
class Tournament {
    private:
    int tournamentID;
    string tournamentName;
    Match matchesList[120];
    string winner;
    public:
    void AddMatch(){
        cout << "---Adding Match to Tournament---" << endl;
        int matchCount;
        cout << "Enter number of matches to add: ";
        cin >> matchCount;
        for (int i = 0; i < matchCount; i++) {
            cout << "\nMatch " << (i + 1) << ":\n";
            matchesList[i].PlayMatch();
        }
    }
    void displayResults() {
        cout << "---Tournament Results---" << endl;
        for (int i = 0; i < 120; i++) {
            matchesList[i].displayMatch();
        }
    }
};
class RankingSystem {
private:
    string teamNames[10];
    int teamPoints[10];
    int teamCount;

    string playerNames[50];
    int playerPoints[50];
    int playerCount;

public:
    RankingSystem() {
        teamCount = 0;
        playerCount = 0;
    }

    void updateRankings(string winningTeam, string playerName) {
        bool teamFound = false;
        for (int i = 0; i < teamCount; i++) {
            if (teamNames[i] == winningTeam) {
                teamPoints[i] += 2;
                teamFound = true;
                break;
            }
        }

        if (!teamFound && teamCount < 10) {
            teamNames[teamCount] = winningTeam;
            teamPoints[teamCount] = 2;
            teamCount++;
        }

        bool playerFound = false;
        for (int i = 0; i < playerCount; i++) {
            if (playerNames[i] == playerName) {
                playerPoints[i] += 10;
                playerFound = true;
                break;
            }
        }

        if (!playerFound && playerCount < 50) {
            playerNames[playerCount] = playerName;
            playerPoints[playerCount] = 10;
            playerCount++;
        }
    }

    void displayRankings() {
        cout << "\n--- Team Rankings ---\n";
        for (int i = 0; i < teamCount; i++) {
            cout << teamNames[i] << " : " << teamPoints[i] << " points\n";
        }

        cout << "\n--- Player Rankings ---\n";
        for (int i = 0; i < playerCount; i++) {
            cout << playerNames[i] << " : " << playerPoints[i] << " points\n";
        }
    }

    bool operator>(RankingSystem &other) {
        if (teamCount == 0 || other.teamCount == 0)
            return false;

        return teamPoints[0] > other.teamPoints[0];
    }
};
class Statistics {
public:
    void generateTopScorers() {
        ifstream file("players.csv");
        int id, runs, wickets;
        string name;
        int maxRuns = -1;
        string topScorer;

        while (file >> id >> name >> runs >> wickets) {
            if (runs > maxRuns) {
                maxRuns = runs;
                topScorer = name;
            }
        }
        file.close();

        cout << "Top Scorer: " << topScorer << " (" << maxRuns << " runs)\n";
    }

    void bestBowler() {
        ifstream file("players.csv");
        int id, runs, wickets;
        string name;
        int maxWickets = -1;
        string best;

        while (file >> id >> name >> runs >> wickets) {
            if (wickets > maxWickets) {
                maxWickets = wickets;
                best = name;
            }
        }
        file.close();

        cout << "Best Bowler: " << best << " (" << maxWickets << " wickets)\n";
    }

    void teamWinRatio() {
        ifstream file("teams.csv");
        string teamName;
        int wins, matches;

        cout << "\n--- Team Win Ratios ---\n";
        while (file >> teamName >> wins >> matches) {
            float ratio = (matches == 0) ? 0 : (float)wins / matches;
            cout << teamName << " : " << ratio << endl;
        }
        file.close();
    }
};

class ICC {
private:
    list<CricketBoard> boards;   

    string tournaments[20];      
    int tournamentCount;

    string globalRankings[50];   
    int rankingCount;

public:
    ICC() {
        tournamentCount = 0;
        rankingCount = 0;
    }

    void registerBoard(CricketBoard cb) {
        boards.push_back(cb);
        cout << "Cricket Board registered in ICC.\n";
    }

    void organizeTournament() {
        if (tournamentCount >= 20) {
            cout << "No space for more tournaments.\n";
            return;
        }

        cout << "Enter Tournament Name: ";
        cin.ignore();
        getline(cin, tournaments[tournamentCount]);
        tournamentCount++;

        cout << "Tournament organized under ICC.\n";
    }

    void addGlobalRanking() {
        if (rankingCount >= 50) {
            cout << "Ranking list full.\n";
            return;
        }

        cout << "Enter Team/Player Name for Ranking: ";
        cin.ignore();
        getline(cin, globalRankings[rankingCount]);
        rankingCount++;
    }

    void displayGlobalRankings() {
        cout << "\n--- ICC Global Rankings ---\n";
        for (int i = 0; i < rankingCount; i++) {
            cout << i + 1 << ". " << globalRankings[i] << endl;
        }
    }

    void saveToCSV() {
        ofstream file("ICC_Data.csv");

        file << "Cricket Boards\n";
        for (auto cb : boards) {
            file << "Board Saved\n";
        }

        file << "\nTournaments\n";
        for (int i = 0; i < tournamentCount; i++) {
            file << tournaments[i] << endl;
        }

        file << "\nGlobal Rankings\n";
        for (int i = 0; i < rankingCount; i++) {
            file << globalRankings[i] << endl;
        }

        file.close();
        cout << "ICC data saved to file.\n";
    }

    void loadFromCSV() {
        ifstream file("ICC_Data.csv");
        string line;

        cout << "\n--- Loading ICC Data ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
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

    T20Match t20;
    t20.PlayMatch();

    t20.displayMatch();

    Tournament tour;
    tour.AddMatch();
    tour.displayResults();

    ICC icc;
    icc.registerBoard(cb);
    icc.organizeTournament();
    icc.addGlobalRanking();
    icc.saveToCSV();

    return 0;
}

