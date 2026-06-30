# Write your MySQL query statement below
select name from SalesPerson where sales_id not in (select O.sales_id from Company as C join Orders as O on C.com_id = O.com_id where C.name = 'RED');
