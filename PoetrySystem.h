#pragma once
#ifndef POETRY_POETRY_SYSTEM
#define POETRY_POETRY_SYSTEM

#include <map>
#include <string>

#include "Poetry/Poem.h"
#include "Poetry/StringUtils.h"

using std::map;
using std::string;

using poetry::Poem;
using poetry::StringUtils;

namespace poetry
{
    enum Result
    {
        SUCCESS = 0,
        FAILED,
        EXISTED,
    };

    class PoetrySystem
    {
    public:
        PoetrySystem();
        ~PoetrySystem();

        Result Init();

        Result AddPoem(Poem* poem);

        Result ShowPoem();

        string SelectNextPoem(Poem* poem);

        Result AddPoemFromFile(string poem_file);

        Poem* GetRandomPoem();

        Result GetAllNextPoem(string str_content, vector<Poem*>& poem_vector);

    private:
        map<string, Poem*> poem_map_;
        StringUtils* string_utils_;
        vector<string> used_poem_vector_;
    };
}


#endif // POETRY_POETRY_SYSTEM