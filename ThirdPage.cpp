#include "ThirdPage.h"


ThirdPage::ThirdPage(int num) : m_blocks("third"), m_texts("third"), seatInfo("third"), t_offer("third"),
b_offer("third"), t_payment("third"), b_payment("third")
{

    selectedItemIndex = num;
    curentState = num;

    bold.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
    semiBold.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
    regular.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");

    listMovie x;
    int filmIndex = (num - 10) % 11;
    string filePath = x.a[filmIndex].filePath;
    string filePathIconPrev = "images/icon-prev.png";

    m_blocks.AddBlockContainer(filePath, xPos, 113, xScale, yScale);
    m_blocks.AddBlockContainer(filePathIconPrev, xPos, 44, 0.22, 0.2);

    m_texts.AddTextContainer("SLC2T", bold, 50, Color::Red, 212, 35);
    // set film's name
    m_texts.AddTextContainer(x.a[filmIndex].name, bold, 30, Color::Black, 220 - 15, 100);
    // set film's category
    m_texts.AddTextContainer("The loai:", semiBold, 18, Color::Black, xLogoPosition - 15, 135);
    // set film's category content
    m_texts.AddTextContainer(x.a[filmIndex].type, regular, 16, Color::Black, xLogoPosition - 15 + 85, 137);
    // set film's time
    m_texts.AddTextContainer("Thoi luong:", semiBold, 18, Color::Black, xLogoPosition - 15, 160);
    // set film's time content
    m_texts.AddTextContainer(x.a[filmIndex].time, regular, 16, Color::Black, xLogoPosition - 15 + 110, 162);
    // set film's language
    m_texts.AddTextContainer("Ngon ngu:", semiBold, 18, Color::Black, xLogoPosition - 15, 185);
    // set film's language content
    m_texts.AddTextContainer(x.a[filmIndex].language, regular, 16, Color::Black, xLogoPosition - 15 + 105, 187);
    // set film's Rate
    m_texts.AddTextContainer("Danh gia:", semiBold, 18, Color::Black, xLogoPosition - 15, 210);
    m_texts.AddTextContainer(x.a[filmIndex].rating, regular, 16, Color::Black, xLogoPosition - 15 + 100, 212);
    // set film's Date
    m_texts.AddTextContainer("Khoi Chieu:", semiBold, 18, Color::Black, xLogoPosition - 15, 235);
    // set film's Date content
    m_texts.AddTextContainer("10/11/2023", regular, 16, Color::Black, xLogoPosition - 15 + 110, 237);
    // set film's description heading
    m_texts.AddTextContainer("Mo ta phim", semiBold, 26, Color::Black, xIconPrevPosition, 320);
    // set film's director
    m_texts.AddTextContainer("Dao dien:", semiBold, 18, Color::Black, xIconPrevPosition, 350);
    // set film's director content
    m_texts.AddTextContainer(x.a[filmIndex].director, regular, 16, Color::Black, xIconPrevPosition + 110, 352);
    // set film's actor
    m_texts.AddTextContainer("Dien vien long tieng:", semiBold, 18, Color::Black, xIconPrevPosition, 375);
    m_texts.AddTextContainer(x.a[filmIndex].artist, regular, 16, Color::Black, xIconPrevPosition + 200, 377);

    m_texts.AddTextContainer("Chon ghe", semiBold, 25, Color::White, xIconPrevPosition + 35, 421);

    // set bg-action
    Texture bgRed;
    bgRed.loadFromFile("images/bg-red.png");
    Sprite bgAction(bgRed);
    bgAction.setScale(0.3, 0.3);
    bgAction.setPosition(xIconPrevPosition, yIconPrevPosition + 380);

    // set action'title
    Text actionTitle("Chon ngay chieu", semiBold, 18);
    actionTitle.setFillColor(Color(255, 255, 255));
    actionTitle.move(xIconPrevPosition + 25, yIconPrevPosition + 390);

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 380, 0.3, 0.3);
    m_blocks.AddBlockContainer("images/img-screen.png", xIconPrevPosition + 10, yIconPrevPosition + 450, 0.7, 0.7);

    for (int i = 0; i < 35; i++) {
        float xScale = 0.1;
        float xMargin = 50.0f;
        if (i > 29) {
            xScale = 0.2f;
            xMargin = 100.0f;
        }
        m_blocks.AddBlockContainer("images/bg-gray-page3.png", 40 + (i % 10) * xMargin, 35.0f + 520 + (i / 10) * 40, xScale, 0.1f);
    }

    m_blocks.AddBlockContainer("images/bg-gray-page3.png", xIconPrevPosition + 20, yIconPrevPosition + 690, 0.05, 0.05);
    m_texts.AddTextContainer("Ghe chua chon", regular, 15, Color::Black, xIconPrevPosition + 50, yIconPrevPosition + 690);

    m_blocks.AddBlockContainer("images/bg-red-2.png", xIconPrevPosition + 20, yIconPrevPosition + 710, 0.2, 0.16);
    m_texts.AddTextContainer("Ghe da chon", regular, 15, Color::Black, xIconPrevPosition + 50, yIconPrevPosition + 710);

    m_texts.AddTextContainer("A,B,C,D", semiBold, 15, Color::Black, xIconPrevPosition + 270, yIconPrevPosition + 710);
    m_texts.AddTextContainer("Hang ghe", regular, 15, Color::Black, xIconPrevPosition + 340, yIconPrevPosition + 710);

    m_blocks.AddBlockContainer("images/bg-gray-page3.png", xIconPrevPosition + 270, yIconPrevPosition + 690, 0.1, 0.05);
    m_texts.AddTextContainer("Ghe doi", regular, 15, Color::Black, xIconPrevPosition + 340, yIconPrevPosition + 690);


    for (int i = 0; i <= 7; i++) {
        if (i < 2)
            m_texts.AddTextContainer("A", semiBold, 18, Color::Black, 15 + i * 540, yIconPrevPosition + 525);
        else if (i < 4)
            m_texts.AddTextContainer("B", semiBold, 18, Color::Black, 15 + (i - 2) * 540, yIconPrevPosition + 565);
        else if (i < 6)
            m_texts.AddTextContainer("C", semiBold, 18, Color::Black, 15 + (i - 4) * 540, yIconPrevPosition + 605);
        else
            m_texts.AddTextContainer("D", semiBold, 18, Color::Black, 15 + (i - 6) * 540, yIconPrevPosition + 650);
    }


    vector<int> v[4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) v[i].push_back(j + 1);
    }
    for (int i = 1; i <= 5; i++) v[3].push_back(i);
    float yP = 560.0f;
    for (int i = 0; i < 4; i++) {
        float xP = xIconPrevPosition + 20.0f;
        for (int j = 0; j < v[i].size(); j++) {
            m_texts.AddTextContainer(to_string(v[i][j]), semiBold, 18, Color::Black, xP, yP);
            if (i == 3) xP += 100.0f;
            else xP += 49.0f;
        }
        yP += 40.0f;
    }


    m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 22, yIconPrevPosition + 750, 1.3, 1.3);
    m_texts.AddTextContainer("Ghe chon:", semiBold, 22, Color::Black, xIconPrevPosition, yIconPrevPosition + 758);
    m_texts.AddTextContainer("Tam tinh:", semiBold, 22, Color::Black, xIconPrevPosition, yIconPrevPosition + 790);
}

ThirdPage::~ThirdPage() {}

void ThirdPage::draw(RenderWindow& window)
{
    m_blocks.Render(window);
    m_texts.Render(window);
    seatInfo.Render(window);
    b_payment.Render(window);
    t_payment.Render(window);
    b_offer.Render(window);
    t_offer.Render(window);
}

int ThirdPage::seatSelected(int x, int y) {

    const int rows = 4; // Tổng số hàng là 4 (3 hàng trên và 1 hàng dưới cùng)
    const int cols = 10;
    const int extraCols = 5; // Số cột ở hàng dưới cùng
    const int height = 35;
    const int width_1 = 42; // Chiều rộng của ghế ở 3 hàng trên
    const int width_2 = 85; // Chiều rộng của ghế ở hàng dưới cùng
    const int spacing_1 = 8;
    const int spacing_2 = 15; // Khoảng cách giữa các vật thể ở hàng dưới cùng
    const int startX = 40;
    const int startY = 550;

    for (int i = 0; i < 35; ++i) {

        int row = i / cols;
        int colUpper = i % cols;
        int colLower = i % extraCols;
        int xLeft;
        int yTop;

        if (row == rows - 1 && colLower < extraCols) {
            xLeft = startX + colLower * (width_2 + spacing_2);
            yTop = startY + row * (height + spacing_1);

            if (xLeft <= x && x <= xLeft + width_2 && yTop <= y && y <= yTop + height) {
                return i;
            }
        }
        else {
            xLeft = startX + colUpper * (width_1 + spacing_1);
            yTop = startY + row * (height + spacing_1);

            if (xLeft <= x && x <= xLeft + width_1 && yTop <= y && y <= yTop + height) {
                return i;
            }
        }
    }

    return -1;
}

void ThirdPage::seatColorUpdate(vector<int> seatIndex) {
    float xMargin = 50.0f;
    float grayxScale = 0.1f;
    float redxScale = 0.7f;
    for (int i = 0; i < 35; i++) {
        if (i > 28) {
            xMargin = 100.0f;
            grayxScale = 0.2f;
            redxScale = 1.3f;
        }
        m_blocks.AddBlockContainer("images/bg-gray-page3.png", 40 + (i % 10) * xMargin, 35.0f + 520 + (i / 10) * 40, grayxScale, 0.1f);
        for (int temp : seatIndex) {
            if (i == temp) {
                m_blocks.AddBlockContainer("images/bg-gray-hover.png", 40 + (i % 10) * xMargin, 35.0f + 520 + (i / 10) * 40, redxScale, 0.65f);
            }
        }
    }
}

string ThirdPage::seatName(int seatIndex) {
    string text, num;
    switch (seatIndex / 10) {
    case 0:
        text = "A";
        break;
    case 1:
        text = "B";
        break;
    case 2:
        text = "C";
        break;
    default:
        text = "D";
        break;
    }
    if ((seatIndex % 10) != 9) num = "0" + to_string((seatIndex + 1) % 10);
    else num = "10";
    return text + num;
}

void ThirdPage::seatUpdate(vector<int> seats) {
    float xPos = 500.0f;
    float xMarginRight = 50.0f;
    seatInfo.reset();
    price = 0;
    for (int temp : seats) {
        seatInfo.AddTextContainer(seatName(temp), regular, 16, Color::Black, xPos, 793.0f);
        xPos -= xMarginRight;
        price += (temp > 28 ? 90 : 45);
    }
    if (price) {
        seatInfo.AddTextContainer(to_string(price * 1000), regular, 16, Color::Black, 480.0f, 825.0f);
    }
}



/* */           


void ThirdPage::selectOffer()
{
    string code[3] = { {"Combo cuoi tuan"}, {"Combo 1"}, {"Combo 2"} };
    b_offer.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 20, yIconPrevPosition + 480, 1.3, 1.6);
    b_offer.AddBlockContainer("images/list-2.png", xIconPrevPosition + 487, yIconPrevPosition + 490, 0.3, 0.3);
    for (int i = 0; i < 3; i++)
    {
        t_offer.AddTextContainer(code[i], regular, 16, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 520 + (i * 25));
    }
}

void ThirdPage::resetOffer()
{
    t_offer.reset();
    b_offer.reset();
}


void ThirdPage::resetPayment()
{
    t_payment.reset();
    b_payment.reset();
}


void ThirdPage::selectPayment()
{
    string method[3] = { {"Tien mat"}, {"MoMo"}, {"The ngan hang"} };
    b_payment.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 20, yIconPrevPosition + 600, 1.3, 1.6);
    b_payment.AddBlockContainer("images/list-2.png", xIconPrevPosition + 487, yIconPrevPosition + 610, 0.3, 0.3);
    for (int i = 0; i < 3; i++)
    {
        t_payment.AddTextContainer(method[i], regular, 16, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 520 + (i * 25) + 120);
    }
}


void ThirdPage::setBill() {

    listMovie x;
    int filmIndex = (curentState - 10) % 11;
    string filePath = x.a[filmIndex].filePath;
    string filePathIconPrev = "images/icon-prev.png";

    m_blocks.AddBlockContainer(filePath, xPos, 113, xScale, yScale);
    m_blocks.AddBlockContainer(filePathIconPrev, xPos, 44, 0.22, 0.2);


    m_texts.AddTextContainer("SLC2T", bold, 50, Color::Red, 212, 35);
    // set film's name
    m_texts.AddTextContainer(x.a[filmIndex].name, bold, 30, Color::Black, 220 - 15, 100);
    // set film's category
    m_texts.AddTextContainer("The loai:", semiBold, 18, Color::Black, xLogoPosition - 15, 135);
    // set film's category content
    m_texts.AddTextContainer(x.a[filmIndex].type, regular, 16, Color::Black, xLogoPosition - 15 + 85, 137);
    // set film's time
    m_texts.AddTextContainer("Thoi luong:", semiBold, 18, Color::Black, xLogoPosition - 15, 160);
    // set film's time content
    m_texts.AddTextContainer(x.a[filmIndex].time, regular, 16, Color::Black, xLogoPosition - 15 + 110, 162);
    // set film's language
    m_texts.AddTextContainer("Ngon ngu:", semiBold, 18, Color::Black, xLogoPosition - 15, 185);
    // set film's language content
    m_texts.AddTextContainer(x.a[filmIndex].language, regular, 16, Color::Black, xLogoPosition - 15 + 105, 187);
    // set film's Rate
    m_texts.AddTextContainer("Danh gia:", semiBold, 18, Color::Black, xLogoPosition - 15, 210);
    // set film's Rate content
    m_texts.AddTextContainer(x.a[filmIndex].rating, regular, 16, Color::Black, xLogoPosition - 15 + 100, 212);
    // set film's Date
    m_texts.AddTextContainer("Khoi Chieu:", semiBold, 18, Color::Black, xLogoPosition - 15, 235);
    // set film's Date content
    m_texts.AddTextContainer("10/11/2023", regular, 16, Color::Black, xLogoPosition - 15 + 110, 237);

    // set bg-action
    Texture bgRed;
    bgRed.loadFromFile("images/bg-red.png");
    Sprite bgAction(bgRed);
    bgAction.setScale(0.3, 0.3);
    bgAction.setPosition(xIconPrevPosition, yIconPrevPosition + 380);
    // set action'title
    Text actionTitle("Thong tin ve", semiBold, 18);
    actionTitle.setFillColor(Color::Black);
    actionTitle.move(xIconPrevPosition + 25, yIconPrevPosition + 390);

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 280, 0.25, 0.3);
    m_texts.AddTextContainer("Thong tin ve", semiBold, 20, Color::White, xIconPrevPosition + 18, yIconPrevPosition + 290);

    m_texts.AddTextContainer("Vui long kiem tra thong tin truoc khi xac nhan!", regular, 16, Color::Black, xIconPrevPosition + 60, yIconPrevPosition + 360);

   
    string totalPrice = to_string(price * 100) + " VND";

    m_texts.AddTextContainer("SO LUONG", semiBold, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 410);
    m_texts.AddTextContainer(to_string(seats.size()), semiBold, 18, Color::Black, xIconPrevPosition + 400, yIconPrevPosition + 410);
    m_blocks.AddBlockContainer("images/line.png", xIconPrevPosition - 50, yIconPrevPosition + 425, 1, 1);
    m_texts.AddTextContainer("Tong", regular, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 440);
    m_texts.AddTextContainer(totalPrice, semiBold, 18, Color::Black, xIconPrevPosition + 400, yIconPrevPosition + 440);


   /* m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 20, yIconPrevPosition + 480, 1.3, 0.5);
    t_offer.AddTextContainer("MA KHUYEN MAI", semiBold, 18, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 490);
    m_blocks.AddBlockContainer("images/list-1.png", xIconPrevPosition + 487, yIconPrevPosition + 490, 0.3, 0.3);

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 540, 0.25, 0.3);
    m_texts.AddTextContainer("Thanh toan", semiBold, 20, Color::White, xIconPrevPosition + 25, yIconPrevPosition + 550);

    m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 20, yIconPrevPosition + 600, 1.3, 0.5);
    t_payment.AddTextContainer("PHUONG THUC THANH TOAN", semiBold, 18, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 610);
    m_blocks.AddBlockContainer("images/list-1.png", xIconPrevPosition + 487, yIconPrevPosition + 610, 0.3, 0.3);*/

    /*m_texts.AddTextContainer("Tong cong", regular, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 670);
    m_texts.AddTextContainer("Giam gia", regular, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 700);
    m_blocks.AddBlockContainer("images/line.png", xIconPrevPosition - 50, yIconPrevPosition + 720, 1, 1);
    m_texts.AddTextContainer("Tong", semiBold, 20, Color::Black, xIconPrevPosition, yIconPrevPosition + 750);
    */

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition + 30, yIconPrevPosition + 550, 0.65, 0.45);
    m_texts.AddTextContainer("Xac nhan thanh toan", semiBold, 25, Color::White, xIconPrevPosition + 130, yIconPrevPosition + 560);
}

//



void ThirdPage::HandleMouseClick(int x, int y)
{
    // trở về page2 nếu bấm vào nút prev
   if (x >= 40 && x <= 80 && y >= 40 && y <= 80)
   {
        cout << "Back button" << endl;
        if (!isBillShowed) {
            curentState -= 10;
            // xóa các ghế vừa chọn được chọn
            seats.clear();
            this->seatColorUpdate(seats);
            this->seatUpdate(seats);
        }
       /* else {
            
        }*/
   }

   // click logo chuyển về trang đầu tiên
   if (212 <= x && x <= 360 && 37 <= y && y <= 73) {
       cout << "Click on logo" << endl;
       curentState = 1;
   }

   if (isBillShowed && 75 <= x && x <= 587 && 500 <= y && y <= 650) {
       curentState = 1;
   }

   // kiểm tra nếu ghế đã được chọn và bấm vào nút thì chuyển sang page4
   // nếu ghế chưa được chọn thì k cho chuyển
   if (!seats.empty() && x >= 40 && x <= 240 && y >= 415 && y <= 455) {
       m_texts.reset();
       m_blocks.reset();
       seatInfo.reset();
       this->setBill();
       isBillShowed = true;
   }


   int temp = this->seatSelected(x, y);

   if (temp != -1) {
       auto it = find(seats.begin(), seats.end(), temp);
       // hủy chọn nếu ghế đã được chọn trước đó
       if (it != seats.end()) {
           seats.erase(remove(seats.begin(), seats.end(), temp), seats.end());
           this->seatUpdate(seats);
           this->seatColorUpdate(seats);
           cout << '~' << this->seatName(temp) << endl;
       }
       // chọn ghế nếu ghế chưa được chọn
       else {
           seats.push_back(temp);
           this->seatUpdate(seats);
           this->seatColorUpdate(seats);
           cout << this->seatName(temp) << endl;
       }
   }

}
void ThirdPage::Click(int x, int y) {

}
int ThirdPage::GetState()
{
    return selectedItemIndex;
}
int ThirdPage::GetCurrentState()
{
    return curentState;
}
void ThirdPage::SetCurrentState(int state)
{
    curentState = state;
}