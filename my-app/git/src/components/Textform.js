import React, { useState } from 'react';
export default function TextForm(props) {
 
    // setText("ankit gautam g");
 
    const handleUpClick = () => {
        console.log("Uppercase was clicked  " + text);
        let newText = text.toUpperCase();
        setText(newText);
        props.showAlert("Converted to uppercase","success");
    }
    const handleDownClick = () => {
        console.log("Lowercase was clicked  " + text);
        let newText = text.toLowerCase();
        setText(newText);
        props.showAlert("Converted to lowercase","success");
    }
 
    const clearText = ()=>{
        console.log("Text is cleared");
        var text= document.getElementById("myBox");
       setText("");
       props.showAlert("Text is cleared","success");
    }
    const handleCopy = ()=>{
        console.log("I am copy");
        var text= document.getElementById("myBox");
        text.select();
        navigator.clipboard.writeText(text.value);
        props.showAlert("Text is copied","success");
    }
 
    const handleExtraSpaces = ()=>{
        let newText=text.split(/[ ]+/);
        setText(newText.join(" "))
    }
 
    const handleOnChange = (event) => {
        console.log("On Change");
        setText(event.target.value);
    }
    const [text, setText] = useState('Enter text here:');
    return (
        <>
            <div className="container" style={{color: props.mode==='light'?'black':'white'}}>
            <h1>{props.heading} </h1>
                <div className="mb-3">
                    <textarea className="form-control" value={text} onChange={handleOnChange} style={{backgroundColor: props.mode==='light'?'white':'black',color: props.mode==='light'?'black':'white'}} id="myBox" rows="6"></textarea>
                </div>
                <button className="btn btn-primary mx-light" onClick={handleUpClick} >CONVERT TO
                UPPER</button>
                <button className="btn btn-primary mx-1" onClick={handleDownClick} >CONVERT TO
                LOWER</button>
                <button className="btn btn-primary mx-1" onClick={handleCopy} >Copy Text</button>
                <button className="btn btn-primary mx-1" onClick={handleExtraSpaces} >handleExtraSpaces</button>
                <button className="btn btn-primary mx-1" onClick={clearText} >clearText</button>
 
            </div>
            <div className="container my-3" style={{color: props.mode==='light'?'black':'white'}}>
                <h1>Your text results</h1>
                <h6>{text.split(" ").length} words and {text.length} characters.</h6>
                <h6>it will take {0.45 * text.split(" ").length} seconds to read the given text.</h6>
                <h2>Preview</h2>
                <p>{ text}</p>
            </div>
        </>
    )
}
