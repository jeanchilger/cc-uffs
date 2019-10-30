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

-------------------------------------------------------------------------------------------
------------------------------------ NOT CHECKED ------------------------------------------
-------------------------------------------------------------------------------------------

-- Q9: ok
select s.sname from sailors s
where not exists (
    select b.bid from boats b
    except
    select r.bid from reserves r
        where s.sid = r.sid;
);

-- Q10: ok
select s.sname from sailors s
    where not exists (
        select b.bid from boats b
            where b.bname = 'Interlake'
        except
        select r.bid from reserves r
            where s.sid = r.sid
    );

-- Q19: ok
select s.sid from sailors s
    natural join reserves r
    natural join boats b
    where b.color = 'red'
except
select s.sid from sailors s
    natural join reserves r
    natural join boats b
    where b.color = 'green';

-- Q21: ok
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

-- Q24??:
select s.sid from silors s
    having s.rating = max(s.rating);

-- Q29:
select distinct count(s.sname) from sailors s;

-- Q30:

