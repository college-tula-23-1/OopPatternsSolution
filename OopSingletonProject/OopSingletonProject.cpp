#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

class Singleton
{
    static Singleton* instanse;
    Singleton() 
    {
        // implementation constructor
    }

    Singleton(Singleton& obj) = delete;
    Singleton& operator=(Singleton& obj) = delete;
public:
    static Singleton* GetInstance()
    {
        if (instanse == nullptr)
            instanse = new Singleton();

        return instanse;
    }

};

Singleton* Singleton::instanse = nullptr;


class OperationSystem
{
    static OperationSystem* system;
    std::string title;
    OperationSystem(std::string title) : title{ title } {}

public:
    std::string& Title() { return title; }

    static OperationSystem* LounchSystem(std::string title)
    {
        std::lock_guard<std::mutex> lock(m);
        if (system == nullptr)
            system = new OperationSystem(title);
        return system;
    }
};

OperationSystem* OperationSystem::system = nullptr;

class Computer
{
    OperationSystem* system;
public:
    OperationSystem* System() { return system; }

    void Lounch(std::string title)
    {
        system = OperationSystem::LounchSystem(title);
    }
};

void ComputerLaunch(std::string title)
{
    Computer* computer = new Computer();

    computer->Lounch(title);
    std::cout << computer->System() << "\n";
}


int main()
{
    std::thread comp1(ComputerLaunch, "Debian");
    std::thread comp2(ComputerLaunch, "Windows");

    comp1.join();
    comp2.join();

    system("pause");
}
