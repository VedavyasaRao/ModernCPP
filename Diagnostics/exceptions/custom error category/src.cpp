// custom error_category example
#include <iostream>       // std::cout, std::endl
#include <system_error>   // std::is_error_condition_enum, std::error_category,
                          // std::error_condition, std::error_code
#include <string>         // std::string


// custom error conditions enum type:
enum class custom_errc { success=0, client_error, server_error, other };
namespace std 
{
    template<> struct is_error_condition_enum<custom_errc> : public true_type {};
}

// custom category:
struct custom_category_t : public std::error_category 
{
    virtual const char* name() const noexcept  { return catname; }
    virtual std::error_condition default_error_condition  (int ev) const noexcept 
    {
        if ((ev>=200)&&(ev<300)) return std::error_condition(custom_errc::success);
        else if ((ev>=400)&&(ev<500)) return std::error_condition(custom_errc::client_error);
        else if ((ev>=500)&&(ev<600)) return std::error_condition(custom_errc::server_error);
        else return std::error_condition(custom_errc::other);
    }
    virtual bool equivalent (const std::error_code& code, int condition) const noexcept 
    {
        return *this==code.category() &&
        static_cast<int>(default_error_condition(code.value()).value())==condition;
    }
    virtual std::string message(int ev) const 
    {
        switch (ev) 
        {
            case 200: return "OK";
            case 403: return "403 Forbidden";
            case 404: return "404 Not Found";
            case 500: return "500 Internal Server Error";
            case 503: return "503 Service Unavailable";
            default: return "Unknown error";
        }
    }
    const char *catname = "custom_http";
} custom_category;

// make_error_code overload to generate custom conditions:
std::error_condition make_error_condition (custom_errc e) 
{
    return std::error_condition(static_cast<int>(e), custom_category);
}

void readapage(const char* url)
{
    if (std::string(url) == "no url")
        throw (std::system_error(std::error_code(404, custom_category)));
}

int main()
{
    try
    {
        readapage("no url");
    }
    catch(const std::system_error& ex)
    {
        auto &e = ex.code();
        if (e == custom_errc::success) std::cout << "Success: " << e.message();
        else if (e == custom_errc::client_error) std::cout << "Client Error: " << e.message();
        else if (e == custom_errc::server_error) std::cout << "Server Error: " << e.message();
        else std::cout << "Unknown";
        std::cout << std::endl;
    }

    return 0;
}