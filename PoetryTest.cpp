#include "stdafx.h"
#include "PoetryTest.h"
#include <iostream>
#include <string>

#include "Poetry/PoetrySystem.h"
#include "Poetry/Poem.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;

using poetry::PoetrySystem;
using poetry::Poem;

PoetryTest::PoetryTest()
{
}


PoetryTest::~PoetryTest()
{
}

#define DELETE_NEW_SINGLE(var)          \
        {                               \
            if(nullptr != var)          \
            {                           \
                delete var;             \
                var = nullptr;          \
            }                           \
        };

int main()
{
    //// test1:Init
    //cout << "----[Test1]----" << endl;
    //PoetrySystem* poetry_system = new PoetrySystem();
    //poetry_system->Init();

    //// test2:Add first poem
    //cout << "----[Test2]----" << endl;
    //string poem_content_1 = "去日苦多";
    //string character_content_1 = "qu-ri-ku-duo";
    //Poem* poem_1 = new Poem(poem_content_1, character_content_1);
    //poetry_system->AddPoem(poem_1);

    //// test3:Add second poem
    //cout << "----[Test3]----" << endl;
    //string poem_content_2 = "多情总被无情恼";
    //string character_content_2 = "duo-qing-zong-bei-wu-qing-nao";
    //Poem* poem_2 = new Poem(poem_content_2, character_content_2);
    //poetry_system->AddPoem(poem_2);

    //// test4:Show all poem
    //cout << "----[Test4]----" << endl;
    //poetry_system->ShowPoem();

    //// test5:Add repeat poem
    //cout << "----[Test5]----" << endl;
    //string poem_content_3 = "去日苦多";
    //string character_content_3 = "qu-ri-ku-duo";
    //Poem* poem_3 = new Poem(poem_content_3, character_content_3);
    //poetry_system->AddPoem(poem_3);

    //// test6:Select next poem
    //cout << "----[Test6]----" << endl;
    //string poem_content_4 = "去日苦多";
    //string str_content_4 = "qu-ri-ku-duo";
    //Poem* poem_4 = new Poem(poem_content_4, str_content_4);
    //poetry_system->SelectNextPoem(poem_4);

    //// test7:Add poem from file
    //cout << "----[Test7]----" << endl;
    //string poem_file = "Poetry/poem_file.txt";
    //poetry_system->AddPoemFromFile(poem_file);
    //poetry_system->ShowPoem();

    //// test8:Get random poem
    //cout << "----[Test8]----" << endl;
    //Poem* poem = poetry_system->GetRandomPoem();
    //cout << poem->GetPoemContent() << endl;

    //// test9:Get next poem from string
    //cout << "----[Test9]----" << endl;
    //string str_content = "duo";
    //vector<Poem*> poem_vector;
    //poetry_system->GetAllNextPoem(str_content, poem_vector);
    //for (unsigned int i = 0; i < poem_vector.size(); ++i)
    //{
    //    cout << poem_vector[i]->GetPoemContent() << endl;
    //}

    PoetrySystem* poetry_system = new PoetrySystem();
    poetry_system->Init();

    cout << "Hello , ready ? [Y/N]" << endl;

    string input_str_1;
    cin >> input_str_1;

    if ("Y" == input_str_1)
    {
        cout << "Ok, let us go. If you want to leave , just press Q, or press C." << endl;

        Poem* poem = poetry_system->GetRandomPoem();
        cout << poem->GetPoemContent() << endl;
        cout << "Please speak next poem.If you need help, just input HELP." << endl;

        string input_str_2;
        cin >> input_str_2;
        while ("Q" != input_str_2)
        {
            if ("HELP" == input_str_2)
            {
                cout << "Please input last word pronunciation" << endl;
                cin >> input_str_2;

                vector<Poem*> poem_vector;
                poetry_system->GetAllNextPoem(input_str_2, poem_vector);

                if (0 == poem_vector.size())
                {
                    cout << "Oh, guys, I can not answer either." << endl;
                }
                else
                {
                    cout << "OK, let me tell you" << endl;
                    for (unsigned int i = 0; i < poem_vector.size(); ++i)
                    {
                        cout << poem_vector[i]->GetPoemContent() << endl;
                    }

                    cout << "Now, you remember them. We will go on." << endl;
                }

            }
            else
            {
                cout << "Please input your poem:" << endl;
                cin >> input_str_2;

                Poem poem(input_str_2, input_str_2);
                string next_poem = poetry_system->SelectNextPoem(&poem);
                if ("NULL" != next_poem)
                {
                    cout << next_poem << endl;
                }
                else
                {
                    cout << "You win, I do not know." << endl;
                    break;
                }
            }

        }
    }
    else
    {
        cout << "It is a pitty. Hope to see you again." << endl;
    }

    DELETE_NEW_SINGLE(poetry_system);
    //DELETE_NEW_SINGLE(poem_1);
    //DELETE_NEW_SINGLE(poem_2);
    //DELETE_NEW_SINGLE(poem_3);
    //DELETE_NEW_SINGLE(poem_4);

    system("pause");
    return 1;
}
