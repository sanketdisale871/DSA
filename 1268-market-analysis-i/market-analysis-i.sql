# Write your MySQL query statement below
# join date,no.of Orders = "2019"
select U.user_id as buyer_id,U.join_date,count(O.buyer_id) as "orders_in_2019"
from Users as U left outer join 
Orders as O
on U.user_id = O.buyer_id and year(O.order_date) = "2019"
group by U.user_id