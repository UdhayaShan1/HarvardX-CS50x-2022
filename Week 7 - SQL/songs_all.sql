SELECT name FROM songs;

SELECT name FROM songs ORDER BY tempo ASC;

SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;

SELECT name FROM songs WHERE danceability > 0.75 AND energy > 0.75 and valence > 0.75;

SELECT AVG(energy) FROM songs;

SELECT name from songs where artist_id = (SELECT id FROM artists WHERE name LIKE 'Post Malone');

SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id from artists where name LIKE 'Drake');

SELECT name from songs where name like '%feat.%';
