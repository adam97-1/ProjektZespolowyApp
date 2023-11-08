#ifndef RESULT_H
#define RESULT_H

#include <QtWidgets>
#include "BaseWidget.h"

class Result : public BaseWidget
{
    Q_OBJECT
public:
    explicit Result(QWidget *parent = nullptr);

private:
    void onBackClidked();
};

#endif // RESULT_H
