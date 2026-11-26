import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt.labs.platform

//Standardpath, native dialog; instead of import QtQuick.Dialogs
Window {
    visible: false //show per action acConfiguration
    modality: Qt.ApplicationModal
    title: qsTr("Configuration")
    width: 680 > screen.width ? screen.width : 680
    height: 540 > screen.height ? screen.height : 540

    property alias showTips: cbShowTips.checked

    property bool bMarkers: true // ConfigBoard::cbMarkers.checked
    property bool bColoredPlayers: true // ConfigBoard::cbPlayerColors.checked
    property bool bIs3D: false // ConfigBoard::rb3D.checked

    property int numberOfLettersOnRack: 7 // ConfigLetter::sbPieces.value
    property int numberOfRandomLetters: 0 // ConfigLetter::sbRandoms.value
    property int numberOfJokers: 2 // ConfigLetter::sbJoker.value
    property bool ltr: true // configLetter::rbReadingDirectionLTR

    property int numberOfPasses: 3 // ConfigTime::sbPasses
    property int timeControl: 0 // ConfigTime::rbNoLimit/rbPerMove/rbPerGame
    property int timeControlValue: 10 // ConfigTime::rbNoLimit/rbPerMove/rbPerGame

    property int bingoBonus: 35 // ConfigRules::sbBingo
    property int gameEndBonus: 0 // ConfigRules::sbGameEnd
    property bool addLetters: true // ConfigRules::sbGameEnd
    property bool subtractLetters: true // ConfigRules::sbGameEnd
    property int jokerPenalty: 0 // ConfigRules::sbJokerPanelty
    property bool changeIsPass: false // ConfigRules::cbChangeIsPass
    property bool cambiosecco: false // ConfigRules::cbCambioSecco
    property int performance: 0 // ConfigRules::slPerformance

    property int wordCheckMode: 0 // ConfigWordCheck::rbTakeback = 0, rbPoll = 1, rbChallenge = 2
    property int wordCheckPeriod: 10 // ConfigWordCheck::sbPeriod.value
    property int wordCheckPenalty: 10 // ConfigWordCheck::sbPenalty.value
    property int wordCheckBonus: 0 // ConfigWordCheck::sbBonus.value
    property bool clabbers: false // ConfigWordCheck::cbClabbers

    property bool canbuytime: false // ConfigTimeControl::rbGameEnd/rbPenalty
    property int buytimecount: 0 // ConfigTimeControl::sbPenaltyCount
    property int buytimepenalty: 0 // ConfigTimeControl::sbPenaltyPoints
    property bool timegamelost: false // ConfigTimeControl::sbPenaltyPoints

    property alias colors: scrColors
    property alias playercolors: scrPlayerColors
    property var board: []

    property alias myPalette: myPalette

    property string boardName: configBoard.boardName
    property string lettersetName: configLetter.getLetterSetName()
    property string dictionaryName: configDictionary.dictionaryName
    Component.onCompleted: {
        //fill color names with random color values and reset later to the default
        var cNames = [qsTr("Start"), qsTr("Regular"), qsTr("Double letter"), qsTr(
                          "Triple letter"), qsTr("Quadruple letter"), qsTr(
                          "Double word"), qsTr("Triple word"), qsTr("Quadruple word"),
                          qsTr("Double consonants"), qsTr("Triple vowels"), qsTr("Product"),
                          qsTr("Word length square"), qsTr("Letter square"), qsTr("Factorial"),
                          qsTr("Floor"), qsTr("Plus"), qsTr("Times"), qsTr("Power"),
                          qsTr("Mimic"), qsTr("Ceiling"), qsTr("Sum"), qsTr("Zero"),
                          qsTr("One"), qsTr("Two"), qsTr("Three"), qsTr("Four"),
                          qsTr("Five"), qsTr("Six"), qsTr("Seven"), qsTr("Eight"),
                          qsTr("Nine"), qsTr("Ten"), qsTr("Fifty"), qsTr("Hundred"),
                          qsTr("Double vertical symmetry"), qsTr("Triple horizontal symmetry"),
                          qsTr("Quadruple rotational symmetry"), qsTr("Inverter"),
                          qsTr("Position in alphabet"), qsTr("Reviver"), qsTr("Wall"),
                          qsTr("Pieces")]
        /* var cLabels = [qsTr("★"), qsTr(""), qsTr("2L"), qsTr("3L"), qsTr("4L"), qsTr("2W"),
                          qsTr("3W"), qsTr("4W"), qsTr("2C"), qsTr("3V"), qsTr("∏"), qsTr("...²"),
                          qsTr("L²"), qsTr("!"), qsTr(":1"), qsTr("✚"), qsTr("✱"), qsTr("^"),
                          qsTr("⤺"), qsTr("Γ"), qsTr("∑"), qsTr("0"), qsTr("1"), qsTr("2"),
                          qsTr("3"), qsTr("4"), qsTr("5"), qsTr("6"), qsTr("7"), qsTr("8"),
                          qsTr("9"), qsTr("10"), qsTr("50"), qsTr("100"), qsTr("2┋"), qsTr("3┉"),
                          qsTr("4⭯"), qsTr("10−"), qsTr("A1"), qsTr("☥"), qsTr(""), qsTr("")] */
        var cImages = [qsTr("assets/08e9eb8a-6859-47da-9e24-710ebc2ef3bd.png"),
                       qsTr("assets/a8e570ec-a197-40e9-8a03-f13c08b01f15.png"),
                       qsTr("assets/2c6acac7-d85f-4c17-accc-a9e07f568b45.png"),
                       qsTr("assets/8e6537c6-ac37-41b8-be6f-cf960b8a9c74.png"),
                       qsTr("assets/544a9941-4a48-457d-8941-602d697942e3.png"),
                       qsTr("assets/66b2682e-8999-4f87-949e-f5426845326e.png"),
                       qsTr("assets/2c6f3510-6030-4f90-898f-961d29753ca1.png"),
                       qsTr("assets/5bb1ef58-7976-4209-af09-04e7e4bfd84f.png"),
                       qsTr("assets/d4e58fc2-15fa-428f-a31c-98df2bf8832e.png"),
                       qsTr("assets/bdc104ac-e1dc-40ae-a593-85267a8bdd89.png"),
                       qsTr("assets/b9055be1-5e75-46ed-b65e-8ede304eff53.png"),
                       qsTr("assets/92f2527f-37cf-4f6e-a593-cc31af0c2053.png"),
                       qsTr("assets/5f68a69d-8163-4960-b275-062ad8c2d932.png"),
                       qsTr("assets/5e317211-41de-4268-ae42-ca2d6d7e3503.png"),
                       qsTr("assets/57dc84e0-c25c-4a9b-b362-3f7cc4802667.png"),
                       qsTr("assets/4f9dfec8-a574-4d68-a06b-e1424cd60ad6.png"),
                       qsTr("assets/7832c8b0-ce11-4142-8a7e-5b1c057ca655.png"),
                       qsTr("assets/f128e18e-33c1-4e4f-bff5-22d95954fef8.png"),
                       qsTr("assets/c8421320-bfb7-495b-8aab-5d91b937b05b.png"),
                       qsTr("assets/961e6b36-f5ff-4655-ba33-cae39f0ce201.png"),
                       qsTr("assets/d537c8b9-a96e-477e-9b51-bc97642d10e3.png"),
                       qsTr("assets/ed4e0127-9bd4-458f-8f8c-1ff688e29de1.png"),
                       qsTr("assets/306f086a-db6c-434b-9aa4-c31303a873b7.png"),
                       qsTr("assets/a8a3202e-9ac0-48a3-bcf6-f0aa68b28a42.png"),
                       qsTr("assets/b6c15add-66d6-4b65-ab17-aad247f4e9b0.png"),
                       qsTr("assets/6253b36c-ccb8-493f-84b5-47863957897c.png"),
                       qsTr("assets/b4a64259-79c1-42ef-a547-053dd073f319.png"),
                       qsTr("assets/2bc3eda2-c256-442b-91e2-37c900b3427c.png"),
                       qsTr("assets/3875f51f-beb8-4c1d-8759-8a9a41ae6b84.png"),
                       qsTr("assets/b0833898-ff8f-4951-be6c-f2bc70661baa.png"),
                       qsTr("assets/00884760-bc00-42dd-ae31-4facd6f96eaf.png"),
                       qsTr("assets/535c9d68-127f-488e-b215-cfe97146c55e.png"),
                       qsTr("assets/06284a47-4d3e-46ec-acfb-44166e6fa5a2.png"),
                       qsTr("assets/53a5e848-bac8-4d67-9c10-8d7040c71b0b.png"),
                       qsTr("assets/4bb9e989-ae12-4d7a-b37c-53b9453b1711.png"),
                       qsTr("assets/ad6602c3-261f-4a5a-a7be-dc403e5a9d48.png"),
                       qsTr("assets/e2b706a2-b379-45bc-ad19-b317c4f7acd8.png"),
                       qsTr("assets/fd9c8c20-23c4-4a0e-aeaf-0a2b740f5607.png"),
                       qsTr("assets/d6c9450b-15a5-4144-a137-4fc08bc6c4ff.png"),
                       qsTr("assets/c747f0c9-a700-4025-96c0-14af353f826f.png"),
                       qsTr("assets/12616d88-beb2-4dfd-bf14-80fe9d7d3aec.png")]
        for (var i = 0; i < cNames.length; i++)
            scrColors.append({
                                 "itemColor": "#000000",
                                 "itemName": cNames[i],
                                 // "itemLabel": cLabels[i],
                                 "itemImage": cImages[i]
                             })
        cNames = [qsTr("First player"), qsTr("Second player"), qsTr(
                      "Third player"), qsTr("Fourth player")]
        for (i = 0; i < cNames.length; i++)
            scrPlayerColors.append({
                                       "itemColor": "#000000",
                                       "itemName": cNames[i]
                                   })

        //load last session properties
        loadConfig("")
    }
    function getLetterSet(index) {
        return configLetter.getLetterSet(index)
    }

    function getConfigData(bComplete = true) {
        var configData = {}
        //board
        if (bComplete)
            configData["cbMarkers"] = configBoard.cbMarkers.checked
        configData["rb3D"] = configBoard.rb3D.checked
        configData["board"] = board.toString()
        if (bComplete) {
            var aColors = []
            for (var i = 0; i < scrColors.count; ++i)
                aColors.push(scrColors.get(i).itemColor.toString())
            configData["colors"] = aColors.toString()
            aColors = []
            for (i = 0; i < scrPlayerColors.count; ++i)
                aColors.push(scrPlayerColors.get(i).itemColor.toString())
            configData["playercolors"] = aColors.toString()
            configData["cbPlayerColors"] = configBoard.cbPlayerColors.checked
        }
        //letter
        configData["cbLetterSet"] = configLetter.cbLetterSet.currentIndex
        if (configLetter.cbLetterSet.currentIndex === -1)
            configData["cbLetterSetData"] = getLetterSet(-1).toString()
        configData["sbJokers"] = configLetter.sbJoker.value
        configData["sbPieces"] = configLetter.sbPieces.value
        configData["sbRandoms"] = configLetter.sbRandoms.value
        if (bComplete)
            configData["rbReadingDirectionLTR"] = configLetter.rbReadingDirectionLTR.checked
        //configWordCheck
        configData["rbTakeback"] = configWordCheck.rbTakeback.checked
        configData["rbPoll"] = configWordCheck.rbPoll.checked
        configData["rbChallenge"] = configWordCheck.rbChallenge.checked
        configData["sbPeriod"] = configWordCheck.sbPeriod.value
        configData["sbPenalty"] = configWordCheck.sbPenalty.value
        configData["sbBonus"] = configWordCheck.sbBonus.value
        configData["cbClabbers"] = configWordCheck.cbClabbers.checked
        //configTime
        configData["rbNoLimit"] = configTime.rbNoLimit.checked
        configData["rbPerMove"] = configTime.rbPerMove.checked
        configData["tiPerMove"] = configTime.tiPerMove.text
        configData["rbPerGame"] = configTime.rbPerGame.checked
        configData["tiPerGame"] = configTime.tiPerGame.text
        configData["rbGameEnd"] = configTime.rbGameEnd.checked
        configData["rbPenalty"] = configTime.rbPenalty.checked
        configData["sbPenaltyPoints"] = configTime.sbPenaltyPoints.value
        configData["sbPenaltyCount"] = configTime.sbPenaltyCount.value
        configData["cbGameEnd"] = configTime.cbGameEnd.checked
        //configRules
        configData["sbPasses"] = configRules.sbPasses.value
        configData["sbBingo"] = configRules.sbBingo.value
        configData["sbGameEnd"] = configRules.sbGameEnd.value
        configData["sbJokerPenalty"] = configRules.sbJokerPenalty.value
        configData["cbAddLetters"] = configRules.cbAddLetters.checked
        configData["cbSubtractLetters"] = configRules.cbSubtractLetters.checked
        configData["cbChangeIsPass"] = configRules.cbChangeIsPass.checked
        configData["cbCambioSecco"] = configRules.cbCambioSecco.checked
        configData["slPerformance"] = configRules.slPerformance.value

        //dictionary
        configData["dictionary"] = configDictionary.dictionaryFile
        const dictionaryCategories = configDictionary.dictionaryCategories
        var selectedCategories = []
        for (i = 0; i < dictionaryCategories.length; i++)
            if (GamePlay.getCategoryChecked(dictionaryCategories[i]))
                selectedCategories.push(dictionaryCategories[i])
        configData["categories"] = selectedCategories.toString()
        return configData
    }
    function saveConfig(fileName) {
        GamePlay.saveConfig(fileName, getConfigData())
    }
    function loadConfig(fileName) {
        //reset calls applyConfig({})
        applyConfig(GamePlay.loadConfig(fileName))
    }
    function applyConfig(configData) {
        function getConfigValue(key, def) {
            return configData[key] || def
        }

        //board
        configBoard.cbMarkers.checked = getConfigValue("cbMarkers",
                                                       "true") === "true"
        if (getConfigValue("rb3D", "false") === "true")
            configBoard.rb3D.checked = true
        else
            configBoard.rb2D.checked = true
        board = []
        board = getConfigValue(
                    "board",
                    "6,1,1,2,1,1,1,6,1,1,1,2,1,1,6,1,5,1,1,1,3,1,1,1,3,1,1,1,5,1,1,1,5,1,1,1,2,1,2,1,1,1,5,1,1,2,1,1,5,1,1,1,2,1,1,1,5,1,1,2,1,1,1,1,5,1,1,1,1,1,5,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,6,1,1,2,1,1,1,0,1,1,1,2,1,1,6,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,5,1,1,1,1,1,5,1,1,1,1,2,1,1,5,1,1,1,2,1,1,1,5,1,1,2,1,1,5,1,1,1,2,1,2,1,1,1,5,1,1,1,5,1,1,1,3,1,1,1,3,1,1,1,5,1,6,1,1,2,1,1,1,6,1,1,1,2,1,1,6").split(
                    ",").map(function (t) {
                        return parseInt(t)
                    })
        configBoard.checkDefault()
        if (configBoard.rb2D.checked)
            configBoard.sbSize.value = Math.sqrt(config.board.length)
        else
            configBoard.sbSize.value = Math.round(Math.cbrt(
                                                      config.board.length))
        var aColors = getConfigValue("colors", "#c0c0c0,#a3a3a3,#6ab6dc,#1b8cc5,#105172,
        #dc6ad3,#c51bb7,#72106a,#6adc6a,#1bc51b,#1b1bc5,#107210,#6a6adc,#101072,#7d7d7d,
        #dc6a6a,#c51b1b,#721010,#dcdc6a,#c5c51b,#727210,#363636,#eec9a5,#eeeea5,#c9eea5,
        #a5eea5,#a5eec9,#a5eeee,#a5c9ee,#a5a5ee,#c9a5ee,#eea5ee,#eea5c9,#f0f0f0,#a36adc,
        #701bc5,#411072,#6adcb6,#1bc58c,#107251,#000000,#ffff00").split(",")
        if (scrColors.count === aColors.length) {
            for (var i = 0; i < scrColors.count; ++i)
                scrColors.setProperty(i, "itemColor",
                                      Qt.color(aColors[i].trim()))
        } else
            console.warn("Unexpected number of colors in configuration")

        aColors = getConfigValue("playercolors",
                                 "#ff0000,#00ff00,#0000ff,#a77a00").split(",")
        if (scrPlayerColors.count === aColors.length) {
            for (i = 0; i < scrPlayerColors.count; ++i)
                scrPlayerColors.setProperty(i, "itemColor",
                                            Qt.color(aColors[i].trim()))
        } else
            console.warn("Unexpected number of player colors in configuration")

        configBoard.cbPlayerColors.checked = getConfigValue("cbPlayerColors",
                                                            "true") === "true"

        //letters
        configLetter.cbLetterSet.currentIndex = -1
        configLetter.cbLetterSet.currentIndex = getConfigValue("cbLetterSet", 0)
        //load letter set before dictionary to suppress warning of different letter sets
        if (configLetter.cbLetterSet.currentIndex === -1) {
            var aLetters = []
            aLetters = getConfigValue("cbLetterSetData", "").split(",")
            if (aLetters.length > 0)
                configLetter.setLetterSet(aLetters)
        }

        configLetter.sbJoker.value = getConfigValue("sbJokers", 2)
        configLetter.sbPieces.value = getConfigValue("sbPieces", 7)
        configLetter.sbRandoms.value = getConfigValue("sbRandoms", 0)
        configLetter.rbReadingDirectionLTR.checked = getConfigValue(
                    "rbReadingDirectionLTR", "true") === "true"
        configLetter.rbReadingDirectionRTL.checked = getConfigValue(
                    "rbReadingDirectionLTR", "true") !== "true"

        //configWordCheck
        configWordCheck.rbTakeback.checked = getConfigValue("rbTakeback",
                                                            "true") === "true"
        configWordCheck.rbPoll.checked = getConfigValue("rbPoll",
                                                        "false") === "true"
        configWordCheck.rbChallenge.checked = getConfigValue("rbChallenge",
                                                             "false") === "true"
        configWordCheck.sbPeriod.value = getConfigValue("sbPeriod", 10)
        configWordCheck.sbPenalty.value = getConfigValue("sbPenalty", 10)
        configWordCheck.sbBonus.value = getConfigValue("sbBonus", 0)
        configWordCheck.cbClabbers.checked = getConfigValue("cbClabbers",
                                                            "false") === "true"

        //time
        configTime.rbNoLimit.checked = getConfigValue("rbNoLimit",
                                                      "false") === "true"
        configTime.rbPerMove.checked = getConfigValue("rbPerMove",
                                                      "false") === "true"
        configTime.tiPerMove.text = getConfigValue("tiPerMove", "0:01:00")
        configTime.rbPerGame.checked = getConfigValue("rbPerGame",
                                                      "true") === "true"
        configTime.tiPerGame.text = getConfigValue("tiPerGame", "0:50:00")
        configTime.rbGameEnd.checked = getConfigValue("rbGameEnd",
                                                      "false") === "true"
        configTime.rbPenalty.checked = getConfigValue("rbPenalty",
                                                      "true") === "true"
        configTime.sbPenaltyPoints.value = getConfigValue("sbPenaltyPoints", 10)
        configTime.sbPenaltyCount.value = getConfigValue("sbPenaltyCount", 10)
        configTime.cbGameEnd.checked = getConfigValue("cbGameEnd",
                                                      "true") === "true"

        //rules
        configRules.sbPasses.value = getConfigValue("sbPasses", 3)
        configRules.sbBingo.value = getConfigValue("sbBingo", 50)
        configRules.sbGameEnd.value = getConfigValue("sbGameEnd", 0)
        configRules.sbJokerPenalty.value = getConfigValue("sbJokerPenalty", 0)
        configRules.cbAddLetters.checked = getConfigValue("cbAddLetters",
                                                          "true") === "true"
        configRules.cbSubtractLetters.checked = getConfigValue(
                    "cbSubtractLetters", getConfigValue("cbSubstractLetters", "true")) === "true"
        configRules.cbChangeIsPass.checked = getConfigValue("cbChangeIsPass",
                                                            "false") === "true"
        configRules.cbCambioSecco.checked = getConfigValue("cbCambioSecco",
                                                           "false") === "true"
        configRules.slPerformance.value = getConfigValue("slPerformance", 10)

        // dictionary
        var aFileName = getConfigValue("dictionary", "")
        var aCategories = getConfigValue("categories", "")
        if (aFileName !== configDictionary.dictionaryFile)
            GamePlay.loadDictionary(aFileName, aCategories)
        else
            configDictionary.setCategories(
                        aCategories) // same dictionary name but different categories in network mode
    }

    ListModel {
        id: scrColors
        dynamicRoles: true
    }
    ListModel {
        id: scrPlayerColors
        dynamicRoles: true
    }
    FileDialog {
        id: fileDialog
        folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        nameFilters: [qsTr("Scrabble3D configuration (*.ssc)"), qsTr(
                "All files (*)")]
        defaultSuffix: "ssc"
        onAccepted: {
            fileMode === FileDialog.OpenFile ? loadConfig(
                                                   file) : saveConfig(file)
        }
    }

    Action {
        id: acClose
        text: qsTr("Close")
        onTriggered: config.close()
    }
    Action {
        id: acLoadConfig
        text: qsTr("Load")
        icon.source: "qrc:///resources/load.png"
        onTriggered: {
            fileDialog.acceptLabel = qsTr("Open")
            fileDialog.fileMode = FileDialog.OpenFile
            fileDialog.title = qsTr("Load configuration")
            fileDialog.open()
        }
    }
    Action {
        id: acSaveConfig
        text: qsTr("Save")
        icon.source: "qrc:///resources/save.png"
        onTriggered: {
            fileDialog.acceptLabel = qsTr("Save")
            fileDialog.fileMode = FileDialog.SaveFile
            fileDialog.title = qsTr("Save configuration")
            fileDialog.open()
        }
    }
    Action {
        id: acResetConfig
        text: qsTr("Reset")
        icon.source: "qrc:///resources/reset.png"
        onTriggered: applyConfig({})
    }

    SystemPalette {
        id: aPalette
        colorGroup: SystemPalette.Active
    }
    SystemPalette {
        id: bPalette
        colorGroup: SystemPalette.Disabled
    }
    Palette {
        id: myPalette
        alternateBase: aPalette.alternateBase
        base: aPalette.base
        button: aPalette.button
        buttonText: aPalette.buttonText
        dark: aPalette.dark
        highlight: aPalette.highlighted
        highlightedText: aPalette.highlightedText
        light: aPalette.light
        mid: aPalette.mid
        midlight: aPalette.midlight
        placeholderText: aPalette.placeholderText
        shadow: aPalette.shadow
        text: aPalette.text
        window: aPalette.window
        windowText: aPalette.windowText

        disabled.alternateBase: bPalette.alternateBase
        disabled.base: bPalette.base
        disabled.button: bPalette.button
        disabled.buttonText: bPalette.buttonText
        disabled.dark: bPalette.dark
        disabled.highlight: bPalette.highlighted
        disabled.highlightedText: bPalette.highlightedText
        disabled.light: bPalette.light
        disabled.mid: bPalette.mid
        disabled.midlight: bPalette.midlight
        disabled.placeholderText: bPalette.placeholderText
        disabled.shadow: bPalette.shadow
        disabled.text: bPalette.text
        disabled.window: bPalette.window
        disabled.windowText: bPalette.windowText
    }
    color: myPalette.base

    ListModel {
        id: lmCategories
        ListElement {
            name: qsTr("Board")
            imgname: "optboard.png"
        }
        ListElement {
            name: qsTr("Letters")
            imgname: "optletters.png"
        }
        ListElement {
            name: qsTr("Word Check Mode")
            imgname: "optwordcheck.png"
        }
        ListElement {
            name: qsTr("Time Control")
            imgname: "opttime.png"
        }
        ListElement {
            name: qsTr("Rules")
            imgname: "optrules.png"
        }
        ListElement {
            name: qsTr("Dictionary")
            imgname: "optdic.png"
        }
        ListElement {
            name: qsTr("Localization")
            imgname: "optui.png"
        }
    }

    Component {
        id: lViewDelegates
        Rectangle {
            width: parent.width
            height: 48 + 12
            color: ListView.isCurrentItem ? myPalette.highlight : "transparent"
            Image {
                id: delegateImage
                source: "qrc:///resources/" + imgname
                anchors.left: parent.left
                anchors.leftMargin: 8
                anchors.verticalCenter: parent.verticalCenter
            }
            Text {
                id: delegateText
                text: name
                leftPadding: 8
                anchors.left: delegateImage.right
                anchors.verticalCenter: parent.verticalCenter
                color: lView.currentIndex
                       === index ? myPalette.highlightedText : myPalette.windowText
            }
            MouseArea {
                anchors.fill: parent
                onClicked: lView.currentIndex = index
            }
        }
    }

    ColumnLayout {
        anchors {
            fill: parent

            // Android system bars
            topMargin: parent.SafeArea.margins.top
            leftMargin: parent.SafeArea.margins.left
            rightMargin: parent.SafeArea.margins.right
            bottomMargin: parent.SafeArea.margins.bottom
        }

        SplitView {
            id: splitView

            //hide the handle left-hand of the splitview
            handle: Rectangle {
                visible: mainLoader.state === "landscape" && x > 10
                implicitWidth: 2
                implicitHeight: 2
                color: SplitHandle.pressed ? Qt.lighter(
                                                 palette.dark,
                                                 1.5) : (SplitHandle.hovered ? Qt.lighter(palette.dark, 1.1) : palette.dark)

                containmentMask: Item {
                    x: -width / 2
                    width: 48
                    height: splitView.height
                }
            }

            orientation: mainLoader.state === "landscape" ? Qt.Horizontal : Qt.Vertical

            Layout.fillWidth: true
            Layout.fillHeight: true

            focus: true
            Keys.onEscapePressed: close()

            Rectangle {
                id: leftPane
                visible: mainLoader.state === "landscape"
                SplitView.preferredWidth: parent.width * 28 / 100
                SplitView.minimumWidth: 50
                color: myPalette.window //"#FF0000" //
                ListView {
                    id: lView
                    anchors.fill: parent
                    model: lmCategories
                    delegate: lViewDelegates
                }
            }
            ColorComboBox {
                id: catSelector
                visible: mainLoader.state === "portrait"
                model: lmCategories
                textRole: "name"
                onCurrentIndexChanged: lView.currentIndex = currentIndex
            }
            Rectangle {
                id: rightPane
                SplitView.minimumWidth: 100
                SplitView.fillWidth: true
                color: myPalette.window
                ScrollView {
                    id: scrollView
                    anchors.fill: parent
                    ConfigBoard {
                        id: configBoard
                        visible: lView.currentIndex === 0
                        onVisibleChanged: {
                            scrollView.contentHeight = configBoard.height
                            scrollView.contentWidth = configBoard.width
                        }
                    }
                    ConfigLetter {
                        id: configLetter
                        visible: lView.currentIndex === 1
                        onVisibleChanged: {
                            scrollView.contentHeight = configLetter.height
                            scrollView.contentWidth = configLetter.width
                        }
                    }
                    ConfigWordCheck {
                        id: configWordCheck
                        visible: lView.currentIndex === 2
                        defaultLetterSet: configLetter.cbLetterSet.currentIndex
                                          > -1 ? configLetter.cbLetterSet.currentIndex : defaultLetterSet
                        onVisibleChanged: {
                            scrollView.contentHeight = configWordCheck.height
                            scrollView.contentWidth = configWordCheck.width
                        }
                    }
                    ConfigTime {
                        id: configTime
                        visible: lView.currentIndex === 3
                        defaultLetterSet: configLetter.cbLetterSet.currentIndex
                                          > -1 ? configLetter.cbLetterSet.currentIndex : defaultLetterSet
                        onVisibleChanged: {
                            scrollView.contentHeight = configTime.height
                            scrollView.contentWidth = configTime.width
                        }
                    }
                    ConfigRules {
                        id: configRules
                        visible: lView.currentIndex === 4
                        defaultLetterSet: configLetter.cbLetterSet.currentIndex
                                          > -1 ? configLetter.cbLetterSet.currentIndex : defaultLetterSet
                        onVisibleChanged: {
                            scrollView.contentHeight = configRules.height
                            scrollView.contentWidth = configRules.width
                        }
                    }
                }
                ConfigDictionary {
                    id: configDictionary
                    visible: lView.currentIndex === 5
                }
                ConfigUI {
                    id: configUI
                    visible: lView.currentIndex === 6
                }
            }
        }

        Rectangle {
            id: configFooter
            Layout.minimumHeight: btnClose.height + 12
            Layout.fillWidth: true
            Layout.leftMargin: 12
            Layout.rightMargin: 12
            Layout.bottomMargin: 6
            color: "transparent"
            ColorButton {
                id: btnLoad
                leftPadding: 8
                rightPadding: 8
                spacing: 2
                action: acLoadConfig
                display: config.width
                         < 500 ? AbstractButton.IconOnly : AbstractButton.TextBesideIcon
                width: display == AbstractButton.IconOnly ? height : Math.max(
                                                                implicitBackgroundWidth + leftInset
                                                                + rightInset,
                                                                implicitContentWidth + leftPadding
                                                                + rightPadding)
                icon.width: 16
                icon.height: 16 //needed on macOS
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
            }
            ColorButton {
                id: btnSave
                leftPadding: 8
                rightPadding: 8
                spacing: 2
                action: acSaveConfig
                display: config.width
                         < 500 ? AbstractButton.IconOnly : AbstractButton.TextBesideIcon
                width: display == AbstractButton.IconOnly ? height : Math.max(
                                                                implicitBackgroundWidth + leftInset
                                                                + rightInset,
                                                                implicitContentWidth + leftPadding
                                                                + rightPadding)
                icon.width: 16
                icon.height: 16
                anchors.left: btnLoad.right
                anchors.leftMargin: 3
                anchors.verticalCenter: parent.verticalCenter
            }
            ColorButton {
                id: btnReset
                action: acResetConfig
                icon.width: 16
                icon.height: 16
                display: AbstractButton.IconOnly
                height: btnSave.height
                width: height
                anchors.left: btnSave.right
                anchors.leftMargin: 3
                anchors.verticalCenter: parent.verticalCenter
                ToolTip {
                    text: acResetConfig.text
                    visible: btnReset.hovered
                    delay: 1000
                    timeout: 5000
                }
            }
            ColorCheckBox {
                id: cbShowTips
                anchors.left: btnReset.right
                anchors.leftMargin: 3
                anchors.verticalCenter: parent.verticalCenter
                checked: true
                text: qsTr("Show tips")
            }
            ColorButton {
                id: btnClose
                leftPadding: 8
                rightPadding: 8
                spacing: 2
                action: acClose
                icon.width: 16
                icon.height: 16
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                anchors.rightMargin: 10
            }
        }
    }
}
