from minio import Minio


#   nhrYWAOXuNVdkyAkC2iK
#   5RKwhxI4ULZqb7HaZr7Fw8g72HYyBUem7jNyaXOz


# Create client with access key and secret key.
client = Minio(
    "192.168.1.230:9000",
    access_key="nhrYWAOXuNVdkyAkC2iK",
    secret_key="5RKwhxI4ULZqb7HaZr7Fw8g72HYyBUem7jNyaXOz",
    secure=False,
)


bucket_name = "bucket1"  # Nombre del nuevo bucket que deseas crear

# Comprueba si el bucket ya existe
if client.bucket_exists(bucket_name):
    print(f"El bucket '{bucket_name}' ya existe.")
else:
    # Crea el nuevo bucket
    client.make_bucket(bucket_name)
    print(f"Se ha creado el bucket '{bucket_name}' correctamente.")

# Subir un archivo al bucket.
file_path = "C:/Users/juanan.fernandez/Juan-Antonio/archivo1.txt"
object_name = "archivo1.txt"
client.fput_object(bucket_name, object_name, file_path)

# # Descargar un archivo del bucket.
# download_path = "/path/to/downloaded_file.txt"
# client.fget_object(bucket_name, object_name, download_path)

# # Listar objetos en el bucket.
# objects = client.list_objects(bucket_name, recursive=True)
# for obj in objects:
#     print(obj.object_name, obj.size)

# # Eliminar un objeto del bucket.
# client.remove_object(bucket_name, object_name)