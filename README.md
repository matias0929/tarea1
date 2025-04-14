# descripcion
Este programa permite a los usuarios enviar **tickets de soporte**, cada uno con:

- Un ID
- Una descripción
- Una prioridad (`BAJA`, `MEDIA`, `ALTA`)
- Y una hora de registro (automática), utilizada para ordenar los tickets por prioridad y orden de llegada

Los tickets se almacenan y procesan según estas prioridades.
# Funcionalidades
1	Registrar ticket: solicita ID y descripción. Se asigna prioridad BAJA por defecto.
2	Asignar prioridad: permite cambiar la prioridad de un ticket existente (0 = Baja, 1 = Media, 2 = Alta).
3	Mostrar tickets: lista todos los tickets ordenados por prioridad y hora.
4	Procesar siguiente ticket: toma el ticket más urgente (alta prioridad primero).
5	Buscar ticket por ID: muestra los detalles del ticket con ese ID.
0	Terminar programa
# limitaciones
Actualmente, no se valida si el ID del ticket ya existe al momento de registrar uno nuevo.
No se guarda la información en archivos, por lo que los datos se pierden al cerrar el programa.
No hay manejo de errores si el usuario ingresa letras en vez de números.


