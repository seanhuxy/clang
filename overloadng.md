## C++ Overloading increment and decrement operators

- prefix ++/--: increase/decrease first, then return the value;
- postfix ++/--: return first, then increase/decrease the value;

1.	postfix version: dummy int parameter

```c++
// prefix version
T& operator++()	// return by reference
{
	++m_value;
	return *this;
}

// postfix version
T operator++(int)	// return by value
{
	// create a tmep variable to return
	T temp(m_value);
	
	// increment this
	++(*this);
	
	return temp;
}
```