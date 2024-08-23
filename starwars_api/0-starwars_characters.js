#!/usr/bin/node
// github.com/zafarali/starwars-api
const request = require('request');
const util = require('util');

// Promisify the request function
const requestPromise = util.promisify(request);

// Get the movie ID from the command line arguments
const movieId = process.argv[2];

if (!movieId) {
  console.error('Please provide a Movie ID as the first argument.');
  process.exit(1);
}

// URL for the specified movie
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// Function to fetch character data
async function fetchCharacterData(characterUrl) {
  try {
    const response = await requestPromise(characterUrl);
    if (response.statusCode !== 200) {
      throw new Error(`Failed to fetch character data. Status code: ${response.statusCode}`);
    }
    const characterData = JSON.parse(response.body);
    return characterData.name;
  } catch (error) {
    console.error('Error fetching character data:', error);
    return null;
  }
}

// Main function to fetch movie and character data
async function fetchMovieAndCharacters() {
  try {
    const movieResponse = await requestPromise(url);
    if (movieResponse.statusCode !== 200) {
      throw new Error(`Failed to fetch movie data. Status code: ${movieResponse.statusCode}`);
    }

    const movieData = JSON.parse(movieResponse.body);
    const characterUrls = movieData.characters;

    for (const characterUrl of characterUrls) {
      const characterName = await fetchCharacterData(characterUrl);
      if (characterName) {
        console.log(characterName);
      }
    }
  } catch (error) {
    console.error('Error:', error);
  }
}

// Run the main function
fetchMovieAndCharacters();