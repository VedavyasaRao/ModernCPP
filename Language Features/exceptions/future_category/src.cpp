// std::future_errc example:
#include <iostream>     // std::cerr
#include <future>       // std::promise, std::future_error, std::future_errc

int main ()
{
  std::promise<int> prom;

  try 
  {
    prom.get_future();
    prom.get_future();   // throws std::future_error with future_already_retrieved
  }
  catch (std::future_error& excptn) 
  {
    std::error_condition cond = excptn.code().default_error_condition();
    std::cout << "Exception caught (future_error):\n";
    std::cout << "Value: " << cond.value() << '\n';
    std::cout << "Category: " << cond.category().name() << '\n';
    std::cout << "Message: " << cond.message() << '\n';
  }

  return 0;
}