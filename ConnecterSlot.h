//ConnecterSlot.h
#pragma once
 
#include <vector>
 
class ISloter
{
public:
    virtual ~ISloter() { };
    virtual void doFun() = 0;
};
 
template<typename T>
class Sloter : public ISloter
{
    typedef void(T::*CallBackFun)(void);
 
public:
    Sloter(T* obj, CallBackFun fun) : d_object(obj), m_callBackFun(fun)
    {
    }
 
    ~Sloter()
    {
    }
 
private:
    T* d_object;
    CallBackFun m_callBackFun;
 
public:
    void doFun()
    {
        (d_object->*m_callBackFun)();
    }
};
 
class Signal
{
public:
    Signal()
    {
    }
 
    ~Signal()
    {
        if (1 == m_slots.size())
        {
            delete m_slots[0];
        }
    }
 
private:
    std::vector<ISloter*> m_slots;
 
public:
    template<typename T>
    void regest(T* obj, void(T::*fun)(void))
    {
        if (0 == m_slots.size())
        {
            m_slots.push_back(new Sloter<T>(obj, fun));
        }
    }
 
    void doFun()
    {
        if (1 == m_slots.size())
        {
            m_slots[0]->doFun();
        }
    }
};
 
// bind signal and triggered function
#define CONNECT(signalObj, signal, slotObj, slot) (signalObj)->get_##signal().regest(slotObj, slot);

// define signal
#define SIGNAL(signal) \
public: \
    Signal signal_##signal; \
public: \
    Signal& get_##signal() \
    {\
        return signal_##signal;\
    }\
	
// trigger signal
#define EMIT(signal) signal_##signal.doFun();

