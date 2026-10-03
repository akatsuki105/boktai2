	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r6, #0
_080AC9AE:
	movs r0, #0x5c
	adds r1, r6, #0
	muls r1, r0, r1
	adds r0, r7, r1
	adds r0, #0x90
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AC9C8
	adds r0, r1, #0
	adds r0, #0x40
	adds r0, r7, r0
	bl FUN_080ac738
_080AC9C8:
	adds r6, #1
	cmp r6, #0x17
	ble _080AC9AE
	movs r0, #0
	mov sb, r0
	ldr r1, _080ACA3C @ =0x0000FFFF
	mov r8, r1
	adds r5, r7, #0
	adds r5, #0x24
	adds r3, r7, #0
	adds r3, #0x1c
	movs r6, #2
_080AC9E0:
	ldrh r0, [r5, #2]
	adds r0, #1
	strh r0, [r5, #2]
	mov r1, r8
	ands r0, r1
	cmp r0, #0x1f
	bls _080ACA20
	movs r0, #0x8e
	lsls r0, r0, #4
	adds r4, r7, r0
	ldrh r1, [r4]
	movs r0, #0x5c
	muls r0, r1, r0
	adds r0, #0x40
	adds r0, r7, r0
	ldrh r2, [r5]
	adds r1, r3, #0
	str r3, [sp]
	bl FUN_080ac874
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	mov r1, r8
	ands r0, r1
	ldr r3, [sp]
	cmp r0, #0x17
	bls _080ACA1C
	mov r0, sb
	strh r0, [r4]
_080ACA1C:
	mov r1, sb
	strh r1, [r5, #2]
_080ACA20:
	adds r5, #0xc
	adds r3, #0xc
	subs r6, #1
	cmp r6, #0
	bge _080AC9E0
	movs r0, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080ACA3C: .4byte 0x0000FFFF
