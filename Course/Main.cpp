#include "Course.h"
#include <iostream>
int main (){


Study uni("John Smith", 2, 3);
    std::cout << Course::count() << std::endl; // 0


 try {
        uni.add(new ScoredCourse("Programming", "Computers", 65));
        uni.add(new AveragedCourse("English", "Languages", 4, 5));
        uni.add(new CheckCourse("Spanish ","Languages",true,false,true,true));
        uni.add(new ScoredCourse("OOP", "Programming", 95));


    } catch (Study::LimitError& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << uni<<std::endl;
    uni.Remove("Programming");
    std::cout<<uni<<std::endl;
    std::cout<<uni[2].getName()<<std::endl;
    std::cout << Course::count() << std::endl;//2
}
