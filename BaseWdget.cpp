#include "BaseWidget.h"

#include <iostream>
std::map<QString, QWidget*> BaseWidget::widgetMap;

BaseWidget::BaseWidget(QString name, QWidget *parent) : QWidget{parent}
{
    widgetMap.insert({name, this});
}

QWidget* BaseWidget::getWidget(QString name)
{
    return widgetMap.at(name);
}
