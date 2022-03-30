from flask import Flask , request,jsonify
from flask_cors import CORS, cross_origin


app=Flask(__name__)
CORS(app)
cors = CORS(app, resource={
    r"/*":{"origins":"*"}
})

mode = 0

@app.route("/")
def main():
    return 'main'

# 1-Get Mode From Mobile: 0 = Manual , 1 = Auto
@app.route('/post', methods=['POST'])
def post():
    if request.method == 'POST':
        data = request.get_json()
        print(data["value"])
        mode = data["value"]
        # print(type(mode))
        return str(data)

# 2-Get Manual Direction From Mobile
@app.route("/get/")
def move():
    global dir 
    value=request.args.get('val')
    print(value)
    dir=value
    return "done"

# Send Manual Direction value to Arduino    
@app.route("/send",methods=['GET'])
def send():
    return str(dir)

    
if __name__ == "__main__":
    app.run(host='172.28.132.223', port= 8000, debug=True)
    # app.run(port=8000,debug=True)