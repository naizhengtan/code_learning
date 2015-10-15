#include "iostream"

using namespace std;

int global = 0;
int main() {
	const int cen = 10;
	int ncen = 10;

	// (1) const reference
	const int& cref = cen;
	// not allow
	//int& ncref = cen;
	// cannot bind, because the (int)cen is a temp value
	//int& ncref = (int)cen;
	const int& cref2 = ncen;
	int& ncref2 = ncen;

	// (2) pointer to const
	const int* cptr = &cen;
	const int* cptr2 = &ncen;
	// not allow
	//int* ncptr = &cen;
	int* ncptr2 = &ncen;
	int* ncptr3 = (int *)&cen;

	// (3) const pointer
	const int* const const_ptr = &cen;
	int* const const_ptr2 = &ncen;

	// (4) constant expression
	constexpr int cexpr = 10;
	// not allow
	//cexpr++;
	// not allow, because ncen is changable
	//constexpr int cexpr2 = ncen;
	constexpr int *cexpr_ptr = &global;
	// not allow, &ncen is not sure during compilation time
	//constexpr int *cexpr_ptr2 = &ncen;
}
