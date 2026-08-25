	push {lr}
	ldr r0, _08224D44 @ =0x03000248
	ldr r0, [r0]
	cmp r0, #0
	bne _08224D4C
	ldr r0, _08224D48 @ =0x0000BB34
	movs r1, #0
	bl Entity8AAB_Create
	cmp r0, #0
	bne _08224D4C
	movs r0, #0
	b _08224D52
	.align 2, 0
_08224D44: .4byte 0x03000248
_08224D48: .4byte 0x0000BB34
_08224D4C:
	ldr r1, _08224D58 @ =0x00000F24
	adds r0, r0, r1
	ldrb r0, [r0]
_08224D52:
	pop {r1}
	bx r1
	.align 2, 0
_08224D58: .4byte 0x00000F24
