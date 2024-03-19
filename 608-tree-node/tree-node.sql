# Write your MySQL query statement below


select id,
(case 
    when p_id is null then 'Root'
    when id in (select S.p_id from Tree S) then 'Inner'
    else 'Leaf'
    end) as type
from Tree
