#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "ThirdPage.h"
#include "MainTab.h"
#include "dataBase.h"
class FourthPage : public MainTab
{
private:
	pair<int, int> m_seats;
	BlockContainer m_blocks;
	TextContainer m_texts;
	BlockContainer b_payment;
	TextContainer t_payment;
	BlockContainer b_offer;
	TextContainer t_offer;

	bool isOfferSelected = false;
	bool isPaymentSelected = false;

public:
	FourthPage(int num);
	~FourthPage();
	void draw(RenderWindow& window);
	void setSeat(const ThirdPage& temp) {
		m_seats = temp.getSeat();
	}
	void selectOffer();
	void resetOffer();
	void selectPayment();
	//void paymentIndex(int x, int y);
	//void offerIndex(int x, int y);
	void resetPayment();
	void HandleMouseClick(int x, int y);
	void Click(int x, int y);
	int GetState();
	int GetCurrentState();
	void SetCurrentState(int state);
};
