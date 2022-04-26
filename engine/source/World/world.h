#pragma once


namespace Fighters
{
    class World
    {
        public:
            void createBasicEntity(BasicEntity& basicEntity) noexcept;
            void destroyBasicEntity(BasicEntity& basicEntity) noexcept;
            Window& getWindow() noexcept;
		    void EndApplication() noexcept;

            void setMainCamera(CameraComponent& camera) noexcept;
            CameraComponent& GetMainCameraComponent() noexcept;


        private:
            World(Application &app);
            ~World();

            void starMainLoop() noexcept;
            void update(float timestep) noexcept;

            Controllers m_controllers;
            Window m_window;
            Application& m_application;
            
    }
}