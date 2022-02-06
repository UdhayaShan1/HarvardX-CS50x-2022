All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.

-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports where year like '%2021%' and day like '28' and month like '7' and street like '%Humphrey Street%' and description like '%CS50%';
-- Know information on crime first ID 295 Time 10:15am, bakery
SELECT * from interviews where year = '2021' and month = '7' and day = '28';
-- Interviews on that date, thief drove away, ATM Leggett Street, thief plans to take the earliest flight out tommorow (29) accomplice to purchase ticket, half an hour call, within 10 mins
-- he left, two phone calls, half an hour in bakery and one min after theft


--SUSPECTS -G412CB7, 6P58WS2, 4328GD8, 5P2BI95
--(770) 555-1861

SELECT * from phone_calls where year = '2021' and month = '7' and day = '28' and duration < 60;

SELECT account_number from atm_transactions where year = '2021' and month = '7' and day = '28' and atm_location like '%Leggett%' and transaction_type like "%withdraw%";
-- account numbers of those withdrawing in morning

SELECT person_id from bank_accounts where account_number in (SELECT account_number from atm_transactions where year = '2021' and month = '7' and day = '28' and atm_location like '%Leggett%' and transaction_type like "%withdraw%");
-- person ids

SELECT name from people where id in (SELECT person_id from bank_accounts where account_number in (SELECT account_number from atm_transactions where year = '2021' and month = '7' and day = '28' and atm_location like '%Leggett%' and transaction_type like "%withdraw%"));
-- names of those who withdrew in morning
 name   |
-- Main suspects
--| Kenny   |
--| Iman    |
--| Benista |
--| Taylor  |
--| Brooke  |
--| Luca    |
--| Diana   |
--| Bruce

-- find those with license number of car that left bakery within 10 mins from 1015am
SELECT name from people where license_plate in (SELECT license_plate from bakery_security_logs where year = '2021' and month = '7' and day = '28' and hour = 10 and minute >=15 and minute <=25) INTERSECT SELECT name from people where id in (SELECT person_id from bank_accounts where account_number in (SELECT account_number from atm_transactions where year = '2021' and month = '7' and day = '28' and atm_location like '%Leggett%' and transaction_type like "%withdraw%"));

-- info abt those that called <= 60 ,
SELECT * from phone_calls where year = '2021' and month = '7' and day = '28' and duration <= 60;
-- names of those who call <= 60 seconds

SELECT name from people where phone_number in (SELECT caller from phone_calls where year = '2021' and month = '7' and day = '28' and duration <= 60);
-- common names with those with license number of car earlier and also those who withdrew from ATM in morning and call <=60 seconds (ATM N CALL N LICENSE)

SELECT name from people where license_plate in (SELECT license_plate from bakery_security_logs where year = '2021' and month = '7' and day = '28' and hour = 10 and minute >=15 and minute <=25) INTERSECT SELECT name from people where id in (SELECT person_id from bank_accounts where account_number in (SELECT account_number from atm_transactions where year = '2021' and month = '7' and day = '28' and atm_location like '%Leggett%' and transaction_type like "%withdraw%")) INTERSECT SELECT name from people where phone_number in (SELECT caller from phone_calls where year = '2021' and month = '7' and day = '28' and duration <= 60);
--Bruce and Diana left--
--check bruce calls
SELECT phone_number from people where name like "%Bruce%";

SELECT phone_number from people where name like "%Diana%";

SELECT * from phone_calls where caller in (SELECT phone_number from people where name like "%Bruce%") and year = '2021' and month = '7' and day = '28';
-- one call of 45 seconds and possibly three other calls in store whispering in phone
-- check diana next

SELECT * from phone_calls where caller in (SELECT phone_number from people where name like "%Diana%") and year = '2021' and month = '7' and day = '28';
-- diana has only one call
--Only Bruce has two calls, Bruce is thief


SELECT receiver from phone_calls where caller in (SELECT phone_number from people where name like "%Bruce%") and year = '2021' and month = '7' and day = '28';

SELECT name from people where phone_number in (SELECT receiver from phone_calls where caller in (SELECT phone_number from people where name like "%Bruce%") and year = '2021' and month = '7' and day = '28');
-- Possible accomplices
--| Gregory |
--| Carl    |
--| Robin   |
--| Deborah |
-- Airport id

SELECT id from airports where city like "%Fiftyville%";
--Earliest flight out of fiftyville

SELECT * from flights where origin_airport_id in (SELECT id from airports where city like "%Fiftyville%") and year = '2021' and month = '7' and day = '29' ORDER BY hour ASC LIMIT 1;
--Destination id

SELECT destination_airport_id from flights where origin_airport_id in (SELECT id from airports where city like "%Fiftyville%") and year = '2021' and month = '7' and day = '29' ORDER BY hour ASC LIMIT 1;
--Final aiport

SELECT city from airports where id like (SELECT destination_airport_id from flights where origin_airport_id in (SELECT id from airports where city like "%Fiftyville%") and year = '2021' and month = '7' and day = '29' ORDER BY hour ASC LIMIT 1);
-- New York City
-- Only phone call to be 45 seconds and what is the receiver of that
SELECT receiver from phone_calls where caller in (SELECT phone_number from people where name like "%Bruce%") and year = '2021' and month = '7' and day = '28' ORDER BY duration ASC;
-- Name of that receiver, he/she is the one to help book the flight
SELECT name from people where phone_number = (SELECT receiver from phone_calls where caller in (SELECT phone_number from people where name like "%Bruce%") and year = '2021' and month = '7' and day = '28' ORDER BY duration ASC);
-- Robin is the accomplice
