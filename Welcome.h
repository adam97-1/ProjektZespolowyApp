#ifndef WELCOME_H
#define WELCOME_H

#include <QtWidgets>
#include "BaseWidget.h"

class Welcome : public BaseWidget
{
    Q_OBJECT
public:
    explicit Welcome( QWidget *parent = nullptr);

private:
    void onBackClidked();
};

#endif // WELCOME_H
