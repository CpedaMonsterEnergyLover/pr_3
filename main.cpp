#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int main(){
    /*
    //Запоняем myArray значениями с клавиатуры
    std::array<int, 5> myArray;
    for (int i = 0; i < 5; i++) {
        std::cout << "Put ur int into array >> " << i + 1 << " " << std::endl;
        std::cin >> myArray[i];
    } 
    * Он мне мешал в будущем поэтому я его закомментировал (он работает)
    */

    //Запоняем myVector случайными значениями без рэнжа потому что зачем делать рэнж
    srand(static_cast<unsigned int>(time(0)));
    std::vector<int> myVector;
    for (int i = 0; i < 100; i++){
        myVector.push_back(rand());
    }

    LARGE_INTEGER frequency, t1, t2;
    QueryPerformanceFrequency(&frequency);

    QueryPerformanceCounter(&t1); //Сохраняем время и делаем insert
    myVector.insert(myVector.begin(), 777);
    QueryPerformanceCounter(&t2);
    double seconds = (double)(t2.QuadPart - t1.QuadPart) / frequency.QuadPart;
    std::cout << "Insert took " << seconds << " seconds;" << std::endl;
    
    QueryPerformanceCounter(&t1); //Сохраняем время и делаем resize
    myVector.resize(1000);
    QueryPerformanceCounter(&t2);
    seconds = (double)(t2.QuadPart - t1.QuadPart) / frequency.QuadPart;
    std::cout << "Resize took " << seconds << " seconds;" << std::endl;

    QueryPerformanceCounter(&t1); //Сохраняем время и делаем insert в массив с 1000ю элементами.
    myVector.insert(myVector.begin(), 666);
    QueryPerformanceCounter(&t2);
    seconds = (double)(t2.QuadPart - t1.QuadPart) / frequency.QuadPart;
    std::cout << "Second insert took " << seconds << " seconds;" << std::endl;
    std::cout << "End;";
    return 0;
}