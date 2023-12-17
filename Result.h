#ifndef RESULT_H
#define RESULT_H

#include <QtWidgets>
#include "BaseWidget.h"

class Result : public BaseWidget
{
    Q_OBJECT
public:
    explicit Result(QWidget *parent = nullptr);
    void setTextResult(QString text);

private:
    void createAllObject();
    void createStaticObjectAndAddToLayout();
    void connectAllSignals();

    QVBoxLayout * m_mainLayout {nullptr};
    QLabel *m_ResultLabel {nullptr};
    QPushButton *m_backButton = {nullptr};

    void onBackClidked();
};

#endif // RESULT_H
