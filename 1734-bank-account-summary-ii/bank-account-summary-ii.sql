# Write your MySQL query statement below

select name,sum(amount) as 'balance'
from Transactions inner join
Users on
Transactions.account = Users.account
group by Transactions.account
having balance>10000