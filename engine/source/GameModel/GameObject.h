#pragma once
#include "TypesComponent.h"

namespace Fighters{
    class BasicEntity
    {
        private:
            std::shared_ptr<TransfomrComponent> m_TransformComp;
            std::shared_ptr<CameraComponent> m_CameraComp;
            std::shared_ptr<InputComponent> m_InputComp;

        public:

            BasicEntity();

            BasicEntity(
                std::shared_ptr<CameraComponent> m_camera,
                std::shared_ptr<InputComponent> m_input,
                std::shared_ptr<TransfomrComponent> m_transform
            );

            ~BasicEntity();

            void setTransformComponent(std::shared_ptr<TransfomrComponent> &transform);
            void setCameraComponent(std::shared_ptr<InputComponent> &m_CameraComp);
            void setInputComponent(std::shared_ptr<CameraComponent> &m_InputComp);

            std::shared_ptr<TransfomrComponent> getTransformComponent();
            std::shared_ptr<InputComponent> getInputComponent();
            std::shared_ptr<CameraComponent> getCameraComponent();

            void update();

    };
}
