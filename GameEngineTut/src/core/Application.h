#pragma once

#include "core.h"

namespace GE
{
	class GE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined by client
	Application* CreateApplication();
}