#include <windows.h>
#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;
template <class T>
struct vallocator
{

	using value_type = T;

	vallocator() noexcept {} 
	template <class U> vallocator(vallocator<U> const&) noexcept {}

	value_type*  allocate(std::size_t n)
	{
		// Create a shared memory object
		HANDLE hFileMapping = CreateFileMapping(
			INVALID_HANDLE_VALUE,  // No file
			NULL,                 // No security attributes
			PAGE_READWRITE,        // Read/write access
			0,                     // Maximum size (high part)
			n,                  // Maximum size (low part)
			getname().c_str()     // Name of the object
		);

		if (hFileMapping == NULL)
		{
			throw(runtime_error("Failed to create file mapping object"));
		}

		// Map the shared memory into the process's address space
		LPVOID lpMem = MapViewOfFile(
			hFileMapping,
			FILE_MAP_ALL_ACCESS,
			0,
			0,
			n
		);

		if (lpMem == NULL)
		{
			CloseHandle(hFileMapping);
			throw(runtime_error("Failed to map view of file"));
		}

		mmap[lpMem] = hFileMapping;
		return static_cast<T*>(lpMem);
	}

	void deallocate(value_type* p, std::size_t) noexcept  
	{
		// Unmap the shared memory
		UnmapViewOfFile(p);

		// Close the handle
		CloseHandle(mmap[p]);
	}

private:
	string getname()
	{
		GUID guid;
		HRESULT hr = CoCreateGuid(&guid);
		if (FAILED(hr))
			throw(runtime_error("cannot create guid"));

		stringstream stream;
		stream << hex << uppercase
			<< setw(8) << setfill('0') << guid.Data1
			<< "-" << setw(4) << setfill('0') << guid.Data2
			<< "-" << setw(4) << setfill('0') << guid.Data3
			<< "-";
		for (int i = 0; i < sizeof(guid.Data4); ++i)
		{
			if (i == 2)
				stream << "-";
			stream << hex << setw(2) << setfill('0') << (int)guid.Data4[i];
		}
		return stream.str();
	}
	map<LPVOID, HANDLE> mmap;
};

template <class T, class U>
bool operator==(vallocator<T> const&, vallocator<U> const&) noexcept
{
	return true;
}

template <class T, class U>
bool operator!=(vallocator<T> const& x, vallocator<U> const& y) noexcept
{
	return !(x == y);
}

int main() {
	vallocator<char> alloc;
	basic_string<char, char_traits<char>, vallocator<char>> s;
	//allocate 100 mb
	s.resize(1024 * 1024 * 100);
	s.assign("Khrisha Rao");

	//prints Khrisha Rao
	cout << s << endl;
}