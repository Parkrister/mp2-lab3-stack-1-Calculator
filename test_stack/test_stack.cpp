#include "../stack/stack.h"

#include "gtest.h"

TEST(Stack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(Stack<int> bf(3));
}

TEST(Stack, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(Stack<int> bf(-3));
}

TEST(Stack, can_add_element)
{
	Stack<int> s(3);
	s.push(2);
	EXPECT_EQ(1, s.getSize());
	EXPECT_EQ(2, s.top());
}