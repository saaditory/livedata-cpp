/**
 * Implementation of `liveddata.h` header file.
 * 
 * Created by Saad Khan on Dec 03, 2021.
*/

#include "livedata.h"

#include <string>

template <typename T>
void LiveData<T>::setValue(T newValue)
{
    if (mValue != newValue)
    {
        mValue = newValue;
        if (hasObserver())
            mObserver->onChanged(newValue);
    }
}

template <typename T>
T LiveData<T>::getValue() { return mValue; }

template <typename T>
void LiveData<T>::observe(Observer<T> *obs) { mObserver = obs; }

template <typename T>
bool LiveData<T>::hasObserver() { return (nullptr != mObserver); }

template <typename T>
void LiveData<T>::removeObserver() { mObserver = nullptr; }

template <typename T>
LiveData<T>::LiveData() : mObserver(nullptr) {}

template <typename T>
LiveData<T>::LiveData(T value) : mValue(value), mObserver(nullptr) {}

TEMPLATE(int)
TEMPLATE(char)
TEMPLATE(bool)
TEMPLATE(float)
TEMPLATE(double)
TEMPLATE(std::string)
