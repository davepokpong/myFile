from flask import Flask, request
from flask_pymongo import PyMongo
from flask_cors import CORS, cross_origin

app = Flask(__name__)
cors = CORS(app, resources={r"/": {"origins": "*"}})
app.config['MONGO_URI'] = 'mongodb://exceed_group12:nhm88g6s@158.108.182.0:2255/exceed_group12'
mongo = PyMongo(app)

myCollection = mongo.db.data

@app.route('/', methods=['GET'])
@cross_origin()
def hello():
    return{'result':'hello'}

@app.route('/data', methods=['GET'])
@cross_origin()
def getall():
    f_name = request.args.get('firstname', -1)
    l_name = request.args.get('lastname', -1)
    people = request.args.get('people', -1)
    phone_num = request.args.get('phone_num', -1)

    if f_name != -1:
        flit={'firstname': f_name}
        query = myCollection.find(flit)
    elif l_name != -1:
        flit={'lastname': l_name}
        query = myCollection.find(flit)
    elif people != -1:
        flit={'pplnum': people}
        query = myCollection.find(flit)
    elif phone_num != -1:
        flit={'tel': phone_num}
        query = myCollection.find(flit)
    else:
        query = myCollection.find()

    output = []
    for i in query:
        output.append({
            'firstname' : i['firstname'],
            'lastname' : i['lastname'],
            'pplnum' : i['pplnum'],
            'tel' : i['tel']
        })
    
    return {'result': output}

@app.route('/data', methods=['POST'])
@cross_origin()
def insert():
    data = request.json

    if 'firstname' in data and 'lastname' in data and 'pplnum' in data:
        myCollection.insert(data)
        return {'result' : 'success'}
    else:
        return {'result' : 'false'}



# @app.route('/store', methods=['POST'])
# def inp():
#     data = request.json

#     if 'Brand' in data and 'Product_name' in data and 'Product_description' in data:
#         myCollection.insert_one(data)
#         return {'result' : 'success'}
#     else:
#         return {'result' : 'false'}

if __name__ == "__main__":
    app.run(host='192.168.1.38', port='3000', debug=True) 