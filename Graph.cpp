#include "Graph.h"
#include <QtMath>

constexpr double TIME_MEASURE = 0.05;

Graph::Graph(QObject *parent)
    : QObject{parent}
{
    m_time = 0;
    connect(&m_timer, &QTimer::timeout, this, &Graph::pushToQueue);
    //connect(&m_timer, &QTimer::timeout, this, &Graph::getValue);
    connect(&m_timer, &QTimer::timeout, this, &Graph::incrementTime);
    m_timer.start(10);
}

void Graph::setNewPoint(QSplineSeries *spline)
{
    QPointF point;
    point.setX(m_time * TIME_MEASURE);
    point.setY(getValue());

}

void Graph::incrementTime()
{
    m_time += 10;
}
void Graph::pushToQueue()
{
    m_queue.push_back(qSin(m_time));
}


double Graph::getValue()
{
    return m_queue.dequeue();
}
