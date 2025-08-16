with SelectionRank as(
    select name,salary,departmentId,
    dense_rank() over(partition by departmentId order by salary desc) as 'SalRank'
    from Employee
)

select D.name as 'Department',S.name 'Employee',S.salary as 'Salary'
from SelectionRank S
inner join 
Department D 
on 
S.departmentId = D.id
where S.SalRank = 1;


-- // Group by dept id karata and after that ranking karata.