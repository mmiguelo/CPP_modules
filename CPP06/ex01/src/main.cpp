#include "../Data.hpp"
#include "../Serializer.hpp"

int main() {
	Data data;
	data.info = "Hello, World!";

	std::cout << "Original Data info: " << data.info << std::endl;

	// Serialize the Data pointer
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized Data pointer: " << serialized << std::endl;

	// Deserialize back to Data pointer
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data info: " << deserialized->info << std::endl;

	return 0;
}