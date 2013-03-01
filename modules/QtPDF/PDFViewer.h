#include <QtGui/QtGui>

class PDFViewer : public QMainWindow {
  Q_OBJECT

public:
  PDFViewer(QString pdf_doc, QWidget *parent = 0, Qt::WindowFlags flags = 0);

private slots:
  void openUrl(const QUrl url) const;
  void openPdf(QString filename, int page, bool newWindow) const;
  void syncFromPdf(const int page, const QPointF pos);
};


class SearchLineEdit : public QLineEdit
{
  Q_OBJECT

public:
  SearchLineEdit(QWidget *parent = 0);

protected:
  void resizeEvent(QResizeEvent *);

private:
  QToolButton *nextResultButton, *previousResultButton, *clearButton;

signals:
  void searchRequested(QString searchText);

private slots:
  void prepareSearch();

};


class PageCounter : public QLabel {
  Q_OBJECT
  typedef QLabel super;
  int currentPage, lastPage;

public:
  PageCounter(QWidget *parent = 0, Qt::WindowFlags f = 0);

public slots:
  void setLastPage(int page);
  void setCurrentPage(int page);

private:
  void refreshText();
};


class ZoomTracker : public QLabel {
  Q_OBJECT
  typedef QLabel super;
  qreal zoom;

public:
  ZoomTracker(QWidget *parent = 0, Qt::WindowFlags f = 0);

public slots:
  void setZoom(qreal newZoom);

private:
  void refreshText();
};
