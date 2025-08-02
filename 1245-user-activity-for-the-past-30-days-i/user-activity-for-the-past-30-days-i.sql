# Write your MySQL query statement below
# 2019-07-27 - 2019-06-28
select A.activity_date as 'day',count(distinct user_id) as 'active_users'
from Activity as A
group by A.activity_date
having A.activity_date between '2019-06-28' and '2019-07-27' 


