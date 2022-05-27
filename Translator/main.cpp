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

int menu;
std::string menu_str;

//main menu function
void Menu()
{
    std::cout   << "Choose option:" << std::endl
                << "1) Start test" << std::endl
                << "2) Entry new words" << std::endl
                << "3) Read the words" << std::endl
                << "4) Info about the creator and license" << std::endl
                << "0) Exit" << std::endl
                << "Your choise: ";

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
    std::string doubleDelimiter = "========================================================================";

    srand(time(NULL)); //for using the random_shuffle() algorithm

    Menu();
    while(menu != 0)
    {
        switch(menu)
        {
            //testing case
            case 1:
                std::cout << doubleDelimiter << std::endl;

                std::cout << "Enter a file name for test (format: name.txt): ";
                getline(std::cin, fileName);

                readData(dataBase, fileName); //entering data from a file into a vector

                std::cout << doubleDelimiter << std::endl;

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

                std::cout << doubleDelimiter << std::endl;

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
                std::cout << doubleDelimiter << std::endl;

                std::cout << "Enter a name to new file (format: name.txt): ";
                getline(std::cin, fileName);

                std::cout << "Enter a number of words to emplace: ";
                getline(std::cin, action_str);
                std::stringstream(action_str) >> action;

                std::cout << doubleDelimiter << std::endl;

                for(int i = 0; i < action; i++) //entering new words(depends on the number)
                {
                    std::cout << "Enter a new word: ";
                    getline(std::cin, bufer1);
                    std::cout << "Enter translation for this word: ";
                    getline(std::cin, bufer2);

                    new_word.DataEntry(bufer1, bufer2);

                    dataBase.push_back(new_word);
                }

                saveData(dataBase, fileName); //saving data into a file

                std::cout << doubleDelimiter << std::endl;
                
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
                std::cout << doubleDelimiter << std::endl;

                std::cout << "Enter a file name for reading (format: name.txt): ";
                getline(std::cin, fileName);

                readData(dataBase, fileName); //entering data from a file into a vector

                dataBase.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

                #ifdef testing

                    std::cout << dataBase.capacity() << std::endl;
                    for(auto el : dataBase)
                    {
                        std::cout << el.Get_word() << " " << el.Get_translation() << std::endl;
                    }
                    
                #endif

                std::cout << doubleDelimiter << std::endl;

                readFile(dataBase); //output each element

                std::cout << doubleDelimiter << std::endl;

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
                std::cout   << doubleDelimiter << std::endl << std::endl
                            << "---> Creator of this program: git-user-cpp (m!haly4) <---" << std::endl << std::endl
                            << "---> Link: https://github.com/git-user-cpp <---" << std::endl << std::endl
                            << doubleDelimiter << std::endl << std::endl

                            << "MIT License\n\n"

                            << "Copyright (c) 2022 m!haly4\n\n"

                            <<  "Permission is hereby granted, free of charge, to any person obtaining a copy\n"
                            <<  "of this software and associated documentation files (the \"Software\"), to deal\n"
                            <<  "in the Software without restriction, including without limitation the rights\n"
                            <<  "to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n"
                            <<  "copies of the Software, and to permit persons to whom the Software is\n"
                            <<  "furnished to do so, subject to the following conditions:\n\n"

                            <<  "The above copyright notice and this permission notice shall be included in all\n"
                            <<  "copies or substantial portions of the Software.\n\n"

                            <<  "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
                            <<  "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
                            <<  "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
                            <<  "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
                            <<  "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
                            <<  "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n"
                            <<  "SOFTWARE. "
                            << std::endl << std::endl
                            << doubleDelimiter << std::endl;

                Menu();
            break;

            default:
                std::cout << "Error" << std::endl;

                Menu();
            break;
        }
    }

    std::cout << doubleDelimiter << std::endl;
    std::cout << "The programm is stopped" << std::endl;

return 0;
}