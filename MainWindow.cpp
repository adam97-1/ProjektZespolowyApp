#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{

    resize(600,600);

    m_welcome = new Welcome(this);
    m_selectDiscipline = new SelectDiscipline(this);
    m_selectCountry = new SelectCountry(this);
    m_result = new Result(this);


    m_stackWidget = new QStackedWidget(this);
    QVBoxLayout *layaut = new QVBoxLayout(this);
    layaut->addWidget(m_stackWidget);

    m_stackWidget->addWidget(m_welcome);
    m_stackWidget->addWidget(m_selectDiscipline);
    m_stackWidget->addWidget(m_selectCountry);
    m_stackWidget->addWidget(m_result);

    connect(m_welcome, &BaseWidget::changeWidget, this, &MainWindow::onChangeWidget);

    connect(m_selectDiscipline, &BaseWidget::changeWidget, this, &MainWindow::onChangeWidget);
    connect(m_selectDiscipline, &SelectDiscipline::sportChosed, this, &MainWindow::onSportSelected);

    connect(m_selectCountry, &SelectCountry::changeWidget, this, &MainWindow::onChangeWidget);
    connect(m_selectCountry, &SelectCountry::countryChosed, this, &MainWindow::onCountrySelected);

    connect(m_result, &Result::changeWidget, this, &MainWindow::onChangeWidget);



}

MainWindow::~MainWindow()
{
}

void MainWindow::onChangeWidget(QWidget *widget)
{
    m_stackWidget->setCurrentWidget(widget);
}

void MainWindow::onSportSelected(std::string name)
{
    std::cout << __PRETTY_FUNCTION__ << ": " << name << std::endl;
    m_stackWidget->setCurrentWidget(m_selectCountry);
}

void MainWindow::onCountrySelected(std::string name)
{
    std::cout << __PRETTY_FUNCTION__ << ": " << name << std::endl;
    m_stackWidget->setCurrentWidget(m_result);
}


