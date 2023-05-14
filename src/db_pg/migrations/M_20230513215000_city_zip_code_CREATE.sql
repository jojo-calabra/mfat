-- Create the user table and fields
CREATE TABLE cities (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    id_country INTEGER FOREIGN KEY NOT NULL,
    id_district INTEGER FOREIGN KEY NOT NULL,

    timezone TEXT NOT NULL CHECK (now() AT TIME ZONE timezone IS NOT NULL) -- throws error if timezone is not valid
    zip_code VARCHAR(10) NOT NULL,
    city_name VARCHAR(256) NOT NULL,
    
    lat double precision NOT NULL,
    lng double precision NOT NULL,

    created_at DATETIME NOT NULL,
    updated_at DATETIME NOT NULL
);

CREATE INDEX cities_name_lowercase_idx ON cities USING btree (lower((name)::text));

CREATE INDEX cities_geo_location_idx ON cities USING gist (ll_to_earth(lat, lng));