#ifndef AUXILIARC_H
#define AUXILIARC_H

#include <QDialog>

namespace Ui {
class auxiliarC;
}

class auxiliarC : public QDialog
{
    Q_OBJECT

public:
    explicit auxiliarC(QWidget *parent = nullptr);
    ~auxiliarC();

private:
    Ui::auxiliarC *ui;
};

#endif // AUXILIARC_H
