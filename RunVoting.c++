#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream>
#include <random>
#include <algorithm>
#include <iterator> 

#include "Voting.h"

// ----
// main
// ----

int main () {
  using namespace std;
  int i = 0;
  
  voting_read_args(std::cin, i);
    
  while(i > 0){
    int j = 0;
    Ballot b[20];
    voting_read_cand(std::cin, j, b);

    int totalVotes = 0;
    while(voting_read_ballot(std::cin, b)){
      ++totalVotes;
    }
    std::string s = voting_eval(totalVotes, j, b);
    if(i == 1){
      std::cout << s << std::endl;
    }
    else{
      std::cout << s << std::endl << std::endl;
    }
    --i;
  }
  return 0;
}