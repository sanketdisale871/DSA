# Write your MySQL query statement below
select O.customer_number
from Orders as O
group by O.customer_number
order by count(O.customer_number) desc
limit 1
