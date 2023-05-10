#!/bin/bash

# Load database credentials from .env file
source ../.env

# Spawn a shell in the running PostgreSQL container
docker exec -it my-db sh -c "psql -U $POSTGRES_USER $POSTGRES_DB"
