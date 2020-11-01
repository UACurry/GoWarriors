from flask import Flask,render_template,redirect,url_for

app = Flask(__name__)


#登录
@app.route('/')
def home():
    return render_template('home.html')


@app.route('/login')
def login_success():
    return render_template('login.html')


@app.route('/<name>')
def test(name):
    return f"hello {name}"


@app.route('/big_dick')
def admin():
    return redirect(url_for('login_success'))


if __name__ == '__main__':
    app.run(debug=True)
