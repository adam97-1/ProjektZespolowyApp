#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QtWidgets>
#include <map>

class BaseWidget : public QWidget
{
Q_OBJECT

public:
    explicit BaseWidget(std::string name, QWidget *parent = nullptr);
signals:
    void changeWidget(QWidget *widget);

protected:
    static std::map<std::string, QWidget*> widgetMap;
};

#endif // BASEWIDGET_H
