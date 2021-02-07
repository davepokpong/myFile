let cache = [];

a = document.createElement("h1");
a.classList.add("title-text")
a.innerText = "Dave";

function makeNewNode(text) {
    newNode = document.createElement('p')
    newNode.innerText = text
    return newNode
}

app = document.getElementById("app");

app.appendChild(a);

setInterval(()=>{
fetch("https://backend.cpsk-club.xyz/twitter")
    .then((data) => data.json())
    .then((datas) => {
    datas.forEach(data => {
        if (!cache.includes(data.auther)){
            app.appendChild(makeNewNode(data.author));
            cache.push(data.author);
        }
        });
    });
}, 5000);


// fetch("https://jsonplaceholder.typicode.com/posts")
//     .then((data) => data.json)
//     .then((data) => {
//         a.innerText = data.title;
//     });

function scream(author, content) {
    fetch("https://backend.cpsk-club.xyz/twitter", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ author: author, content: content }),
    })
      .then((response) => response.text())
      .then((result) => console.log(result))
      .catch((error) => console.log("error", error));
  }
// เอา function ผูกกับ form ใน html
let form = document.getElementById("tweet");
form.addEventListener("submit", (event) => {
    event.preventDefault();
    author = form.elements["author"].value;
    content = form.elements["content"].value;
    scream(author, content);
    form.elements["author"].value = "";
    form.elements["content"].value = "";
  });