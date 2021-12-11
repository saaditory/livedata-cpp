/**
 * Main header file of the library.
 * 
 * Created by Saad Khan on Dec 03, 2021.
*/

#ifndef LIVEDATA_H
#define LIVEDATA_H

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
    LiveData(T);
};

template <typename T>
inline void LiveData<T>::setValue(T newValue)
{
    if (mValue != newValue)
    {
        mValue = newValue;
        if (hasObserver())
            mObserver->onChanged(newValue);
    }
}

template <typename T>
inline T LiveData<T>::getValue() { return mValue; }

template <typename T>
inline void LiveData<T>::observe(Observer<T> *obs) { mObserver = obs; }

template <typename T>
inline bool LiveData<T>::hasObserver() { return (nullptr != mObserver); }

template <typename T>
inline void LiveData<T>::removeObserver() { mObserver = nullptr; }

template <typename T>
inline LiveData<T>::LiveData() : mObserver(nullptr) {}

template <typename T>
inline LiveData<T>::LiveData(T value) : mValue(value), mObserver(nullptr){};

#endif
