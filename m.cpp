    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>
    int main()
{
    std::string COMMAND;

    std::vector<std::string> task;
    std::cout << "TM  : TASK MANAGER FOR MY SELF" <<  std::endl;
    std::cout << "HOW TO USE : add doing reza" << std::endl;
    std::cout << "remove 1" << std::endl;
    if (task.size() != 0){
    for ( int i  = 0 ; i < task.size() ; i++){
    std::cout <<  i + 1 << ". " << task[i] << std::endl;
    }
    }
    else
    {
    std::cout << "START WITH ENTER YOU TASK" << std::endl;
    }
    std::cout << "ENTER COMMAND : " ;
    std::cin >> COMMAND ;

    if ( COMMAND == "ADD" ) {
    std::string TASKNAME;
    std::cout << " WHAT NAME IS THE TASK YOU WANT TO ADD : ";
    std::cin >> TASKNAME ;
    }
    else if ( COMMAND == "REMOVE" &&  task.size() != 0 ){
    int tasknum;
    std::cout << "WHAT TASK NUMBER YOU WANT TO REMOVE : " ;
    std::cin >> tasknum ;
    vec.erase(vec.begin() + (tasknum - 1));
    }
}
