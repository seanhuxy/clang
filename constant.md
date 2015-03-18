# Constant Pointer
is a pointer that can't change the address it's holding

```
T * const ptr;	

int a = 0, b = 1;
int * const ptr = &a;
ptr = &b;	// error!!
```

# Pointer to Constant

is a pointer that pointer to constant variable

```
const T * ptr;
T const * ptr;	// identical
int main(){
    int a = 1, b =2;
    const int * ptr;

    ptr = &a;
    ptr = &b;

    *ptr = 20;  // error!

    cout<<*ptr;
}
```

# const_cast
is used to cast away the constness of variables.

- can be used to change non-const-class members inside a const member function.

```
class student
{
private:
	int roll;
public:
	student(int r) ...
	
	// change non-constant class member inside a const
	// member function
	void fun() const
	{
		( const_cast<student*>(this) )->roll = 5;
	}
}
```

- can be used to pass **const data** to a function that **doesn't receive const parameter**

```
int fun(int* ptr) // non-const parameter
{
	return (*ptr+10);
}

int main()
{
	const int val = 10;
	const int * const_ptr = &val;
	int * ptr = const_cast<int*>(const_ptr);
	fun(ptr);
	return 0;
}
```

- const_cast can't modify a value which is initially declared as const:

```
int fun(int* ptr)
{
    *ptr = *ptr + 10;	//modifying a value which is
    						// initially const;
    return (*ptr);
}
 
int main(void)
{
    const int val = 10;
    const int *ptr = &val;
    int *ptr1 = const_cast <int *>(ptr);
    fun(ptr1);
    cout << val;
    return 0;
}
```

Output:
```
Undefined Behavior
```

- can't do type casting, but only change constness

# const_iterator
returns a reference to a constant value ( const T & )

