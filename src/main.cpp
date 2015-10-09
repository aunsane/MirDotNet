#include "stdafx.h"

int hLangpack;
HINSTANCE g_hInstance;

PLUGININFOEX pluginInfo =
{
	sizeof(PLUGININFOEX),
	__PLUGIN_NAME,
	PLUGIN_MAKE_VERSION(__MAJOR_VERSION, __MINOR_VERSION, __RELEASE_NUM, __BUILD_NUM),
	__DESCRIPTION,
	__AUTHOR,
	__AUTHOREMAIL,
	__COPYRIGHT,
	__AUTHORWEB,
	UNICODE_AWARE,
	// {61F08CAA-EAA0-4BEA-811D-94A39726A81B}
	{ 0x61f08caa, 0xeaa0, 0x4bea, { 0x81, 0x1d, 0x94, 0xa3, 0x97, 0x26, 0xa8, 0x1b } }
};

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD, LPVOID)
{
	g_hInstance = hInstance;

	return TRUE;
}

extern "C" __declspec(dllexport) PLUGININFOEX *MirandaPluginInfoEx(DWORD)
{
	return &pluginInfo;
}

#pragma managed

using namespace MirandaNG;

extern "C" int __declspec(dllexport) Load(void)
{
	mir_getLP(&pluginInfo);

	PluginLoader::Load();

	return 0;
}

extern "C" int __declspec(dllexport) Unload(void)
{
	PluginLoader::Unload();

	return 0;
}