#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <unistd.h>

using namespace std;

class Foo {
    bool firstDone;
    bool secondDone;
    mutex mt;
    condition_variable cv;
public:
    Foo() : firstDone(false), secondDone(false) {

    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstDone=true;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lc(mt);
        while(!firstDone) {
            cv.wait(lc);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondDone=true;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lc(mt);
        while(!secondDone) {
            cv.wait(lc);
        }
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