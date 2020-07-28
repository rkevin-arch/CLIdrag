#include <iostream>
#include <filesystem>
#include <QGuiApplication>
#include <QUrl>
#include <QMimeData>
#include <QDrag>
int main(int argc, char *argv[])
{
    if(argc==1){
        std::cout << "Usage: " << argv[0] << " FILENAME [FILENAME ...]" << std::endl;
        std::cout << "Initiates a drag operation as if you're dragging a file / multiple files." << std::endl;
        std::cout << "Click in the window you want to drag the files to." << std::endl;
        return 0;
    }

    QGuiApplication app(argc, argv);

    QList<QUrl> urls;
    for(int i=1;i<argc;i++){
        std::filesystem::path abspath = std::filesystem::absolute(argv[i]);
        if(!std::filesystem::exists(abspath)){
            std::cout << "WARNING: File " << argv[i] << " doesn't exist!" << std::endl;
        }
        urls.append(QUrl::fromLocalFile(abspath.c_str()));
    }

    QMimeData* mimedata = new QMimeData();
    mimedata->setUrls(urls);

    QObject dummyobj;
    QDrag* qdrag = new QDrag(&dummyobj);
    qdrag->setMimeData(mimedata);
    qdrag->exec();

    return 0;
}
