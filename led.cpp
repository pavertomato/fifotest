#include "led.h"


Led::Led():Led(0,red,1)
{

}

Led::Led(bool state, Led::Color color, short rate): state_(state),color_(color),rate_(rate)
{

}

bool Led::state()
{
    return state_;
}


std::string Led::stateText(std::vector<std::string> elems)
{
    if(elems.size()!=1)
        return "FAILED";
    std::string answer="OK ";
    if(state_)
        answer+="on";
    else
        answer+="off";
    return answer;
}

std::string Led::colorText(std::vector<std::string> elems)
{
    if(elems.size()!=1)
        return "FAILED";
    std::string answer="OK ";
    answer+=color();
    return answer;
}

std::string Led::setColorText(std::vector<std::string> elems)
{
    std::string answer="FAILED";
    if(elems.size()==2)
        if(setColor(elems[1]))
            answer="OK";
    return answer;
}


std::string Led::setStateText(std::vector<std::string> elems)
{
    std::string answer="FAILED";
    if(elems.size()==2)
        if(setState(elems[1]))
            answer="OK";
    return answer;
}

std::string Led::color()
{
    std::string colorTmp;
    switch(color_)
    {
        case red  : colorTmp="red";   break;
        case green: colorTmp="green"; break;
        case blue : colorTmp="blue";  break;
    }
    return colorTmp;
}

short Led::rate()
{
    return rate_;
}

std::string Led::rateText(std::vector<std::string> elems)
{
    if(elems.size()>1)
        return "FAILED";
    std::string answer="OK ";
    std::ostringstream stm ;
    stm << rate();
    answer+=stm.str();
    return answer;
}

bool Led::setState(bool state)
{
    state_=state;
    return 1;
}

bool Led::setState(std::string state)
{
    bool stateB;
    if(state=="on\n")
        stateB=1;
    else if(state=="off\n")
            stateB=0;
    else
        return 0;
    return setState(stateB);
}


bool Led::setColor(Led::Color color)
{
    color_=color;
    return 1;
}

bool Led::setColor(int color)
{
    bool status=1;
    switch(color)
    {
        case 0  : setColor(red);   break;
        case 1:   setColor(green); break;
        case 2 : setColor(blue);  break;
        default: status=0; break;
    }
    return status;
}

bool Led::setColor(std::string color)
{
    Color colorC;
    if(color=="red\n")
        colorC=red;
    else if(color=="green\n")
        colorC=green;
    else if(color=="blue\n")
        colorC=blue;
    else
        return 0;
    return setColor(colorC);
}

bool Led::setRate(short rate)
{
    if(rate>=0&&rate<=5)
        return rate_=rate;
    return 0;
}

std::string Led::setRateText(std::vector<std::string> elems)
{
    std::string answer="FAILED";
    if(elems.size()==2)
        if(setRate(short(elems[1][0])-48))
            answer="OK";
    return answer;
}

std::string Led::textCommand(std::string command)
{
    
     std::stringstream ss(command);
    std::string item;
    char sep=' ';
     std::vector<std::string> elems;
    while (std::getline(ss, item, sep))
    {
           elems.push_back(item);
    }
    
    std::string answer;
    int commandNum=selectCommand(elems[0]);
    
    switch(commandNum)
        {
            case 0:
                answer=stateText(elems);
            break;

            case 1:
                answer=setStateText(elems);
            break;
            case 2:
                answer=colorText(elems);
            break;

            case 3:
                answer=setColorText(elems);
            break;
            case 4:
                answer=rateText(elems);
            break;
            case 5:
                answer=setRateText(elems);
            break;

            default:
                answer="FAILED";
            break;
        }
    return answer;
}

int Led::selectCommand(std::string command)
{
    int commandNum=-1;
    if(command=="get-led-state\n")
        commandNum=0;
    else if (command=="set-led-state")
        commandNum=1;
    else if (command=="get-led-color\n")
        commandNum=2;
    else if (command=="set-led-color")
        commandNum=3;
    else if (command=="get-led-rate\n")
        commandNum=4;
    else if (command=="set-led-rate")
        commandNum=5;

    return commandNum;
}

