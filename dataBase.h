#pragma once
#include <iostream>
using namespace std;
class movie
{
public:
	string filePath, rating, time, name, type, language, rate, director, artist, content;
	void setData(string filePath, string rating, string time, string name, string type, string language, string rate, string director, string artist, string content) {
		this->filePath = filePath;
		this->rating = rating;
		this->time = time;
		this->name = name;
		this->type = type;
		this->language = language;
		this->rate = rate;
		this->director = director;
		this->artist = artist;
		this->content = content;

	}
};
class listMovie {
public:
	movie a[6];
	listMovie() {
		a[0].setData(
			"images/data/nam-dem-kinh-hoang.png",
			"4.5 / 5",
			"1 gio 49 phut",
			"Nam dem kinh hoang",
			"Kinh di",
			"Tieng Anh - Phu de Tieng Viet",
			"13+",
			"Emma Tammi",
			"Matthew Lillard, Josh Hutcherson, Mary Stuart",
			"Nhan vien bao ve Mike bat dau lam viec tai ..."
		);
		a[1].setData(
			"images/data/marvel.png",
			"4.6 / 5",
			"1 gio 45 phut",
			"The Marvels",
			"Hanh dong, Phieu luu, Than thoai",
			"Tieng Anh - Phu de Tieng Viet",
			"13+",
			"Nia DaCosta",
			"Brie Larson, Samuel L. Jackson, Zawe Ashton",
			"Phan tiep theo cua Captain Marvel (2019)"
		);
		a[2].setData(
			"images/data/ke-kien-tao.png",
			"4.5 / 5",
			"2 gio 15 phut",
			"Ke kien tao",
			"Hanh dong, Kho hoc vien tuong",
			"Tieng Anh - Phu de Tieng Viet",
			"16+",
			"Gareth Edwards",
			"Allison Janney, Amar Chadha-Patel,...",
			"Vien canh tuong lai ve cuoc chien keo dai ..."
		);
		a[3].setData(
			"images/data/sieu-dang.png",
			"4.5 / 5",
			"1 gio 35 phut",
			"Sieu dang",
			"Hoat hinh, Hanh dong, Phieu luu",
			"Tieng Anh - Phu de Tieng Viet",
			"13+",
			"Cal Brunker",
			"Mckenna Grace, James Marsden, Kristen Bell, chris rock, tyler perry",
			"Mot mang thien thach roi vao Trai Dat ..."
		);
		a[4].setData(
			"images/data/cu-may-an-tien.png",
			"4.5 / 5",
			"2 gio 13 phut",
			"Cu may an tien",
			"Tam ly",
			"Tieng Han - Phu de Tieng Viet, Tieng Anh",
			"16+",
			"KIM Jee-woon",
			"SONG Kang-ho, LIM Soo-jung, OH Jung-se, JEON Yeo-been,...",
			"Lay boi canh thuc te nhung nam 1970..."
		);
		a[5].setData(
			"images/data/biet-doi-danh-thue.png",
			"4.5 / 5",
			"1 gio 43 phut",
			"Biet doi danh thue 4",
			"Hanh dong, Hoi hop, Phieu luu",
			"Tieng Anh - Phu de Tieng Viet",
			"18+",
			"Scott Waugh",
			"Jason Statham, 50 Cent, Megan Fox",
			"lan nay ho tro lai voi nhiem vu moi..."
		);
	}
};