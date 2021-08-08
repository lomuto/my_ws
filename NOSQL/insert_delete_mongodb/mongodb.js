const { MongoClient, ObjectId } = require('mongodb');

const connectionURL = 'mongodb://127.0.0.1:27017';
const databaseName = 'task-manager';

MongoClient.connect(connectionURL, { useNewUrlParser: true }, (error, client)=>{
    if(error) {
        return console.log(`Unable to connect to database: ${error}`);
    }

    const db = client.db(databaseName);

    const id = new ObjectId();

    // Insert a single task in `task` collection
    db.collection('task').insertOne(
        {
            _id: id,                        // With no given `_id` property, mongo will generate it automatically
            description: "Clean my room",
            isFinished: false
        },
        (error, result) => {
            if(error) {
                console.log(`Fail to insert task`);
            }
            console.log(result);
        }
    )

    // Inserting mant tasks
    db.collection('task').insertMany([
            {
                description: "Eat dinner",
                isFinished: false
            },
            {
                description: "Throw away garbages",
                isFinished: false
            }
        ],
        (error, result) => {
            if(error) {
                console.log(`Fail to insert task`);
            }
            console.log(result);
        }
    )

    // Delete every task that is not finished
    db.collection('tasks').deleteMany(
        {
            isFinished: false
        }
    )
});