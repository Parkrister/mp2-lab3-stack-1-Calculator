#include "gtest.h"
#include <conio.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int rez = RUN_ALL_TESTS();
	_getch();
	return rez;
}
