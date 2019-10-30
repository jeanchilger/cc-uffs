-- Q6:
select s.sname from sailors s
    natural join reserves r
    natural join boats b
    where b.color='red'
intersect
select s.sname from sailors s
    natural join reserves r
    natural join boats b
    where b.color='green';

-- Q7:

-- Q8:
select s.sid from sailors s
    natural join reserves r
    natural join boats b
    where b.color != 'red' and s.age > 20;

-- Q9:
