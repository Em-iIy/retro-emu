/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/04/2026
*/

#include <string>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

std::vector<uint8_t>	readFile(const std::string &fileName)
{
	std::vector<uint8_t>	ret;

	int	fd = open(fileName.c_str(), O_RDONLY);
	if (fd < 0)
		throw std::runtime_error(std::strerror(errno));

	uint64_t	fileSize = lseek(fd, 0, SEEK_END);
	ret.resize(fileSize);
	lseek(fd, 0, SEEK_SET);

	uint64_t	bytesRead = read(fd, ret.data(), fileSize);
	if (bytesRead < 0)
		throw std::runtime_error(std::strerror(errno));

	return (ret);
}