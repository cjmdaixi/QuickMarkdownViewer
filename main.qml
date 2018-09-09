import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import "markdown-it.js" as MarkdownIt

Window {
    visible: true
    width: 1024
    height: 768
    title: qsTr("Quick Markdown Viewer")
    ScrollView{
        anchors.fill: parent
        TextArea{
            id: textArea
            readOnly: true
            textFormat: TextEdit.RichText
            wrapMode: TextEdit.WordWrap
            font.pixelSize: 15
            font.family: "Microsoft YaHei UI"
            Component.onCompleted: {
                $app.setDefaultStyleSheet(textArea.textDocument);
            }
        }
    }

    DropArea{
        id: dropArea
        anchors.fill: parent
        onDropped:{
            //console.log("dropped", drop.keys);
            var path = drop.urls[0].toString();
            // remove prefixed "file:///"
            path= path.replace(/^(file:\/{3})|(qrc:\/{2})|(http:\/{2})/,"");
            // unescape html codes like '%23' for '#'
            var cleanPath = decodeURIComponent(path);
            console.log("clean path:", cleanPath);
            var suffix = $app.fileSuffix(cleanPath);
            if(suffix === "md" || suffix === "markdown"){
                var fileDir = $app.fileDir(cleanPath);
                console.log(fileDir);
                $app.setBaseUrl(textArea.textDocument, "file:///" + fileDir + "/");
                var md = new MarkdownIt.markdownit();
                var mdHtml = md.render($app.readAll(cleanPath));
                textArea.text = mdHtml;
            }
        }
    }
}
