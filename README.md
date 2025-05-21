# Modern C++ (11-14)#
*Discusses some of the regular and C++ 11 and 14 features*
## TOC ##
|||||
|-|-|-|-|
|[New Language Features➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#new-language-features)|[type traits➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#type-traits)|[Literals and Strings➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#literals-and-strings)|[regular expressions➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#regular-expressions) |
|[localization➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#localization)     | [I/O Streams➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#io-streams)| [Diagnostics➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#diagnostics)|[Containers➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#containers)|
|[iterators➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#iterators)|[Algorithms➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#algorithms)|[General Utilities➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#general-utilities)|[smart pointer➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#smart-pointer)
|[chrono library➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#chrono-library)|[Concurrency:stdLib➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#concurrencystdlib)|[Concurrency:win32➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#concurrencywin32)|[Numerical Library➹](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#numerical-library)|

## <span style='color: blue;'>New Language Features</span> ##
The following discusses some of the new features introduced in C++11 and 14.
### auto
The auto keyword is remnant of C that was used to declare local variable in a function. In C++ it has a different meaning and is used to assign a data type based on initialized value.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/new-language-support.html#auto).    
[TOC #↑#](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### decltype
decltype is reverse of auto where a data type can be deduced from a variable or an expression. decltype can also be used specify return types in template functions.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/new-language-support.html#decltype).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### declval
It's a template function for type T.It returns an rvalue reference to type T without referring to any object, making it possible to use member functions in the operand of the decltype specifier without the need to go through constructors. T may be an incomplete type.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/new-language-support.html#declval).    
[TOC ↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### long long
The size of long is not consistent across platforms. In linux,  it's 64 bits and in Windows it's 32 bits.The new data type long long is a 64 bits across all the platforms.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/numerical-library.html#long_long).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### nullptr_t
nullptr_t data type is introduced specifically to prevent misuse of NULL in place of null pointers. nullptr is the only instance of this type and can be used in place of a null pointer.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/smartpointers.html#nullptr).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### char16_t and char32_t
char16_t  and char32_t  were introduced to provide uniformity among other things. The size of char16_t data type is fixed at 16 bits and the size of char32_t data type is fixed at 32 bits across all the platforms. char16_t is used for UTF-16 encoding and   char32_t is used for UTF-32 encoding.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/strings-and-literals.html#char16_t).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### constexpr
The keyword constexpr means constant expression. Like const, it can be applied to variable. Also, unlike const, constexpr can also be applied to functions and class constructors. constexpr indicates variable value, or return value, which is constant and, where possible, is computed at compile time.  
More details can be found [here➹](https://modcpp11.blogspot.com/2023/09/constexpr.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### =default
=default
In  C++ 11, a class can define following special member functions.
- default constructor
- copy constructor
- copy assignment operator
- destructor
- move constructor
- move assignment operator 
If it's missing, the compiler conditionally generates some of these functions.
Sometimes it's desirable to explicitly generate these functions, when it's not generated by the compiler  using keyword =default.  
More details can be found [here➹](https://modcpp11.blogspot.com/2024/05/defaut-and-delete.html#=default).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### =delete
It's also possible to suppress conditional generation of these functions by using keyword =delete.  
More details can be found [here➹](https://modcpp11.blogspot.com/2024/05/defaut-and-delete.html#=delete).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### initializer_list
The C++11 standard library introduced a new template based type initializer_list <T> to handle variable-length {}-lists. initializer_list is used to aid uniform initialization. It's automatically created when braces {} are used to initialize.  
More details can be found [here➹](https://modcpp11.blogspot.com/2023/09/list-initialization.html#initializer_list).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### list initialization
list initialization enables uniform way of initializing using a pair of braces {}. Arithmetic types such as int, double etc are implicitly initialized. When used with structs or classes the compiler generates code to call appropriate constructor.  
More details can be found [here➹](https://modcpp11.blogspot.com/2023/09/list-initialization.html#list_initialization).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### rvalue reference
When using containers such as lists, vectors, maps, a lot of temporary objects are created and destroyed during the life time of an application. 
To overcome this, rvalue reference and move semantics are introduced.  An rvalue reference behaves just like an lvalue reference except that it can bind to a temporary value.    
More details can be found [here➹](https://modcpp11.blogspot.com/2023/09/move-semantics.html#rvalue).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### move
move semantics takes advantage of  the new rvalue reference to optimize temporary object creation and its reuse.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/09/move-semantics.html#move).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### perfect forwarding
The rvalue semantics enable passing the arguments without ambiguity  to the handler function in the factory method.  
More details can be found [here➹](https://modcpp11.blogspot.com/2023/09/move-semantics.html#Perfect).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Universal reference
Before C++11, universal reference was used to bind to both rvalue and lvalue. An universal reference is formed by making const reference of some type.  
More details can be found [here➹](https://modcpp11.blogspot.com/2023/09/move-semantics.html#universal).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### namespace
In large projects, multiple classes can share same name, which can lead to compilation errors and confusion. namespace can be used to modularise them in separately to avoid overlapping.   
More details can be found [here➹](https://modcpp11.blogspot.com/2024/07/namespaces-and-using.html#namespace).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### using
typedefs are commonly used provide an alias to a type. However it has some limitations when used in templates. In C++ 11, using keyword is introduced to overcome these limitations also extend its functionality.  
More details can be found [here➹](https://modcpp11.blogspot.com/2024/07/namespaces-and-using.html#using).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### noexcept
noexcept specifier determines whether a function could throw exceptions. This enables  optimizations such as overheads related to stack unwinding.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/new-language-support.html#noexcept).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### override
In a multi class hierarchy, virtual functions enable overriding base class functionality by derived classes. However sometimes it can be confusing and often mistakes can happen in a large project if the signatures don't match in the derived classes. The suffix override is designed to overcome this.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/new-language-support.html#override).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### final
Sometimes it's desirable to prevent overriding a virtual function or derivation from a class itself. The suffix final is designed to handle it.
final keyword indicates compiler that a virtual function of a base class cannot be overridden. in derived classes.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/new-language-support.html#final).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### range for loop
*for* loops are versatile can be used in various scenarios. *range based for* loop are designed to work with containers so that their elements for a given range can be iterated directly either by value or a by reference.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/new-language-support.html#range).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### static_assert
Macros such as assert() can be used in debug builds to check for errors during runtime to break when an error condition becomes true.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/new-language-support.html#static_assert).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### variadic template
With the variadic templates feature, it's possible to define template based class or function that can have any number (including zero) of parameters. 
To accomplish this, a new kind of parameter called parameter pack is introduced that can singly represent a list of zero or more parameters in the templates definition. A template class or function with at least one parameter pack is called a variadic template.    
More details can be found [here➹](https://modcpp11.blogspot.com/2023/09/variadic-templates.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>type traits</span> ##
type_traits were introduced in C++11, basically defines templates for compile-time constants that give information about the properties of their type arguments, or produce transformed types. The classes and templates in type_traits are used to support type inference, classification, and transformation at compile time.  
### Utility classes
type traits classes internally uses a number of utility classes  such as integral_constant in its implementation.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/type-traits.html#Utility).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Unary type traits
Unary Type Traits describe a property of a single type. Most Unary Type Traits return true or false and are derived from true_type or false_type.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/type-traits.html#Unary).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Binary Type Traits
Binary Type Traits provide information about a relationship between two types. Every Binary Type Trait return  true_type  or false_type. based on the presence or absence of a specific relationship between the two argument types.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/type-traits.html#Binary).
### Transformation Type Traits
Transformation Type Traits modify a type. Every Transformation Type Trait possesses a nested typedef named type that represents the result of the modification.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/type-traits.html#Transformation).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Memory Allocation
Allocate uninitialized memory of POD type.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/type-traits.html#Memory).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>Literals and Strings</span> ##
strings and literals are essential part of any programming language. The following describes various facilities and classes available to handle strings and literals.   
### char_traits
char_traits classes define common behavior such as comparison, assignment, copy etc. and also other aspects such as eof  type, offset type position type etc.   
More details can be found [here➹](https://modcpp11.blogspot.com/2024/11/chartraits.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### char16_t and char32_t
char16_t  and char32_t  were introduced to provide uniformity among other things. The size of char16_t data type is fixed at 16 bits and the size of char32_t data type is fixed at 32 bits across all the platforms. char16_t is used for UTF-16 encoding and   char32_t is used for UTF-32 encoding.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/strings-and-literals.html#char16_t).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Unicode String Literals
string literals prefixed with u8 are encoded as UTF-8. Similarly, prefix for UTF-32 encoded strings is U. char_32_t is used for encoding UTF-32 strings.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/strings-and-literals.html#Unicode).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### raw string
Assigning a free flowing text to a string variable has been a challenge especially if it contains " character embedded in it.The raw string feature enables declaring strings containing special characters such as newline, tab etc as is without escaping.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/strings-and-literals.html#raw).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### user defined literals
In  C++, arithmetic types such as long, float can be represented with suffix as 1L,1.2f etc. C++11 extends this to represent standard library and user defined types using user defined literals.  
More details can be found [here➹](https://modcpp11.blogspot.com/p/strings-and-literals.html#user).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### basic_string
CRT provides plethora of functions to handle strings. There are different functions for getting length, append, copy, find etc.   
std::basic_string class attempts to objectify strings so that it's easier to use.  
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/string.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>regular expressions</span> ##
Regular expressions are indispensable when looking for a specific information.  
They are highly versatile to filter out information or for validating inputs without needing to write lots of code.  
### Validation
Regular expressions can be used to validate an input.    
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Validation).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Extraction
Regular expressions can be used to extract information from the input strings.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Extraction).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Dot character
Patterns can use . to map any character except some control characters. Note that it has no effect in a character class construct and maps to decimal point.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Dot).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Character class
The basic ingredient of the regular expression grammar is a character class.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Character).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Shorthands
To reduce clutter, shorthands to character classes are provided. These can be freely used in another character class or even in pattern.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Predefined).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Escaping
Some times a meta character needs to be escaped in a pattern or a character class. Escaping is done by placing \  in front of the meta character.    
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Escaping).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Anchors and boundary markers
Anchors and  boundary markers marks special locations such as beginning or ending of the lines, word boundaries etc. These can be used only in the pattern and not in character classes.  
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Anchors).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Quantifiers
Quantifiers determine  repetitiveness of a token in the pattern. Quantifiers applies to any token in the pattern only.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Quantifiers).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Greedy, Lazy and Possessive Quantifiers
Produces different results for the same patteren with different Quantifiers.  
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Greedy).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Capture groups
The capture groups are one of the key aspects of the regular expression.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Capture).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Non capturing groups
Non capturing groups are used for efficiency and optimization. As the name indicates, contents of non capturing groups are discarded.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Capture2).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### References
The captured groups in a pattern are internally labeled as \1, \2 , \3 etc.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#References).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Unicode support
The behavior of the regular expression engine can be changed by setting flags in the pattern.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Unicode).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Branch Reset Groups
Consider a pattern (1a)|(2a)|(1b)\1. This defines three capture groups. For the input 1a1a, it is expected to match, however it does not.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Branch).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### LookAround
There are 4 types look around, positive/negative look ahead/behind. Collectively they are called lookaround, are zero-length assertions just like the start and end of line, or start and end of word anchors.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#LookAround).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### LookBehind with \K
Due to certain restriction in matching expression of positive lookbehind i.e., <=expression,  as an alternative to positive lookbehind, \K switch can be used.    
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#LookBehind).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Atomic Grouping
An atomic group is a group that, when the regex engine exits from it, automatically throws away all backtracking positions remembered by any tokens inside the group.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Atomic).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### If-Then-Else Conditionals
If-Then-Else is a special construct allows creation of conditional regular expressions.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#If).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Recursion
Suppose the task is to find out if random number of open and close braces such as () or {} match, regular expression recursion comes to the rescue.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Recursion).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Subroutines
Subroutines are applied to the capture groups. These are very similar to regular expression recursion. Instead of matching the entire regular expression again, a subroutine call only matches the regular expression inside a capturing group. A subroutine call can be made to any capturing group from anywhere in the pattern. A call made to same capturing group leads to recursion.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Subroutines).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Using Regular expressions in C++
It's possible to replace  captured groups or entire match. Regular expressions is a part of in C++ 11 standard library,  however it does not support many features discussed here. An alternate would be to use boost libraries which seems compatible with feature rich  perl.   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/regular-expression-quick-tour-with_6.html#Using).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>localization</span> ##
Each country has one or more native speaking languages and writing systems or a scripts, numbering symbols, number grouping symbol, decimal point symbol, currency symbols, date format etc.   
The *locale* and *facet* classes provide the support for all these aspects so that it can be integrated into the daily lives of the people, government and businesses etc.  
### Character Set
A Character Set is a set of characters identifying a particular writing system of a particular region.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/localization.html#Character_Set).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Encoding
Character encoding is the process of assigning numbers to the characters of the character set, allowing them to be stored, transmitted, and transformed using digital computers so that they can be reinterpreted back correctly.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/01/encoding.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### codepages
A code page is basically a coded character set. The term code page initially referred to the page number of IBM standard character set manual containing character mapping for plethora of character sets.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/localization.html#codepages).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Localization
Internationalization is the process of designing and developing software or applications to be accessible and adaptable to different languages, cultures, and regions. Localization is the process of adapting software or applications to meet the language, cultural, and other requirements of a specific target market or locale.    
While internationalization creates a framework that supports multiple languages and regions, localization involves customizing the software or application for a specific target market or region.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/localization.html#Localization).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Locales
A locale is a collection of information pertaining to a culture, region, and language. Locales are physically stored in external files in POSIX environments. In Windows, they are located in the registry.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/localization.html#Locales).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Locales in C
In C, locales can be set using setlocale() api.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/localization.html#Locales_C).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### locale class
In C++, a locales are represented by a locale object, which  is a collection of indexed facets. It also contains a basic_regex object.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/01/locale.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Facets
facets are defined for each category.  It's possible to override default behavior of a fact.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/localization.html#Facets).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Character classification and conversion
CRT provides set of functions to classify characters and changes their cases to  upper or lower. Standard library also provides template based functions to provide the same facility.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/02/character-classification-and-conversion.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Unicode Conversion Facets
Performs  convertion of Unicode based formats with each other. For example, conversion from UTF-8 to UCS-2, UTF-16 and UTF-32. Also reverse.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/localization.html#Unicode_Conversion).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### String and stream conversions
Performs conversions between wide strings and byte strings (on either direction) using a conversion object of type.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/localization.html#stream_conversions).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>I/O Streams</span> ##
The CRT provides  printf() variants to emit formatted output of data such as integers, boolean, strings etc. on different targets such as console, character buffers, files.    
Similarly, CRT also provides  scanf() variants to extract input from console, character buffers, files for data such as integers, boolean, strings etc   
### Class Structure
All the IO Stream classes are derived from ios_base.  The diagram represents classes that start with the letter w are defined for whcar_t and other classes are defined for char. char16_t and char32_t are not supported.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/io-and-locales.html#Structure).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Class Organization
The classes can be grouped into following categories - Primitive base, Intermediate base , disk based  streams and String based streams.   
More details can be found [here➹](https://modcpp11.blogspot.com/2025/01/class-organization.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Primitive Base classes
The primitive base classes can be categorized as Input and Output Preparation classes and Serialization classes. These also defines classes for console I/O stream objects.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/io-and-locales.html#Primitive).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### IO Stream extraction and insertion operators and Manipulators
istreams defines extraction operators that are basically overloaded operator >>() functions to extract values from the inputs. Similarly, ostreams defines insertion operators that are basically overloaded operator<<() functions to insert values into the output.   
Manipulators are helper functions that prepare the input/output streams before using operator << or operator >>.   
More details can be found [here➹](https://modcpp11.blogspot.com/2024/12/input-output-manipulators.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### FileSystem based Streams
These provides classes that can be used  for Disk I/O. The can be Input only, Output only or Both.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/io-and-locales.html#Disk).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Memory based streams
These provides stream classes that can be used with strings in memory. These can be Input only, Output only or Both.   
Classes that does input only are derived from basic_istream. Similarly classes that does output only are derived from basic_ostream. Classes that do both input and output are derived from basic_iostream class.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/io-and-locales.html#String).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Stream iterators
stream iterators istream_iterator and ostream_iterator can be used for typed input and output. They are faster as they skip construction of sentry objects.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/io-and-locales.html#iterators).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Streambuf iterators
streambuf defines input iterator and output iterator for unformatted input and output. istreambuf_iterator and ostreambuf_iterator can be used instead of raw i/o apis.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/io-and-locales.html#Streambuf_iterators).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>Diagnostics</span> ##
The CRT provides  printf() variants to emit formatted output of data such as integers, boolean, strings etc. on different targets such as console, character buffers, files.   
Similarly, CRT also provides  scanf() variants to extract input from console, character buffers, files for data such as integers, boolean, strings etc   
### exception class
In C++ 11, a new family of classes were introduced to handle exceptions with exception class as its root.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/diagnostics.html#exception).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Standard Library Exception hierarchy
The hierarchy of exceptions can be grouped into three categories. User applications can also throw them.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/diagnostics.html#Standard).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Standard Library Exception Categories
This discusses various standard library exceptions with examples.   
More details can be found [here➹](https://modcpp11.blogspot.com/2024/12/standard-library-exceptions.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Advanced Exception Handling
This discusses how to handle an exception, nested exceptions, uncaught and unexpected exceptions, termination. Also setting exception and termination handlers.   
More details can be found [here➹](https://modcpp11.blogspot.com/2024/12/exceptionptr.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Handling Exception Failures
When an exception is unhandled, it leads to termination of the application. The following discusses setting up custom handlers that's called before before termination.   
More details can be found [here➹](https://modcpp11.blogspot.com/2024/12/handling-exception-failures.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### System Errors
System error numbers are different in different platforms. e.g., file system errors.  In C++11,  a new exception class system_error along with helper classes - error_category,  error_code, error_condition    
were introduced to the diagnostic infrastructure to bring uniformity and develop cross platform applications.   
More details can be found [here➹](https://modcpp11.blogspot.com/2024/12/system-errors.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Predefined System error enumerations
The standard library provides predefined enumeration classes to define error conditions for these categories: generic_category, iostream_category and future_categoty.   
More details can be found [here➹](https://modcpp11.blogspot.com/2024/12/predefined-system-error-enumarations.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>Containers</span> ##
STL provides a host of template based containers serving as arrays and lookups to store and retrieve any data type.   
### sequence containers
These containers  store data sequentially using different mechanisms.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/algorithms_22.html#sequence).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### container adapters
Container adapters provide specialized functionality and are based on a sequence container.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/algorithms_22.html#adapters).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### associative containers
These are basically lookup tables that store key value pairs. They can be classified into two categories - ordered and unordered.  The ordered category containers are implemented using balanced binary trees whereas the the unordered category containers are implemented using hash tables.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/algorithms_22.html#associative).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### emplacement functions
STL containers such as vector, list, map to provide pushxxx and insert functions to add new elements. Most of these functions end up creating a temporary object of the type T of the container. In C++ 11,  a new emplace functions were that would accept added to directly construct the object of type T in the container.    
More details can be found [here➹](https://modcpp11.blogspot.com/2024/05/emplacement-functions.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>iterators</span> ##
STL provides a host of template based iterators that act as glue between containers and algorithms.   
### Operation
An iterator basically wraps a range of elements from a STL container or even an array. It's analogues to a smartpointer.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/iterators.html#Operation).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### overloaded operators
iterator uses overloaded operators to provide functionality.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/iterators.html#overloaded).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Iterator Classification
Iterators can be broadly classified into 5 categories based on their behaviour.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/iterators.html#Classification).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### iterator traits
For every iterator type, a corresponding specialization of iterator_traits class is  defined, with a minimum set of member types.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/iterators.html#iterator_traits).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### iterator apis
iterator apis generate iterators and enable manipulating iterators to change positions.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/iterators.html#iterator_apis).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### predefined iterator adaptors 
Iterator adaptors are a separate type of iterators with special behavior. They simplify the work with containers and are very useful in standard algorithms.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/iterators.html#iterator_adaptors).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### predefined stream iterators
input and output iterators for stream and streambuf are predefined.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/iterators.html#stream_iterators).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### uninitialized_memory
output iterators for uninitialized_memory is  predefined.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/iterators.html#uninitialized_memory).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>Algorithms</span>
The standard library template based algorithms to process containers using iterators for a variety of purposes (e.g. searching, sorting, counting, manipulating) that operate on ranges of elements.    
### Complexity Analysis
Asymptotic Notation is used to describe the represent time complexity of an algorithm where it represents time taken to execute the algorithm for a given input, n.    
More details can be found [here➹](https://modcpp11.blogspot.com/2024/11/complexity-analysis.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Binary Search
Binary search algorithms  operate on various types of containers such as sequence, associative and unordered that are sorted to perform actions such as finding upper, lower, equal bounds for a value or its existence.     
More details can be found [here➹](https://modcpp11.blogspot.com/2023/12/algorithms-binary-search.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Heap
Heap Algorithms  operate on various types of containers such as sequence, associative and unordered to organize the elements of a range that allows for fast retrieval of the element with the highest    
value at any moment (with pop_heap), even repeatedly, while allowing for fast insertion of new elements  (with push_heap).    
More details can be found [here➹](https://modcpp11.blogspot.com/2023/12/algorithms-heap.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Lexicographical
Lexicographical algorithms  operate on various types of containers such as sequence, associative and unordered to perform lexicographical actions such as comparing elements, generate sequences etc.    
More details can be found [here➹](https://modcpp11.blogspot.com/2023/12/algorithms-numerics.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Merge
Merge algorithms  operate on various types of containers such as sequence, associative and unordered to perform actions such as merging sorted sequences, set union, intersection and differences.    
More details can be found [here➹](https://modcpp11.blogspot.com/2023/12/algorithms-search-and-merge.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Min/Max
Min/Max Algorithms  are template based functions that operate on various types of containers such as sequence, associative and unordered to perform actions such as finding the smallest and the largest element.     
More details can be found [here➹](https://modcpp11.blogspot.com/2023/12/algorithms-minmax.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Modifying
Modifying Algorithms  operate transparently on containers such as lists, vectors, maps, sets, arrays etc.  using a pair of iterators, These are collectively known as sequences. They perform actions such as  replace, remove, copy etc.     
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/algorithms-modifying.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Non modifying
Non Modifying Algorithms  operate transparently on containers such as lists, vectors, maps, sets, arrays etc.  using a pair of iterators, These are collectively known as sequences. They perform actions such as search, find, count etc.     
More details can be found [here➹](https://modcpp11.blogspot.com/2023/11/algorithmsnon-modifying.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Numerical
Numerical algorithms  operate on various types of containers such as sequence, associative and unordered to perform operations on the elements of a range to return a value or a sequence.     
More details can be found [here➹](https://modcpp11.blogspot.com/2023/12/algorithms-numerical.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Partitions
Partitions are commonly used for searching and sorting. Partitioning algorithms  operate on various types of containers such as sequence, associative and unordered to perform actions such as partition, sort and more.    
More details can be found [here➹](https://modcpp11.blogspot.com/2023/12/algorithms-partitions_18.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Sort
Sorting Algorithms  operate on various types of containers such as sequence, associative and unordered to perform actions such as sorting.    
More details can be found [here➹](https://modcpp11.blogspot.com/2023/12/algorithms-partitions.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### uninitialized memory
uninitialized memory algorithms enable populating objects in uninitialized memory. They construct the objects in-place, This allows to obtain fully constructed copies of the elements into a range of uninitialized memory, such as a memory block obtained by a call to malloc.   
More details can be found [here➹](https://modcpp11.blogspot.com/2024/10/unintialized-memory.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>General Utilities</span>
Function Objects or Functors are widely used in std library and serve in various modes such as passing ref objects, wrapping up function objects, accessing member functions etc.   
### Functors
A functor is an object or structure that can be called like a function by overloading the function call operator () . Functors also wrap a state during construction which can be used in function calls.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/general-utilities.html#Functors).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### lambda expression
A functor or function objects is an object or structure that can be called like a function by overloading the function call.    
More details can be found [here➹](https://modcpp11.blogspot.com/2024/12/lambda-expression.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### predefined function objects
Predefined function objects are defined in the std. library to perform bitwise, relational, logical and arithmetic operations.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/general-utilities.html#Predefined).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### function and class member pointers
function pointers are pointers to functions that can be defined as variables. function pointer can be defined for "C" type free functions.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/general-utilities.html#functionptr).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### reference_wrapper
reference_wrapper is a class template that creates a wrapper around a reference to object or reference to function of type T.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/02/referencewrapper.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### ref and cref
Function templates ref and cref are helper functions that generate an object of type reference_wrapper, using template argument deduction to determine the template argument of the result.    
More details about ref can be found [here➹](https://modcpp11.blogspot.com/2025/02/referencewrapper.html#ref).   
More details about cref can be found [here➹](https://modcpp11.blogspot.com/2025/02/referencewrapper.html#cref).       
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### function
A function class can wrap any kind of callable element (such as functions and function objects) into a copyable object, and whose type depends solely on its call signature (and not on the callable element type itself).   
More details can be found [here➹](https://modcpp11.blogspot.com/2025/02/function.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### placeholder namespace
placeholder defines an unspecified number of objects: _1, _2, _3,..._N, where _N is implementation specific upper limit.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/02/function.html#placeholder).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### is_placeholder class
is_placeholder trait class can be used to check if the argument is a placeholder type or not.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/02/function.html#is_placeholder).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### mem_fn
mem_fn() converts member function to a functor whose functional call invokes the member function pointed by the parameter.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/02/function.html#mem_fn).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### bind
bind function returns a function object based on fn, but with its arguments bound to args. The syntax is as shown below.   
More details can be found [here➹](https://modcpp11.blogspot.com/2025/02/function.html#bind).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### allocator
Allocators are classes that define memory models to be used by some parts of the Standard Library, and most specifically, by STL containers.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/03/allocator.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### allocator_traits
The allocator_traits class template provides the standardized way to access various properties of Allocators.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/03/allocatortraits.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>smart pointer</span> ##
Internally C/C++ runtime does not have garbage collector support therefore dangling pointers, leaked resources causes instability in applications. Smartpointers are used to get around this issue.    
### nullptr_t
nullptr_t data type is introduced specifically to prevent misuse of NULL in place of null pointers. nullptr is the only instance of this type and can be used in place of a null pointer.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/smartpointers.html#nullptr).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Generic smartpointer
A smartpointer is basically a RAII (Resource Acquisition Is Initialization) object that wraps a pointer to an object or an array. When the smartpointer object is destroyed, the underlying memory of the pointer is released. A smartpointer uses dereferencing operators such as [], * and -> to access the object or its members the pointer is inferring.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/smartpointers.html#smartpointer).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### default_delete
default_delete is a functor object. aka deleter object used by smart pointers to recycle the resources.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/03/defaultdelete.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### unique_ptr
unique_ptr are useful when a resource such as a piece of memory or a file handle needs to be singly managed.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/03/uniqueptr.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### shared_ptr
shared_ptr are useful when a resource such as a piece of memory or a file handle can be collectively shared by multiple owners.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/03/sharedptr.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### weak_ptr
A weak_ptr is a smart pointer that holds a non-owning ("weak") reference to an object that is managed by shared_ptr. It must be converted to shared_ptr in order to access the referenced object.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/03/weakptr.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>chrono library</span> ##
Chrono library defines a set of Clocks that can represent a Duration or a specific Time Point. These are used by concurrency object APIs (sleep_for(duration) and sleep_until(time_point)) to pause processing within a thread.    
### ratio library
standard library defines a new template class ratio to define ratios that can be used only during compile time.ratio is used in chrono library to represent different time units such as millisecond, seconds, hour etc.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/01/ratio-library.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Terminology
duration means a fixed number of  time units. A clock is a device that has a starting time or epoch time and a resolution or period. time_point is associated with a clock . It represents the duration  since epoch time of the clock.     
More details can be found [here➹](https://modcpp11.blogspot.com/p/chrono-library.html#Terminology).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### duration
duration means a fixed number of time units. A Time unit could be a second or a millisecond or any user defined such as a day or a month. Examples, 10 milliseconds. 2 days etc.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/02/duration.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### clocks
Chrono library defines three clocks - system_clock,steady_clock,high_resolution_clock with different resolution and monotonicity.     
More details can be found [here➹](https://modcpp11.blogspot.com/p/chrono-library.html#clocks).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### time_point
time_point is associated with a clock . It represents the duration since epoch time of the clock.    
More details can be found [here➹](https://modcpp11.blogspot.com/2025/02/timepoint.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### POSIX time functions
POSIX CRT functions are widely used for time calculations. Some of the functions use the data types discussed below. In addition, environment time variable TZ is used for time zone settings.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/chrono-library.html#POSIX).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>Concurrency:stdLib</span> ##
Standard library concurrency objects execute code and retrieve results asynchronously, also provide synchronization. They can be broadly classified into five categories.    
### Execution Classes and functions
These classes or functions can execute code asynchronously. They include async(), thread, this_thread, packaged_task. The results or exceptions are stored in Execution Utility Classes.   
More details can be found [here➹](https://modcpp11.blogspot.com/p/concurrency.html#Execution_Classes).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Execution Utility Classes
These classes store the result or exception to be retrieved asynchronously. They include promise, future, shared_future.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/concurrency.html#Execution_Utilities).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Synchronization Classes and functions
These classes provide synchronization between Execution Classes. They include mutex, timed_mutex, recursive_mutex, recursive_timed_mutex, conditional variable, conditional variable_any, call_once().    
More details can be found [here➹](https://modcpp11.blogspot.com/p/concurrency.html#Synchronization_Classes).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Synchronization wrapper Classes
These classes provide wrapper for Synchronization classes. They include lock_guard, unique_lock, shared_lock, lock().    
More details can be found [here➹](https://modcpp11.blogspot.com/p/concurrency.html#Synchronization_Utility).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Lock free programming
The synchronization mechanisms discussed earlier uses operating system provided objects using atomic classes which provide interlocked atomic operations.. They include atomic, atomic_flag.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/concurrency.html#Lock_free).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>Concurrency:win32</span> ##
This discusses concurrency objects that are available in Windows win32 API and from standard library.    
### Execution objects
These objects execute code in threads, thread pools APC(Asynchronous Process Call) queues.    
More details can be found [here➹](https://modcpp11.blogspot.com/2024/11/win32-synchronization-objects.html#Execution).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Synchronization objects
These objects are used by execution objects to provide synchronizations within a process or across. Some provide specialization for reader-writer and producer - consumer scenarios. They include Critical Section,Mutex,Event,Semaphore,Slim Reader/Writer,Conditional Variable,WaitOnAddress,InitOnce,Interlocked functions.    
More details can be found [here➹](https://modcpp11.blogspot.com/2024/11/win32-synchronization-objects.html#Synchronization).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
## <span style='color: blue;'>Numerical Library</span> ##
Standard Library provides classes such as bitset to handle bits, valarray to handle matrix operations. random number generators and distributions.    
### long long
The size of long is not consistent across platforms. In linux, it's 64 bits and in Windows it's 32 bits. The new data type long long address this by keeping size at 64 bits across all the platforms.    
More details can be found [here➹](https://modcpp11.blogspot.com/p/numerical-library.html#long_long).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### numeric limits
Maximum and minimum values of integral types such as int, short, long,float, double  have been defined in <climits> as macros. For example, INT_MAX, INT_MIN, FLT_MIN,FLT_MAX etc.    
numeric_limits<>  is a template class that defines static methods such as min(), max() along with host of other functions. Specialized classes of numeric_limits<> are defined for arithmetic types such as int, double etc. These methods can be used instead of  of macros. For example, numeric_limits<int>::max().   
More details can be found [here➹](https://modcpp11.blogspot.com/2023/10/numeric-limits.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### valarray
The standard library provides valarray class is similar to a vector but mathematical functions can be applied directly to all the elements. It also allows to get different cross section of the elements in the valarray including multidimensional using helper classes.    
More details can be found [here➹](https://modcpp11.blogspot.com/2024/09/valarray.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).
### Random number Engines and Distributions
CRT provides limited capability of generating random numbers based on a seed. In C++ 11 numerous random number engines and distributions were introduced.
More details can be found [here➹](https://modcpp11.blogspot.com/2025/05/defaultrandomengine.html).    
[TOC↑](https://github.com/VedavyasaRao/ModernCPP?tab=readme-ov-file#toc).

