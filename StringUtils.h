#pragma once
#ifndef POETRY_STRING_UTILS
#define POETRY_STRING_UTILS

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace poetry
{
    class StringUtils
    {
    public:
        StringUtils();
        ~StringUtils();

        // split str by delimiter
        vector<string> split(string str, char delimiter);

    };
}


#endif // POETRY_STRING_UTILS