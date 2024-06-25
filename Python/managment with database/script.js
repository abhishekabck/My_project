function signIn() {
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    // Here you would typically make an AJAX request to your Python backend
    // for user authentication. For demo purposes, we'll just assume authentication is successful.
    // If successful, redirect to the user dashboard or display a success message.
    alert("Sign in successful. Redirecting to dashboard...");
}

function showSignUpForm() {
    document.getElementById("loginForm").style.display = "none";
    document.getElementById("signUpForm").style.display = "block";
}

function hideSignUpForm() {
    document.getElementById("loginForm").style.display = "block";
    document.getElementById("signUpForm").style.display = "none";
}

function signUp() {
    var name = document.getElementById("name").value;
    var age = document.getElementById("age").value;
    var mobile = document.getElementById("mobile").value;
    var address = document.getElementById("address").value;
    var gender = document.getElementById("gender").value;

    // Here you would typically make an AJAX request to your Python backend
    // for user registration. For demo purposes, we'll just display a success message.
    alert("Sign up successful. Please wait for account confirmation.");
}
