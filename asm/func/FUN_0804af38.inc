	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AF8A
	movs r5, #0
	strb r5, [r1]
	movs r0, #4
	str r0, [sp]
	ldr r0, _0804AF7C @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0804AF84
	ldr r0, _0804AF80 @ =0x0300481C
	str r5, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _0804AF8A
	.align 2, 0
_0804AF7C: .4byte 0x0000FFFF
_0804AF80: .4byte 0x0300481C
_0804AF84:
	movs r0, #0xdd
	bl PlaySound_082406e0
_0804AF8A:
	ldr r0, [r4, #0x34]
	cmp r0, #0x14
	bne _0804AFAA
	adds r0, r4, #0
	adds r0, #0x2f
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #2
	subs r0, #0x17
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804AFAA
	movs r1, #0
	bl VM_ExecByID
_0804AFAA:
	ldr r0, [r4, #0x34]
	adds r0, #1
	str r0, [r4, #0x34]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
