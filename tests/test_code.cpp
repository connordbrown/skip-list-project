// Checkout TEST_F functions below to learn what is being tested.
#include "../code/SkipList.h"
#include <gtest/gtest.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class test_SkipList : public ::testing::Test {
protected:
  // This function runs only once before any TEST_F function
  static void SetUpTestCase() {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)0;
      outgrade.close();
    }
  }

  // This function runs after all TEST_F functions have been executed
  static void TearDownTestCase() {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)std::ceil(100 * total_grade / max_grade);
      outgrade.close();
      std::cout << "Total Grade is : "
                << (int)std::ceil(100 * total_grade / max_grade) << std::endl;
    }
  }

  void add_points_to_grade(double points) {
    if (!::testing::Test::HasFailure()) {
      total_grade += points;
    }
  }

  // this function runs before every TEST_F function
  void SetUp() override {}

  // this function runs after every TEST_F function
  void TearDown() override {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)std::ceil(100 * total_grade / max_grade);
      outgrade.close();
    }
  }

  static double total_grade;
  static double max_grade;
};

double test_SkipList::total_grade = 0;
double test_SkipList::max_grade = 38;

TEST_F(test_SkipList, TestInitialization) {
  SkipList mylist;
  ASSERT_FALSE(mylist.get_head()); // expect top to be NULL
  add_points_to_grade(1);
  node* root = mylist.init_node("42", "forty-two");
  ASSERT_TRUE(root); // expect root itself to have a pointer (not NULL)
  add_points_to_grade(1);
  ASSERT_EQ("forty-two", root->data);
  add_points_to_grade(1);
  for (unsigned int i = 0; i < root->next_ptrs.size(); ++i) {
    ASSERT_FALSE(root->next_ptrs.at(i)); 
  }
  // expect next pointer to be null
  add_points_to_grade(1);
}