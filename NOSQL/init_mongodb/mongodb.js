const { MongoClient } = require('mongodb');

const connectionURL = '~~';
const databaseName = 'myDb';

MongoClient.connect(connectionURL, { useNewUrlParser: true }, (errpr, client) => {
    if(error) {
        return console.log(`Unable to connect to database ${error}`);
    }

    const db = client.db(databaseName);
})