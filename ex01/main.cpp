#include "Serializer.h"
#include <iostream>

int main(void)
{

	Data *data = new Data;
	data->name = "Peter";
	data->age = 42;
	data->sername = "Meier";

    std::cout << std::endl;
    std::cout << MAGENTA "Before serialization:" RESET << std::endl;
    std::cout << data << std::endl;

    std::cout << MAGENTA "Serializing..." RESET << std::endl;

	uintptr_t raw = Serializer::serialize(data);

    std::cout << CYAN "raw ptr: " GREEN << raw << RESET << std::endl;
    std::cout << MAGENTA "Deserializing..." RESET << std::endl << std::endl;

	Data *serialized = Serializer::deserialize(raw);

    std::cout << MAGENTA "After serialization->deserialization:" RESET << std::endl;
    std::cout << serialized << std::endl;

	delete data;
	return (0);
}