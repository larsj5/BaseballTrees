/**
 * Lars Jensen
 * CS 124
 * Section C
 */

#ifndef PROJECT1_TEAM_H
#define PROJECT1_TEAM_H

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdio.h> //this was obtained from https://www.cplusplus.com/reference/cstdio/printf/

using std::string;
using std::vector;
using std::ifstream;
using std::ostream;
using std::setw;
using std::left;
using std::right;

/**
 * Class represents statistics from all MLB baseball teams and all of
 * their seasons from 1962 to 2012.
 *
 * Fields:
 * team: string: The abbreviation of the team that the rest of the data in the row is for.
 * league: string: The league that the team plays in, either the National League (NL) or the
 *                  American League (AL). This is important as the two leagues have differing
 *                  rules that can affect a team’s statistics depending on the league they play in.
 * year: integer: The season that the data is from.
 * runsScored: integer: The number of runs scored by a team over the entire season.
 * runsAllowed: integer: The number of runs allowed by a team over the entire season.
 * wins: integer: Number of games a team won that season.
 * obp (On-Base Percentage): float: The average rate a team gets on base per at-bat.
 * slg (Slugging Percentage): float: A stat to signify the number of bases each hit results in, and
                                    the frequency that they occur. (Similar to batting average but
                                    a double is worth 2x, triple 3x, and home run 4x).
 * avg (Batting Average): float: The average rate at which a team will get a hit per at-bat.
 * playoffs: integer: 1 if the team made the playoffs that year, 0 if they did not.
 * seasonRank: integer: If the team made the playoffs, this signifies what their season rank was.
 * playoffRank: integer: In what place they finished in the playoffs, so 1 would mean that they
                         won the world series.
 * games: integer: The number of games a team played in that season.
 * oOBP (Opponent On-Base Percentage): float: The rate at which their opponents got on base per at bat.
 * oSLG (Opponent Slugging Percentage): float: The rate at which their opponents got hits, and how many
                                               bases each one resulted in.
 */

class Team {
private:
    //fields
    string team, league, teamID;
    int year, runsScored, runsAllowed, wins,
        playoffs, seasonRank, playoffRank, games;
    double obp, slg, avg, oOBP, oSLG;

public:
    //constructors
    Team(){
        team = "Team";
        league = "MLB";
        teamID = "TEAM0";

        year = runsScored = runsAllowed = wins = obp = slg = avg =
                playoffs = seasonRank = playoffRank = games = oOBP = oSLG = 0;

    }

    Team(string team, string league, int year, int runsScored, int runsAllowed, int wins,
         double obp, double slg, double avg, int playoffs, int seasonRank, int playoffRank,
         int games, double oOBP, double oSLG){

        this->team = team;
        this->league = league;
        this->year = year;
        setTeamID(team, year);
        this->runsScored = runsScored;
        this->runsAllowed = runsAllowed;
        this->wins = wins;
        this->obp = obp;
        this->slg = slg;
        this->avg = avg;
        this->playoffs = playoffs;
        this->seasonRank = seasonRank;
        this->playoffRank = playoffRank;
        this->games = games;
        this->oOBP = oOBP;
        this->oSLG = oSLG;
    }

    //getters
    string getTeam() const {
        return team;
    }
    string getLeague() const{
        return league;
    }
    string getTeamID() const{
        return teamID;
    }
    int getYear() const{
        return year;
    }
    int getRunsScored() const{
        return runsScored;
    }
    int getRunsAllowed() const{
        return runsAllowed;
    }
    int getWins() const {
        return wins;
    }
    double getOBP() const{
        return obp;
    }
    double getSLG() const{
        return slg;
    }
    double getAVG() const{
        return avg;
    }
    int getPlayoffs() const {
        return playoffs;
    }
    int getSeasonRank() const{
        return seasonRank;
    }
    int getPlayoffRank() const{
        return playoffRank;
    }
    int getGames() const{
        return games;
    }
    double getOOBP() const{
        return oOBP;
    }
    double getOSLG() const{
        return oSLG;
    }

    //setters
    void setTeam(string team){
        this->team = team;
    }
    void setLeague(string league){
        this->league = league;
    }
    void setTeamID(string team, int year) {
        if (team.front() == 13){
            team = team.erase(0, 1);
        }
        teamID = team + std::to_string(year);
    }
    void setYear(int year){
        this->year = year;
    }
    void setRunsScored(int runsScored){
        this->runsScored = runsScored;
    }
    void setRunsAllowed(int runsAllowed){
        this->runsAllowed = runsAllowed;
    }
    void setWins(int wins){
        this->wins = wins;
    }
    void setOBP(double obp){
        this->obp = obp;
    }
    void setSLG(double slg){
        this->slg = slg;
    }
    void setAVG(double avg){
        this->avg = avg;
    }
    void setPlayoffs(int playoffs){
        this->playoffs = playoffs;
    }
    void setSeasonRank(int seasonRank){
        this->seasonRank = seasonRank;
    }
    void setPlayoffRank(int playoffRank){
        this->playoffRank = playoffRank;
    }
    void setGames(int games){
        this->games = games;
    }
    void setOOBP(double oOBP){
        this->oOBP = oOBP;
    }
    void setOSLG(double oSLG){
        this->oSLG = oSLG;
    }

    //Overloaded operator that prints the data neatly
    friend ostream& operator << (ostream& outs, Team baseballTeam){
        outs << left << setw(5) << baseballTeam.team;
        outs << setw(4) << baseballTeam.league;
        outs << right << setw(5) << baseballTeam.year;
        outs << setw(5) << baseballTeam.runsScored;
        outs << setw(5) << baseballTeam.runsAllowed;
        outs << setw(4) << baseballTeam.wins;
        outs << setw(7) << baseballTeam.obp;
        outs << setw(7) << baseballTeam.slg;
        outs << setw(7) << baseballTeam.avg;
        outs << setw(3) << baseballTeam.playoffs;
        outs << setw(3) << baseballTeam.seasonRank;
        outs << setw(3) << baseballTeam.playoffRank;
        outs << setw(5) << baseballTeam.games;
        outs << setw(7) << baseballTeam.oOBP;
        outs << setw(7) << baseballTeam.oSLG;
        outs << setw(9) << baseballTeam.teamID;
        return outs;
    }

    /**
     * overload ==, >, <, >=, <= operators for object comparison
     */
    friend bool operator == (const Team &lhs, const Team &rhs){
        return (lhs.getTeamID() == rhs.getTeamID());
    }
    friend bool operator < (const Team &lhs, const Team &rhs){
        return (lhs.getTeamID() < rhs.getTeamID());
    }
    friend bool operator > (const Team &lhs, const Team &rhs){
        return (lhs.getTeamID() > rhs.getTeamID());
    }
    friend bool operator <= (const Team &lhs, const Team &rhs){
        return (lhs.getTeamID() <= rhs.getTeamID());
    }
    friend bool operator >= (const Team &lhs, const Team &rhs){
        return (lhs.getTeamID() >= rhs.getTeamID());
    }
    friend bool operator != (const Team &lhs, const Team &rhs){
        return (lhs.getTeamID() != rhs.getTeamID());
    }
};
/**
 * This function reads data from a CSV file into a vector
 * @param filename is name of file
 * @param baseballTeams is the vector of baseball teams
 * @return true if successfully read in from file, false if not
 */
bool getDataFromFile(string filename, vector<Team> &baseballTeams ){

    //open file
    ifstream fIn;
    fIn.open(filename);

    //make sure file isn't empty
    if (!fIn){
        return false;
    }

    //get rid of headers
    string headers;
    getline(fIn, headers, '\r');

    //declare variables to read in
    string team, league, line;
    int year, runsScored, runsAllowed, wins,
            playoffs, seasonRank, playoffRank, games;
    double obp, slg, avg, oOBP, oSLG;
    char comma;

    //loop through data and read into vector
    while (fIn && fIn.peek() != EOF) {
        //read in team
        getline(fIn, team, ',');

        //read in league
        getline(fIn, league, ',');

        //read in Year
        fIn >> year;
        fIn >> comma;

        //read in runs scored
        fIn >> runsScored;
        fIn >> comma;

        //read in runs allowed
        fIn >> runsAllowed;
        fIn >> comma;

        //read in wins
        fIn >> wins;
        fIn >> comma;

        //read in on base percentage
        fIn >> obp;
        fIn >> comma;

        //read in slugging
        fIn >> slg;
        fIn >> comma;

        //read in batting average
        fIn >> avg;
        fIn >> comma;

        //read in playoffs (if they made it a 1, if they didn't a 0)
        fIn >> playoffs;
        fIn >> comma;

        //read in season rank
        fIn >> seasonRank;
        //if there is no value (not a playoff team)
        if (!fIn) {
            seasonRank = 0;
            fIn.clear();
        }
        fIn >> comma;

        //read in playoff rank (1 is won world series)
        fIn >> playoffRank;
        //if there is no value (not a playoff team)
        if (!fIn) {
            playoffRank = 0;
            fIn.clear();
        }
        fIn >> comma;

        //read in games played
        fIn >> games;
        fIn >> comma;

        //read in opponent on base percentage
        fIn >> oOBP;
        //if there is no value (wasn't tracked before 1999)
        if (!fIn) {
            oOBP = 0;
            fIn.clear();
        }
        fIn >> comma;

        //read in opponent slugging
        //check and see if it's just a carriage return, and if so
        //just skip over as there is no value for oSLG
        if (fIn.peek() == 13){
            oSLG = 0;
        }
        else{
            fIn >> oSLG;
        }


        //create a baseballTeam object
        baseballTeams.push_back(Team(team, league, year, runsScored, runsAllowed, wins, obp, slg,
                                avg, playoffs, seasonRank, playoffRank, games, oOBP, oSLG));
    }
    fIn.close();
    return true;
}
/**
 * This function loops through all teams in the vector and finds the
 * teams with the best and worst winning percentages in the data set
 * and then prints the findings
 * @param baseballTeams is the vector of teams
 */
void calculateWinPercentages(vector<Team> &baseballTeams)
{
    //create fields
    string bestTeam, worstTeam;
    int wins, games, bestTeamYear, worstTeamYear;
    double winPercentage;

    //create min/max winning percentage variables and initialize to
    //highest and lowest possible values
    double highWinPercentage = 0;
    double lowWinPercentage = 1.000;

    //loop through all teams
    for (int i = 0; i < baseballTeams.size(); ++i){
        wins = baseballTeams[i].getWins();
        games = baseballTeams[i].getGames();
        winPercentage = (float)wins/games;

        //check if this team had the highest winning percentage
        if (winPercentage > highWinPercentage){
            highWinPercentage = winPercentage;
            bestTeam = baseballTeams[i].getTeam();
            bestTeamYear = baseballTeams[i].getYear();
        }
        //check if this team had the lowest winning percentage
        if (winPercentage < lowWinPercentage){
            lowWinPercentage = winPercentage;
            worstTeam = baseballTeams[i].getTeam();
            worstTeamYear = baseballTeams[i].getYear();
        }
    }

    //print string highest and lowest win totals and their team/year
    //how I learned to use printf in c++ was obtained from:
    //https://www.cplusplus.com/reference/cstdio/printf/
    printf("\n%s in %d had the highest winning percentage of %.3f\n",
           bestTeam.c_str(), bestTeamYear, highWinPercentage);
    printf("%s in %d had the lowest winning percentage of %.3f\n",
           worstTeam.c_str(), worstTeamYear, lowWinPercentage);
}

/**
 * method that tests getters and setters
 * uses assertions to test if they work correctly
 */
 void teamTest(){
     Team testObject = Team();
     //Test getters and setters
     testObject.setTeam("BOS");
     assert (testObject.getTeam() == "BOS");
     testObject.setLeague("AL");
     assert (testObject.getLeague() == "AL");
     testObject.setYear(2020);
     assert (testObject.getYear() == 2020);
     testObject.setRunsScored(1);
     assert (testObject.getRunsScored() == 1);
     testObject.setRunsAllowed(1);
     assert (testObject.getRunsAllowed() == 1);
    testObject.setWins(1);
    assert (testObject.getWins() == 1);
    testObject.setOBP(.1);
    assert (testObject.getOBP() == .1);
    testObject.setSLG(.1);
    assert (testObject.getSLG() == .1);
    testObject.setAVG(.1);
    assert (testObject.getAVG() == .1);
    testObject.setPlayoffs(1);
    assert (testObject.getPlayoffs() == 1);
    testObject.setSeasonRank(1);
    assert (testObject.getSeasonRank() == 1);
    testObject.setPlayoffRank(1);
    assert (testObject.getPlayoffRank() == 1);
    testObject.setGames(1);
    assert (testObject.getGames() == 1);
    testObject.setOOBP(.1);
    assert (testObject.getOOBP() == .1);
    testObject.setOSLG(.1);
    assert (testObject.getOSLG() == .1);
 }

#endif //PROJECT1_TEAM_H
