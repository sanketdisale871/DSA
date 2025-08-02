# Write your MySQL query statement below
with SelectionRank as(
    select id,email,
    row_number() over(partition by email order by id asc) as 'Ranki'
    from Person
)

delete from Person P
where P.id in (
    select sr.id
    from SelectionRank as sr
    where sr.Ranki>1
)