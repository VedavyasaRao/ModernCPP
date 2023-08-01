struct Timer {};

struct TimeKeeper 
{
  explicit TimeKeeper(Timer t) :t(t) {}
  int get_time() {return 0;};
Timer t;
};

int main() 
{
  TimeKeeper time_keeper(Timer ());
  return time_keeper.get_time();
}