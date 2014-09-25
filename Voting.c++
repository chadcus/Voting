#include <cassert>  
#include <iostream> 
#include <sstream>
#include <string>

#include "Voting.h"

void voting_read_args(std::istream& r, int& i){
  std::string s;

  getline(r, s);
  std::stringstream ss(s);
  ss >> i;
  getline(r, s);
  assert(i > 0); //Number of cases have to be greater than 0
  // std::cout << i << std::endl;
}

void voting_read_cand (std::istream& r, int& j, Ballot b[]){
  int i = 0;
  std::string s;

  getline(r, s);
  std::stringstream ss(s);
  ss >> j;

  while(i < j){
    getline(r, s);
    b[i].s = s;
    ++i;
  }
  //boundary cases for number of candidates
  assert(j > 0);
  assert(j < 21);
}

bool voting_read_ballot(std::istream& r, Ballot b[]){
  int i;
  std::string s;

  getline(r, s);
  std::stringstream ss(s);

  if(s == ""){
    return false;
  }
  else{
  	// std::cout << s << std::endl;
    ss >> i;
    getline (ss, s);
	b[i-1].v.push_back(s);
	++b[i-1].count;
    return true;
  }
}

std::string voting_eval(int& totalVotes, int& cand, Ballot b[]){
	std::string s = "";
  int min = 1001;
  int max = 0;
  int winCount = 0;

  //no votes
  if(totalVotes == 0){
    for(int i = 0; i < cand; ++i){
      if(winCount > 0){
        s += "\n" + b[i].s;
      }
      else{
        s += b[i].s;
      }
      ++winCount;
    }
    return s;
  }

  while(1){
    for(int i = 0; i < cand; ++i){
      if(b[i].count > (totalVotes / 2)){
        return b[i].s;
      }
    }
  }
	return s;
}