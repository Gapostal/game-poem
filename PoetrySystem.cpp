#include "stdafx.h"
#include "PoetrySystem.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::ctime;

namespace poetry
{
#define DELETE_NEW_SINGLE(var)          \
        {                               \
            if(nullptr != var)          \
            {                           \
                delete var;             \
                var = nullptr;          \
            }                           \
        };


    PoetrySystem::PoetrySystem()
    {
    }


    PoetrySystem::~PoetrySystem()
    {
        DELETE_NEW_SINGLE(string_utils_);

        poem_map_.erase(poem_map_.begin(), poem_map_.end());

        used_poem_vector_.clear();
    }

    Result PoetrySystem::Init()
    {
        cout << "[Info]: enter PoetrySystem::Init" << endl;

        poem_map_.erase(poem_map_.begin(), poem_map_.end());

        string_utils_ = new StringUtils();

        string poem_file = "Poetry/poem_file.txt";
        AddPoemFromFile(poem_file);

        return SUCCESS;
    }

    Result PoetrySystem::AddPoem(Poem * poem)
    {
        /*cout << "[Info]: enter PoetrySystem::AddPoem" << endl;*/

        if (nullptr == poem)
        {
            cout << "[Error]: poem is null." << endl;
            return FAILED;
        }

        if (poem_map_.find(poem->GetPoemContent()) != poem_map_.end())
        {
            cout << "[Warnning]: poem is exist." << endl;
            return EXISTED;
        }

        vector<string> input_str_vector = string_utils_->split(poem->GetStrContent(), '-');
        for (unsigned int i = 0; i < input_str_vector.size(); ++i)
        {
            poem->GetStrVector().push_back(input_str_vector[i]);
        }

        poem_map_[poem->GetPoemContent()] = poem;

        return SUCCESS;
    }

    Result PoetrySystem::ShowPoem()
    {
        cout << "[Info]: enter PoetrySystem::ShowPoem." << endl;

        if (0 == poem_map_.size())
        {
            cout << "[Warnning]: there is no poem." << endl;
            return SUCCESS;
        }

        cout << "#####################" << endl;
        for (auto iter = poem_map_.begin(); iter != poem_map_.end(); iter++)
        {
            cout << "#   " << iter->first << endl;
        }
        cout << "#####################" << endl;

        return SUCCESS;
    }

    string PoetrySystem::SelectNextPoem(Poem* poem)
    {
        //cout << "[Info]: enter PoetrySystem::SelectNextPoem." << endl;

        if (nullptr == poem)
        {
            cout << "[Error]: poem is null." << endl;
            return "NULL";
        }

        // get select_poem last world
        //cout << "[Info]: current poem is " << poem->GetPoemContent() << endl;
        vector<string> input_str_vector = string_utils_->split(poem->GetStrContent(), '-');
        string input_last_word = input_str_vector[input_str_vector.size() - 1];

        for (auto iter = poem_map_.begin(); iter != poem_map_.end(); iter++)
        {
            if (poem->GetPoemContent() == iter->first)
            {
                continue;
            }
            Poem* poem_tmp = iter->second;
            vector<string>str_vector = poem_tmp->GetStrVector();
            string tmp_poem_content = poem_tmp->GetPoemContent();
            if (std::find(str_vector.begin(), str_vector.end(), input_last_word) != str_vector.end() &&
                std::find(used_poem_vector_.begin(), used_poem_vector_.end(), tmp_poem_content) == used_poem_vector_.end())
            {
                //cout << "[Info]: next poem is " << poem_tmp->GetPoemContent() << endl;
                //return poem_tmp->GetStrContent();
                used_poem_vector_.push_back(tmp_poem_content);
                return tmp_poem_content;
            }
        }

        cout << "[Warnning]: next poem is not exist." << endl;
        return "NULL";
    }

    Result PoetrySystem::AddPoemFromFile(string poem_file)
    {
        cout << "[Info]: enter PoetrySystem::AddPoemFromFile." << endl;

        ifstream infile;
        infile.open(poem_file.data());

        if (!infile.is_open())
        {
            cout << "[Error]: open file failed." << endl;
            return FAILED;
        }

        string s;
        while (getline(infile, s))
        {
            vector<string> input_str_vector = string_utils_->split(s, ',');
            Poem* poem = new Poem(input_str_vector[0], input_str_vector[1]);
            AddPoem(poem);
        }

        infile.close();

        return SUCCESS;
    }

    Poem * PoetrySystem::GetRandomPoem()
    {
        cout << "[Info]: enter PoetrySystem::GetRandomPoem." << endl;
        if (0 == poem_map_.size())
        {
            cout << "[Warnning]: there is no poem." << endl;
            return nullptr;
        }

        srand(time(0));
        unsigned int num = rand() % poem_map_.size();

        unsigned int tmp_num = 0;
        for (auto iter = poem_map_.begin(); iter != poem_map_.end(); iter++)
        {
            if (tmp_num != num)
            {
                ++tmp_num;
            }
            else
            {
                return iter->second;
            }

        }

        return nullptr;
    }

    Result PoetrySystem::GetAllNextPoem(string str_content, vector<Poem*>& poem_vector)
    {
        for (auto iter = poem_map_.begin(); iter != poem_map_.end(); iter++)
        {
            Poem* poem_tmp = iter->second;
            vector<string>str_vector = poem_tmp->GetStrVector();
            if (std::find(str_vector.begin(), str_vector.end(), str_content) != str_vector.end())
            {
                poem_vector.push_back(poem_tmp);
            }
        }

        return SUCCESS;
    }
}

