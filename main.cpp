#include <QApplication>
#include "view.h"
#include "presenter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
   // View w;
  //  w.show();
   // return a.exec();

    View *view = new View();
   Presenter *presenter = new Presenter(view);
    Q_UNUSED(presenter);
    view->show();

    return app.exec();
}
