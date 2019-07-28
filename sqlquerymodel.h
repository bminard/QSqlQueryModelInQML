#ifndef SQLQUERYMODEL_H
#define SQLQUERYMODEL_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>

class SqlQueryModel : public QSqlQueryModel
{
    Q_OBJECT

    Q_PROPERTY(QString query READ queryStr WRITE setQueryStr NOTIFY queryStrChanged)
    Q_PROPERTY(QStringList userRoleNames READ userRoleNames CONSTANT)

public:
    SqlQueryModel(QObject* parent = nullptr);
    ~SqlQueryModel(); 

    void clear();
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    QString queryStr() const;
    void setQueryStr(const QString &query);
    QStringList userRoleNames() const;
signals:
    void queryStrChanged();
};
#endif // SQLQUERYMODEL_H
