#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void validatorChanged();
    bool isDigitString(const QString src);

private slots:


    void on_Button_DJ_1_clicked();

    void on_Button_DJ_2_clicked();

    void on_Button_DJ_3_clicked();

    void on_Button_DX_1_clicked();

    void on_Button_DX_2_clicked();

    void on_Button_DX_3_clicked();

    void on_Button_qingkong_clicked();








private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
