import QtQuick
import QtCharts

Rectangle {

    Timer {
        id: _graphTimer
        interval: 10; running: true; repeat: true;

    }

    ChartView {
        anchors.fill: parent

        SplineSeries {
            id: _graph
        }

        Connections {
            target: Graph
            _graphTimer.onTriggered
            {

            }
        }

    }
}
