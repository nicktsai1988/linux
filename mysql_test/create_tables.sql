--
--   create CD tables
--

create table cd(
	id integer auto_increment not NULL primary key,
	title varchar(70) not NULL,
	artist_id integer not NULL,
	catalogue varchar(30) not NULL,
	notes varchar(100)
);

create table artist(
    id integer auto_increment not NULL primary key,
    name varchar(100) not NULL
);
    
create table track(
    cd_id integer not NULL,
    track_id integer not NULL,
    title varchar(70),
    primary key(cd_id,track_id)
    );
