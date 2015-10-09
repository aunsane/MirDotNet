#pragma once

namespace MirandaNG
{
	public ref class Plugin abstract
	{
	public protected:
		virtual void Load() = 0;
		virtual void Unload() { };
	};
};