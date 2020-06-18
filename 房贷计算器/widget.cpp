#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}
Widget::~Widget()
{
    delete ui;
}
bool Widget::isDigitString(const QString src)//判断是否为数字
{
    const char *s = src.toUtf8().data();
    while((*s && *s>='.' && *s<='9'))s++;
    return !bool(*s);
}
void Widget::on_Button_DJ_1_clicked()
{
    //按单价、面积计算  等额本金
    double danjia,area,chengshu,year1,lilv;//单价、面积、按揭成数、按揭年数、年利率
    double dai0,huan0,li0,yue0,shouyue0,dijian0;//贷款总额、还款总额、支付利息、还款月数、首月月供、每月递减
    QString dai,huan,li,yue,shouyue,dijian;
    danjia=ui->lineEdit_danjia->text().toDouble();//得到lineEdit中数据
    area=ui->lineEdit_area->text().toDouble();
    chengshu=ui->lineEdit_chengshu->text().toDouble();
    year1=ui->lineEdit_year1->text().toDouble();
    lilv=ui->lineEdit_lilv1->text().toDouble();
    if(danjia<0||danjia>1000000||isDigitString(ui->lineEdit_danjia->text())==false
            ||area<0||area>1000||isDigitString(ui->lineEdit_area->text())==false
            ||chengshu<2||chengshu>8||isDigitString(ui->lineEdit_chengshu->text())==false
            ||year1<1||year1>30||isDigitString(ui->lineEdit_year1->text())==false
            ||lilv<2||lilv>6||isDigitString(ui->lineEdit_lilv1->text())==false)
    {
        QMessageBox::StandardButton lineEdit;
        lineEdit=QMessageBox::warning(this,"提示","输入数据不合法",QMessageBox::Yes);
        if(lineEdit== QMessageBox::Yes)
           {
             ui->lineEdit_danjia->clear();
             ui->lineEdit_area->clear();
             ui->lineEdit_chengshu->clear();
             ui->lineEdit_year1->clear();
             ui->lineEdit_lilv1->clear();
             ui->lineEdit_dai->clear();
             ui->lineEdit_huan->clear();
             ui->lineEdit_li->clear();
             ui->lineEdit_shouyue->clear();
             ui->lineEdit_dijian->clear();
             ui->lineEdit_yue->clear();
           }
    }
    dai0=danjia*area*chengshu*0.1;//贷款总额
    yue0=year1*12;//还款月数
    li0=(yue0+1)*dai0*0.01*lilv/24;//支付利息
    huan0=dai0+li0;//还款总额
    shouyue0=(dai0/yue0)+dai0*0.01*lilv/12;//首月月供
    dijian0=dai0/yue0*0.01*lilv/12;//每月递减
    dai=QString::number(dai0);
    huan=QString::number(huan0);
    li=QString::number(li0);
    yue=QString::number(yue0);
    shouyue=QString::number(shouyue0);
    dijian=QString::number(dijian0);
    ui->lineEdit_dai->setText(dai);
    ui->lineEdit_huan->setText(huan);
    ui->lineEdit_li->setText(li);
    ui->lineEdit_yue->setText(yue);
    ui->lineEdit_shouyue->setText(shouyue);
    ui->lineEdit_dijian->setText(dijian);
}
void Widget::on_Button_DJ_2_clicked()
{
    //按贷款总额  等额本金
    double zonge,year1,lilv;//贷款总额、按揭年数、年利率
    double dai0,huan0,li0,yue0,shouyue0,dijian0;//贷款总额、还款总额、支付利息、还款月数、首月月供、每月递减
    QString dai,huan,li,yue,shouyue,dijian;
    zonge=ui->lineEdit_zonge->text().toDouble();
    year1=ui->lineEdit_year2->text().toDouble();
    lilv=ui->lineEdit_lilv2->text().toDouble();
    if(zonge<1||zonge>10000||isDigitString(ui->lineEdit_zonge->text())==false
            ||year1<1||year1>30||isDigitString(ui->lineEdit_year2->text())==false
            ||lilv<2||lilv>6||isDigitString(ui->lineEdit_lilv2->text())==false)
    {
        QMessageBox::StandardButton lineEdit;
        lineEdit=QMessageBox::warning(this,"提示","输入数据不合法",QMessageBox::Yes);
        if(lineEdit== QMessageBox::Yes)
          {
            ui->lineEdit_zonge->clear();
            ui->lineEdit_year2->clear();
            ui->lineEdit_lilv2->clear();
            ui->lineEdit_dai->clear();
            ui->lineEdit_huan->clear();
            ui->lineEdit_li->clear();
            ui->lineEdit_shouyue->clear();
            ui->lineEdit_dijian->clear();
            ui->lineEdit_yue->clear();
          }
    }
    dai0=zonge*10000;//贷款总额
    yue0=year1*12;//还款月数
    li0=(yue0+1)*dai0*0.01*lilv/24;//支付利息
    huan0=dai0+li0;//还款总额
    shouyue0=(dai0/yue0)+dai0*0.01*lilv/12;//首月月供
    dijian0=dai0/yue0*0.01*lilv/12;//每月递减
    dai=QString::number(dai0);
    huan=QString::number(huan0);
    li=QString::number(li0);
    yue=QString::number(yue0);
    shouyue=QString::number(shouyue0);
    dijian=QString::number(dijian0);
    ui->lineEdit_dai->setText(dai);
    ui->lineEdit_huan->setText(huan);
    ui->lineEdit_li->setText(li);
    ui->lineEdit_yue->setText(yue);
    ui->lineEdit_shouyue->setText(shouyue);
    ui->lineEdit_dijian->setText(dijian);
}
void Widget::on_Button_DJ_3_clicked()
{
    //组合型贷款  等额本金
    double shangdai,gongdai,year1,shanglilv,gonglilv;//商业贷款总额，公积金贷款总额，按揭年数，商业利率，公积金利率
    double dai0,huan0,li0,yue0,shouyue0,dijian0;//贷款总额、还款总额、支付利息、还款月数、首月月供、每月递减
    QString dai,huan,li,yue,shouyue,dijian;
    shangdai=ui->lineEdit_shangye->text().toDouble();
    gongdai=ui->lineEdit_gongjijin->text().toDouble();
    year1=ui->lineEdit_year3->text().toDouble();
    shanglilv=ui->lineEdit_shangye_lilv->text().toDouble();
    gonglilv=ui->lineEdit_gongjijin_lilv->text().toDouble();
    if(year1<1||year1>30||isDigitString(ui->lineEdit_year3->text())==false
           ||shangdai<1||shangdai>10000||isDigitString(ui->lineEdit_shangye->text())==false
           ||gongdai<1||gongdai>10000||isDigitString(ui->lineEdit_gongjijin->text())==false
           ||shanglilv<2||shanglilv>6||isDigitString(ui->lineEdit_shangye_lilv->text())==false
           ||gonglilv<2||gonglilv>6||isDigitString(ui->lineEdit_gongjijin_lilv->text())==false)
    {
        QMessageBox::StandardButton lineEdit;
        lineEdit=QMessageBox::warning(this,"提示","输入数据不合法",QMessageBox::Yes);
        if(lineEdit== QMessageBox::Yes)
          {
            ui->lineEdit_year3->clear();
            ui->lineEdit_shangye->clear();
            ui->lineEdit_gongjijin->clear();
            ui->lineEdit_shangye_lilv->clear();
            ui->lineEdit_gongjijin_lilv->clear();
            ui->lineEdit_dai->clear();
            ui->lineEdit_huan->clear();
            ui->lineEdit_li->clear();
            ui->lineEdit_shouyue->clear();
            ui->lineEdit_dijian->clear();
            ui->lineEdit_yue->clear();
          }
    }
    dai0=shangdai*10000+gongdai*10000;//贷款总额
    yue0=year1*12;//还款月数
    li0=(yue0+1)*shangdai*10000*0.01*shanglilv/24+(yue0+1)*gongdai*10000*0.01*gonglilv/24;//支付利息
    huan0=dai0+li0;//还款总额
    shouyue0=(shangdai*10000/yue0)+shangdai*10000*0.01*shanglilv/12+(gongdai*10000/yue0)+gongdai*10000*0.01*gonglilv/12;//首月月供
    dijian0=shangdai*10000/yue0*0.01*shanglilv/12+gongdai*10000/yue0*0.01*gonglilv/12;//每月递减
    dai=QString::number(dai0);
    huan=QString::number(huan0);
    li=QString::number(li0);
    yue=QString::number(yue0);
    shouyue=QString::number(shouyue0);
    dijian=QString::number(dijian0);
    ui->lineEdit_dai->setText(dai);
    ui->lineEdit_huan->setText(huan);
    ui->lineEdit_li->setText(li);
    ui->lineEdit_yue->setText(yue);
    ui->lineEdit_shouyue->setText(shouyue);
    ui->lineEdit_dijian->setText(dijian);
}
void Widget::on_Button_DX_1_clicked()
{
    //按单价、面积计算  等额本息
    double a=1.0,c=1.0;//用于计算乘方
    double danjia,area,chengshu,year1,lilv;//单价、面积、按揭成数、按揭年数、年利率
    double dai0,huan0,li0,yue0,yuehuan0;//贷款总额、还款总额、支付利息、还款月数、每月月供
    QString dai,huan,li,yue,yuehuan;
    danjia=ui->lineEdit_danjia->text().toDouble();//得到lineEdit中数据
    area=ui->lineEdit_area->text().toDouble();
    chengshu=ui->lineEdit_chengshu->text().toDouble();
    year1=ui->lineEdit_year1->text().toDouble();
    lilv=ui->lineEdit_lilv1->text().toDouble();
    if(danjia<0||danjia>1000000||isDigitString(ui->lineEdit_danjia->text())==false
            ||area<0||area>1000||isDigitString(ui->lineEdit_area->text())==false
            ||chengshu<2||chengshu>8||isDigitString(ui->lineEdit_chengshu->text())==false
            ||year1<1||year1>30||isDigitString(ui->lineEdit_year1->text())==false
            ||lilv<2||lilv>6||isDigitString(ui->lineEdit_lilv1->text())==false)
    {
        QMessageBox::StandardButton lineEdit;
        lineEdit=QMessageBox::warning(this,"提示","输入数据不合法",QMessageBox::Yes);
        if(lineEdit== QMessageBox::Yes)
           {
             ui->lineEdit_danjia->clear();
             ui->lineEdit_area->clear();
             ui->lineEdit_chengshu->clear();
             ui->lineEdit_year1->clear();
             ui->lineEdit_lilv1->clear();
             ui->lineEdit_dai2->clear();
             ui->lineEdit_huan2->clear();
             ui->lineEdit_li2->clear();
             ui->lineEdit_yue2->clear();
             ui->lineEdit_yuehuan->clear();
           }
    }
    yue0=year1*12;//还款月数
    for(int i=0;i<yue0;i++)
       {
        c=1+0.01*lilv/12;
        a=a*c;
       }
    dai0=danjia*area*chengshu*0.1;//贷款总额
    yuehuan0=dai0*0.01*lilv/12*a/(a-1);//每月月供
    huan0=yuehuan0*yue0;//还款总额
    li0=huan0-dai0;//支付利息
    dai=QString::number(dai0);
    huan=QString::number(huan0);
    li=QString::number(li0);
    yue=QString::number(yue0);
    yuehuan=QString::number(yuehuan0);
    ui->lineEdit_dai2->setText(dai);
    ui->lineEdit_huan2->setText(huan);
    ui->lineEdit_li2->setText(li);
    ui->lineEdit_yue2->setText(yue);
    ui->lineEdit_yuehuan->setText(yuehuan);
}
void Widget::on_Button_DX_2_clicked()
{
    //按贷款总额  等额本息
    double a=1.0,c=1.0;//用于计算乘方
    double zonge,year1,lilv;//贷款总额、按揭年数、年利率
    double dai0,huan0,li0,yue0,yuehuan0;//贷款总额、还款总额、支付利息、还款月数、每月月供
    QString dai,huan,li,yue,yuehuan;
    zonge=ui->lineEdit_zonge->text().toDouble();
    year1=ui->lineEdit_year2->text().toDouble();
    lilv=ui->lineEdit_lilv2->text().toDouble();
    if(zonge<1||zonge>10000||isDigitString(ui->lineEdit_zonge->text())==false
            ||year1<1||year1>30||isDigitString(ui->lineEdit_year2->text())==false
            ||lilv<2||lilv>6||isDigitString(ui->lineEdit_lilv2->text())==false)
    {
        QMessageBox::StandardButton lineEdit;
        lineEdit=QMessageBox::warning(this,"提示","输入数据不合法",QMessageBox::Yes);
        if(lineEdit== QMessageBox::Yes)
          {
            ui->lineEdit_zonge->clear();
            ui->lineEdit_year2->clear();
            ui->lineEdit_lilv2->clear();
            ui->lineEdit_dai2->clear();
            ui->lineEdit_huan2->clear();
            ui->lineEdit_li2->clear();
            ui->lineEdit_yue2->clear();
            ui->lineEdit_yuehuan->clear();
          }
    }
    dai0=zonge*10000;//贷款总额
    yue0=year1*12;//还款月数
    for(int i=0;i<yue0;i++)
       {
        c=1+0.01*lilv/12;
        a=a*c;
       }
    yuehuan0=dai0*0.01*lilv/12*a/(a-1);//每月月供
    huan0=yuehuan0*yue0;//还款总额
    li0=huan0-dai0;//支付利息
    dai=QString::number(dai0);
    huan=QString::number(huan0);
    li=QString::number(li0);
    yue=QString::number(yue0);
    yuehuan=QString::number(yuehuan0);
    ui->lineEdit_dai2->setText(dai);
    ui->lineEdit_huan2->setText(huan);
    ui->lineEdit_li2->setText(li);
    ui->lineEdit_yue2->setText(yue);
    ui->lineEdit_yuehuan->setText(yuehuan);

}
void Widget::on_Button_DX_3_clicked()
{
    //组合型贷款  等额本息
    double a=1.0,b=1.0,c=1.0;//用于计算乘方
    double shangdai,gongdai,year1,shanglilv,gonglilv;//商业贷款总额，公积金贷款总额，按揭年数，商业利率，公积金利率
    double dai0,huan0,li0,yue0,yuehuan0;//贷款总额、还款总额、支付利息、还款月数、每月月供
    QString dai,huan,li,yue,yuehuan;
    shangdai=ui->lineEdit_shangye->text().toDouble();
    gongdai=ui->lineEdit_gongjijin->text().toDouble();
    year1=ui->lineEdit_year3->text().toDouble();
    shanglilv=ui->lineEdit_shangye_lilv->text().toDouble();
    gonglilv=ui->lineEdit_gongjijin_lilv->text().toDouble();
    if(year1<1||year1>30||isDigitString(ui->lineEdit_year3->text())==false
           ||shangdai<1||shangdai>10000||isDigitString(ui->lineEdit_shangye->text())==false
           ||gongdai<1||gongdai>10000||isDigitString(ui->lineEdit_gongjijin->text())==false
           ||shanglilv<2||shanglilv>6||isDigitString(ui->lineEdit_shangye_lilv->text())==false
           ||gonglilv<2||gonglilv>6||isDigitString(ui->lineEdit_gongjijin_lilv->text())==false)
    {
        QMessageBox::StandardButton lineEdit;
        lineEdit=QMessageBox::warning(this,"提示","输入数据不合法",QMessageBox::Yes);
        if(lineEdit== QMessageBox::Yes)
          {
            ui->lineEdit_year3->clear();
            ui->lineEdit_shangye->clear();
            ui->lineEdit_gongjijin->clear();
            ui->lineEdit_shangye_lilv->clear();
            ui->lineEdit_gongjijin_lilv->clear();
            ui->lineEdit_dai2->clear();
            ui->lineEdit_huan2->clear();
            ui->lineEdit_li2->clear();
            ui->lineEdit_yue2->clear();
            ui->lineEdit_yuehuan->clear();
          }
    }
    dai0=shangdai*10000+gongdai*10000;//贷款总额
    yue0=year1*12;//还款月数
    for(int i=0;i<yue0;i++)
       {
        c=1+0.01*shanglilv/12;
        a=a*c;
       }
    for(int i=0;i<yue0;i++)
       {
        c=1+0.01*gonglilv/12;
        b=b*c;
       }
    yuehuan0=shangdai*10000*0.01*shanglilv/12*a/(a-1)+gongdai*10000*0.01*gonglilv/12*b/(b-1);//每月月供
    huan0=yuehuan0*yue0;//还款总额
    li0=huan0-dai0;//支付利息
    dai=QString::number(dai0);
    huan=QString::number(huan0);
    li=QString::number(li0);
    yue=QString::number(yue0);
    yuehuan=QString::number(yuehuan0);
    ui->lineEdit_dai2->setText(dai);
    ui->lineEdit_huan2->setText(huan);
    ui->lineEdit_li2->setText(li);
    ui->lineEdit_yue2->setText(yue);
    ui->lineEdit_yuehuan->setText(yuehuan);

}
void Widget::on_Button_qingkong_clicked()
{
    //全部清空
    QMessageBox::StandardButton button;
    button=QMessageBox::warning(this,"提示","请再次确认全部清空",QMessageBox::Yes | QMessageBox::No);
    if(button== QMessageBox::Yes)
    {
        ui->lineEdit_danjia->clear();
        ui->lineEdit_area->clear();
        ui->lineEdit_chengshu->clear();
        ui->lineEdit_year1->clear();
        ui->lineEdit_dai->clear();
        ui->lineEdit_huan->clear();
        ui->lineEdit_li->clear();
        ui->lineEdit_shouyue->clear();
        ui->lineEdit_dijian->clear();
        ui->lineEdit_yue->clear();
        ui->lineEdit_gongjijin->clear();
        ui->lineEdit_gongjijin_lilv->clear();
        ui->lineEdit_dai2->clear();
        ui->lineEdit_huan2->clear();
        ui->lineEdit_li2->clear();
        ui->lineEdit_yue2->clear();
        ui->lineEdit_yuehuan->clear();
        ui->lineEdit_lilv1->clear();
        ui->lineEdit_lilv2->clear();
        ui->lineEdit_shangye->clear();
        ui->lineEdit_shangye_lilv->clear();
        ui->lineEdit_year2->clear();
        ui->lineEdit_year3->clear();
        ui->lineEdit_zonge->clear();
    }
}
