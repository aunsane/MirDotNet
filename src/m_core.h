#pragma once

namespace MirandaNG
{
	using namespace System;
	using namespace System::Runtime::InteropServices;

	public ref class Core abstract sealed
	{
	public:
		static IntPtr CreateHookableEvent(String ^name)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			return (IntPtr)::CreateHookableEvent(rawName);
		}

#pragma warning(push)
#pragma warning(disable:4693)
		delegate int MirandaHook(IntPtr wParam, IntPtr lParam);
		delegate int MirandaHookObj(IntPtr pObject, IntPtr wParam, IntPtr lParam);
		delegate int MirandaHookParam(IntPtr wParam, IntPtr lParam, IntPtr param);
		delegate int MirandaHookObjParam(IntPtr pObject, IntPtr wParam, IntPtr lParam, IntPtr param);
#pragma warning(pop)

		static int DestroyHookableEvent(IntPtr hEvent)
		{
			return ::DestroyHookableEvent(hEvent.ToPointer());
		}

		static int NotifyEventHooks(IntPtr hEvent, IntPtr wParam, IntPtr lParam)
		{
			return ::NotifyEventHooks(hEvent.ToPointer(), (WPARAM)wParam.ToInt32(), (LPARAM)lParam.ToInt64());
		}

		static IntPtr HookEvent(String ^name, MirandaHook ^hookProc)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			IntPtr rawHook = Marshal::GetFunctionPointerForDelegate(hookProc);
			return (IntPtr)::HookEvent(rawName, (MIRANDAHOOK)rawHook.ToPointer());
		}

		static IntPtr HookEventObj(String ^name, MirandaHookObj ^hookProc, IntPtr pObject)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			IntPtr rawHook = Marshal::GetFunctionPointerForDelegate(hookProc);
			return (IntPtr)::HookEventObj(rawName, (MIRANDAHOOKOBJ)rawHook.ToPointer(), pObject.ToPointer());
		}

		static IntPtr HookEventParam(String ^name, MirandaHookParam ^hookProc, IntPtr param)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			IntPtr rawHook = Marshal::GetFunctionPointerForDelegate(hookProc);
			return (IntPtr)::HookEventParam(rawName, (MIRANDAHOOKPARAM)rawHook.ToPointer(), (LPARAM)param.ToInt64());
		}

		static IntPtr HookEventObjParam(String ^name, MirandaHookObjParam ^hookProc, IntPtr pObject, IntPtr param)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			IntPtr rawHook = Marshal::GetFunctionPointerForDelegate(hookProc);
			return (IntPtr)::HookEventObjParam(rawName, (MIRANDAHOOKOBJPARAM)rawHook.ToPointer(), pObject.ToPointer(), (LPARAM)param.ToInt64());
		}

		static int UnhookEvent(IntPtr hHook)
		{
			return ::UnhookEvent(hHook.ToPointer());
		}

#pragma warning(push)
#pragma warning(disable:4693)
		delegate IntPtr MirandaService(IntPtr wParam, IntPtr lParam);
		delegate IntPtr MirandaServiceObj(IntPtr pObject, IntPtr wParam, IntPtr lParam);
		delegate IntPtr MirandaServiceParam(IntPtr wParam, IntPtr lParam, IntPtr param);
		delegate IntPtr MirandaServiceObjParam(IntPtr pObject, IntPtr wParam, IntPtr lParam, IntPtr param);
#pragma warning(pop)

		static IntPtr CreateServiceFunction(String ^name, MirandaService ^serviceProc)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			IntPtr rawService = Marshal::GetFunctionPointerForDelegate(serviceProc);
			return (IntPtr)::CreateServiceFunction(rawName, (MIRANDASERVICE)rawService.ToPointer());
		}

		static IntPtr CreateServiceFunctionObj(String ^name, MirandaService ^serviceProc, IntPtr pObject)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			IntPtr rawService = Marshal::GetFunctionPointerForDelegate(serviceProc);
			return (IntPtr)::CreateServiceFunctionObj(rawName, (MIRANDASERVICEOBJ)rawService.ToPointer(), pObject.ToPointer());
		}

		static IntPtr CreateServiceFunctionParam(String ^name, MirandaService ^serviceProc, IntPtr param)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			IntPtr rawService = Marshal::GetFunctionPointerForDelegate(serviceProc);
			return (IntPtr)::CreateServiceFunctionParam(rawName, (MIRANDASERVICEPARAM)rawService.ToPointer(), (LPARAM)param.ToInt64());
		}

		static IntPtr CreateServiceFunctionObjParam(String ^name, MirandaService ^serviceProc, IntPtr pObject, IntPtr param)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			IntPtr rawService = Marshal::GetFunctionPointerForDelegate(serviceProc);
			return (IntPtr)::CreateServiceFunctionObjParam(rawName, (MIRANDASERVICEOBJPARAM)rawService.ToPointer(), pObject.ToPointer(), (LPARAM)param.ToInt64());
		}

		static int DestroyServiceFunction(IntPtr hService)
		{
			return ::DestroyServiceFunction(hService.ToPointer());
		}

		static bool ServiceExists(String ^name)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			return ::ServiceExists(rawName) > 0;
		}

		static IntPtr CallService(String ^name, IntPtr wParam, IntPtr lParam)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			return (IntPtr)::CallService(rawName, (WPARAM)wParam.ToInt32(), (LPARAM)lParam.ToInt64());
		}

		static IntPtr CallContactService(IntPtr hContact, String ^name, IntPtr wParam, IntPtr lParam)
		{
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			return (IntPtr)::CallContactService((MCONTACT)hContact.ToInt32(), rawName, (WPARAM)wParam.ToInt32(), (LPARAM)lParam.ToInt64());
		}

		static IntPtr CallProtoService(String ^module, String ^name, IntPtr wParam, IntPtr lParam)
		{
			HGlobalPtr<char*> rawModule(Marshal::StringToHGlobalAnsi(module));
			HGlobalPtr<char*> rawName(Marshal::StringToHGlobalAnsi(name));
			return (IntPtr)::CallProtoService(rawModule, rawName, (WPARAM)wParam.ToInt32(), (LPARAM)lParam.ToInt64());
		}
	};
};