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