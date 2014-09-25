#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <utility>  // make_pair, pair

#include "gtest/gtest.h"

#include "Voting.h"

// g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Voting.c++ TestVoting.c++ -o TestVoting -lgtest -lgtest_main -lpthread

// ---
// read_args
// ---
TEST(Voting, read_args_1){
  std::istringstream r("1\n\n2\nChad Custodio\nAndy Tran\n1 2\n2 1\n2 1");
  int v;
  voting_read_args(r, v);
  ASSERT_EQ(1, v);
}

TEST(Voting, read_args_2){
  std::istringstream r("2\n\n2\nChad\nAndy\n1 2\n2 1\n2 1\n\n2\nChad\nAndy\n2 1\n1 2\n1 2");
  int v;
  voting_read_args(r, v);
  ASSERT_EQ(2, v);
}

TEST(Voting, read_args_3){
  std::istringstream r("1\n\n3\nChad\nAndy\nGabe\n1 2 3\n2 1 3\n2 3 1");
  int v;
  voting_read_args(r, v);
  ASSERT_EQ(1, v);
}

TEST(Voting, read_cand_1){
  std::istringstream r("3\nChad\nAndy\nGlenn");
  int v;
  Ballot b[3];
  voting_read_cand(r, v, b);
  ASSERT_EQ(3, v);
}

TEST(Voting, read_cand_2){
  std::istringstream r("20\nShyvana\nLee Sin\nJayce\nGnar\nRengar\nJarvan\nMaokai\nNidalee\nLucian\nJinx\nLina\nJuggy\nRikimaru\nShadow Fiend\nInvoker\nLion\nSniper\nPudge\nDisruptor\nChad");
  int v;
  Ballot b[20];
  voting_read_cand(r, v, b);
  ASSERT_EQ(20, v);
}

TEST(Voting, read_cand_3){
  std::istringstream r("2\nChad\nAndy");
  int v;
  Ballot b[2];
  voting_read_cand(r, v, b);
  ASSERT_EQ(2, v);
}

TEST(Voting, read_ballot_1){
  std::istringstream r("1 2 3\n2 1 3\n2 3 1");
  Ballot b[3];
  bool v = voting_read_ballot(r, b);
  ASSERT_EQ(1, v);
}

TEST(Voting, read_ballot_2){
  std::istringstream r("");
  Ballot b[1];
  bool v = voting_read_ballot(r, b);
  ASSERT_EQ(0, v);
}

TEST(Voting, read_ballot_3){
  std::istringstream r("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20\n");
  Ballot b[20];
  bool v = voting_read_ballot(r, b);
  ASSERT_EQ(1, v);
}

TEST(Voting, eval_1){
  std::istringstream r("1\n\n2\nChad\nAndy");
  int v;
  int j;
  int votes = 0;
  Ballot b[2];
  voting_read_args(r, v);
  voting_read_cand(r, j, b);
  while(voting_read_ballot(r, b)){
    ++votes;
  }
  std::string s = voting_eval(votes, j, b);
  ASSERT_EQ("Chad\nAndy", s);
}

TEST(Voting, eval_2){
  std::istringstream r("1\n\n2\nChad\nAndy\n1 2\n2 1");
  int v;
  int j;
  int votes = 0;
  Ballot b[2];
  voting_read_args(r, v);
  voting_read_cand(r, j, b);
  while(voting_read_ballot(r, b)){
    ++votes;
  }
  std::string s = voting_eval(votes, j, b);
  ASSERT_EQ("Chad\nAndy", s);
}

TEST(Voting, eval_3){
  std::istringstream r("1\n\n3\nChad\nAndy\nGlenn\n1 2 3\n2 1 3\n1 2 3\n3 1 2");
  int v;
  int j;
  int votes = 0;
  Ballot b[3];
  voting_read_args(r, v);
  voting_read_cand(r, j, b);
  while(voting_read_ballot(r, b)){
    ++votes;
  }
  std::string s = voting_eval(votes, j, b);
  ASSERT_EQ("Chad", s);
}

TEST(Voting, solve_1){
  std::istringstream r("1\n\n2\nChad\nAndy");
  std::ostringstream w;
  voting_solve(r, w);
  ASSERT_EQ("Chad\nAndy\n", w.str());
}

TEST(Voting, solve_2){
  std::istringstream r("2\n\n2\nChad\nAndy\n\n2\nChad\nAndy\n1 2\n2 1");
  std::ostringstream w;
  voting_solve(r, w);
  ASSERT_EQ("Chad\nAndy\n\nChad\nAndy\n", w.str());
}

TEST(Voting, solve_3){
  std::istringstream r("1\n\n3\nChad\nAndy\nGlenn\n1 2 3\n2 1 3\n1 2 3\n3 1 2");
  std::ostringstream w;
  voting_solve(r, w);
  ASSERT_EQ("Chad\n", w.str());
}