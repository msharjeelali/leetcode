# Write your MySQL query statement below
select (select num from MyNumbers group by num having count(*) < 2 order by num desc limit 1) as num;
