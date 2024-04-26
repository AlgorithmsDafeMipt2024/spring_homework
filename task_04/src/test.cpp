#include "heap.hpp"
#include <gtest/gtest.h>

// Простое тестирование
TEST(heap, Simple) {
  ASSERT_EQ(Find_Minimum(std::vector<int>{1, 3, 5, 6, 2, 4}), 1);
  ASSERT_EQ(Find_Minimum(std::vector<int>{11, 37, 55, 34, -6, 0, 4}), -6);
  ASSERT_EQ(Heap_Ready(std::vector<int>{4, 1, 3, 2, 5}),
            (std::vector<int>{1, 2, 3, 4, 5}));
  ASSERT_EQ(Heap_Ready(std::vector<int>{3, 1, 5, 6, 2, 4}),
            (std::vector<int>{1, 2, 4, 6, 3, 5}));
  Heap heap;
  heap.Build_heap(std::vector<int>{1, 3, 5, 7, 9, 12, 324, 5, 47, 457, 9467, -4,
                                   758, -579, -4, 0});
  ASSERT_EQ(heap.Find_Min(), -579);
  heap.Insert(23);
  heap.Insert(-1000);
  ASSERT_EQ(heap.Extract_Min(), -1000);
  ASSERT_EQ(heap.Find_Min(), -579);
}

// Тестирование поведения кучи при вставке элементов
TEST(HeapTest, Insert) {
  Heap heap;
  heap.Insert(5);
  ASSERT_EQ(heap.Find_Min(), 5);
  heap.Insert(3);
  ASSERT_EQ(heap.Find_Min(), 3);
  heap.Insert(8);
  ASSERT_EQ(heap.Find_Min(), 3);
}

// Тестирование поведения кучи при удалении элементов
TEST(HeapTest, ExtractMin) {
  Heap heap;
  heap.Insert(5);
  heap.Insert(3);
  heap.Insert(8);
  ASSERT_EQ(heap.Extract_Min(), 3);
  ASSERT_EQ(heap.Find_Min(), 5);
  ASSERT_EQ(heap.Extract_Min(), 5);
  ASSERT_EQ(heap.Find_Min(), 8);
}

// Тестирование поведения кучи с отрицательными числами
TEST(HeapTest, NegativeNumbers) {
  Heap heap;
  heap.Insert(-5);
  heap.Insert(-3);
  heap.Insert(-8);
  ASSERT_EQ(heap.Find_Min(), -8);
  ASSERT_EQ(heap.Extract_Min(), -8);
  ASSERT_EQ(heap.Find_Min(), -5);
}

// Тестирование поведения кучи с большим количеством элементов
TEST(HeapTest, LargeHeap) {
  Heap heap;
  for (int i = 0; i < 1000; ++i) {
    heap.Insert(i);
  }
  ASSERT_EQ(heap.Find_Min(), 0);
  for (int i = 0; i < 1000; ++i) {
    ASSERT_EQ(heap.Extract_Min(), i);
  }
}

// Тестирование поведения кучи при построении из вектора
TEST(HeapTest, BuildHeap) {
  Heap heap;
  heap.Build_heap(std::vector<int>{5, 3, 8, 1, 2, 9});
  ASSERT_EQ(heap.Find_Min(), 1);
  ASSERT_EQ(heap.Extract_Min(), 1);
  ASSERT_EQ(heap.Find_Min(), 2);
}
