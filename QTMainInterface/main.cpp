#include "QTMainWindow.h"

int main(int argc, char* argv[])
{
    QApplication qtAMain(argc, argv);
    
    QTMainWindow mainWindow;
    mainWindow.show();

    return qtAMain.exec();
}