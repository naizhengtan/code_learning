#include "iostream"

class A {

public:
	int a;
	A(const A& b) { a = b.a; std::cout << "  copy\n";} 
	A(const A&& b) { a = b.a; std::cout << "  move\n";} 
	A(int b) { a = b; std::cout << "  xxx\n";} 
};

A operator + (const A& a, const A&b) {
	return A(a.a+b.a);
}

/* start:
 * 	xxx
 * 	xxx
 * end construct
 * 	xxx
 * end copy
 */
int main() {
	std::cout << "start:\n";
	A a(1);
	A b(1);
	std::cout << "end construct\n";
	A c = a + b;
	A d = std::move(a);
	std::cout << "end copy\n";
}
