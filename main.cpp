/* Author:      Floyd Ack
 * Date:        Tuesday, 22 February 2020
 * Github:      https://github.com/jaesonnn
 * Twitter:     https://twitter.com/WellFloyd
 * Facebook:    https://www.facebook.com/jason.ack/
 * Instagram:   https://www.instagram.com/wellfloyd_/
 * LinkedIn:    https://www.linkedin.com/in/floyd-ack-28b5a11a0/
*/

#include "calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.show();

    return a.exec();
}
