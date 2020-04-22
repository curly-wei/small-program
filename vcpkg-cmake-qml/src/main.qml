import QtQuick 2.0
import QtQuick.Window 2.0

// main window
Window {	
    visible: true
    MouseArea {
        anchors.fill: parent
        onClicked: {
            	Qt.quit();
        }
    }

	Rectangle {
		anchors.fill: parent
		Text {
			anchors.centerIn: parent
			text: "Hello World"			
		}
	}

}


