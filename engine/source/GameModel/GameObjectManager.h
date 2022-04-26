#pragma once
#include "GameObject.h"
#include <iostream>
#include <vector>

namespace Fighters
{
    class GameObjectManager
    {
        public:
            GameObjectManager();
            GameObjectManager(const GameObjectManager& manager) = delete;
		    GameObjectManager& operator=(const GameObjectManager& manager) = delete;
            template <typename ObjectType,typename ...Args>

            ObjectType* CreateGameObject(Args&& ... args);
            void DestroyGameObject() noexcept;
            bool isValid() const noexcept;

            void UpdateGameObject() noexcept;

    };
}