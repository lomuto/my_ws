const { MongoClient, ObjectId } = require('mongodb');

const connectionURL = 'mongodb://127.0.0.1:27017';
const databaseName = 'task-manager';

// Pass async callback function
MongoClient.connect(connectionURL, { useNewUrlParser: true }, async (error, client)=>{
    if(error) {
        return console.log(`Unable to connect to database: ${error}`);
    }

    const db = client.db(databaseName);

    const id = new ObjectId();

    const insertOneResult = await db.collection('task').insertOne(
        {
            _id: id,                        // With no given `_id` property, mongo will generate it automatically
            description: "Clean my room",
            isFinished: false
        }
    );
    console.log(insertOneResult);

    const deleteUnfinishedTasksResult = await db.collection('tasks').deleteMany(
        {
            isFinished: false
        }
    );
    console.log(deleteUnfinishedTasksResult);
});