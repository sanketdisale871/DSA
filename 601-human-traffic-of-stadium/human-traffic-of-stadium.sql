with CTE as(
    select id,visit_date,people,
    id-row_number() over(order by id asc) as "grp"
    from Stadium
    where people > 99
)

select id,visit_date,people
from CTE 
where grp in (
    select grp from CTE
    group by grp
    having count(*)>2
)
order by visit_date


