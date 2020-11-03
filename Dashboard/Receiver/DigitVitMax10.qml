import QtQuick 2.9
import QtQuick.Controls 2.0
import VAL.CAPT 1.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.2

Item
{
    
    id: boussole
    
    Layout.fillWidth: true
    Image {
        id: cadran_boussole
        anchors.fill:parent
        clip: true
        source: "Visu/Boussole/cadran2.svg"
        fillMode: Image.PreserveAspectFit
    }
    
    Image {
        id: aiguille_boussole
        
        Layout.fillWidth: true
        Layout.fillHeight: true
        anchors.fill:parent
        clip: true
        
        
        source: "Visu/Boussole/aiguille2.svg"
        fillMode: Image.PreserveAspectFit
    }
    
}
