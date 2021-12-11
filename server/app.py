from flask import Flask, render_template, url_for
app = Flask(__name__)

debug_bool = True


@app.route('/')
@app.route('/home')
def main_page():
    return render_template("index.html")


@app.route('/about')
def about_page():
    return render_template("about.html")

@app.route('/user/<string:name>/<int:id>')
def person(name, id):
    return("user hage " + name  + " - "+ str(id))

if(__name__ == '__main__'):
    app.run(debug=debug_bool)
