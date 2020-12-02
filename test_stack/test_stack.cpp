#include "../stack/stack.h"
#include "..\stack\Calculator.h"
#include "gtest.h"

TEST(stack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(stack<int> bf(3));
}

TEST(stack, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(stack<int> bf(-3));
}

TEST(stack, new_stack_is_empty)
{
	stack<int> s(2);
	EXPECT_EQ(s.getSize(), 0);
}

TEST(stack, can_look_top_element)
{
	stack<int> s(2);
	s.push(1);
	EXPECT_EQ(1, s.top());
}

TEST(stack, cant_look_top_element_in_empty_stack)
{
	stack<int> s(2);
	ASSERT_ANY_THROW(s.top());
}


TEST(stack, can_add_element_in_non_empty_stack)
{
	stack<int> s(2);
	s.push(1);
	s.push(2);
	EXPECT_EQ(2, s.getSize());
	EXPECT_EQ(2, s.top());
}

TEST(stack, cant_add_element_in_full_stack)
{
	stack<int> s(3);
	s.push(1);
	s.push(2);
	s.push(3);
	ASSERT_ANY_THROW(s.push(4));
}


TEST(stack, can_get_element_from_non_empty_stack) {
	stack<char> s(3);
	s.push('a');
	EXPECT_EQ('a', s.pop());
}

TEST(stack, cant_get_element_from_empty_stack) {
	stack<char> s(3);
	char a;
	ASSERT_ANY_THROW(a = s.pop());
}

TEST(stack, can_clear_stack) {
	stack<char> s(3);
	s.push('a');
	s.Clear();
	EXPECT_EQ(0, s.getSize());
}

TEST(stack, can_create_copied_stack)
{
	stack<int> s(10);

	ASSERT_NO_THROW(stack<int> s1(s));
}

TEST(stack, copied_stack_is_equal_to_source_one)
{
	stack<int> s(10);
	s.push(5);
	stack<int> s1(s);
	EXPECT_EQ(s1.getSize(), s.getSize());
	EXPECT_EQ(s1.top(), s.top());
}

TEST(stack, copied_stack_has_its_own_memory)
{
	stack<int> s(10);
	s.push(5);

	if (true) {
		stack<int> s1(s);
	}

	ASSERT_NO_THROW(s.top());
}
