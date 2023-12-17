#ifndef SELECTDISCIPLINE_H
#define SELECTDISCIPLINE_H

#include <QtWidgets>
#include <vector>
#include <string>
#include "BaseWidget.h"
#include "PushButton.h"

class SelectDiscipline : public BaseWidget
{
    Q_OBJECT

public:
    explicit SelectDiscipline(QWidget *parent = nullptr);

    void loadDisciplines();

signals:
    void sportChosed(QString name);

private:
    std::vector<PushButton *> m_sportVect;
    QVBoxLayout *m_mainLayout {nullptr};
    QPushButton *m_backButton {nullptr};
    void onSoprtClidked(QString name);
    void onClickedBack();
    void createAllObject();
    void createStaticObjectAndAddToLayout();
    void connectAllSignals();
};

#endif // SELECTDISCIPLINE_H
