# Write your MySQL query statement below
-- select email as Email
-- from Person
-- group by email
-- having count(email)>1

# Same mail id But Different Id wrt?

select distinct P1.email as Email
from Person as P1,
Person as P2
where P1.email = P2.email and P1.id != p2.id;