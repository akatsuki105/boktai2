	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, _0809EBA8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EBAC
	movs r0, #0
	b _0809EBB0
	.align 2, 0
_0809EBA8: .4byte 0x03002C68
_0809EBAC:
	adds r0, #0x66
	ldrh r0, [r0]
_0809EBB0:
	cmp r0, #0
	beq _0809EBE4
	movs r1, #2
	ldr r0, _0809EBCC @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _0809EBD0 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809EBD4
	movs r0, #1
	b _0809EBD6
	.align 2, 0
_0809EBCC: .4byte 0x030046A0
_0809EBD0: .4byte 0x00000934
_0809EBD4:
	movs r0, #0
_0809EBD6:
	cmp r0, #0
	bne _0809EBE8
	adds r0, r2, #0
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809EBE8
_0809EBE4:
	movs r0, #0
	b _0809EBEE
_0809EBE8:
	adds r0, r4, #0
	bl FUN_0809eb6c
_0809EBEE:
	pop {r4}
	pop {r1}
	bx r1
