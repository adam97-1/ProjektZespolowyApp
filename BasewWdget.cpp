#include "BaseWidget.h"

#include <iostream>
std::map<std::string, QWidget*> BaseWidget::widgetMap;

BaseWidget::BaseWidget(std::string name, QWidget *parent) : QWidget{parent}
{
    std::cout << "Name:" << name << std::endl;
    widgetMap.insert({name, this});
}
