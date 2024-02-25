# Modern C++ #
*Discusses some of the regular and C++ 11 features*
## Language Features ##

### auto
The auto keyword is remnant of C that was used to declare local variable in a function. In C++ it has a different meaning and is used to assign a data type based on initialized value.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/auto.html).
### char16_t and char32_t
char16_t  and char32_t  were introduced to provide uniformity among other things. The size of char16_t data type is fixed at 16 bits and the size of char32_t data type is fixed at 32 bits across all the platforms. char16_t is used for UTF-16 encoding and   char32_t is used for UTF-32 encoding.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/char16t-and-char32t.html).
### constexpr
The keyword constexpr means constant expression. Like const, it can be applied to variable. Also, unlike const, constexpr can also be applied to functions and class constructors. constexpr indicates variable value, or return value, which is constant and, where possible, is computed at compile time.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/constexpr.html).
### decltype
decltype is reverse of auto where a data type can be deduced from a variable or an expression. decltype can also be used specify return types in template functions.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/auto.html).
### declval
It's a template function for type T.It returns an rvalue reference to type T without referring to any object, making it possible to use member functions in the operand of the decltype specifier without the need to go through constructors. T may be an incomplete type.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/auto.html).
### lambda expression
Lambdas are basically anonymous function objects generated right at the location where it's invoked or passed as an argument to a function. Lambdas are game changer since they seamlessly integrate into std lib algorithms, concurrency objects and more.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/lambda.html).
### list initialization
list initialization enables uniform way of initializing arithmetic types such as int, double etc or structs, classes using a pair of braces {}.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/list-initialization.html).
### long long
The size of long is not consistent across platforms. In linux,  it's 64 bits and in Windows it's 32 bits.The new data type long long is a 64 bits across all the platforms.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/char16t-and-char32t.html).
### move semantics
move semantics takes advantage of  the new rvalue reference to optimize temporary object creation and its reuse.   
More details can be found [here](https://modcpp11.blogspot.com/2023/09/move-semantics.html).
### noexcept
noexcept specifier determines whether a function could throw exceptions.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/noexcept.html).
### nullptr
nullptr_t data type is introduced specifically to prevent misuse of NULL in place of null pointers. nullptr is the only instance of this type and can be used in place of a null pointer.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/char16t-and-char32t.html).
### perfect forwarding
The rvalue semantics enable passing the arguments without ambiguity  to the handler function in the factory method.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/move-semantics.html).
### range for loop
*for* loops are versatile can be used in various scenarios. *range based for* loop are designed to work with containers so that their elements for a given range can be iterated directly either by value or a by reference.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/range-based-for-loop.html).
### raw string
Assigning a free flowing text to a string variable has been a challenge especially if it contains *"* character embedded in it. Escaping special characters  and adding newline characters can be tedious and reduces readability of the text.The raw string feature enables declaring strings containing special characters such as newline, tab etc as is without escaping.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/raw-string-literal.html).
### rvalue reference
When using containers such as lists, vectors, maps, a lot of temporary objects are created and destroyed during the life time of an application. 
To overcome this, rvalue reference and move semantics are introduced.  An rvalue reference behaves just like an lvalue reference except that it can bind to a temporary value.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/move-semantics.html).
### string literals
string literals prefixed with u8 are encoded as UTF-8. Similarly string literals prefixed with u are encoded as UTF-16 and literals prefixed with U are encoded as UTF-32.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/char16t-and-char32t.html).
### variadic template
With the variadic templates feature, it's possible to define template based class or function that can have any number (including zero) of parameters. 
To accomplish this, a new kind of parameter called parameter pack is introduced that can singly represent a list of zero or more parameters in the templates definition. A template class or function with at least one parameter pack is called a variadic template.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/variadic-templates.html).
## Library Features ##

### basic_string
CRT provides plethora of functions to handle strings. There are different functions for getting length, append, copy, find etc. 
std::basic_string class attempts to objectify strings so that it's easier to use.  
More details can be found [here](https://modcpp11.blogspot.com/2023/11/string.html).
### chrono library
Chrono library defines a set of Clocks that can represent a Duration or a specific Time Point. These are used by concurrency object APIs (*sleep_for(duration)* and *sleep_until(time_point)*) to pause processing within a thread.  
More details can be found [here](https://modcpp11.blogspot.com/2023/10/chrono-library.html).
### concurrency
C++11 introduces a new memory model and the concurrency library to support multi threaded peogramming.  
More details can be found [here](https://modcpp11.blogspot.com/2023/10/concurrency-quick-tour-with-examples.html).
### exceptions
In C++ 11, a new family of classes were introduced to handle exceptions with *exception* class as its root.  
The derived classes overrides *what()* to return error string. In addition, newer classes such as *error_code* and *error_condition*  were added to return additional error information.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/exception.html).
### io stream
The IOStreams provides classes to perform IO for console, disk and memory as an alternative to CRT functions. In C++11, new classes were introduced to handle currency and time.  
More details can be found [here](https://modcpp11.blogspot.com/2023/11/iostream-classes-quick-tour-with.html).
### localization
Each country has one or more native speaking languages and writing systems or a scripts, numbering symbols, number grouping symbol, decimal point symbol, currency symbols, date format etc. 
The *locale* and *facet* classes provide the support for all these aspects so that it can be integrated into the daily lives of the people, government and businesses etc.  
More details can be found [here](https://modcpp11.blogspot.com/2023/11/internationalization-quick-tour-with.html).
### numeric limits
numeric_limits is a template class that defines functions such as min(), max() along with host of other functions that are related to arithmetic types. Specialized classes from numeric_limits are defined for fundamental arithmetic types such as int, double. These methods in these classes can be used instead of  of macros such as INT_MAX.  
More details can be found [here](https://modcpp11.blogspot.com/2023/10/numeric-limits.html).
### ratio library
standard library defines a new template class *ratio* to define ratios that can be used only during compile time.*ratio* is used in chrono library to represent different time units such as millisecond, hour etc.  
More details can be found [here](https://modcpp11.blogspot.com/2023/10/ratio.html).
### regular expressions
Regular expressions are indispensable when looking for a specific information.
They are highly versatile to filter out information or for validating inputs without needing to write lots of code.  
More details can be found [here](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html).
### smart pointer
CRT does not have garbage collector support therefore  dangling pointers, leaked resources causes instability in applications. Smartpointers are  used to get around this issue. A Smartpointer is basically a RAII (Resource Acquisition Is Initialization) object that wraps a pointer to an object or an array. New classes such as *unique_ptr* for sole ownership, *shared_ptr* for shared ownership and *weak_ptr* for non ownership references.  
More details can be found [here](https://modcpp11.blogspot.com/2023/09/smartpointer.html).
### type traits
type_traits were introduced in C++11, basically defines templates for compile-time constants that give information about the properties of their type arguments, or produce transformed types. The classes and templates in type_traits are used to support type inference, classification, and transformation at compile time.  
More details can be found [here](https://modcpp11.blogspot.com/2024/02/type-traits.html).
## Algorithms

### Binary Search
Binary search algorithms  operate on various types of containers such as sequence, associative and unordered that are sorted to perform actions such as finding upper, lower, equal bounds for a value or its existence.  
More details can be found [here](https://modcpp11.blogspot.com/2023/12/algorithms-binary-search.html).
### Heap
Heap Algorithms  operate on various types of containers such as sequence, associative and unordered to organize the elements of a range that allows for fast retrieval of the element with the highest 
value at any moment (with pop_heap), even repeatedly, while allowing for fast insertion of new elements  (with push_heap).  
More details can be found [here](https://modcpp11.blogspot.com/2023/12/algorithms-heap.html).
### Lexicographical
Lexicographical algorithms  operate on various types of containers such as sequence, associative and unordered to perform lexicographical actions such as comparing elements, generate sequences etc.  
More details can be found [here](https://modcpp11.blogspot.com/2023/12/algorithms-numerics.html).
### Merge
Merge algorithms  operate on various types of containers such as sequence, associative and unordered to perform actions such as merging sorted sequences, set union, intersection and differences.  
More details can be found [here](https://modcpp11.blogspot.com/2023/12/algorithms-search-and-merge.html).
### Min/Max
Min/Max Algorithms  are template based functions that operate on various types of containers such as sequence, associative and unordered to perform actions such as finding the smallest and the largest element.  
More details can be found [here](https://modcpp11.blogspot.com/2023/12/algorithms-minmax.html).
### Modifying
Modifying Algorithms  operate transparently on containers such as lists, vectors, maps, sets, arrays etc.  using a pair of iterators, These are collectively known as sequences. They perform actions such as  replace, remove, copy etc.  
More details can be found [here](https://modcpp11.blogspot.com/2023/11/algorithms-modifying.html).
### Non modifying
Non Modifying Algorithms  operate transparently on containers such as lists, vectors, maps, sets, arrays etc.  using a pair of iterators, These are collectively known as sequences. They perform actions such as search, find, count etc.  
More details can be found [here](https://modcpp11.blogspot.com/2023/11/algorithmsnon-modifying.html).
### Numerical
Numerical algorithms  operate on various types of containers such as sequence, associative and unordered to perform operations on the elements of a range to return a value or a sequence.  
More details can be found [here](https://modcpp11.blogspot.com/2023/12/algorithms-numerical.html).
### Partitions
Partitions are commonly used for searching and sorting. Partitioning algorithms  operate on various types of containers such as sequence, associative and unordered to perform actions such as partition, sort and more.  
More details can be found [here](https://modcpp11.blogspot.com/2023/12/algorithms-partitions_18.html).
### Sort
Sorting Algorithms  operate on various types of containers such as sequence, associative and unordered to perform actions such as sorting.  
More details can be found [here](https://modcpp11.blogspot.com/2023/12/algorithms-partitions.html).
