#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "MainTab.h"
#include "dataBase.h"
class ThirdPage : public MainTab
{
private:
	int price = 0;
	vector<int> seats;
	BlockContainer m_blocks;
	TextContainer m_texts;


	/*BlockContainer f_blocks;
	TextContainer f_texts;*/


	TextContainer seatInfo;

	BlockContainer b_payment;
	TextContainer t_payment;
	BlockContainer b_offer;
	TextContainer t_offer;


	bool isBillShowed = false;
	bool isOfferSelected = false;
	bool isPaymentSelected = false;


public:
	ThirdPage(int num);
	~ThirdPage();
	void draw(RenderWindow& window);
	pair<int,int> getSeat() const {
		return { seats.size(), price };
	}
	int seatSelected(int x, int y);
	void seatColorUpdate(vector<int> seatIndex);
	string seatName(int seatIndex);
	void seatUpdate(vector<int> seats);
	void setBill();
	void HandleMouseClick(int x, int y);
	void Click(int x, int y);
	int GetState();
	int GetCurrentState();
	void SetCurrentState(int state);
	void selectOffer();
	void resetOffer();
	void selectPayment();
	void resetPayment();
	friend class FourthPage;
};