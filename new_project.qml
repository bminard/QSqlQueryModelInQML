import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

import Foo 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("SqlQueryModel")
    SqlQueryModel{
        id: sqlmodel
        query: "select * from COMPANY"
    }
    Component{
        id: columnComponent
        TableViewColumn{width: 100 }
    }
    TableView {
        id: view
        anchors.fill: parent
        resources:{
            var roleList = sqlmodel.userRoleNames
            var temp = []
            for(var i in roleList){
                var role  = roleList[i]
                temp.push(columnComponent.createObject(view, { "role": role, "title": role}))
            }
            return temp
        }
        model: sqlmodel
    }
}
