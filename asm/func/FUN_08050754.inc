	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x29
	ldrb r0, [r2]
	cmp r0, #0
	beq _0805077C
	movs r1, #0
	strb r1, [r2]
	str r1, [sp]
	ldr r0, _0805078C @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl FUN_0823ce68
_0805077C:
	ldr r0, [r4, #0x24]
	cmp r0, #0xa
	bne _08050790
	movs r0, #7
	bl FUN_0809c08c
	b _080507AE
	.align 2, 0
_0805078C: .4byte 0x0000FFFF
_08050790:
	cmp r0, #0x14
	bls _080507AE
	cmp r0, #0x28
	bne _0805079C
	bl FUN_0804e604
_0805079C:
	bl FUN_0804ba3c
	cmp r0, #0
	bne _080507AE
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #1
	str r0, [r1]
	b _080507B4
_080507AE:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
_080507B4:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
