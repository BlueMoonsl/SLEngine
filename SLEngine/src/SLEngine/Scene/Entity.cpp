#include "slpch.h"
#include "Entity.h"

namespace SLEngine {

    Entity::Entity(entt::entity handle, Scene* scene)
        : m_EntityHandle(handle), m_Scene(scene)
    {
    }

}