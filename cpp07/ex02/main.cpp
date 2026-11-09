#include "Array.hpp"

int main()
{
	std::cout << BOLD_CYAN << "\n=== 1. CONSTRUCTION ===" << RESET << std::endl;
	Array<int> empty;
	Array<int> a(5);
	std::cout << "empty.size() = " << empty.size() << YELLOW << " (expected 0)" << RESET << std::endl;
	std::cout << "a.size() = " << a.size() << YELLOW << " (expected 5)" << RESET << std::endl;
	std::cout << "a[0..4] =";
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << " " << a[i];
	std::cout << YELLOW << " (expected all 0)" << RESET << std::endl;

	std::cout << BOLD_CYAN << "\n=== 2. OUT OF BOUNDS (expected 3 exceptions) ===" << RESET << std::endl;
	try { empty[0]; }  catch (const std::exception& ex) { std::cout << "empty[0]: " << GREEN << ex.what() << RESET << std::endl; }
	try { a[5]; }      catch (const std::exception& ex) { std::cout << "a[5]: " << GREEN << ex.what() << RESET << std::endl; }
	try { a[-1]; }     catch (const std::exception& ex) { std::cout << "a[-1]: " << GREEN << ex.what() << RESET << std::endl; }

	std::cout << BOLD_CYAN << "\n=== 3. WRITE AND READ ===" << RESET << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i + 1;
	std::cout << "a[0] = " << a[0] << ", a[4] = " << a[4] << YELLOW << " (expected 1 and 5)" << RESET << std::endl;

	std::cout << BOLD_CYAN << "\n=== 4. COPY: MODIFY THE COPY, THE ORIGINAL MUST NOT CHANGE ===" << RESET << std::endl;
	Array<int> b(a);
	b[0] = 99;
	std::cout << "a[0] = " << a[0] << YELLOW << " (expected 1)" << RESET << ", b[0] = " << b[0] << YELLOW << " (expected 99)" << RESET << std::endl;

	std::cout << BOLD_CYAN << "\n=== 5. ASSIGNMENT: MODIFY THE ORIGINAL, THE COPY MUST NOT CHANGE ===" << RESET << std::endl;
	Array<int> c(2);
	c = a;
	a[1] = 77;
	std::cout << "c.size() = " << c.size() << YELLOW << " (expected 5)" << RESET << ", c[1] = " << c[1] << YELLOW << " (expected 2)" << RESET << std::endl;
	c = empty;
	std::cout << "c.size() after c = empty: " << c.size() << YELLOW << " (expected 0)" << RESET << std::endl;
	Array<int>& ref = a;
	a = ref;
	std::cout << "a after self-assignment: a[1] = " << a[1] << YELLOW << " (expected 77)" << RESET << std::endl;

	std::cout << BOLD_CYAN << "\n=== 6. CONST ===" << RESET << std::endl;
	const Array<int> k(a);
	std::cout << "k.size() = " << k.size() << ", k[4] = " << k[4] << YELLOW << " (expected 5 and 5)" << RESET << std::endl;

	std::cout << BOLD_CYAN << "\n=== 7. OTHER TYPE: std::string ===" << RESET << std::endl;
	Array<std::string> s(3);
	std::cout << "s[0] = \"" << s[0] << "\"" << YELLOW << " (expected empty string)" << RESET << std::endl;
	s[1] = "hello";
	Array<std::string> t(s);
	t[1] = "world";
	std::cout << "s[1] = " << s[1] << YELLOW << " (expected hello)" << RESET << ", t[1] = " << t[1] << YELLOW << " (expected world)" << RESET << std::endl;

	return 0;
}