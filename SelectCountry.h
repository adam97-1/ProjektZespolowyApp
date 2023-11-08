#ifndef SELECTCOUNTRY_H
#define SELECTCOUNTRY_H

#include <QtWidgets>
#include <vector>
#include "BaseWidget.h"
#include "PushButton.h"

class SelectCountry : public BaseWidget
{
Q_OBJECT

public:
    explicit SelectCountry(QWidget *parent = nullptr);

signals:
    void countryChosed(std::string name);

private:
    std::vector<PushButton *> m_countryVect;
    QLineEdit *m_searchCountry  {nullptr};
    void onCountryClidked(std::string name);
    void onSearchCountryTextChanged(const QString &text);
};

#endif // SELECTCOUNTRY_H
