#ifndef JSONMAP_H
#define JSONMAP_H

#include <string>
#include <map>

#define JsonMap_BufferSize 600

namespace JsonMap
{
	std::map<std::string, std::string> jsonToMap(std::string json);

	std::string MapToJson(std::map<std::string, std::string> map);

	void MapPrinter(std::map<std::string, std::string> map);

	void Example();
}

#endif