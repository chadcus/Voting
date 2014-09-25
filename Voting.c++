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
  std::string ball = "";
  int min = 1001;
  int max = 0;
  int winCount = 0;
  int token = 0;

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
      else{
        if(b[i].count < min && b[i].count > 0){
          min = b[i].count;
        }
        if(b[i].count > max){
          max = b[i].count;
        }
      }
    }

    if(max == min){
      for(int i = 0; i < cand; ++i){
        if(b[i].count > 0){
          if(winCount > 0){
           s += "\n" + b[i].s;
          }
          else{
            s += b[i].s;
          }
          ++winCount;
        }
      }
      return s;
    }

    // redo votes if no winner
    for(int i = 0; i < cand; ++i){
      if(min == b[i].count){
        for(int k = 0; k < b[i].count; ++k){
          ball = b[i].v[k];
          std::stringstream ss(ball);
          ss >> token;
          while(b[token - 1].count <= min){
            ss >> token;
          }
          getline(ss, ball);
          b[token - 1].v.push_back(ball);
          ++b[token - 1].count;
        }
        b[i].v.clear();
        b[i].count = 0;
      }
    }
    min = 1001;
  }
}

void voting_solve(std::istream& r, std::ostream& w){
  int i = 0;
  
  voting_read_args(r, i);
    
  while(i > 0){
    int j = 0;
    Ballot b[20];
    voting_read_cand(r, j, b);

    int totalVotes = 0;
    while(voting_read_ballot(r, b)){
      ++totalVotes;
    }
    std::string s = voting_eval(totalVotes, j, b);
    if(i == 1){
      w << s << std::endl;
    }
    else{
      w << s << std::endl << std::endl;
    }
    --i;
  }
}