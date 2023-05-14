/*
MIT License

Copyright (c) 2022 Andrew Kushyk

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

#include "function.hpp"

//to save data from vector to file
void saveData(std::vector<Word> &words, const std::string &file_name)
{
    std::fstream record;
    record.open(file_name, std::ios::app); //opening the file to add data to the end

        if(record)
        {            
            for(auto &el : words) //recording each element into file
            {
                record << el.Get_word() << '\n';
                record << el.Get_translation() << '\n';
            }
            record.close();
        }
        else
        {
            std::cout   << " _____________________________________________________________" << std::endl
                        << "|                    Error(file recording)                    |" << std::endl
                        << "|_____________________________________________________________|" << std::endl;
        }

    std::cout   << " _____________________________________________________________" << std::endl
                << "|                       Data is recorded                      |" << std::endl
                << "|_____________________________________________________________|" << std::endl;
}

//to read data from file to vector
void readData(std::vector<Word> &words, const std::string &file_name)
{
    Word word; //variable for input into the vector
    char str[510]; //string to read from a file
    int counter = 0;
    int flag = 0;

    std::fstream reading;
    reading.open(file_name, std::ios::in);

        if(reading)
        {
            while (reading.getline(str, 510, '\n')) //reading each line of the file
            {
                counter++;

                if(counter == 0 || counter % 2 == 0) //separation of the word from its translation
                {
                    word.Set_translation(str);
                    flag++;
                }
                else
                {
                    word.Set_word(str);
                    flag++;
                }

                if(flag % 2 == 0) //if a word and its translation are found, insert them into the vector
                {
                    words.push_back(word);
                }
            }
            
            reading.close();
        }
        else
        {
            std::cout   << " _____________________________________________________________" << std::endl
                        << "|                     Error(file reading)                     |" << std::endl
                        << "|_____________________________________________________________|" << std::endl;
        }

    std::cout   << " _____________________________________________________________" << std::endl
                << "|                         Data is red                         |" << std::endl
                << "|_____________________________________________________________|" << std::endl;
}

//function for test mode
void test(std::vector<Word> &words)
{
    std::string answer;
    int score = 0;

    std::cout << " _____________________________________________________________" << std::endl;

    for(auto &element : words)
    {
        std::cout << "| Write a word on English: ";
        std::cout << element.Get_translation() << std::endl;
        std::cout << "| Your answer: ";
        getline(std::cin, answer);

        //lambda function for evaluation
        auto result = [&]()
        {
            if(answer == element.Get_word()) //if the answer is equivalent to a word, the score increases
            {
                score++;
            }
        };
        result(); //calling the lambda function
    }

    std::cout << "|_____________________________________________________________" << std::endl;
    
    //derivation of the general estimation
    std::cout   << " _____________________________________________________________" << std::endl
                << "| Your mark is: " << score << "/" << words.capacity() << std::endl
                << "|_____________________________________________________________" << std::endl;
}

//output data from the vector
void readFile(std::vector<Word> &words)
{
    std::cout   << " _____________________________________________________________" << std::endl;
    for(auto &element : words)
    {
        std::cout << "| " << element.Get_word() << "\t-->\t" << element.Get_translation() << std::endl;
    }
    std::cout   << "|_____________________________________________________________" << std::endl;
}
