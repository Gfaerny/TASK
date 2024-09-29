/// using getline exp cin

/// Gfaerny
/// With G++ and focus editor
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>
    #ifdef __linux__
    #include <cstdlib>
    #else
    #include <windows.h>
    #endif

/// Clear The CLI for Windows
    void cls()
{
    #ifdef __linux__
    system("clear");
    #else
    system("cls");
    #endif
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
    std::vector<std::string> task;

    std::cout << "TM  : TASK MANAGER FOR MY SELF" <<  std::endl;
    std::cout << "START WITH ENTER YOU TASK" << std::endl;
    while(true){
    std::cout << "ENTER COMMAND : " ;
    std::string COMMAND;
    std::cin >> COMMAND ;

    if ( COMMAND == "ADD" ) {
    std::string TASKNAME;
    std::cout << " WHAT NAME IS THE TASK YOU WANT TO ADD : ";
    std::cin >> TASKNAME ;
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
