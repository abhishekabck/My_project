from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/login', methods=['POST'])
def login():
    # Get username and password from the request
    username = request.json.get('username')
    password = request.json.get('password')

    # Perform authentication (replace this with your actual authentication logic)
    if username == 'admin' and password == 'password':
        return jsonify({'success': True, 'message': 'Login successful'})
    else:
        return jsonify({'success': False, 'message': 'Invalid username or password'})

if __name__ == '__main__':
    app.run(debug=True)
    login()
