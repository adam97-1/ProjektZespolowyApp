#include "SelectCountry.h"
#include <iostream>

SelectCountry::SelectCountry(QWidget *parent) : BaseWidget(__FUNCTION__, parent)
{
    QFile file("./Country.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd())
    {
        QByteArray line = file.readLine().removeLast();
        m_countryVect.push_back(new PushButton(QString(line.toStdString().data()), this));
    }


    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->addWidget(new QLabel("Select country's representation", this), 0, Qt::AlignCenter);

    m_searchCountry = new QLineEdit(this);
    layout_main->addWidget(m_searchCountry);

    QScrollArea *scrollarea = new QScrollArea(this);
    QWidget * scrollWidget = new QWidget();
    QVBoxLayout *layout_button = new QVBoxLayout(scrollWidget);

    scrollarea->setWidgetResizable(true);
    layout_main->addWidget(scrollarea, 1);
    scrollarea->setWidget( scrollWidget );

    for(auto country : m_countryVect)
    {
        layout_button->addWidget(country);
        connect(country, &PushButton::onClidkedWithText, this, &SelectCountry::onCountryClidked);
    }

    QPushButton *bt_back = new QPushButton("Back", this);
    layout_main->addWidget(bt_back);

    connect(bt_back, &QAbstractButton::clicked, [&](){emit changeWidget(widgetMap.at("SelectDiscipline"));});
    connect(m_searchCountry, &QLineEdit::textChanged, this, &SelectCountry::onSearchCountryTextChanged);
}

void SelectCountry::onCountryClidked(std::string name)
{
    emit countryChosed(name);
}

void SelectCountry::onSearchCountryTextChanged(const QString &text)
{
    for(auto country : m_countryVect)
    {
        if(!country->text().toLower().contains(text.toLower()))
            country->hide();
        else
            country->show();
    }
}

