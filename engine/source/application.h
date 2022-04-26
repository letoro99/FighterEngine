#pragma once
namespace Fighters
{
    class Window;
    class World;
    class Application
    {
        public:
            friend class World;

            virtual void UserStarUp(World &world) noexcept = 0;

            virtual void UserShutDown(World &world) noexcept = 0;

            virtual void UserUpdate(World& world, float timestep) noexcept = 0;

            virtual ~Application() = default;

        private:
            void StarUp(World& world) noexcept;
    }
}