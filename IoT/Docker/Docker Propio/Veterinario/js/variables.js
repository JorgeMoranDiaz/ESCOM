import { generarId } from "./funciones.js";
let editando = {
    value:false
};

const citaObj = {
    id : generarId(),
    paciente : '',
    propietario: '',
    email :'',
    fecha:'',
    sintomas :''
}

export {
    editando, citaObj
}