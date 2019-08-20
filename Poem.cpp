#include "stdafx.h"
#include "Poem.h"

namespace poetry
{
    Poem::Poem(string poem_content, string str_content)
    {
        poem_content_ = poem_content;
        str_content_ = str_content;
    }


    Poem::~Poem()
    {
        str_vector_.clear();
    }

    string Poem::GetPoemContent()
    {
        return poem_content_;
    }

    string Poem::GetStrContent()
    {
        return str_content_;
    }

    vector<string>& Poem::GetStrVector()
    {
        return str_vector_;
    }


}
