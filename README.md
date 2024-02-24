# Modern C++ #
*Discusses some of the new features of C++ 11 and existing too*
## Language Features ##

$${\color{red}Welcome \space \color{lightblue}To \space \color{orange}Stackoverflow}$$

$${\color{red} ### auto }$$
The auto keyword is remnant of C that was used to declare local variable in a function. In C++ it has a different meaning and is used to assign a data type based on initialized value. 

### char16 and char32
char16_t  and char32_t  were introduced to provide uniformity among other things. The size of char16_t data type is fixed at 16 bits across all the platforms.
Similarly, the size of char32_t data type is fixed at 32 bits across all the platforms. 
The shorthand for char16_t is u, char32_t is U.
### constexpr
The keyword constexpr means constant expression. Like const, it can be applied to variables: A compiler error is raised when any code attempts to modify the value. Unlike const, constexpr can also be applied to functions and class constructors. constexpr indicates that the value, or return value, is constant and, where possible, is computed at compile time.
### decltype
decltype is reverse of auto where a data type can be deduced from a variable or an expression. decltype can also be used specify return types in template functions.
### declval
It's a template function for type T.It returns an rvalue reference to type T without referring to any object, making it possible to use member functions in the operand of the decltype specifier without the need to go through constructors. T may be an incomplete type.
### lambda expression
Lambdas are basically anonymous function objects generated right at the location where it's invoked or passed as an argument to a function. Lambdas are game changer since they seamlessly integrate into stl algorithms, concurrency objects and more. 
### list initialization
list initialization enables uniform way of initializing scalar and complex objects such as ints, doubles, structs, classes using a pair of braces {}. 
### long long
The size of long is not consistent across platforms. In linux,  it's 64 bits and in Windows it's 32 bits.The new data type long long is a 64 bits across all the platforms. The short form long long is ll or LL.
### move semantics
move semantics takes advantage of  the new rvalue reference to optimize temporary object creation. In order to use move semantics, classes are expected to support rvalue copy constructor and rvalue assignment operator. In these functions, expensive resources such as heap memory are stripped off the source object and assigned to the target object instead of reallocation. After move operation, source object may not be used. 
The move operation itself involves just changing the lavalue type to rvalue type.
### noexcept
noexcept specifier determines whether a function could throw exceptions. 
### nullptr
NULL is defined as macro, represented as an integer of value 0. However it's misused to represent null pointers as shown below.
### numeric limits
numeric_limits is a template class that defines functions such as min(), max() along with host of other functions that are related to arithmetic types. Specialized classes from numeric_limits are defined for fundamental arithmetic types such as int, double. These methods in these classes can be used instead of  of macros. For example, numeric_limits<int>::max() can be used in place INT_MAX. These classes can be queried for minimum, maximum values and other properties such as number of digits, signed etc. 
### perfect forwarding
The rvalue semantics enable passing the arguments without ambiguity  to the handler function in the factory method.
### range for loop
*for* loops are versatile can be used in various scenarios. When used in conjunction with containers vector, list, map  etc or memory arrays, it provides only indexing using either iterators or integers. To access the underlying data structure inside these containers or arrays, an explicit temporary variable needs to be created. Also the range should be explicitly mentioned. C++11 introduces a new form of *for* loop, which iterates over all elements of a given range, array,
or collection. 
### raw string
Assigning a free flowing text to a string variable has been a challenge especially if it contains " character embedded in it. Escaping special characters  and adding newline characters can be tedious and reduces readability of the text.  
The raw string feature enables declaring strings containing special characters such as newline, tab etc as is without escaping.
### rvalue reference
When using STL containers such as lists, vectors, maps, a lot of temporary objects are created and destroyed during the life time of an application. 
To overcome this, rvalue reference and move semantics are introduced.
An rvalue reference behaves just like an lvalue reference except that it can bind to a temporary (an rvalue), whereas you can not bind a (non const) lvalue reference to an rvalue.
### string literals
string literals prefixed with u8 are encoded as UTF-8. The difference between a C string and u8 string is that way they are encoded which can vary based on platforms.  
Similarly string literals prefixed with u are encoded as UTF-16 and literals prefixed with U are encoded as UTF-32.
### type traits
type_traits were introduced in C++11, basically defines templates for compile-time constants that give information about the properties of their type arguments, or produce transformed types. The classes and templates in type_traits are used to support type inference, classification, and transformation at compile time.
### variadic template
With the variadic templates feature, it's possible to define template based class or function that can have any number (including zero) of parameters. 
To accomplish this, a new kind of parameter called parameter pack is introduced that can singly represent a list of zero or more parameters in the templates definition. A template class or function with at least one parameter pack is called a variadic template.
## Library Features ##

### chrono library

### concurrency
 
### exceptions
 
### io stream
 
### localization
 
### ratio library
 
### regular expressions
 
### smart pointer
 
### numeric limits
 
### type traits
 
### basic_string

## Algorithms

### Partitions

### Binary Search

### Min/Max

### Numerical

### Lexicographical

### Heap

### Merge

### Sort

### Modifying

### Non modifying




