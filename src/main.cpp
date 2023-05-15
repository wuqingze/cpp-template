#include "SingleInstance.h"
#include "utility/CalculateUtility.h"
#include <stdio.h>

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

void test00(){
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
            printf("%s:%d age:%d\tgender:%s\tname:%s\tphone:%s\temail:%s\tbirth:%s\n", 
                    __FILE__, __LINE__,
                    res->getInt("age"),
                    res->getString("gender").c_str(),
                    res->getString("name").c_str(),
                    res->getString("phone").c_str(),
                    res->getString("email").c_str(),
                    res->getString("birth").c_str()
                    );
        }

        /* 清理资源 */
        delete res;
        delete stmt;
        delete con;
    } catch (sql::SQLException& e) {
        /* 处理异常 */
        printf("%s:%d sqlexception occured\n", __FILE__, __LINE__);
    }

}


int main(){
    test00();
    return 0;

    printf("%s|%d| hello world----\n", __FILE__, __LINE__);
    auto& obj = SingleInstance::getInstance();
    obj.hello();
    CalculateUtility cal;
    int i = cal.add(3,9);
    printf("---- i is %d ----\n", i);
    return 0;
}
