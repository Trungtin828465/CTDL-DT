#include "BlockContainer.h"
BlockContainer::BlockContainer(string name)
{
    m_name = name;
}

void BlockContainer::AddBlockContainer(string filepath, float xPosotion, float yPosotion, float xScale, float yScale)
{
    shared_ptr<BlockComponent> item = make_shared<BlockComponent>(filepath, xPosotion, yPosotion, xScale, yScale);
    m_components.push_back(item);
}
void BlockContainer::Render(RenderWindow& ref)
{
    for (int i = 0; i < m_components.size(); i++)
    {
        m_components[i]->Render(ref);
    }
}