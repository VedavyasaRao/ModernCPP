# Modern C++ #

## Language Features ##

### auto
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
It returns an rvalue reference to type T without referring to any object, making it possible to use member functions in the operand of the decltype specifier without the need to go through constructors. T may be an incomplete type.
### lambda expression
 
### list initialization
 
### long long
 
### move semantics
 
### noexcept
 
### nullptr
 
### numeric limits
 
### perfect forwarding
 
### range for loop
 
### raw string
 
### rvalue reference
 
### string literals
 
### type traits
 
### variadic template

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




