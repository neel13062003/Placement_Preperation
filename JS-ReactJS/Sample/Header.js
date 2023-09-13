import React from 'react'

function Header(props){
    return (
        <div style={{background:"red"}}>
            <p><h1 style={{background:"yellow"}}>Header</h1></p>
            <h1>{props.name} - {props.title}</h1>                                                     
            <p style={{background:"blue"}}>This is Header</p>
        </div>
    )
}

export default Header;