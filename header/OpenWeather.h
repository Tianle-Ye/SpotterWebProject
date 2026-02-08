#ifndef OPEN_WEATHER_H
#define OPEN_WEATHER_H

#include <string>

struct WindInfo(){
    double wind_speed;
    int wind_deg;
    bool state;
}

WindInfo get_ksmf_wind(const std::string open_weather_api);

#endif