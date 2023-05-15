#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <stdio.h>
int main(){
    try {
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        /* 创建 MySQL 连接 */
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "nong", "nong");

        /* 选择数据库 */
        con->setSchema("test00");

        /* 执行 SQL 查询 */
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM person");
        while (res->next()) {
            /* 处理查询结果 */
            printf("%s:%d  --\n", __FILE__, __LINE__);
        }

        /* 清理资源 */
        delete res;
        delete stmt;
        delete con;
    } catch (sql::SQLException& e) {
        int i=0;
        /* 处理异常 */
            printf("%s:%d sqlexception --\n", __FILE__, __LINE__);
    }
    return 0;
}
