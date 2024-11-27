/// Gfaerny
/// With GCC and focus editor
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>
    #include <filesystem>
    #include <cstdlib>
    #include <fstream>

    #ifdef __linux__
    #include <cstdlib>
    #else
    #include <windows.h>
    #endif

    using namespace std;

    void saveBE(std::vector<std::string>& vec)
{
    #ifdef __linux__

    for (int i = 0 ; i < vec.size() ; i++ )
        {
            ofstream file("/bin/TASK/lud.zngdm", ios_base::app);
            if (file.is_open())
            {
                file <<  vec[i]  << endl;
                file.close();
            }
            else
            {
                cerr << "Unable to open file" << endl;
                return 1;
            }
        }


/// FOR WINDOWS
    #else
    for (int i = 0 ; i < vec.size() ; i++ )
        {
            ofstream file("C::\\TASK\\lud.zngdm", ios_base::app);
            if (file.is_open())
            {
                file <<  vec[i]  << endl;
                file.close();
            }
            else
            {
                cerr << "Unable to open file" << endl;
                return 1;
            }
        }


}



    bool FEX()
{
    #ifdef __linux__
    std::filesystem::path path("/bin/TASK/");
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
    {
        return true;
    }
    else
    {
        return false;
    }
    #else
    std::filesystem::path path("C:\\TASK");
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
    {
        return true;
    }
    else
    {
        return false;
    }

}



/// Clear The CLI for Windows
    void cls()
{
    #ifdef __linux__
    system("clear");
    #else
    system("cls");
    #endif
}

    void firstTime ()
{
/// /etc/TASK/
    #ifdef __linux__
    system("mkdir /etc/TASK/ && touch lud.zngdm")
    #else
    system("mkdir /etc/TASK/ && echo. > lud.zngdm")
}


/// Print The TASK LIST
    void st(std::vector<std::string>& task)
{
    for (int i = 0; i < task.size(); i++) {
        std::cout << i + 1 << " ."<< task[i] << std::endl;
    }
}

    int main()
{


    if(FEX() == false)
    {
    firstTime();
    }
    else if (FEX() == true)
    {

/// include lud file to vector task

    }

    std::vector<std::string> task;

    std::cout << "TM  : TASK MANAGER FOR MY SELF" <<  std::endl;
    std::cout << "START WITH ENTER YOU TASK" << std::endl;

    std::atexit(SaveBE(task));

    while(true)
    {
        std::cout << "ENTER COMMAND : " ;
        std::string COMMAND;
        std::getline(std::cin, COMMAND);

        if ( COMMAND == "ADD" || COMMAND == "Add" ) {
        std::string TASKNAME;
        std::cout << " WHAT NAME IS THE TASK YOU WANT TO ADD : "<< std::endl;
        std::getline(std::cin, TASKNAME);
        task.push_back(TASKNAME);
        }

        else if ( COMMAND == "REMOVE" &&  task.size() != 0 ){
        int tasknum;
        std::cout << "WHAT TASK NUMBER YOU WANT TO REMOVE : " ;
        std::cin >> tasknum ;
        task.erase(task.begin() + (tasknum - 1));
        }
        else if ( COMMAND == "EXIT"){
        std::cout << "TM IS ABOUT TO EXIT" << std::endl;
        break;
        }

        cls();
        st(task);

    }
    return 0;
}
