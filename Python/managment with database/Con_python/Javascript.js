function signIn() {
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    // Make an AJAX POST request to the Flask server
    fetch('/login', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({
            username: username,
            password: password
        })
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            alert(data.message);
            // Redirect to dashboard or perform other actions upon successful login
        } else {
            alert(data.message);
            // Handle failed login (display error message, clear input fields, etc.)
        }
    })
    .catch(error => console.error('Error:', error));
}
