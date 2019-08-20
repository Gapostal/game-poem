#include "stdafx.h"
#include "StringUtils.h"

#include <sstream>

using std::stringstream;

namespace poetry
{
    StringUtils::StringUtils()
    {
    }


    StringUtils::~StringUtils()
    {
    }

    vector<string> StringUtils::split(string str, char delimiter)
    {
        vector<string> internal;
        stringstream ss(str); // Turn the string into a stream.
        string tok;

        while (getline(ss, tok, delimiter))
        {
            internal.push_back(tok);
        }

        return internal;
    }
}

