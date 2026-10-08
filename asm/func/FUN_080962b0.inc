	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _080962CA
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08095a5c
	b _080962FC
_080962CA:
	cmp r0, #1
	bne _080962FC
	ldr r0, _08096304 @ =0x00003AEE
	adds r4, r5, r0
	ldrb r2, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0x14
	bl FUN_080956c4
	ldrb r0, [r4]
	bl FUN_08242c08
	adds r0, r5, #0
	bl FUN_0809536c
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080954a8
	ldr r1, _08096308 @ =FUN_0809630c
	adds r0, r5, #0
	movs r2, #1
	bl EntityCC28_SetState
_080962FC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096304: .4byte 0x00003AEE
_08096308: .4byte FUN_0809630c
