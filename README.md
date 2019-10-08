# JsonMap
A Simple &amp; easy to use json to std::map, std::map to json open source library.

## Functions
<strong>JsonMap::jsonToMap(std::string)</strong>	<-- Converts string to std::map</br>
<strong>JsonMap::mapToJson(std::map)</strong>		<-- Converts map to string</br>
<strong>JsonMap::MapPrinter(std::map)</strong>      	<-- Prints key and values of map in console</br>
<strong>JsonMap::Example()</strong>			<-- Basic example how to use</br>

## How to use?
Include <strong>JsonMap.hpp</strong> to your project (you can find it in the source folder),</br> now link the <strong>JsonMap.lib</strong> file to your project(you can find it in the lib folder or compile it yourself).</br>
Now you can use JsonMap::mapToJson to convert a std::map to json string and JsonMap::jsonToMap to convert json string to std::map.

## Example
```cpp
#include <iostream>
#include "JsonMap.hpp"
#pragma comment(lib, "lib/x86/JsonMap.lib")

void main()
{
	std::cout << "JsonMap Example" << std::endl;

	auto map = JsonMap::jsonToMap("{\"name\":\"testuser1\",\"id\":\"12345\", \"level\":\"64\",\"rank\":\"1\"}");

	std::cout << "\nPrinting std::map:" << std::endl;
	JsonMap::MapPrinter(map);

	std::cout << "\nPrinting json string:" << std::endl;
	std::string res = JsonMap::mapToJson(map);

	std::cout << res << std::endl;
}
```
