#include "Result.h"

Result::Result(QWidget *parent) : BaseWidget(__FUNCTION__, parent)
{
    QVBoxLayout *leyaut = new QVBoxLayout(this);
    QLabel *label = new QLabel("Przewidywany wynik to:",this);
    leyaut->addWidget(label, 0, Qt::AlignHCenter);
    QLabel *label_wynik = new QLabel("Wygrana!!!",this);
    leyaut->addWidget(label_wynik, 0, Qt::AlignHCenter);
    leyaut->addWidget(new QWidget(this),2);
    QPushButton *bt = new QPushButton("Powrót", this);
    leyaut->addWidget(bt);

    connect(bt, &QPushButton::clicked, this, &Result::onBackClidked);
}

void Result::onBackClidked()
{
    emit changeWidget(widgetMap.at("SelectCountry"));
}
