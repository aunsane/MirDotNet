#pragma once

namespace MirandaNG
{
	using namespace System;
	using namespace System::IO;
	using namespace System::Reflection;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::InteropServices;

	ref class PluginLoader
	{
	private:
		static List<Plugin^> ^plugins;

		static PluginLoader()
		{
			plugins = gcnew List<MirandaNG::Plugin^>();
		}

	public:
		static void Load()
		{
			String ^path = Assembly::GetExecutingAssembly()->Location;
			DirectoryInfo ^directory = gcnew DirectoryInfo(Path::GetDirectoryName(path));
			for each(FileInfo ^file in directory->GetFiles("*.dll"))
			{
				try
				{
					Assembly ^assembly = Assembly::LoadFile(file->FullName);
					array<Type^> ^types = assembly->GetExportedTypes();
					for each(Type ^type in types)
					{
						if (type->IsSubclassOf(MirandaNG::Plugin::typeid) && !type->IsAbstract)
						{
							MirandaNG::Plugin ^plugin = safe_cast<MirandaNG::Plugin^>(
								Activator::CreateInstance(type, false));
							plugin->Load();
							plugins->Add(plugin);
						}
					}
				}
				catch (BadImageFormatException^)
				{
					// Do nothing. File is not managed plugin.
				}
			}
		}

		static void Unload()
		{
			while (plugins->Count > 0)
			{
				Plugin ^plugin = plugins[0];
				plugins->Remove(plugin);
				plugin->Unload();
			}
		}
	};
};