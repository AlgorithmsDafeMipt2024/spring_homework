
#include <gtest/gtest.h>

#include "sum_of_two.hpp"

TEST(solve, Test1) {
  ASSERT_EQ(Solve(std::vector<long long>{6, 12, 18, 24, 30}, 42),
            (std::pair<long long, long long>{12, 30}));
}

TEST(solve, Test2) {
  ASSERT_EQ(
      Solve(std::vector<long long>{123088, 140659, 431707, 494583, 516094,
                                   678578, 764994, 852899, 902062, 948797},
            600),
      (std::pair<long long, long long>{-1, -1}));
}

TEST(solve, Test3) {
  ASSERT_EQ(
      Solve(
          std::vector<long long>{
              3,   6,   22,  28,  41,  42,  55,  62,  65,  85,  99,  103, 105,
              122, 132, 138, 139, 144, 145, 166, 171, 173, 179, 200, 221, 251,
              253, 258, 282, 295, 295, 310, 321, 324, 330, 331, 339, 364, 377,
              377, 388, 397, 429, 435, 470, 479, 495, 499, 501, 505, 505, 509,
              542, 578, 582, 586, 605, 617, 630, 633, 647, 663, 672, 675, 684,
              688, 692, 701, 704, 707, 716, 720, 727, 736, 751, 753, 760, 768,
              777, 820, 822, 834, 836, 843, 846, 847, 862, 865, 876, 888, 893,
              895, 904, 920, 925, 957, 959, 961, 989, 989},
          91),
      (std::pair<long long, long long>{6, 85}));
}

TEST(solve, Test4) {
  ASSERT_EQ(Solve(std::vector<long long>{87,  119, 150, 187, 258, 292, 315, 398,
                                         437, 468, 483, 488, 507, 518, 544, 562,
                                         569, 579, 593, 635, 669, 702, 719, 774,
                                         845, 904, 913, 946, 969, 992},
                  1106),
            (pair<long long, long long>{437, 669}));
}

TEST(solve, Test5) {
  ASSERT_EQ(Solve(std::vector<long long>{1}, 5),
            (pair<long long, long long>{-1, -1}));
}

TEST(solve, Test6) {
  ASSERT_EQ(Solve(std::vector<long long>{1, 3, 5, 7, 9}, 52),
           (pair<long long, long long>{-1, -1}));
}

TEST(solve, Test7) {
  ASSERT_EQ(Solve(std::vector<long long>{14, 22, 46, 74, 75}, 96),
            (pair<long long, long long>{22, 74}));
}

TEST(solve, Test8) {
  ASSERT_EQ(
      Solve(std::vector<long long>{402,  1461, 1575, 1944, 2018, 2454, 2753,
                                   3156, 3494, 3792, 4423, 4920, 5066, 6539,
                                   8827, 8885, 9234, 9845, 9918, 9974},
            5674),
      (pair<long long, long long>{-1, -1}));
}

TEST(solve, Test9) {
  ASSERT_EQ(Solve(std::vector<long long>{}, 10),
            (pair<long long, long long>{-1, -1}));
}