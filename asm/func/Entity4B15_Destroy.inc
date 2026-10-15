	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x20
	movs r6, #3
_08019FEA:
	adds r0, r5, #0
	adds r1, r4, #0
	bl Entity4B15Elem_Destroy
	adds r4, #0x38
	subs r6, #1
	cmp r6, #0
	bge _08019FEA
	movs r1, #0
	ldr r0, _0801A008 @ =0x03000090
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801A008: .4byte 0x03000090
