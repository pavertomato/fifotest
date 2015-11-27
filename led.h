#ifndef LED_H
#define LED_H
#include "string"
#include <iostream>
#include "sstream"
#include "vector"

class Led
{

    public:
        enum Color {red, green, blue};
        Led();
        Led(bool state,Color color,short rate);
        bool state();
        std::string stateText(std::vector<std::string> elems);
        std::string setStateText(std::vector<std::string> elems);
        std::string color();
        std::string colorText(std::vector<std::string> elems);
        std::string setColorText(std::vector<std::string> elems);
        short rate();
        std::string rateText(std::vector<std::string> elems);
        bool setState(bool state);
        bool setState(std::string state);
        bool setColor(Color color);
        bool setColor(int color);
        bool setColor(std::string color);
        bool setRate(short rate);
        std::string setRateText(std::vector<std::string> elems);
        std::string textCommand(std::string command);
        int selectCommand(std::string command);
    private:
        bool state_;
        Color color_;
        short rate_;

};

#endif // LED_H
