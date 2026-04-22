import Notificacion from "./clases/Notificacion.js";
import AdminCitas from "./clases/AdminCitas.js";
import { citaObj, editando } from "./variables.js";
import { formulario, pacienteInput, propietarioInput, emailInput, fechaInput, sintomasInput } from "./selectores.js";

const citas = new AdminCitas();
export function datosCita(e){
    citaObj[e.target.name] = e.target.value;
}

export function submitCita(e){
    e.preventDefault();
    if(Object.values(citaObj).some(valor => valor.trim() == '')){
        const notificacion = new Notificacion({
            texto: 'Todos los campos son obligatorios',
            tipo: 'error'
        });
        return;
    }

    if(editando.value){
        citas.editar({...citaObj});
        const notificacion = new Notificacion({
            texto: 'Guardado correctamente',
            tipo: 'exito'
        });
    }
    else{
        citas.agregar({...citaObj});
        const notificacion = new Notificacion({
            texto: 'Cita agregada correctamente',
            tipo: 'exito'
        });
    }
    
    formulario.reset();
    reiniciarObjetoCita();
    btnSubmit.value = 'REGISTRAR PAICIENTE';
    editando.value = false;
}

export function reiniciarObjetoCita(){
    Object.assign(citaObj,{
    id : generarId(),
    paciente : '',
    propietario: '',
    email :'',
    fecha:'',
    sintomas :''});
}

export function cargarEdicion(cita){
    pacienteInput.value = cita.paciente;
    propietarioInput.value = cita.propietario;
    emailInput.value = cita.email;
    fechaInput.value = cita.fecha;
    sintomasInput.value = cita.sintomas;

    Object.assign(citaObj, cita);
    editando.value = true;
    btnSubmit.value = 'GUARDAR CAMBIOS';
    
}

export function generarId(){
    return Math.random().toString(36).substring(2) + Date.now();
}