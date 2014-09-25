#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> 

#include "Voting.h"

// ----
// main
// ----

int main () {
    using namespace std;
    int i = 0;
    int j = 0;
    Ballot b[20];
    voting_read_args(std::cin, i);
    voting_read_cand(std::cin, j, b);
    int k = 0;
    while (k < j){
    	++k;
    }
    int totalVotes = 0;
    while(voting_read_ballot(std::cin, b)){
      ++totalVotes;
    }
    std::string s = voting_eval(totalVotes, j, b);
    std::cout << s << std::endl;
    return 0;
}