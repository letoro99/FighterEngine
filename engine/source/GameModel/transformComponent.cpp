#include "transformComponent.h"

namespace Fighters
{
    TransformComponent::TransformComponent()
    {
        this->position = glm::vec2(0.0,0.0);
        this->rotation = glm::vec2(0.0,0.0);
        this->scale = glm::vec2(1.0,1.0);
    }

    TransformComponent::TransformComponent(glm::vec2 pos, glm::vec2 rot, glm::vec2 scale):
    position(pos), rotation(rot), scale(scale)
    {}

    glm::vec2 TransformComponent::getPosition() const
    {
        return this->position;
    }

    glm::vec2 TransformComponent::getRotation() const
    {
        return this->rotation;
    }

    glm::vec2 TransformComponent::getScale() const
    {
        return this->scale;
    }

    void TransformComponent::setPosition(const glm::vec2& new_pos)
    {
        this->position = new_pos;
    }

    void TransformComponent::setRotation(const glm::vec2& new_rot)
    {
        this->rotation = new_rot;
    }

    void TransformComponent::setPosition(const glm::vec2& new_scale)
    {
        this->scale = new_scale;
    }

    void TransformComponent::move(const glm::vec2 &y)
    {
        this->position += y;
    }
}