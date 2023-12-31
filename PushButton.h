#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QtWidgets>
#include <string>

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(QWidget *parent = nullptr);
    explicit PushButton(const QString &text, QWidget *parent = nullptr);
    PushButton(const QIcon& icon, const QString &text, QWidget *parent = nullptr);

signals:
    void onClidkedWithText(QString name);

};

#endif // PUSHBUTTON_H
