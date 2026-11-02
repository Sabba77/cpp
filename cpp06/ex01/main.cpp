#include "Serializer.hpp"

int	main(void)
{
	Data	data;
	Data*	otherData = NULL;
	uintptr_t	ptr = 0;
	
	data.str = "Naaaain!";
	data.value = 42;
		
	std::cout << BOLD_CYAN << "\n-- PTR INIT VALUE MUST BE 0 --" << std::endl;
	std::cout << "ptr init value : " << BLACK_GRAY << "HEX --> " << std::hex << ptr
		<< std::dec << " | DEC --> " << ptr << RESET << std::endl << std::endl;

	ptr = Serializer::serialize(&data);
	
	std::cout << BOLD_CYAN << "\n-- PTR MUST BE DATA ADDRESS --" << std::endl;
	std::cout << "data address --> " << &data << std::endl;
	std::cout << "ptr value : " << BLACK_GRAY << "HEX --> " << std::hex << ptr
		<< std::dec << " | DEC --> " << ptr << RESET << std::endl;


	std::cout << BOLD_CYAN << "\n-- INIT OTHERDATA ADDRESS MUST BE DIFFERENT --" << std::endl;
	std::cout << "otherData value address &--> " << &otherData << std::endl;
	std::cout << "otherData address *--> " << otherData << RESET << std::endl << std::endl;

	otherData = Serializer::deserialize(ptr);

	std::cout << BOLD_CYAN << "\n-- OTHERDATA ADDRESS MUST BE THE SAME OF DATA --" << std::endl;
	std::cout << "data address --> " << &data << std::endl;
	std::cout << "otherData address *--> " << otherData << std::endl;
	std::cout << "otherData value address &--> " << &otherData << RESET << std::endl;

	std::cout << BOLD_CYAN << "\n-- OTHERDATA VALUE MUST BE THE SAME OF DATA --" << std::endl;
	std::cout << YELLOW << "- otherData <str> | <value> --> "
		<< otherData->str << "  |  " << otherData->value << RESET << std::endl;
	std::cout << YELLOW << "- data      <str> | <value> --> "
		<< data.str << "  |  " << data.value << RESET << std::endl;

	return 0;
}