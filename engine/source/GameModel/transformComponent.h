#pragma once
#include <glm/glm.hpp>
#include <iostream>

namespace Fighters
{
    class TransformComponent
    {
        private:
            glm::vec2 position, rotation, scale;

        public:

            TransformComponent()
            {
                this->position = glm::vec2(0.0,0.0);
                this->rotation = glm::vec2(0.0,0.0);
                this->scale = glm::vec2(1.0,1.0);
            }

            TransformComponent(glm::vec2 pos, glm::vec2 rot, glm::vec2 scale):
            position(pos), rotation(rot), scale(scale)
            {}

            glm::vec2 getPosition() const;
            glm::vec2 getRotation() const;
            glm::vec2 getScale() const;

            void setPosition(const glm::vec2& new_pos);
            void setRotation(const glm::vec2& new_rot);
            void setScale(const glm::vec2& new_scale);

            void move(const glm::vec2 &y);
            void update();
    };
}