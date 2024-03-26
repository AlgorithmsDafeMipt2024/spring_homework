
// #include <gtest/gtest.h>

// #include "bs_tree.hpp"

// TEST(bs_tree, Simple) {
//   BSTree<int> Tree;

//   Tree.Insert(177);
//   Tree.Insert(12);
//   Tree.Insert(7);
//   Tree.Insert(11);
//   Tree.Insert(4);
//   Tree.Insert(-9);
//   ASSERT_EQ(Tree.Contains(13), false);
//   ASSERT_EQ(Tree.Contains(11), true);
//   ASSERT_EQ(Tree.Contains(-9), true);
//   Tree.Remove(-9);
//   ASSERT_EQ(Tree.Contains(-9), false);

//   Tree.Remove(12);
//   Tree.Remove(11);
//   Tree.Insert(999);
//   ASSERT_EQ(Tree.Contains(999), true);
//   ASSERT_EQ(Tree.Contains(4), true);
//   ASSERT_EQ(Tree.Contains(7), true);
//   ASSERT_EQ(Tree.Contains(0), false);
// }
