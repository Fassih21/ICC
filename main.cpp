#include <iostream>
#include <ctime>
#include <string>
#include <list> 
#include <fstream>
#include <type_traits>
#include <sstream>
using namespace std;

class Person {
public:
    virtual void displayInfo() = 0;
};

class Player : public Person {
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

    int getPlayerID(){

         return playerID; 

        }

    void AddPlayer() {
        cout << "---Adding Player Details---\n";
        cout << "Enter Player ID: "; 
        cin >> playerID;
        cin.ignore();
        cout << "Enter Player Name: ";
        getline(cin, name);
        cout << "Enter Age: "; 
        cin >> age; 
        cin.ignore();
        cout << "Enter Role: "; 
        getline(cin, role);
        cout << "Matches Played: "; 
        cin >> matches;
        cout << "Total Runs: "; 
        cin >> runs;
        cout << "Total Wickets: "; 
        cin >> wickets;
    }

    void UpdateStats() {
        int addRuns, addWickets;
        cout << "Additional Runs: "; cin >> addRuns;
        cout << "Additional Wickets: "; cin >> addWickets;
        runs += addRuns; wickets += addWickets;
    }

    void displayInfo() override {
        cout << "---Player Info---\n";
        cout << "ID: " << playerID << "\nName: " << name
             << "\nAge: " << age << "\nRole: " << role
             << "\nMatches: " << matches
             << "\nRuns: " << runs
             << "\nWickets: " << wickets << endl;
    }
    void DisplayPlayer() {
        displayInfo();
    }
    void saveToCSV() {
    ofstream file("players.csv", ios::app);
    if (!file) return;
    file << playerID << "," << name << "," << age << "," << role << "," 
         << matches << "," << runs << "," << wickets << endl;
    file.close();
}

    void loadFromCSV(int id) {
    ifstream file("players.csv");
    if (!file) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        int pid;
        getline(ss, temp, ','); pid = stoi(temp);
        if (pid != id) continue;
        playerID = pid;
        getline(ss, name, ',');
        getline(ss, temp, ','); age = stoi(temp);
        getline(ss, role, ',');
        getline(ss, temp, ','); matches = stoi(temp);
        getline(ss, temp, ','); runs = stoi(temp);
        getline(ss, temp); wickets = stoi(temp);
        break;
    }
    file.close();
}


};

class Coach : public Person {
private:
    string name;
    int age;
    int experience;
public:
    Coach(){ 
    name = ""; 
    age = 0; 
    experience = 0; 
}

    void AddCoach() {
        cout << "---Adding Coach Details---\n";
        cout << "Name: "; cin.ignore(); getline(cin, name);
        cout << "Age: "; cin >> age;
        cout << "Experience (years): "; cin >> experience;
    }

    void displayInfo() override {
        cout << "---Coach Info---\n";
        cout << "Name: " << name << "\nAge: " << age << "\nExperience: " << experience << " years\n";
    }
};

class Umpire : public Person {
private:
    string name;
    int age;
    int totalMatches;
public:
    Umpire() { name = ""; age = 0; totalMatches = 0; }

    void AddUmpire() {
        cout << "---Adding Umpire Details---\n";
        cout << "Name: "; cin.ignore(); getline(cin, name);
        cout << "Age: "; cin >> age;
        cout << "Total Matches Officiated: "; cin >> totalMatches;
    }

    void displayInfo() override {
        cout << "---Umpire Info---\n";
        cout << "Name: " << name << "\nAge: " << age
             << "\nMatches Officiated: " << totalMatches << endl;
    }
};

template <class T>
class List {
private:
    T* items[100];
    int count;

public:
    List() {
        count = 0;
    }

    void addItem(T* item) {
        if (count < 100)
            items[count++] = item;
    }

    void displayAll() {
        for (int i = 0; i < count; i++) {
            items[i]->displayInfo();
            cout << endl;
        }
    }

    T* findItemByID(int id) {
        for (int i = 0; i < count; i++) {
            if (items[i]->getID() == id)
                return items[i];
        }
        return nullptr;
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

    void saveToCSV() {
    ofstream file("teams.csv", ios::app);

    if (!file) {
        cout << "Error opening team file!\n";
        return;
    }

    file << TeamID << ","
         << teamname << ","
         << country << endl;

    file.close();

   
    for (int i = 0; i < 11; i++) {
        if (listofplayers[i].getPlayerID() != 0) {
            listofplayers[i].saveToCSV();
        }
    }
}

    void loadFromCSV() {
        
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
    void saveToCSV() {
    ofstream file("boards.csv", ios::app);
    if (!file) return;

    file << boardID << "," << boardName << "," << country << "," << teamCount << endl;
    file.close();

    for (int i = 0; i < teamCount; i++)
        listOfTeams[i].saveToCSV();
}

void loadFromCSV(int id) {
    ifstream file("boards.csv");
    if (!file) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        int bid;
        getline(ss, temp, ','); bid = stoi(temp);
        if (bid != id) continue;

        boardID = bid;
        getline(ss, boardName, ',');
        getline(ss, country, ',');
        getline(ss, temp); teamCount = stoi(temp);
        break;
    }
    file.close();
}

};

class Venue {
private:
    string venueName;
    string country;
    int capacity;
    string pitchCondition;

public:
    Venue() {
        venueName = "";
        country = "";
        capacity = 0;
        pitchCondition = "";
    }

    void addVenue() {
        cout << "\n---Enter Venue Details---\n";
        cout << "Venue Name: ";
        cin >> ws;
        getline(cin, venueName);
        cout << "Country: ";
        getline(cin, country);
        cout << "Capacity: ";
        cin >> capacity;
        cout << "Pitch Condition: ";
        cin >> ws;
        getline(cin, pitchCondition);
    }

    void displayVenueInfo() {
        cout << "\nVenue Name: " << venueName << endl;
        cout << "Country: " << country << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Pitch Condition: " << pitchCondition << endl;
    }

    void saveToCSV() {
    ofstream file("Venue_Data.csv", ios::app);
    if (!file) return;
    file << venueName << "," << country << "," << capacity << "," << pitchCondition << endl;
    file.close();
}

void loadFromCSV(string vname) {
    ifstream file("Venue_Data.csv");
    if (!file) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        getline(ss, temp, ',');
        if (temp != vname) continue;

        venueName = temp;
        getline(ss, country, ',');
        getline(ss, temp, ','); capacity = stoi(temp);
        getline(ss, pitchCondition);
        break;
    }
    file.close();
}

};

class Match {
public:
    int matchID;
    string Team1;
    string Team2;
    string date;
    string result;
    Venue venue;

    Match() {
        matchID = 0;
        Team1 = "";
        Team2 = "";
        date = "";
        result = "";
    }

    virtual void PlayMatch() {
        cout << "---Playing Match---\n";
        cout << "Enter Match ID: ";
        cin >> matchID;
        cout << "Enter Team 1 Name: ";
        cin >> ws;
        getline(cin, Team1);
        cout << "Enter Team 2 Name: ";
        getline(cin, Team2);
        venue.addVenue();
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
            result = "Match Draw";
        venue.saveToCSV();
    }

    void displayMatch() {
        cout << "\n---Match Details---\n";
        cout << "Match ID: " << matchID << endl;
        cout << "Team 1: " << Team1 << endl;
        cout << "Team 2: " << Team2 << endl;
        cout << "Date: " << date << endl;
        cout << "Result: " << result << endl;
        venue.displayVenueInfo();
    }

    void saveToCSV() {
    ofstream file("matches.csv", ios::app);

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

        file << matchID << ","
         << Team1 << ","
         << Team2 << ","
         << date << ","
         << result << endl;

        file.close();
    }
    
  void loadFromCSV() {
    ifstream file("matches.csv");

    if (!file) {
        cout << "File not found!\n";
        return;
    }

    string line;
    getline(file, line);

    if (line == "") {
        cout << "File is empty!\n";
        return;
    }

    string temp;
    stringstream ss(line);

    getline(ss, temp, ',');
    matchID = stoi(temp);

    getline(ss, Team1, ',');
    getline(ss, Team2, ',');
    getline(ss, date, ',');
    getline(ss, result);

    file.close();
}



};

class T20Match : public Match {
private:
    int overs;
public:
    T20Match() {
        overs = 20;
    }

    int CalculateScore(int runs, int wickets) {
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
        venue.addVenue();
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
        venue.saveToCSV();
        // also save match details to CSV
        saveToCSV();
    }
};



class Tournament {
private:
    int tournamentID;
    string tournamentName;
    Match matchesList[120];
    int matchCount;
    string winner;

public:
    Tournament() {
        tournamentID = 0;
        tournamentName = "";
        matchCount = 0;
        winner = "";
    }

    void AddMatch() {
        cout << "Enter number of matches to add: ";
        cin >> matchCount;

        for (int i = 0; i < matchCount; i++) {
            cout << "\nMatch " << (i + 1) << ":\n";
            matchesList[i].PlayMatch();
        }
    }

    void displayResults() {
        for (int i = 0; i < matchCount; i++) {
            matchesList[i].displayMatch();
        }
    }

    void saveToCSV() {
    ofstream file("tournament.csv", ios::app);
    if (!file) return;

    file << tournamentID << "," << tournamentName << "," << matchCount << "," << winner << endl;
    file.close();

    for (int i = 0; i < matchCount; i++)
        matchesList[i].saveToCSV();
}

void loadFromCSV(int id) {
    ifstream file("tournament.csv");
    if (!file) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        int tid;
        getline(ss, temp, ','); tid = stoi(temp);
        if (tid != id) continue;

        tournamentID = tid;
        getline(ss, tournamentName, ',');
        getline(ss, temp, ','); matchCount = stoi(temp);
        getline(ss, winner);
        break;
    }
    file.close();
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
        for (int i = 0; i < teamCount; i++) {
            cout << teamNames[i] << " : " << teamPoints[i] << " points\n";
        }
        for (int i = 0; i < playerCount; i++) {
            cout << playerNames[i] << " : " << playerPoints[i] << " points\n";
        }
    }
    bool operator>(RankingSystem &other) {
        if (teamCount == 0 || other.teamCount == 0) return false;
        return teamPoints[0] > other.teamPoints[0];
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
    }
    void loadFromCSV() {
        ifstream file("ICC_Data.csv");
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

int main() {
    Player p;
    p.AddPlayer();
    p.displayInfo();
    p.UpdateStats();
    p.displayInfo();

    Coach c;
    c.AddCoach();
    c.displayInfo();

    Umpire u;
    u.AddUmpire();
    u.displayInfo();

    List<Person> humans;
    humans.addItem(&p);
    humans.addItem(&c);
    humans.addItem(&u);
    cout << "\n---All Humans in List---\n";
    humans.displayAll();

    Team t;
    t.AddTeam();
    t.DisplayTeam();

    CricketBoard cb;
    cb.AddBoard();
    cb.addTeamToBoard(t);
    cb.DisplayBoard();

    T20Match t20;
    t20.PlayMatch();
    t20.displayMatch();

    RankingSystem rank;
    rank.updateRankings("Pakistan", "Babar Azam");
    rank.updateRankings("Pakistan", "Shaheen Afridi");
    rank.updateRankings("India", "Virat Kohli");
    rank.updateRankings("Australia", "Pat Cummins");
    rank.displayRankings();

    ICC icc;
    icc.registerBoard(cb);
    icc.organizeTournament();
    icc.addGlobalRanking();
    icc.saveToCSV();

    return 0;
}
