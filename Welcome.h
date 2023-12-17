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
    QVBoxLayout *m_Mainleyaut {nullptr};
    QPushButton *m_startButton {nullptr};

    void onStartClidked();
    void createAllObject();
    void connectAllSignals();
    void createStaticObjectAndAddToLayout();
};

#endif // WELCOME_H
