#include <iostream>
#include <curl/curl.h>
#include "../header/json.hpp"
#include "../header/OpenWeather.h"

using std::cout;
using std::endl;

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata){
    std::string *buffer = (std::string*) userdata;
    buffer->append(ptr, size * nmemb)
    return size * nmemb;//return the number of bytes actually taken care of
}


WindInfo get_ksmf_wind(const std::string open_weather_api){
    WindInfo ksmf_info = {0.0, 0, false};
    CURL* curl = curl_easy_init();
    std::string api_call = "https://api.openweathermap.org/data/3.0/onecall/day_summary?lat=38.695556&lon=-121.590833&units=metric&appid="
                            + open_weather_api;
    std::string saved_data;

    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, api_call);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, saved_data);

        CURLcode res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            auto data = json::parse(saved_data);
            WindInfo.wind_speed = data["wind"]["speed"];
            WindInfo.wind_deg = data["wind"]["deg"];
            WindInfo.state = true;
        }
        else if(res == CURLE_OPERATION_TIMEDOUT){
            cout << "The request timed out." << endl;
        }

        curl_easy_cleanup(curl);
    }
    
    return ksmf_info;
}