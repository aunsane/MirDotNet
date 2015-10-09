#pragma once

template<typename T>
ref class HGlobalPtr
{
	System::IntPtr ptr;
public:
	HGlobalPtr(System::IntPtr ptr) : ptr(ptr) { }
	operator T() { return static_cast<T>(ptr.ToPointer()); }
	~HGlobalPtr()
	{
		if(ptr != System::IntPtr::Zero)
			System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
	}
};