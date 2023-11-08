#include "Welcome.h"

Welcome::Welcome(QWidget *parent) : BaseWidget(__FUNCTION__, parent)
{
    QVBoxLayout *leyaut = new QVBoxLayout(this);
    QLabel *label = new QLabel("Witamy w aplikacji do przewidywania wyników rozgrywek sportowych reprezentacji polski.",this);
    label->setWordWrap(true);
    leyaut->addWidget(label, 0, Qt::AlignHCenter);
    QPushButton *bt = new QPushButton("Start", this);
    leyaut->addWidget(bt);

    connect(bt, &QPushButton::clicked, this, &Welcome::onBackClidked);

}

void Welcome::onBackClidked()
{
    emit changeWidget(widgetMap.at("SelectDiscipline"));
}
