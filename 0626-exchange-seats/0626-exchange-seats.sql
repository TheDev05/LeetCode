# Write your MySQL query statement below
select t1.id, 

case
when (select count(id) from seat) % 2 != 0 and t1.id = (select count(id) as counted from seat) then t1.student
when t1.id % 2 = 0 then (select student from seat where id = (select max(p2.id) from seat as p2 where p2.id < t1.id ))
when t1.id % 2 != 0 then (select student from seat where id = (select min(p2.id) from seat as p2 where p2.id > t1.id ))
end as student

from seat as t1 
inner join seat as t2 on t1.id = t2.id


