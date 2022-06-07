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

#include "data.hpp"

int menu;
std::string menu_str;

//main menu function
void Menu()
{
    std::cout   << " _____________________________________________________________" << std::endl
                << "|                       Choose option:                        |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << "|                       [1] Start test                        |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << "|                     [2] Entry new words                     |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << "|                      [3] Read the words                     |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << "|            [4] Info about the creator and license           |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << "|                           [0] Exit                          |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << " _____________________________________________________________ " << std::endl
                << "                          Your choise: ";

    getline(std::cin, menu_str);
    std::stringstream(menu_str) >> menu; //using stringstream to avoid the cin.ignore(); command
}

int main()
{
    setlocale(LC_ALL, "ua"); //setlocale for the use of the Ukrainian language
    // setlocale(LC_ALL, "ru");

    int action;
    Word new_word;
    std::string action_str;
    std::string bufer1;
    std::string bufer2;
    std::string fileName;
    std::vector<Word> dataBase;
    std::string delimiter = "|_____________________________________________________________|\n";

    srand(time(NULL)); //for using the random_shuffle() algorithm

    Menu();
    while(menu != 0)
    {
        switch(menu)
        {
            //testing case
            case 1:
                std::cout << delimiter << std::endl;

                std::cout   << " _____________________________________________________________" << std::endl
                            << "| Enter a file name for test (format: name.txt): ";
                getline(std::cin, fileName);
                std::cout   << "|_____________________________________________________________" << std::endl;

                readData(dataBase, fileName); //entering data from a file into a vector

                dataBase.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

                #ifdef testing

                    std::cout << dataBase.capacity() << std::endl;
                    for(auto el : dataBase)
                    {
                        std::cout << el.Get_word() << " " << el.Get_translation() << std::endl;
                    }
                    
                #endif

                random_shuffle(begin(dataBase), end(dataBase)); //shuffling the elements

                #ifdef testing

                    std::cout << "after shuffle" << std::endl;

                    std::cout << dataBase.capacity() << std::endl;
                    for(auto el : dataBase)
                    {
                        std::cout << el.Get_word() << " " << el.Get_translation() << std::endl;
                    }
                    
                #endif

                test(dataBase); //start the test

                dataBase.clear(); //deleting each vector element
                dataBase.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

                #ifdef testing

                    std::cout << "after erasing" << std::endl;

                    std::cout << dataBase.capacity() << std::endl;
                    for(auto el : dataBase)
                    {
                        std::cout << el.Get_word() << " " << el.Get_translation() << std::endl;
                    }
                    
                #endif

                Menu();
            break;

            case 2:
                std::cout << delimiter << std::endl;
            
                std::cout   << " _____________________________________________________________" << std::endl
                            << "| Enter a name to new file (format: name.txt): ";
                getline(std::cin, fileName);
                std::cout   << "|_____________________________________________________________" << std::endl;

                std::cout   << " _____________________________________________________________" << std::endl
                            << "| Enter a number of words to emplace: ";
                getline(std::cin, action_str);
                std::cout   << "|_____________________________________________________________" << std::endl;
                std::stringstream(action_str) >> action;

                for(int i = 0; i < action; i++) //entering new words(depends on the number)
                {
                    std::cout   << " _____________________________________________________________" << std::endl
                                << "| Enter a new word: ";
                    getline(std::cin, bufer1);
                    std::cout   << "| Enter translation for this word: ";
                    getline(std::cin, bufer2);
                    std::cout   << "|_____________________________________________________________" << std::endl;

                    new_word.DataEntry(bufer1, bufer2);

                    dataBase.push_back(new_word);
                }

                saveData(dataBase, fileName); //saving data into a file
                
                dataBase.clear(); //deleting each vector element
                dataBase.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

                #ifdef testing

                    std::cout << "after erasing" << std::endl;

                    std::cout << dataBase.capacity() << std::endl;
                    for(auto el : dataBase)
                    {
                        std::cout << el.Get_word() << " " << el.Get_translation() << std::endl;
                    }
                    
                #endif

                Menu();
            break;

            case 3:
                std::cout << delimiter << std::endl;

                std::cout   << " _____________________________________________________________" << std::endl
                            << "| Enter a file name for reading (format: name.txt): ";
                getline(std::cin, fileName);
                std::cout   << "|_____________________________________________________________" << std::endl;

                readData(dataBase, fileName); //entering data from a file into a vector

                dataBase.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

                #ifdef testing

                    std::cout << dataBase.capacity() << std::endl;
                    for(auto el : dataBase)
                    {
                        std::cout << el.Get_word() << " " << el.Get_translation() << std::endl;
                    }
                    
                #endif

                readFile(dataBase); //output each element

                dataBase.clear(); //deleting each vector element
                dataBase.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

                #ifdef testing

                    std::cout << "after erasing" << std::endl;

                    std::cout << dataBase.capacity() << std::endl;
                    for(auto el : dataBase)
                    {
                        std::cout << el.Get_word() << " " << el.Get_translation() << std::endl;
                    }
                    
                #endif

                Menu();
            break;

            case 4:
                std::cout   << delimiter << std::endl << std::endl
                            << " _____________________________________________________________" << std::endl
                            << "| ---> Creator of this program: git-user-cpp (m!haly4) <---" << std::endl
                            << "|_____________________________________________________________" << std::endl
                            << "|      ---> Link: https://github.com/git-user-cpp <---" << std::endl
                            << "|_____________________________________________________________" << std::endl
                            << "| ---> License: https://github.com/git-user-cpp/translation_training/blob/main/LICENSE <---" << std::endl
                            << "|_____________________________________________________________" << std::endl
                            << std::endl << std::endl;

                Menu();
            break;

            default:
                std::cout   << " _____________________________________________________________" << std::endl
                            << "|                     Error: Invalid input                    |" << std::endl
                            << "|_____________________________________________________________|" << std::endl;

                Menu();
            break;
        }
    }

    std::cout << delimiter << std::endl;
    std::cout   << " _____________________________________________________________" << std::endl
                << "|                   The programm is stopped                   |" << std::endl
                << "|_____________________________________________________________|" << std::endl;

return 0;
}