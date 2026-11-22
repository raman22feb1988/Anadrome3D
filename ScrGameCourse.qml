import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    Layout.fillHeight: true
    Layout.fillWidth: true

    TextMetrics { id: tm }

    property var _roleName: ["move", "word", "value", "best", "time"]
    property int _sortIndex: 0
    property int _sortOrder: 0

    // TODO: SortFilterProxyModel needs to be on the Qt side
    // no key up/down when sorted possible, no true selection,
    // adding items when sorted not at the right position
    SortFilterProxyModel {
        id: sortModel
        model: GamePlay.gamecourseModel
        sorters: [
            FunctionSorter {
                id: customSorter
                sortOrder: _sortOrder === 0 ? Qt.DescendingOrder : Qt.AscendingOrder

                component RoleData: QtObject {
                    property var move
                    property string word
                    property string value
                    property string best
                    property string time
                }

                // Exact arbitrary-precision comparison for base-10 integer strings (mpz_class)
                function compareBigIntStrings(strA: string, strB: string): int {
                    let a = (strA && strA.length > 0) ? strA.trim() : "0";
                    let b = (strB && strB.length > 0) ? strB.trim() : "0";

                    let negA = a.startsWith("-");
                    let negB = b.startsWith("-");

                    if (negA) a = a.slice(1);
                    if (negB) b = b.slice(1);

                    // Strip any leading zeros
                    a = a.replace(/^0+/, "") || "0";
                    b = b.replace(/^0+/, "") || "0";

                    if (a === "0" && b === "0") return 0;
                    if (negA !== negB) return negA ? -1 : 1;

                    // Compare magnitude: length first, then character-by-character
                    let cmp = 0;
                    if (a.length !== b.length) {
                        cmp = a.length < b.length ? -1 : 1;
                    } else if (a !== b) {
                        cmp = a < b ? -1 : 1;
                    }

                    // Reverse magnitude order if both numbers are negative
                        return negA ? -cmp : cmp;
                    }

                function compare(lhsData: RoleData, rhsData: RoleData): int {
                    let role = _roleName[_sortIndex];
                    let rawA = lhsData[role];
                    let rawB = rhsData[role];

                    // 1. Arbitrary-precision integer sort for mpz_class roles
                    if (role === "value" || role === "best") {
                        return compareBigIntStrings(String(rawA ?? "0"), String(rawB ?? "0"));
                    }

                    // 2. Numeric sort for "move"
                    if (role === "move") {
                        let numA = Number(rawA ?? 0);
                        let numB = Number(rawB ?? 0);
                        return (numA < numB) ? -1 : ((numA > numB) ? 1 : 0);
                    }

                    // 3. Duration sort for "hh:mm:ss" time strings
                    if (role === "time") {
                        let partsA = String(rawA ?? "0:0:0").split(":");
                        let partsB = String(rawB ?? "0:0:0").split(":");
                        let secA = (Number(partsA[0]) || 0) * 3600 + (Number(partsA[1]) || 0) * 60 + (Number(partsA[2]) || 0);
                        let secB = (Number(partsB[0]) || 0) * 3600 + (Number(partsB[1]) || 0) * 60 + (Number(partsB[2]) || 0);
                        return (secA < secB) ? -1 : ((secA > secB) ? 1 : 0);
                    }

                    // 4. Alphabetical sort for "word"
                    let strA = String(rawA ?? "");
                    let strB = String(rawB ?? "");
                    return strA.localeCompare(strB);
                }
            }
        ]
    }

    on_SortIndexChanged: sortModel.invalidateSorter()
    on_SortOrderChanged: sortModel.invalidateSorter()

    HorizontalHeaderView {
        id: tableHeader
        Layout.fillWidth: true
        syncView: statTable
        boundsMovement: Flickable.StopAtBounds
        delegate: HorizontalHeaderViewDelegate {
            TapHandler {
                onTapped: {
                    if (index == _sortIndex)
                        _sortOrder ^= 1
                    else
                        _sortIndex = index
                }
            }
        }
    }

    TableView {
        id: statTable
        Layout.fillWidth: true
        Layout.fillHeight: true
        clip: true
        boundsMovement: Flickable.StopAtBounds

        columnWidthProvider: function(column) {
            const pad = 12
            var col = []
            for (var i = 0; i < 5; i++)
            {
                tm.text = model.headerData(i, Qt.Horizontal)
                col[i] = tm.width + 2 * pad
            }
            col[1] = statTable.width - pad - col[0] - col[2] - col[3] - col[4]
            return col[column]
        }
        ScrollBar.vertical: ScrollBar { }
        model: sortModel
        columnSpacing: 1
        rowSpacing: 1
/*
        Keys.onPressed: (event)=> {
            if (event.key === Qt.Key_Down)
                GamePlay.gamecourseModel.selectedMove++;
            else if (event.key === Qt.Key_Up)
                GamePlay.gamecourseModel.selectedMove--;
            positionViewAtRow(GamePlay.gamecourseModel.selectedMove, TableView.Contain | TableView.AlignVCenter)
            if (GamePlay.is3D)
                cube.roll()
        }
*/
        delegate: Rectangle {
            implicitWidth: parent.width
            implicitHeight: (connectedWords !== "")
                            ? tm.height * 2 //we need 2x height in case of connected words
                            : tm.height
            color: GamePlay.gamecourseModel.selectedMove === model.move
                   ? config.myPalette.highlight
                   : config.myPalette.window
            ShadowText {
                id: msgText
                width: parent.width
                height: tm.height
                color: parent.color
                shadowText: model.column === 0
                            ? move
                            : model.column === 1
                              ? word
                              : model.column === 2
                                ? value
                                : model.column === 3
                                  ? best
                                  : model.column === 4
                                    ? time
                                    : ""
                shadowColor: who > -1 && config.bColoredPlayers //color the words according the player, if checked
                             ? Qt.lighter(config.playercolors.get(who).itemColor)
                             : config.myPalette.windowText
                shadowPadding: (model.column === 1) ? 6 : 0 //some padding for the word column
                shadowVertAlign: Text.AlignTop
                shadowHorzAlign: (model.column === 1)
                                 ? config.ltr ? Text.AlignLeft : Text.AlignRight //word column aligns left
                                 : Text.AlignRight
            }
            Image {
                source: "qrc:///resources/bingo.png"
                visible: (model.column === 2) && isScrabble
                width: tm.height
                height: width
            }
            Text {
                id: msgConnected
                text: (model.column === 1) ? connectedWords :
                      (model.column === 2) ? bonuswho > -1 ? bonus > 0 ? "+" + bonus : bonus
                                                           : ""
                                           : ""
                style: (model.column === 2) && bonuswho > -1 ? Text.Outline : Text.Normal
                styleColor: (model.column === 2) && bonuswho > -1 ? Qt.lighter(config.playercolors.get(bonuswho).itemColor) : ""
                color: isDark(config.myPalette.window)
                       ? Qt.lighter(config.myPalette.windowText, 0.8)
                       : Qt.darker(config.myPalette.windowText, 0.8)
                leftPadding: (model.column === 1) ? 6 : 0 //some padding for the word column
                anchors.bottom: parent.bottom
                width: parent.width
                elide: Text.ElideRight
            }

            MouseArea {
                anchors.fill: parent
                //TODO: gamecourse: history should be avail in network mode too
                onClicked: if (!GamePlay.isConnected) {
                    forceActiveFocus()
                    GamePlay.gamecourseModel.selectedMove = model.move
                }
            }
        }
    }
}
