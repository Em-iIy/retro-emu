/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/04/2026
*/

#include <string>
#include <vector>
#include <cstdint>
#include <stdexcept>

#include <fstream>

std::vector<uint8_t>	readFile(const std::string &fileName)
{
	std::vector<uint8_t>	ret;

	std::ifstream stream(fileName, std::ios::binary | std::ios::ate);
	if (!stream.is_open())
		throw std::runtime_error("Failed to open");

	uint64_t	fileSize = stream.tellg();
	ret.resize(fileSize);

	stream.seekg(0, std::ios::beg);

	if (!stream.read(reinterpret_cast<char *>(ret.data()), fileSize))
		throw std::runtime_error("Failed to read");

	return (ret);
}