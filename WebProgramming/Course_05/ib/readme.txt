Всякая всячина по курсовой.

MariaDB [ib]> create table posts (
    -> id INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
    -> message LONGTEXT,
    -> PRIMARY KEY (id)
    -> );

MariaDB [ib]> insert into posts (message) values ('This is simple text');

MariaDB [ib]> create table posts ( id INT(10) UNSIGNED NOT NULL AUTO_INCREMENT, thread_id INT NOT NULL, message LONGTEXT, PRIMARY KEY (id), INDEX (thread_id), FOREIGN KEY (thread_id) REFERENCES threads (thread_id) ON DELETE CASCADE );

MariaDB [ib]> create table posts ( id INT(10) UNSIGNED NOT NULL AUTO_INCREMENT, thread_id INT NOT NULL, message LONGTEXT NOT NULL, PRIMARY KEY (id), INDEX (thread_id), FOREIGN KEY (thread_id) REFERENCES threads (thread_id) ON DELETE CASCADE );

MariaDB [ib]> select now();
+---------------------+
| now()               |
+---------------------+
| 2019-12-03 15:20:29 |
+---------------------+
1 row in set (0.03 sec)

MariaDB [ib]> create table posts ( id INT(10) UNSIGNED NOT NULL AUTO_INCREMENT, thread_id INT NOT NULL, dt DATETIME DEFAULT now(), message LONGTEXT NOT NULL, PRIMARY KEY (id), INDEX (thread_id), FOREIGN KEY (thread_id) REFERENCES threads (thread_id) ON DELETE CASCADE );
Query OK, 0 rows affected (0.47 sec)

MariaDB [ib]> create table posts ( id INT(10) UNSIGNED NOT NULL AUTO_INCREMENT, thread_id INT NOT NULL, dt DATETIME NOT NULL DEFAULT now(), message LONGTEXT NOT NULL, PRIMARY KEY (id), INDEX (thread_id), FOREIGN KEY (thread_id) REFERENCES threads (thread_id) ON DELETE CASCADE );
Query OK, 0 rows affected (0.48 sec)

MariaDB [ib]> create table posts ( id INT(10) UNSIGNED NOT NULL AUTO_INCREMENT, thread_id INT NOT NULL, dt DATETIME NOT NULL DEFAULT now(), picture VARCHAR (30), message LONGTEXT NOT NULL, PRIMARY KEY (id), INDEX (thread_id), FOREIGN KEY (thread_id) REFERENCES threads (thread_id) ON DELETE CASCADE );
Query OK, 0 rows affected (0.37 sec)
