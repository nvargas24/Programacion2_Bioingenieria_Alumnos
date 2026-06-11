#ifndef AUXILIARA_H
#define AUXILIARA_H

#include <QDialog>

namespace Ui {
class auxiliarA;
}

class auxiliarA : public QDialog
{
    Q_OBJECT

public:
    explicit auxiliarA(QWidget *parent = nullptr);
    ~auxiliarA();

private:
    Ui::auxiliarA *ui;
};

#endif // AUXILIARA_H
