#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>
#include <QTimer>
#include <QQueue>
#include <QtCharts/QSplineSeries>

class Graph : public QObject
{
    Q_OBJECT
public:
    explicit Graph(QObject *parent = nullptr);

    QTimer m_timer;
    QQueue<double> m_queue;
    int m_time;
public slots:
    void setNewPoint(QSplineSeries* spline);
    double getValue();

signals:

private:
    void incrementTime();
    void pushToQueue();
};

#endif // GRAPH_H
