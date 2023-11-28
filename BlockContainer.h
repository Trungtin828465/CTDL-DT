#include <iostream>
#include <vector>
#include "BlockComponent.h"
#include "I_Component.h"
using namespace std;
#pragma once
class BlockContainer 
{

private:
    string m_name;
    vector<shared_ptr<I_Component>> m_components;

public:
    BlockContainer(string name);
    ~BlockContainer() {}
    void AddBlockContainer(string filepath, float xPosotion, float yPosotion, float xScale, float yScale);
    void Render(RenderWindow& ref);
    void reset() {
        while (!m_components.empty()) {
            m_components.pop_back();
        }
    }
};

