#include <glm/glm.hpp>
#include <iostream>

namespace Fighters
{
    class CameraComponent
    {
        private:    
            float fieldOfView = 50.0f;
            float aspectRate = 16.0f / 9.0f;
            float nearPlane = 0.1f;
            float farPlane = 100.0f;

        public:

            static constexpr std::string_view  componentName = "CameraComponent";

            CameraComponent() = delete;

            CameraComponent(float fov, float ratio, float nearPlane, float farPlane);

            float GetFieldOfView() const;
            float GetAspectRatio() const;
            float GetNearPlane() const;
            float GetFarPlane() const;

            void SetFieldOfView(float new_value);
            void SetAspectRatio(float new_value);
            void SetNearPlane(float new_value);
            void SetFarPlane(float new_value);

            void update();

    };    
}