# Write your MySQL query statement below

select distinct P1.email
from Person P1,Person P2
where P1.id <> P2.id and P1.email = P2.email;