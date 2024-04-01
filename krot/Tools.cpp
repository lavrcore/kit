#include "Tools.h"


void Tools::showMenu() {
	std::cout << "1 - ���������� ������." << std::endl;
	std::cout << "2 - ���������� ������� �� 5 ����." << std::endl;
	std::cout << "3 - ������ ����� �����." << std::endl;
	std::cout << "4 - �����" << std::endl;
}


void Tools::showCurrentWeather(nlohmann::json data) {
	std::cout << "������: " << data["weather"][0]["main"] << std::endl;
	std::cout << "�����������: " << (int)(data["main"]["temp"].get<double>() - 273.15) << std::endl;
}


void Tools::showFiveDaysForecast(nlohmann::json data) {
	for (int i = 0; i < data["list"].size(); i++) {
		std::cout << data["list"][i]["dt_txt"];
		std::cout << " " << data["list"][i]["weather"][0]["main"];
		std::cout << " Temp: " << (int)(data["list"][i]["main"]["temp"].get<double>() - 273.15) << std::endl;
	}
}