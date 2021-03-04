
extern "C" {
#include <libdedx/dedx.h>
}

#include <memory>
#include <iostream>

/*#include <QApplication>
#include <QtWidgets>
#include <QtCharts>

class LineSeries: public QLineSeries{
public:
    LineSeries(QObject *parent = nullptr):
        QLineSeries(parent)
    {
        connect(this, &QXYSeries::clicked, this, &LineSeries::onClicked);
    }
private slots:
    void onClicked(){
        QPen p = pen();
        p.setWidth(p.width()+1);
        setPen(p);
    }
};*/

int main(int argc, char** argv)
{
    /*QApplication app{argc, argv};

    LineSeries *series = new LineSeries();
    *series << QPointF(10, 1) << QPointF(100, 3) << QPointF(500, 6) << QPointF(1000, 3) << QPointF(10000, 2);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);

    QLogValueAxis *axisX = new QLogValueAxis();
    axisX->setTitleText("Values");
    axisX->setLabelFormat("%g");
    axisX->setBase(10.0);
    axisX->setMinorTickCount(-1);
    //axisX->setFormat()
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Data point");
    axisY->setLabelFormat("%i");
    axisY->setTickCount(series->count());
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);



    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();*/

    using std::unique_ptr;
    using std::cout;
    using std::endl;
    constexpr static auto workspace_deallocator = [](dedx_workspace* workspace){
        int err; dedx_free_workspace(workspace, &err);
    };
    int err;
    unique_ptr<dedx_workspace, decltype(workspace_deallocator)>
        workspace{dedx_allocate_workspace(10,&err), workspace_deallocator};
    cout << "Witam" << endl;
    return 0;

}