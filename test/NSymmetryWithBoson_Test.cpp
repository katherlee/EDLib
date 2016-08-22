//
// Created by iskakoff on 22/08/16.
//

#include "gtest/gtest.h"

#include "NSymmetryWithBoson.h"

TEST(NSymmetryWithBosonTest, Initialization) {
  EDParams p;
  NSymmetryWithBoson sym(p);
  while(sym.next_sector()) {
    sym.init();
    int i = 0;
    while (sym.next_state()) {
      ASSERT_EQ(i, sym.index(sym.state()));
      ++i;
    }
  }
}