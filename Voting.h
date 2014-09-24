#ifndef Voting_h
#define Voting_h

// --------
// includes
// --------

#include <iostream> 
#include <string>

struct Ballot{
	/* data */
	bool loser = false;
	int count;
};

void voting_read_args (std::istream&, int&);

#endif