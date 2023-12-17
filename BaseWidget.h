#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QtWidgets>
#include <map>

class BaseWidget : public QWidget
{
Q_OBJECT

public:
    explicit BaseWidget(QString name, QWidget *parent = nullptr);
    QWidget* getWidget(QString name);
signals:
    void changeWidget(QWidget *widget);

protected:
    static std::map<QString, QWidget*> widgetMap;
};

#endif // BASEWIDGET_H
