from pymongo import MongoClient
from bson.objectid import ObjectId
from pprint import pprint

class AnimalShelter(object):
    def __init__(self, user, passwd, host, port, database, collection):
        USER = user
        PASS = passwd
        HOST = host
        PORT = port
        DB = database
        COL = collection
        
        self.client = MongoClient('mongodb://%s:%s@%s:%d' % (USER,PASS,HOST,PORT))
        self.database = self.client['%s' % (DB)]
        self.collection = self.database['%s' % (COL)]

    #Implements C in CRUD
    def create(self, data):
        if data is not None:
            self.database.animals.insert_one(data)
            print("Animal added")
            return True
        else:
            raise Exception("Data parameter is empty")
            return False

    #Implements R in CRUD
    def read(self, searchQuery=None):
        return self.database.animals.find(searchQuery)
    
    #Implements U in CRUD    
    def update(self, searchQuery, updateQuery):
        if searchQuery is not None and updateQuery is not None:
            self.database.animals.update_one(searchQuery, updateQuery)
            print("Document updated")
            return self.database.animals.find(searchQuery)
        else:
            print("No data entered")
            return None
        
    #Implements D in CRUD    
    def delete(self, searchQuery):
        if searchQuery is not None:
            x = self.database.animals.delete_many(searchQuery)
            print(x.deleted_count, "document(s) deleted")
        #Important to prevent an empty query for delete_many to avoid accidentally deleting all documents
        else:
            print("No data entered")
            return None