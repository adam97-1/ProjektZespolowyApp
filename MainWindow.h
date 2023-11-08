#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <iostream>
#include "Welcome.h"
#include "SelectDiscipline.h"
#include "SelectCountry.h"
#include "Result.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QStackedWidget *m_stackWidget {nullptr};
    Welcome *m_welcome {nullptr};
    SelectDiscipline *m_selectDiscipline {nullptr};
    SelectCountry *m_selectCountry {nullptr};
    Result *m_result {nullptr};

    void onChangeWidget(QWidget *widget);
    void onSportSelected(std::string name);
    void onCountrySelected(std::string name);
};
#endif // MAINWINDOW_H
