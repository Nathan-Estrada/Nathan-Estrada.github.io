from pymongo import MongoClient
from pymongo import MongoClient
from bson.objectid import ObjectId
from pprint import pprint

class DataBase(object):
    def __init__(self):
        connection_string = 'mongodb://localhost:27017/db.perfumania_fragrances_prices_averaged'
        DB = 'db'
        COL = 'perfumania_fragrances_prices_averaged'

        self.client = MongoClient(connection_string)
        self.db = self.client['%s' % (DB)]
        self.collection = self.db['%s' % (COL)]

    #TODO: Ensure quality data is added
    def create(self, data):
        if data is not None:
            self.collection.insert_one(data)
            print("Sale data added")
            return True
        else:
            raise Exception("Data parameter is empty")
            return False

    #TODO: Test for empty searches
    def read(self, searchQuery): 
        if searchQuery is not None:
            return self.collection.find(searchQuery)
        else:
            print("Cannot conduct empty search")
            return None
    
    #TODO: Ensure quality data is added  
    def update(self, searchQuery, updateQuery):
        if searchQuery is not None and updateQuery is not None:
            self.collection.update_one(searchQuery, updateQuery)
            print("Transaction updated")
            return self.collection.find(searchQuery)
        else:
            print("No data entered")
            return None
        
    def delete(self, searchQuery):
        if searchQuery is not None:
            x = self.collection.delete_many(searchQuery)
            print(x.deleted_count, "document(s) deleted")
        #Important to prevent an empty query for delete_many to avoid accidentally deleting all documents
        else:
            print("No data entered")
            return None