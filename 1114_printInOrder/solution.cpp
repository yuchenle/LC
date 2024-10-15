#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <unistd.h>

using namespace std;

class Foo {
    atomic<bool> firstDone;
    atomic<bool> secondDone;
public:
    Foo() : firstDone(false), secondDone(false) {}

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstDone.store(true, std::memory_order_release);
    }

    void second(function<void()> printSecond) {
        while(!firstDone.load(std::memory_order_acquire)){
            std::this_thread::yield();
        };
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondDone.store(true,std::memory_order_release);
    }

    void third(function<void()> printThird) {
        while(!secondDone.load(std::memory_order_acquire)){
            std::this_thread::yield();
        };
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

void printSecond() {cout<<"Second";}
void printFirst() {cout<<"First";}
void printThird() {cout<<"Third";}

int main() {
    Foo f1 = Foo();
    
    std::thread t1(&Foo::third, &f1, printThird);
    std::thread t(&Foo::second, &f1, printSecond);
    std::thread t2(&Foo::first, &f1, printFirst);

    t.join();
    t1.join();
    t2.join();

    cout<<endl;

    return 0;
}