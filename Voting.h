#ifndef Voting_h
#define Voting_h

// --------
// includes
// --------

#include <iostream> 
#include <string>
#include <vector>

struct Ballot{
	/* data */
	std::string s = "";
	std::vector<std::string> v;
	int count = 0;
};

void voting_read_args (std::istream&, int&);

void voting_read_cand (std::istream&, int&, Ballot b[]);

bool voting_read_ballot (std::istream&, Ballot b[]);

std::string voting_eval(int&, int&, Ballot b[]);

#endif