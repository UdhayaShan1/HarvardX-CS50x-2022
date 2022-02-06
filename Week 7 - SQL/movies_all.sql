SELECT title FROM movies where year = '2008';

SELECT birth from people where name like 'Emma Stone';

SELECT title from movies where year>='2018' ORDER BY title ASC;

SELECT COUNT(movie_id) from ratings where rating = '10.0';

SELECT title, year from movies where title like 'Harry Potter%' ORDER BY year ASC;

SELECT AVG(rating) from ratings where movie_id in (SELECT id from movies where year = '2012');

SELECT movies.title, ratings.rating FROM movies inner join ratings on movies.id  = ratings.movie_id where year = '2010' ORDER BY rating DESC,title ASC;

SELECT name from people where id in (SELECT person_id from stars where movie_id in (select id from movies where title like 'Toy Story%'));

SELECT name from people where id in (SELECT person_id from stars where movie_id in (SELECT id from movies where year = '2004')) ORDER BY birth;

SELECT name from people where id in (SELECT person_id from directors where movie_id in (SELECT movie_id from ratings where rating >= 9.0));

SELECT title from movies JOIN ratings ON movies.id = ratings.movie_id where id in (SELECT movie_id from stars where person_id = (SELECT id from people where name like "%Chadwick Boseman%")) ORDER BY rating DESC LIMIT 5;

SELECT title from movies where id in (SELECT movie_id from stars where person_id = (SELECT id from people where name like '%Johnny Depp%') INTERSECT SELECT movie_id from stars where person_id = (SELECT id from people where name like '%Helena Bonham Carter%'));

SELECT (name) from people where (name not like '%Kevin Bacon%') and id in (SELECT person_id from stars where movie_id in (SELECT movie_id from stars where person_id = (SELECT id from people where name like '%Kevin Bacon%' and birth = '1958'))) ORDER BY name;
