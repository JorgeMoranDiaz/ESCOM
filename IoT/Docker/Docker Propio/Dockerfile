FROM python:3.12-slim

WORKDIR /app

RUN apt-get update && apt-get install -y make && rm -rf /var/lib/apt/lists/*

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY app.py .
COPY Makefile .
COPY Veterinario ./Veterinario

EXPOSE 5000

CMD ["make", "run"]
