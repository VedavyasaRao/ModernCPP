#include <future>
#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <functional>

using namespace std;
using namespace std::chrono;

template <typename Duration>
struct chronotimer
{
	~chronotimer()
	{
		waitforcompletion();
	}

	void waitforcompletion()
	{
		if (timer_future.valid())
			timer_future.get();
	}

	void starttimerasync()
	{
		timer_future = async(bind(&chronotimer::timerfunc, this));
	}

	void timerfunc()
	{
		tp_stop = steady_clock::now() + duration_left;
		std::unique_lock<mutex> lk(cvmtx);
		cv.wait_until(lk, tp_stop, [&]() {return (bpause == true); });
		duration_left = timeleft();
	}

	chronotimer(Duration d)
	{
		timer_duration = duration_cast<milliseconds>(d);
		duration_left = timer_duration;
		tp_stop = steady_clock::now();
	}

	void start()
	{
		bpause = false;
		starttimerasync();
	}

	void pause()
	{
		cout << "pause" << endl;
		bpause = true;
		cv.notify_all();
	}

	void resume()
	{
		cout << "resume" << endl;
		waitforcompletion();
		start();
	}

	void reset()
	{
		cout << "reset" << endl;
		pause();
		waitforcompletion();
		duration_left = timer_duration;
		start();
	}

	milliseconds timeleft()
	{
		return duration_cast<milliseconds>((tp_stop - steady_clock::now()));
	}

	bool iscomplete()
	{
		return tp_stop <= steady_clock::now();
	}

	mutex cvmtx;
	condition_variable cv;
	bool bpause = false;
	milliseconds timer_duration{ 0 };
	milliseconds duration_left{ 0 };
	steady_clock::time_point tp_stop;
	future<void> timer_future;


};

int main()
{
	chronotimer<seconds> cn(seconds{ 3 });
	cout << boolalpha;
	cout << "timer started (3000 milliseconds)" << endl;
	cn.start();
	this_thread::sleep_for(seconds(1));
	cout << "sleeping for 1 second" << endl;
	cout << "iscomplete\t:" << cn.iscomplete() << endl;
	cout << "time left on timer(ms)\t:" << cn.timeleft().count() << endl;
	cn.pause();
	this_thread::sleep_for(seconds(1));
	cout << "sleeping for 1 second" << endl;
	cn.resume();
	this_thread::sleep_for(seconds(1));
	cout << "sleeping for 1 second" << endl;
	cout << "iscomplete\t:" << cn.iscomplete() << endl;
	cout << "time left on timer(ms)\t:" << cn.timeleft().count() << endl;
	cn.reset();
	cout << "timer started (3000 milliseconds)" << endl;
	this_thread::sleep_for(seconds(2));
	cout << "sleeping for 2 seconds" << endl;
	cout << "iscomplete\t:" << cn.iscomplete() << endl;
	cout << "time left on timer(ms)\t:" << cn.timeleft().count() << endl;
	this_thread::sleep_for(seconds(2));
	cout << "sleeping for 2 seconds" << endl;
	cout << "iscomplete\t:" << cn.iscomplete() << endl;

	return 0;
}