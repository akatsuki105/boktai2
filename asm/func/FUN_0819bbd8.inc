	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, _0819BBFC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BC00
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BC02
	.align 2, 0
_0819BBFC: .4byte 0x0000046D
_0819BC00:
	movs r0, #0
_0819BC02:
	cmp r0, #0
	beq _0819BC1A
	ldr r1, _0819BC58 @ =0x00000CBB
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0819BC5C @ =0x0000093C
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xfa
	bl FUN_0819fd0c
_0819BC1A:
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_0819f8d8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819BC6C
	ldr r4, _0819BC60 @ =FUN_0819bca0
	movs r3, #0x2f
	ldr r0, _0819BC64 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819BC68 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	b _0819BC76
	.align 2, 0
_0819BC58: .4byte 0x00000CBB
_0819BC5C: .4byte 0x0000093C
_0819BC60: .4byte FUN_0819bca0
_0819BC64: .4byte 0x0000046D
_0819BC68: .4byte 0x0000046B
_0819BC6C:
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0819BC88
_0819BC76:
	ldr r0, _0819BC84 @ =0x000008BC
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xf7
	bl FUN_0819fd0c
	b _0819BC94
	.align 2, 0
_0819BC84: .4byte 0x000008BC
_0819BC88:
	ldr r0, _0819BC9C @ =0x0000093C
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xfa
	bl FUN_0819fd0c
_0819BC94:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819BC9C: .4byte 0x0000093C
