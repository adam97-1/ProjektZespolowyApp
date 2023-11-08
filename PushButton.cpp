#include "PushButton.h"

PushButton::PushButton(QWidget *parent) : QPushButton{parent}
{
    connect(this, &QPushButton::clicked, [&](){emit onClidkedWithText(this->text().toStdString());});
}
PushButton::PushButton(const QString &text, QWidget *parent): QPushButton{text, parent}
{
    connect(this, &QPushButton::clicked, [&](){emit onClidkedWithText(this->text().toStdString());});
}
PushButton::PushButton(const QIcon& icon, const QString &text, QWidget *parent) : QPushButton{icon, text, parent}
{
    connect(this, &QPushButton::clicked, [&](){emit onClidkedWithText(this->text().toStdString());});
}
