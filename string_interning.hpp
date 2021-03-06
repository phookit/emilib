#pragma once

#include <string>
#include <unordered_map>

namespace emilib {

/*
The StringInterner will allocate exactly one string for any unique input.
This means that calling intern() twice with the same characters will result in the same pointer.

This is great for two things:

* Lightweight storage of stirng using const char* instead of std::string
* Cheaply compare const char* for equality without memcmp or std::string::operator==
*/

class StringInterner
{
public:
	~StringInterner();

	// Not thread-safe. The allocated string will be freed when this StringInterner dies.
	const char* intern(const std::string& str);

private:
	std::unordered_map<std::string, char*> _map;
};

// Thread-safe global interning. The allocated string will never be freed.
const char* intern_string(const std::string& str);

} // namespace emilib
