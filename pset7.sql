-- I used the database from:
-- movies.db in https://drive.google.com/drive/folders/1fVlBWNuSw774F0bocQAoxKd24YwTQcwh?usp=sharing

--write a SQL query to list the titles of all movies released in 2008
SELECT title FROM movies WHERE year = 2008;

--write a SQL query to determine the birth year of Emma Stone
SELECT birth FROM people WHERE name = 'Emma Stone';

--write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
SELECT title FROM movies WHERE (year = 2018 OR year > 2018) ORDER BY title;

--write a SQL query to determine the number of movies with an IMDb rating of 10.0
SELECT COUNT(movie_id) FROM ratings WHERE rating = 10.0;

--write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order
SELECT title, year FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year;

-- write a SQL query to determine the average rating of all movies released in 2012
--USE JOIN table ON ... instead of WHERE to apply to all the numbers
SELECT AVG(rating) FROM ratings
JOIN movies ON ratings.movie_id = movies.id WHERE year = 2012;

--write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. 
--For movies with the same rating, order them alphabetically by title.
--Use JOIN to list 2 different elements from 2 tables
SELECT title, rating FROM movies JOIN ratings ON ratings.movie_id = movies.id WHERE year = 2010 ORDER BY rating DESC, title; 

-- write a SQL query to list the names of all people who starred in Toy Story
SELECT name FROM people JOIN movies ON movies.id = stars.movie_id JOIN stars ON stars.person_id = people.id WHERE title = 'Toy Story';

--write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
SELECT name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE year = 2004 ORDER BY birth;

--write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
-- don't use group by, use distinct instead
-- The GROUP BY statement is often used with aggregate functions (COUNT(), MAX(), MIN(), SUM(), AVG()) to group the result-set by one or more columns.
SELECT DISTINCT name FROM people
JOIN directors ON people.id = directors.person_id
JOIN movies ON directors.movie_id = movies.id
JOIN ratings ON movies.id = ratings.movie_id
WHERE rating >= 9.0;


--write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
SELECT title FROM movies
JOIN people ON people.id = stars.person_id
JOIN stars ON stars.movie_id = movies.id
JOIN ratings ON ratings.movie_id = movies.id
WHERE name = 'Ryan Gosling'
ORDER BY rating DESC LIMIT 5;

--write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
--can use INTERSECT to output the titles of movies have 2 stars.
-- Or u can use IN to find all the title of movie has Helena Bonham Carter (nested SQL)
SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE name = 'Johnny Depp' AND title IN
(SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE name = 'Helena Bonham Carter');

--write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
SELECT DISTINCT name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE title IN
(SELECT DISTINCT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE name = 'Kevin Bacon') EXCEPT
SELECT name from people
WHERE name = 'Kevin Bacon';

