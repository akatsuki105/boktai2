	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08067F80
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r3, _08067F7C @ =0x0000036A
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08067F80
	movs r0, #1
	b _08067F82
	.align 2, 0
_08067F7C: .4byte 0x0000036A
_08067F80:
	movs r0, #0
_08067F82:
	pop {r1}
	bx r1
	.align 2, 0
