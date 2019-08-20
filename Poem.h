#pragma once
#ifndef POETRY_POEM
#define POETRY_POEM

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace poetry
{
    class Poem
    {
    public:
        Poem(string poem_content, string character_content);
        ~Poem();

        string GetPoemContent();

        string GetStrContent();

        vector<string>& GetStrVector();

    private:
        //int poem_id;
        string poem_content_;
        string str_content_;
        vector<string> str_vector_;
    };
}


#endif // POETRY_POEM