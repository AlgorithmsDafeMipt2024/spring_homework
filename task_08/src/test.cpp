
// #include <gtest/gtest.h>

// #include "hash_table.hpp"

// TEST(hash_table, Simple) {
//   HashSet set;
//   set.Insert(14);
//   set.Insert(124);
//   set.Insert(1);
//   set.Insert(-23);
//   set.Insert(54);
//   set.Insert(44);
//   set.Insert(0);
//   set.Insert(674);

//   ASSERT_EQ(set.Contains(124), true);
//   ASSERT_EQ(set.Contains(44), true);
//   ASSERT_EQ(set.Contains(54), true);
//   ASSERT_EQ(set.Contains(0), true);
//   ASSERT_EQ(set.Contains(-23), true);
//   ASSERT_EQ(set.Contains(1), true);
//   ASSERT_EQ(set.Contains(1), true);

//   ASSERT_EQ(set.Contains(14), true);
//   set.Remove(14);
//   ASSERT_EQ(set.Contains(14), false);
//   set.Remove(14);
//   ASSERT_EQ(set.Contains(14), false);

//   set.Clear();
//   ASSERT_EQ(set.Contains(0), false);

//   for (int i = 0; i < 100000; ++i) set.Insert(i);
//   ASSERT_EQ(set.Contains(18353), true);
//   set.Remove(18353);
//   ASSERT_EQ(set.Contains(18353), false);
//   set.Insert(-99999);
//   set.Contains(-99999);
// }
