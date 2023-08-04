#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel label("¡Hola, Qt!");
    label.show();

    return app.exec();
}
