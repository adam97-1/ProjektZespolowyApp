#include "Welcome.h"

Welcome::Welcome(QWidget *parent) : BaseWidget(__FUNCTION__, parent)
{
    QVBoxLayout *leyaut = new QVBoxLayout(this);
    QLabel *label = new QLabel("Welcome to the application for predicting the results of sports games of the Polish national team.",this);
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
