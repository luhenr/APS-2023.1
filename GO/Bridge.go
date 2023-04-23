package main

import "fmt"

// Abstração
type Forma interface {
	Desenhar()
}

// Abstração Concreta
type Circulo struct {
	x, y, raio int
	desenhador Desenhador
}

func (c *Circulo) Desenhar() {
	c.desenhador.DesenharCirculo(c.x, c.y, c.raio)
}

// Abstração Concreta
type Quadrado struct {
	x, y, lado int
	desenhador Desenhador
}

func (s *Quadrado) Desenhar() {
	s.desenhador.DesenharQuadrado(s.x, s.y, s.lado)
}

// Implementador
type Desenhador interface {
	DesenharCirculo(x, y, raio int)
	DesenharQuadrado(x, y, lado int)
}

// Implementador Concreto
type Tela struct{}

func (s *Tela) DesenharCirculo(x, y, raio int) {
	fmt.Printf("Desenhando círculo na tela em (%d, %d) com raio %d\n", x, y, raio)
}

func (s *Tela) DesenharQuadrado(x, y, lado int) {
	fmt.Printf("Desenhando quadrado na tela em (%d, %d) com lado %d\n", x, y, lado)
}

// Implementador Concreto
type Impressora struct{}

func (p *Impressora) DesenharCirculo(x, y, raio int) {
	fmt.Printf("Imprimindo círculo em (%d, %d) com raio %d\n", x, y, raio)
}

func (p *Impressora) DesenharQuadrado(x, y, lado int) {
	fmt.Printf("Imprimindo quadrado em (%d, %d) com lado %d\n", x, y, lado)
}

func main() {
	// Desenhar um círculo na tela
	circulo := &Circulo{x: 10, y: 10, raio: 5, desenhador: &Tela{}}
	circulo.Desenhar()

	// Desenhar um quadrado na tela
	quadrado := &Quadrado{x: 20, y: 20, lado: 10, desenhador: &Tela{}}
	quadrado.Desenhar()

	// Imprimir um círculo
	circulo = &Circulo{x: 100, y: 100, raio: 50, desenhador: &Impressora{}}
	circulo.Desenhar()

	// Imprimir um quadrado
	quadrado = &Quadrado{x: 200, y: 200, lado: 20, desenhador: &Impressora{}}
	quadrado.Desenhar()
}
