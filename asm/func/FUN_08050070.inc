	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _080500C6
	movs r0, #0
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x3c
	movs r5, #0
	ldrb r0, [r3, #6]
	lsls r0, r0, #0x10
	str r0, [sp]
	movs r2, #0
_08050092:
	adds r0, r3, r2
	ldrb r1, [r0]
	lsls r1, r5
	ldr r0, [sp]
	orrs r0, r1
	str r0, [sp]
	adds r2, #1
	adds r5, #4
	cmp r2, #3
	ble _08050092
	adds r0, r4, #0
	movs r1, #2
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0804fbd0
	adds r0, r4, #0
	bl FUN_0804fe24
	adds r0, r4, #0
	bl FUN_0804fe68
_080500C6:
	movs r1, #0xc
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0xc
	bne _080500FC
	adds r0, r4, #0
	bl FUN_0804f97c
	movs r1, #0xd
	rsbs r1, r1, #0
	ldr r0, [r4, #0x20]
	ands r0, r1
	str r0, [r4, #0x20]
	movs r1, #3
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x24]
	adds r0, r4, #0
	bl FUN_0804fbe0
	b _08050102
_080500FC:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
_08050102:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
