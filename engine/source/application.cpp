#include "application.h"
#include "World/world.h"

namespace Mona {
	void Application::StartUp(World& world) noexcept
	{

		UserStartUp(world);
	}
}