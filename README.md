# LiveData for C++

LiveData is an observable data holder class written in C++. The data inside a LiveData instance can be observed anytime for new changes. It provides a function callback when the data inside the LiveData changes.

This library is similar to Android's LiveData implementation.

## Supported Data Types:
Supported data types include `int`, `char`, `bool`, `float`, `double` and `string`.

## Usage:
Create an instance of the `LiveData` using:

```
LiveData<T> ld;
```

OR

```
LiveData<T> ld(value);
```

Where `T` can be any supported data type and `value` is the default value of the LiveData. Replace `T` and `value` with the required data type and its default value respectively.

To listen for the changes to the value of LiveData, first, we create our observer by extending from the `Observer` class, provided by this library, as follows:

```
class LdObserver : public Observer<T>
{
public:
     void onChanged(T newValue)
     {
          std::cout << "LiveData value has been updated to " << newValue;
     }
};
```

The `onChanged()` function gets called whenever the value of LiveData updates.

Now, we can set an observer to listen for the changes in the value of LiveData.

```
LdObserver *ldo = new LdObserver;

ld.observe(ldo);
```

After that, we can use setter and getter functions to set and get the value of LiveData. 

```
ld.setValue(newValue);

T newValue = ld.getValue();
```

Here `newValue` is the updated value.

Upon setting a new value to the LiveData, it provides a callback with the updated value using the `onChanged()` function call and the code inside the `onChanged()` function gets executed.
