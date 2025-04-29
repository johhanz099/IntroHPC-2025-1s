# Parámetros comunes
NSAMPLES=1000000
MU=5.0
SIGMA=1.0
XMIN=0.0
XMAX=10.0
NBINS=100

# Seeds específicas
SEEDS=1 2 5

# Nombre del ejecutable
EXE=random_pdf.x

all: random_pdf.pdf

random_pdf.pdf: grafica.gp data1.txt data2.txt data5.txt
	gnuplot grafica.gp

# Reglas para generar cada archivo de datos
data1.txt: $(EXE)
	./$(EXE) 1 $(NSAMPLES) $(MU) $(SIGMA) $(XMIN) $(XMAX) $(NBINS) > data1.txt

data2.txt: $(EXE)
	./$(EXE) 2 $(NSAMPLES) $(MU) $(SIGMA) $(XMIN) $(XMAX) $(NBINS) > data2.txt

data5.txt: $(EXE)
	./$(EXE) 5 $(NSAMPLES) $(MU) $(SIGMA) $(XMIN) $(XMAX) $(NBINS) > data5.txt

# Regla para compilar el programa
$(EXE): random_pdf.cpp
	g++ random_pdf.cpp -o $(EXE)

# Limpieza de archivos generados
clean:
	rm -f *.txt *.x *.pdf

	