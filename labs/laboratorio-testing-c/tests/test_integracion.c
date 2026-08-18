#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_compra_con_descuento(void) {
    printf("\n [descuento: el total del carrito con el descuento es el correcto]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200, 3};
    Producto f = {"Leche", 350, 2};
    carrito_agregar(&c, p);
    carrito_agregar(&c, f);
    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}
/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_agregar_hasta_llenar(void) {
    printf("\n [agregar productos hasta llenar el carrito]\n");
    Carrito c;
    Producto p = {"RTX 5090", 100000, 1};
    while(c.cantidad < MAX_ITEMS){
        carrito_agregar(&c, p);
    }
    ASSERT_IGUAL(c.cantidad, MAX_ITEMS);
    ASSERT_IGUAL(0, carrito_agregar(&c, p));
    ASSERT_IGUAL(c.cantidad, MAX_ITEMS);
}

/* TODO: escribir test_agregar_hasta_llenar() */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento(); 
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
