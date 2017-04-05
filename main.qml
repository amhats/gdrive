import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: application
    visible: true
    width: 640
    height: 480
    title: qsTr("GDrive")

    property  bool ignoreCheck: false

    Connections{
        target: systemTray
        onSignalShow:{
            application.show();
        }
        onSignalQuit: {
            ignoreCheck = true
            close();
        }
        onSignalIconActivated:{
            if(application.visibility === Window.Hidden){
                application.show()
            }else{
                application.hide()
            }
        }
    }
    CheckBox{
        id: checkTray
        anchors.centerIn: parent
        text: qsTr("Enable minimizing with out closing the app.")
    }
    onClosing: {
        if(checkTray.checked === true && ignoreCheck === false){
            close.accepted = false
            application.hide()
        }else{
            Qt.quit()
        }
    }


}
