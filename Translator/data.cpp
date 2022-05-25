/*
MIT License

Copyright (c) 2022 m!haly4

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "data.h"

Word::Word()
{   words.word = "";
    words.w_translation = "";
};

//overloaded two-parameterized constructor for assigning variables
Word::Word(std::string str1, std::string str2)
{
    this->words.word = str1;
    this->words.w_translation = str2;
};

Word::~Word(){};

//for data entry
void Word::DataEntry(std::string str1, std::string str2)
{
    this->words.word = str1;
    this->words.w_translation = str2;
}

//for setting the word
void Word::Set_word(char w[])
{
    this->words.word = w;
}

//for setting the word translation
void Word::Set_translation(char w[])
{
    this->words.w_translation = w;
}

//for getting the word
std::string Word::Get_word()
{
    return words.word;
}

//for getting the word translation
std::string Word::Get_translation()
{
    return words.w_translation;
}