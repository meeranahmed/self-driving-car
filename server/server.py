from flask import Flask , request,jsonify
from flask_cors import CORS, cross_origin


app=Flask(__name__)
CORS(app)
cors = CORS(app, resource={
    r"/*":{
        "origins":"*"
    }
})

@app.route("/")
def main():
    return 'main'

@app.route("/get/")
def predict():
    value=request.args.get('val')
    print(value)
    return "done"

@app.route('/post', methods=['POST'])
def post():
    if request.method == 'POST':
        data = request.get_json()
        print(data["value"])
        return str(data)

if __name__ == "__main__":
    # app.run(host='172.28.130.54', port= 8000, debug=True)
    app.run(port=8000,debug=True)