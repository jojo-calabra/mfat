-- country table and fields
CREATE TABLE countries_en (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    id_country_name INTEGER FOREIGN KEY NOT NULL,
    iso3166_1_alpha_2_code VARCHAR(2) NOT NULL,
    iso3166_1_alpha_3_code VARCHAR(2) NOT NULL,
    created_at DATETIME NOT NULL,
    updated_at DATETIME NOT NULL
);