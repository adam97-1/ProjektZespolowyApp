#ifndef WELLCOME_H
#define WELLCOME_H

#include <QtWidgets>
#include "BaseWidget.h"

class Wellcome : public BaseWidget
{
    Q_OBJECT
public:
    explicit Wellcome( QWidget *parent = nullptr);

private:
    QVBoxLayout *m_Mainleyaut {nullptr};
    QPushButton *m_startButton {nullptr};

    void onStartClidked();
    void createAllObject();
    void connectAllSignals();
    void createStaticObjectAndAddToLayout();
};

#endif // WELLCOME_H
