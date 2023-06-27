#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
     setStyleSheet("background:transparent;");
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->listWidget->addItem("Clipboard++ [SLOT 0]");
     ui->listWidget->addItem("Clipboard++ [SLOT 1]");
      ui->listWidget->addItem("Clipboard++ [SLOT 2]");
       ui->listWidget->addItem("Clipboard++ [SLOT 3]");
        ui->listWidget->addItem("Clipboard++ [SLOT 4]");
         ui->listWidget->addItem("Clipboard++ [SLOT 5]");
          ui->listWidget->addItem("Clipboard++ [SLOT 6]");
           ui->listWidget->addItem("Clipboard++ [SLOT 7]");
            ui->listWidget->addItem("Clipboard++ [SLOT 8]");
             ui->listWidget->addItem("Clipboard++ [SLOT 9]");
    ui->listWidget->setAttribute(Qt::WA_TranslucentBackground,true);
    running=true;
    last="Clipboard++ [Prototype]";
    QTimer *timerAction=new QTimer(this);
    timerAction->start(100);
    QObject::connect(timerAction, SIGNAL(timeout()), this, SLOT(mainLoop()));
    QObject::connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                this, SLOT(onElementClicked(QListWidgetItem*)));
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onElementClicked(QListWidgetItem* item){

            const char* output =item->text().toStdString().c_str();
            lastWid=item;
            const size_t len = strlen(output) + 1;
            HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
            memcpy(GlobalLock(hMem), output, len);
            GlobalUnlock(hMem);
            OpenClipboard(0);
            EmptyClipboard();
            SetClipboardData(CF_TEXT, hMem);
            CloseClipboard();
}
std::string MainWindow::getClipBoardData(){
    HANDLE h;
    if (!OpenClipboard(NULL)){
        return "[|*|]Erreur : Je ne prends que du texte.";
      }

     h = GetClipboardData(CF_TEXT);


     CloseClipboard();
     return (char *)h;
}

void MainWindow::type(char p){
    //for(int i=0;i<p.length();i++) {
        INPUT Input = {0};
        Input.type=INPUT_KEYBOARD;
        Input.ki.wVk=VkKeyScanA(p);
        SendInput(1,&Input,sizeof(Input));
        ZeroMemory(&Input,sizeof(Input));
    //}


}

void MainWindow::mainLoop(){
    /*try{std::string res = getClipBoardData();

        if(res!=last){
            last=res;
            ui->listWidget->addItem(QString::fromStdString(last));

        }
    }
    catch(...){
    }*/
    std::string res="[*]Donnée du ClipBoard pas de type text !";
    try {
        res = getClipBoardData();
    } catch (...) {

    }
    if (GetAsyncKeyState(VK_CONTROL) < 0 & GetAsyncKeyState(18)<0) {
        // The S key is down.
        ui->logs->setText("Alt+Control Detecté");
        if(GetKeyState('C')<0){
            if(GetAsyncKeyState(VK_NUMPAD0)<0){ui->listWidget->item(0)->setText(QString::fromStdString(res));}
            if(GetAsyncKeyState(VK_NUMPAD1)<0){ui->listWidget->item(1)->setText(QString::fromStdString(res));}
            if(GetAsyncKeyState(VK_NUMPAD2)<0){ui->listWidget->item(2)->setText(QString::fromStdString(res));}
            if(GetAsyncKeyState(VK_NUMPAD3)<0){ui->listWidget->item(3)->setText(QString::fromStdString(res));}
            if(GetAsyncKeyState(VK_NUMPAD4)<0){ui->listWidget->item(4)->setText(QString::fromStdString(res));}
            if(GetAsyncKeyState(VK_NUMPAD5)<0){ui->listWidget->item(5)->setText(QString::fromStdString(res));}
            if(GetAsyncKeyState(VK_NUMPAD6)<0){ui->listWidget->item(6)->setText(QString::fromStdString(res));}
            if(GetAsyncKeyState(VK_NUMPAD7)<0){ui->listWidget->item(7)->setText(QString::fromStdString(res));}
            if(GetAsyncKeyState(VK_NUMPAD8)<0){ui->listWidget->item(8)->setText(QString::fromStdString(res));}
            if(GetAsyncKeyState(VK_NUMPAD9)<0){ui->listWidget->item(9)->setText(QString::fromStdString(res));}

            ui->logs->setText("Alt+Control+C detecté");}
        if(GetKeyState('V')<0){
            //ui->logs->setText("Alt+Control+V detecté");
            if(GetAsyncKeyState(VK_NUMPAD0)<0){ onElementClicked(ui->listWidget->item(0));}
            if(GetAsyncKeyState(VK_NUMPAD1)<0){ onElementClicked(ui->listWidget->item(1));}
            if(GetAsyncKeyState(VK_NUMPAD2)<0){ onElementClicked(ui->listWidget->item(2));}
            if(GetAsyncKeyState(VK_NUMPAD3)<0){ onElementClicked(ui->listWidget->item(3));}
            if(GetAsyncKeyState(VK_NUMPAD4)<0){ onElementClicked(ui->listWidget->item(4));}
            if(GetAsyncKeyState(VK_NUMPAD5)<0){ onElementClicked(ui->listWidget->item(5));}
            if(GetAsyncKeyState(VK_NUMPAD6)<0){ onElementClicked(ui->listWidget->item(6));}
            if(GetAsyncKeyState(VK_NUMPAD7)<0){ onElementClicked(ui->listWidget->item(7));}
            if(GetAsyncKeyState(VK_NUMPAD8)<0){ onElementClicked(ui->listWidget->item(8));}
            if(GetAsyncKeyState(VK_NUMPAD9)<0){ onElementClicked(ui->listWidget->item(9));}

        }
    } else {

         ui->logs->setText("Aucun fonctionnement détecté");
    }

}


void MainWindow::on_pushButton_pressed()
{
    qDeleteAll(ui->listWidget->selectedItems());
}
