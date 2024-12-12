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

// FIXME: Edit number of points
double test_SkipList::total_grade = 0;
double test_SkipList::max_grade = 36;

TEST_F(test_SkipList, Test_init_node) {
  SkipList mylist;
  // expect top to be NULL
  ASSERT_FALSE(mylist.get_head());
  add_points_to_grade(1);
  node* root = mylist.init_node("42", "forty-two");
  // expect root itself to have a pointer (not NULL)
  ASSERT_TRUE(root);
  add_points_to_grade(1);
  ASSERT_EQ("forty-two", root->data);
  add_points_to_grade(1);
  // expect next pointers to be null
  for (unsigned int i = 0; i < root->next_ptrs.size(); ++i) {
    ASSERT_FALSE(root->next_ptrs.at(i)); 
  }
  add_points_to_grade(1);
}

node* build_five_node_list_helper(string zero, string one, string two, string three, string four) {
  // 1: HEAD -> almond -> banana -> tangerine -> NULL
  // 0: HEAD -> almond -> apple -> banana -> grape -> tangerine -> NULL
  node* top = new node;
  top->key = "HEAD";
  top->next_ptrs.resize(15, NULL);

  node* node0 = new node;
  node0->key = zero;
  node0->next_ptrs.resize(15, NULL);

  node* node1 = new node;
  node1->key = one;
  node1->next_ptrs.resize(15, NULL);

  node* node2 = new node;
  node2->key = two;
  node2->next_ptrs.resize(15, NULL);

  node* node3 = new node;
  node3->key = three;
  node3->next_ptrs.resize(15, NULL);

  node* node4 = new node;
  node4->key = four;
  node4->next_ptrs.resize(15, NULL);

  top->next_ptrs.at(1) = node0;
  top->next_ptrs.at(0) = node0;

  node0->next_ptrs.at(1) = node2; 
  node0->next_ptrs.at(0) = node1;
 
  node1->next_ptrs.at(0) = node2;

  node2->next_ptrs.at(1) = node4;
  node2->next_ptrs.at(0) = node3;

  node3->next_ptrs.at(0) = node4;

  return top;
}

TEST_F(test_SkipList, Test_report) {
  SkipList mylist;

  ASSERT_EQ("", mylist.report());
  add_points_to_grade(1);

  // create a five node list
  node* top_ptr = build_five_node_list_helper("almond", "apple", "banana", "grape", "tangerine");
  // set current list level to 1
  mylist.set_level(1);
  // replace mylist top pointer with this new top
  mylist.set_head(top_ptr);

  // check that report() matches report
  string report = "1: HEAD -> almond -> banana -> tangerine -> NULL\n0: HEAD -> almond -> apple -> banana -> grape -> tangerine -> NULL\n";
  ASSERT_EQ(report, mylist.report());
  add_points_to_grade(1);
}

TEST_F(test_SkipList, Test_insert) {
  SkipList mylist;

  // create a five node list
  node* top_ptr = build_five_node_list_helper("almond", "apple", "banana", "grape", "tangerine");
  // set current list level to 1
  mylist.set_level(1);
  // replace mylist top pointer with this new top
  mylist.set_head(top_ptr);

  // insert at beginning
  mylist.insert("acai", "red");
  node* search_node = top_ptr->next_ptrs.at(0);
  ASSERT_EQ("acai", search_node->key);
  add_points_to_grade(1);
  // insert in middle
  mylist.insert("dragonfruit", "green");
  search_node = top_ptr->next_ptrs.at(0)->next_ptrs.at(0)->next_ptrs.at(0)->next_ptrs.at(0)->next_ptrs.at(0);
  ASSERT_EQ("dragonfruit", search_node->key);
  add_points_to_grade(1);
  // insert at end
  mylist.insert("watermelon", "green");
  search_node = top_ptr->next_ptrs.at(0)->next_ptrs.at(0)->next_ptrs.at(0)->next_ptrs.at(0)->next_ptrs.at(0)->next_ptrs.at(0)->next_ptrs.at(0)->next_ptrs.at(0);
  ASSERT_EQ("watermelon", search_node->key);
  add_points_to_grade(1);
}


