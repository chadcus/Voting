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
}