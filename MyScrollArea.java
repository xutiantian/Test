��#include 

����<QScrollArea><QPoint>

����

����class

����{

����MyScrollArea : public QScrollArea

����

����

���������Ϳ���ʹ��������������ڵ�parent��������������ݾ�֧���϶��ˡ�

����Q_OBJECT

����public:

����QWidget* parent =NULL);

����MyScrollArea(

����~MyScrollArea(){};

����protected

����:

����    bool eventFilter(QObject *obj, QEvent*evt);

����private

����:bool mMoveStart;bool mContinousMove;    QPoint mMousePoint; 

����};

����cpp�ļ�

����#include <QMouseEvent>

����

����#include <QScrollBar> 

����#include "myscrollarea.h" 

����MyScrollArea::MyScrollArea(QWidget* parent) 

����: QScrollArea(parent)

����,mMoveStart(false)

����{

����installEventFilter

����(this);}  

����bool MSCScrollArea::eventFilter(QObject *obj, QEvent *evt)

����{

����    if (evt->type() == QEvent::MouseMove) {

����        QMouseEvent* me = (QMouseEvent*) evt;

����        if ((me->buttons() & Qt::LeftButton)) {

����            if (!mMoveStart) {

����                mMoveStart = true;

����                mContinousMove =false;

����                mMousePoint = me->globalPos();

����            }

����            else {

����                QScrollBar* scrollBar = verticalScrollBar();

����                QPoint p = me->globalPos();

����                int offset = p.y() - mMousePoint.y();

����                if( !mContinousMove && ( offset > -10 && offset < 10 ) )

����                    return false;

����

����                mContinousMove = true;

����               

����                scrollBar->setValue(scrollBar->value() - offset);

����                mMousePoint = p;

����            }

����            return true;

����        }

����    }

����    else if (evt->type() == QEvent::MouseButtonRelease) {

����        mMoveStart = false;

����    }

����    return QObject::eventFilter(obj, evt);

����}