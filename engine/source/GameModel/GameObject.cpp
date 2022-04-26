#include "GameObject.h"

namespace Fighters
{
    BasicEntity::BasicEntity()
    {
        m_InputComp = nullptr;
        m_TransformComp = nullptr;
        m_CameraComp = nullptr;        
    }

    BasicEntity::~BasicEntity()
    {
        delete m_InputComp;
        delete m_CameraComp;
        delete m_TransformComp;       
    }
}