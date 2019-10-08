#include "JsonMap.hpp"
#include <iostream>

std::map<std::string, std::string> JsonMap::jsonToMap(std::string json)
{
	std::map<std::string, std::string> Map;
	char wordbuffer[JsonMap_BufferSize];
	char key[JsonMap_BufferSize];
	char var[JsonMap_BufferSize];

	__int8 quotes = 0;
	bool onkey = true;

	for (int i = 0, b = 0; i < json.length(); i++)
	{
		if (json[i] != '"')
		{
			if (quotes == 1)
			{
				if (b < JsonMap_BufferSize)
				{
					wordbuffer[b] = json[i];
					if (b < JsonMap_BufferSize + 1)
						wordbuffer[b + 1] = '\0';
					else continue;
					b++;
				}
				else continue;
			}
		}
		else
		{
			quotes += 1;
			b = 0;
			if (quotes == 2)
			{
				if (onkey)
				{
					strcpy_s(key, JsonMap_BufferSize, wordbuffer);
					memset(wordbuffer, 0, JsonMap_BufferSize);
					onkey = false;
				}
				else
				{
					strcpy_s(var, JsonMap_BufferSize, wordbuffer);
					memset(wordbuffer, 0, JsonMap_BufferSize);

					Map[key] = var;
					quotes = 0;
					onkey = true;
				}
				quotes = 0;
			}
		}
	}

	return Map;
}

std::string JsonMap::mapToJson(std::map<std::string, std::string> map)
{
	std::string json = "{";

	bool first = true;
	for (auto [key, val] : map)
	{
		if (!first)
			json += ',';
		else
			first = false;

		json += '"' + key + '"' + ':' + '"' + val + '"';
	}

	json += "}";

	return json;
}

void JsonMap::MapPrinter(std::map<std::string, std::string> map)
{
	for (auto [key, val] : map)
	{
		printf_s("[%s]: %s\n", key.c_str(), val.c_str());
	}
}

void JsonMap::Example()
{
	std::cout << "JsonMap Example" << std::endl;

	auto map = JsonMap::jsonToMap("{\"name\":\"testuser1\",\"id\":\"12345\", \"level\":\"64\",\"rank\":\"1\"}");

	std::cout << "\nPrinting std::map:" << std::endl;
	JsonMap::MapPrinter(map);

	std::cout << "\nPrinting json string:" << std::endl;
	std::string res = JsonMap::mapToJson(map);

	std::cout << res << std::endl;
}