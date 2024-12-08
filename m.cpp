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

    void loadBE(std::vector<std::string>& vec)
{

/// LOAD FIle lud.zngdm that contian the last task before app get close

    #ifdef __linux__
        std::ifstream infile("/etc/TASK/lud.zngdm");
    #else
        std::ifsream infile("C:\\TASK\\lud.zngdm");
    #endif

        if (infile.is_open())
        {
/// Read the contents of the file into the vector
             std::string line;
             while (std::getline(infile, line))
             {
                 vec.push_back(line);
             }
             // Close the file

             infile.close();
             std::cout << "Succes to ADD LAST's TASK's" << std::endl;
        }

        else
        {
/// THE ERROR FOR CAN'T OPEN THE SAVE FILE
            std::cerr <<"ERROR :Cant To open Last Task" << std::endl;
            std::cout << "PLEASE TRY TO RUN WITH SUDO LIKE [sudo task]" << " OR MAKE SURE YOU HAVE your  last task save file"  << std::endl;
            std::cout << "in LINUX /etc/TASK/lud.zngdm and in WINDOWS WE HAVE c/task/lud.zngdm" << std::endl;


        }



}




    void saveBE(std::vector<std::string>& vec)
{
        #ifdef __linux__

            for (int i = 0 ; i < vec.size() ; i++ )
                {
                    ofstream file("/etc/TASK/lud.zngdm", ios_base::app);
                    if (file.is_open())
                    {
                        file <<  vec[i]  << endl;
                        file.close();
                    }
                    else
                    {
                        cerr << "ERROR" << endl;

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
                        cerr << "ERROR" << endl;

                    }
                }
        #endif

}



    bool FEX()
{
    #ifdef __linux__

        std::filesystem::path path("/etc/TASK/");
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


    #endif
}



/// Clear The CLI for Windows
    void Cls()
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
        system("mkdir /etc/TASK/ && touch /etc/TASK/lud.zngdm");
        #else
/// make dir
        #endif
}


/// Print The TASK LIST
    void St(std::vector<std::string>& task)
{

        for (int i = 0; i < task.size(); i++)
        {
        std::cout << i + 1 << " | "<< task[i] << std::endl;
        }

}



    int main()
{


    std::vector<std::string> task = {};

    if(FEX() == false)
    {
    firstTime();
    }
    else if (FEX() == true)
    {
    loadBE(task);
/// include lud file to vector task
    }


    std::cout << "TM  : TASK MANAGER FOR MY SELF" <<  std::endl;
    std::cout << "START WITH ENTER YOU TASK" << std::endl;

/// std::atexit(saveBE(task));

    while(true)
    {
        std::cout << "ENTER COMMAND : " ;
        std::string COMMAND;
        std::getline(std::cin, COMMAND);

<<<<<<< HEAD
        if ( COMMAND == "ADD" || COMMAND == "add")

        {
=======
        if ( COMMAND == "ADD" || COMMAND == "Add" ) {
>>>>>>> origin/main
        std::string TASKNAME;
        std::cout << "WHAT NAME IS THE TASK YOU WANT TO ADD : "<< std::endl;
        std::getline(std::cin, TASKNAME);
        task.push_back(TASKNAME);
        }

        else if ( (COMMAND == "REMOVE" || COMMAND == "remove") &&  task.size() != 0 ){
        int tasknum;
        std::cout << "WHAT TASK NUMBER YOU WANT TO REMOVE : " ;
        std::cin >> tasknum ;
        task.erase(task.begin() + (tasknum - 1));
        }
        else if ( COMMAND == "EXIT" || COMMAND == "exit"){

        saveBE(task);
        std::cout << "TM IS ABOUT TO EXIT" << std::endl;
        break;
        }

        Cls();
        St(task);

    }
    return 0;
}
