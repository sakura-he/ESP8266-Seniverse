/*
To Do:
1. Add ArduinoJson parse success check
2. add http response code check
*/

#ifndef _ESP8266_Xinzhi_H_
#define _ESP8266_Xinzhi_H_
 
#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#define DEBUG
class WeatherNow {
  public:
    WeatherNow();

    void config(String userKey, String location, String unit);
    bool update();
    String getWeatherText();
    int getWeatherCode();
    int getDegree();
    String getLastUpdate();
    
  private:  
    const char* _host = "api.seniverse.com";     // 服务器地址  
        
    String _reqUserKey;   // 私钥
    String _reqLocation;  // 城市
    String _reqUnit;      // 摄氏/华氏

    void _parseNowInfo(WiFiClient client);      // 解析实时天气信息信息

    String _now_text_str = "no_init"; 
    int _now_code_int = 404; 
    int _now_temperature_int = 404;     
    String _last_update_str = "no_init";   
};
 
#endif
