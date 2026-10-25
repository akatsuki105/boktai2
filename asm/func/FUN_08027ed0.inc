	push {lr}
	adds r1, r0, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027EF4
	ldr r2, _08027EF0 @ =0x00000824
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08027EFE
	cmp r0, #1
	bne _08027EFE
	movs r0, #0xc1
	b _08027F0A
	.align 2, 0
_08027EF0: .4byte 0x00000824
_08027EF4:
	ldr r2, _08027F04 @ =0x00000FD4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08027F08
_08027EFE:
	movs r0, #0xc3
	b _08027F0A
	.align 2, 0
_08027F04: .4byte 0x00000FD4
_08027F08:
	movs r0, #0xc8
_08027F0A:
	pop {r1}
	bx r1
	.align 2, 0
