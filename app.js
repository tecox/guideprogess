/*
function User() {               // creates the User() function
    var username, password;     // initializes two undefined variables
    
    function loginAction(user, pw) {    // creates the loginAction() function
        username = user;        // sets username to user
        password = pw;          // sets password to pw

        console.log("You have logged in as " + username); // returns username
        console.log("With the password " + password);     // returns password
    }

    var globalTouchstone = {    // initializes an object variable
        login: loginAction      // with the property "login" set to loginAction
    };

    return globalTouchstone;    // returns an object that would otherwise have
                                // stopped existing after the function ran
}

var johnny = User();            // becomes a private instance of the globalTouchstone
                                // object, with the property "login": loginAction

johnny.login("Johnny", "itsasecret"); // johnny.login is loginAction, but the
                                // instances of username and password are private
*/



var sparky = {
    species: "dog",
    legs: 4,
    happy: true
};
function hideIt() {
    function creator() {
        return 5;
    };
    var obj = new creator();
    console.log(obj);
    console.log(obj.constructor.name);
}

hideIt();

var prefix = "heck";

var anObject = {
    [prefix + "Yeah"]: "cool"
};

console.log(anObject.heckYeah);