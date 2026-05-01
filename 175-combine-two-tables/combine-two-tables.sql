# Write your MySQL query statement below
-- // first name, last name, city and state of each person 
select P.firstName,P.lastName,A.city,A.state
from Person P
left outer join 
Address A 
on 
P.personId = A.personId