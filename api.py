from fastapi import FastAPI
import sqlite3

app = FastAPI()

@app.get("/users/{username}")
def get_user(username: str):
    conn = sqlite3.connect("database.db")
    cursor = conn.cursor()
    # Vulnerable: String concatenation allows SQL Injection
    cursor.execute(f"SELECT * FROM users WHERE username = '{username}'") 
    return cursor.fetchall()
