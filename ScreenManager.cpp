#include "ScreenManager.h"

void ScreenManager::updateCurrentState() //Duyệt qua mảng các trang và cập nhật trạng thái hiện tại của chúng.
{
    for (int i = 0; i < size; i++)
    {
        maintablist[i]->SetCurrentState(maintablist[i]->GetState());
    }
}
void ScreenManager::draw(RenderWindow& window)
{
    for (int i = 0; i < size; i++)
    {
        eScreen currentstate = (eScreen)maintablist[i]->GetCurrentState();
        int state = maintablist[i]->GetState();// truyền giá trị state để hàm GetState() chạy
        if ((int)currentstate != state)
        {
            current = currentstate;// cập nhật lại Id
            break;
        }
    }
    // vẽ page mà mình muốn
    for (int i = 0; i < size; i++)
    {
        if (current == (eScreen)maintablist[i]->GetState())
        {
            maintablist[i]->draw(window);
            break;
        }
    }
    updateCurrentState(); // cập nhật Id
}
void ScreenManager::HandleMouseClick(int x, int y)
{
    for (int i = 0; i < size; i++)
    {
        if (current == (eScreen)maintablist[i]->GetState()) // liệt kê các mảng page
        {
            maintablist[i]->HandleMouseClick(x, y); // Xử lý nhấp chuột
            break;
        }
    }
}
void ScreenManager::Click(int x, int y)
{
    for (int i = 0; i < size; i++)
    {
        if (current == (eScreen)maintablist[i]->GetState())
        {
            maintablist[i]->Click(x, y);
            break;
        }
    }
}