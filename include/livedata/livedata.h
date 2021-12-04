/**
 * Main header file of the library.
 * 
 * Created by Saad Khan on Dec 03, 2021.
*/

#ifndef LIVEDATA_H
#define LIVEDATA_H

#define TEMPLATE(T)                                    \
    template void Observer<T>::onChanged(T);           \
    template void LiveData<T>::setValue(T);            \
    template T LiveData<T>::getValue();                \
    template void LiveData<T>::observe(Observer<T> *); \
    template bool LiveData<T>::hasObserver();          \
    template void LiveData<T>::removeObserver();       \
    template LiveData<T>::LiveData();                  \
    template LiveData<T>::LiveData(T value);

template <typename T>
class Observer
{
public:
    virtual void onChanged(T) {} // Meant to be overloaded
};

template <typename T>
class LiveData
{
private:
    T mValue;
    Observer<T> *mObserver;

public:
    void setValue(T);
    T getValue();

    void observe(Observer<T> *);
    bool hasObserver();
    void removeObserver();

    LiveData();
    LiveData(T value);
};

#endif
