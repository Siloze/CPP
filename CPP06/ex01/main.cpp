#include <stdio.h>
#include <iostream>

typedef struct s_Data
{
	std::string name;
	int         age;
	int			height;
}   Data;

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

int main (void)
{
	Data data = {"George", 12, 180};
	Data *Data_ptr = &data;
	std::cout << "name: " << data.name << ", age: " << data.age << ", height: " << data.height << std::endl;
	Data_ptr = deserialize(serialize(Data_ptr));
	data = *Data_ptr;
	std::cout << "Serialize Data_ptr then deserializing it !" << std::endl;
	std::cout << "name: " << data.name << ", age: " << data.age << ", height: " << data.height << std::endl;
	return 1;
}