//#include <functional>

#include <iostream>
#include <thread>


#include <sys/prctl.h>
static void SetThreadName(const char* name)
{
    ::prctl(PR_SET_NAME, name, 0, 0, 0);
}

void thread_function()
{
    SetThreadName("shang-abc");
    for (int i = 0; i < 100; i++)
    {
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
    }
}

int main() 
{
    std::thread threadObj(thread_function);
    //std::pthread_setname(threadObj, "abc");
    threadObj.join(); 
    std::cout << "Exit of Main function" << std::endl;
    return 0; 
}