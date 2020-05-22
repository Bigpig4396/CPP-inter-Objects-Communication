#include "stdafx.h"
#include "ConnecterSlot.h"
 
class A
{
public:
    A()
    {
    }
 
    ~A()
    {
    }
 
private:
    // define a signal
    SIGNAL(TestSignal)
 
public:
    void EmitSignal()
    {
        printf("A Signal Emit!!\r\n");
 
        // Trigger the signal
        EMIT(TestSignal)
    }
};
 
class B
{
public:
    B()
    {
 
    }
    ~B()
    {
 
    }
 
public:
    // binded slot function
    void DoSlot()
    {
        printf("B Slot Run!!\r\n");
    }
 
};
 
int main()
{
    A a;
    B b;
 
    // bind signal and slot
    CONNECT(&a, TestSignal, &b, &B::DoSlot);
    
    // trigger signal
    a.EmitSignal();
 
    system("pause");
    return 0;
}

