/**
 * Main header file of the library.
 * 
 * Created by Saad Khan on Dec 03, 2021.
*/

#ifndef LIVEDATA_H
#define LIVEDATA_H

#include <vector>

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
    std::vector<Observer<T> *> mObservers;

public:
    void setValue(T);
    T getValue();

    void observe(Observer<T> *);
    bool hasObservers();
    void removeObserver(Observer<T> *);
    void removeObservers();

    LiveData();
    LiveData(T);
};

template <typename T>
inline void LiveData<T>::setValue(T newValue)
{
    if (mValue != newValue)
    {
        mValue = newValue;
        if (hasObservers())
            for (auto &&observer : mObservers)
                observer->onChanged(newValue);
    }
}

template <typename T>
inline T LiveData<T>::getValue() { return mValue; }

template <typename T>
inline void LiveData<T>::observe(Observer<T> *observer) { mObservers.push_back(observer); }

template <typename T>
inline bool LiveData<T>::hasObservers() { return !mObservers.empty(); }

template <typename T>
inline void LiveData<T>::removeObserver(Observer<T> *observer)
{
    for (auto iterator = mObservers.begin(); iterator != mObservers.end(); ++iterator)
        if (*iterator == observer)
            mObservers.erase(iterator--);
}

template <typename T>
inline void LiveData<T>::removeObservers() { mObservers.clear(); }

template <typename T>
inline LiveData<T>::LiveData() {}

template <typename T>
inline LiveData<T>::LiveData(T value) : mValue(value){};

#endif
