#include "WebApp.h"
#include "Tools.h"

using json = nlohmann::json;


WebApp::WebApp(std::string client, std::string API, std::string cityName) {
	this->cli = new httplib::Client(client);
	this->API = API;
	this->cityName = cityName;
}


void WebApp::setCityName(std::string& cityName) {
	this->cityName = cityName;
}


json WebApp::getResult(std::string request) {
	return json::parse(this->cli->Get(request)->body);
}


json WebApp::getCurrentWeather() {
	this->request = "/data/2.5/weather?";
	this->request += "q=" + this->cityName;
	this->request += "&appid=" + this->API;
	return this->getResult(request);
}


json WebApp::getFiveDaysForecast() {
	this->request = "/data/2.5/forecast?";
	this->request += "q=" + this->cityName;
	this->request += "&appid=" + this->API;
	return this->getResult(request);
}
void Tools::showFiveDaysForecast(nlohmann::json data) {
	int i = 0;
	int j = i + 1;

	std::string dateDay;
	std::string dateDayJ;
	int counter = 0;
	double sum = 0;

	while (i < data["list"].size()|| dateDay == dateDayJ && j < data["list"].size()) {
		dateDay = data["list"][i]["dt_txt"].get<std::string>().substr(8, 2);
		counter = 1;
		sum = data["list"][i]["main"]["temp"].get<double>() - 273.15;
		dateDayJ = data["list"][j]["dt_txt"].get<std::string>().substr(8, 2);
		
		counter++;
		sum += data["list"][j]["main"]["temp"].get<double>() - 273.15;
		dateDayJ = data["list"][j]["dt_txt"].get<std::string>().substr(8, 2);
		j++;
		
		std::cout << data["list"][i]["dt_txt"].get<std::string>().substr(0, 10);
		std::cout << " Average Temp: " << (int)(sum / counter) << std::endl;
		i = j;
		j = i + 1;
	}
}