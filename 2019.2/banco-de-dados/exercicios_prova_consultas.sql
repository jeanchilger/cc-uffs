
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
select s.sname from sailors s
    where s.sid in (select s2.sid
                        from sailors s2
                        natural join reserves r
                        group by s2.sid
                        having count(r.bid) >= 2);

select s.sname from sailors s
    natural join reserves r
    group by s.sname
    having count(*) >= 2;

-- Q8:
select s.sid from sailors s
    natural join reserves r
    natural join boats b
    where b.color != 'red' and s.age > 20;

-- Q9: 
select s.sname from sailors s
where not exists (
    select b.bid from boats b
    except
    select r.bid from reserves r
        where s.sid = r.sid;
);

-- Q10: 
select s.sname from sailors s
    where not exists (
        select b.bid from boats b
            where b.bname = 'Interlake'
        except
        select r.bid from reserves r
            where s.sid = r.sid
    );

-- Q19: 
select s.sid from sailors s
    natural join reserves r
    natural join boats b
    where b.color = 'red'
except
select s.sid from sailors s
    natural join reserves r
    natural join boats b
    where b.color = 'green';

-- Q21: 
select s.sname from sailors s
    where not exists (
        select b.bid from boats b
            join reserves r on r.bid = b.bid
                           and r.sid = s.sid
            where b.color = 'red'
    );

-- Q22:
select s.sname from sailors s
    where s.rating > any (select s2.rating from sailors s2 
                                where s2.sname = 'Horatio' );

-- Q24:
select s.sid from sailors s
    where s.rating >= all(select max(s2.rating) from sailors s2;

-- Q26:
select avg(s.age) from sailors s
    where s.rating = 10;

-- Q27:
select s.sname, s.age from sailors s
    where s.age = (select max(s2.age) from sailors s2);

-- Q29:
select count(distinct s.sname) from sailors s;

-- Q30:
select s.sname from sailors s
    where s.age > (select max(s2.age) from sailors s2
                        where s2.rating = 10);

-- Q32:
select s.rating, min(s.age) from sailors s 
    where s.age >= 18
    group by s.rating
    having count(s.rating) >= 2;

-- Q33:
select count(*) as reservations from boats b
    natural join reserves r
    where b.color = 'red'
    group by b.bid;

-- Q34:
select s.rating, avg(s.age) as average_age from sailors s
    group by s.rating
    having count(*) >= 2;

-- Q37:
select s.rating, avg(s.age) as avg_age from sailors s
    group by s.rating
    having avg(s.age) = (select min(avg_age) from 
                            (select avg(s2.age) as avg_age from sailors s2
                                group by s2.rating)t);
