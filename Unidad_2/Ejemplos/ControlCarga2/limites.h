#ifndef LIMITES_H
#define LIMITES_H

#include <QDialog>

namespace Ui {
class Limites;
}

class Limites : public QDialog
{
    Q_OBJECT

public:
    explicit Limites(QWidget *parent = nullptr);
    ~Limites();

private:
    Ui::Limites *ui;
};

#endif // LIMITES_H
