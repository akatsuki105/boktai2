	push {lr}
	adds r1, r0, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	bne _08027F3C
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08027F54
	ldr r2, _08027F38 @ =0x00000FD4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027F4A
	movs r0, #8
	b _08027F56
	.align 2, 0
_08027F38: .4byte 0x00000FD4
_08027F3C:
	ldr r2, _08027F50 @ =0x00000824
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08027F54
	cmp r0, #1
	beq _08027F54
_08027F4A:
	movs r0, #3
	b _08027F56
	.align 2, 0
_08027F50: .4byte 0x00000824
_08027F54:
	movs r0, #1
_08027F56:
	pop {r1}
	bx r1
	.align 2, 0
