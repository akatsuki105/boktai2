	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r4, _08204D28 @ =0x03000220
	ldr r0, [r4]
	cmp r0, #0
	bne _08204D18
	bl Entity08204cb8_Create
	str r0, [r4]
_08204D18:
	adds r0, r5, #0
	adds r1, r6, #0
	bl Entity08204cb8_AddElem
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08204D28: .4byte 0x03000220
