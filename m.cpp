    #include <iostream>
    #include <vector>
    #include <algorithm>

    int main()
{
    std::string taskstring;
    std::vector<std::string> task;
    std::cout << "TM  : TASK MANAGER FOR MY SELF" <<  std::endl;
    std::cout << "HOW TO USE : add doing reza" << std::endl;
    std::cout << "remove 1" << std::endl;
    if (task.size() != 0){
    for ( int i  = 0 ; i < task.size() ; i++){
    std::cout << task[i] << std::endl;
    }
    std::cout << "ENTER INPUT : " ;
    std::cin >> taskstring ;

    }
}
