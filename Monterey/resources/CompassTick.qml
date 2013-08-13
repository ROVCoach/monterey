import QtQuick 2.0

Rectangle {
    id: headingBar
    width: 2
    height: 12
    color: "#0275ac"

    function setNightMode() {
        headingBar.color = "#ff0000";
    }

    function setDayMode() {
        headingBar.color = "#0275ac";
    }

    property string textToDisplay;
    property int paintedWidth: headingText.contentWidth;

    Text {
        id: headingText
        color: "#0275ac"
        text: textToDisplay
        font.pixelSize: 12
        y: -1 * headingText.paintedHeight - 1
        x: -1 * headingText.paintedWidth/2

    }
}
