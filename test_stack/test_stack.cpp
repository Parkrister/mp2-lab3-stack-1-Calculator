#include "../stack/stack.h"
//#include "../stack/Calculator.h"

#include "gtest.h"

TEST(Stack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(Stack<int> bf(3));
}

TEST(Stack, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(Stack<int> bf(-3));
}

TEST(Stack, can_add_element_in_non_empty_stack)
{
	Stack<int> s(2);
	s.push(1);
	s.push(2);
	EXPECT_EQ(2, s.getSize());
	EXPECT_EQ(2, s.top());
}

TEST(Stack, cant_add_element_in_full_stack)
{
	Stack<int> s(3);
	s.push(1);
	s.push(2);
	s.push(3);
	ASSERT_ANY_THROW(s.push(4));
}


TEST(Stack, can_get_element_from_non_empty_stack) {
	Stack<char> s(3);
	s.push('a');
	EXPECT_EQ('a', s.pop());
}

TEST(Stack, cant_get_element_from_empty_stack) {
	Stack<char> s(3);
	char a;
	ASSERT_ANY_THROW(a = s.pop());
}
