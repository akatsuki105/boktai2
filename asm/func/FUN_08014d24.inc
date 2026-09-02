	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _08014D90 @ =0x03000058
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	beq _08014D82
	movs r1, #0
	movs r2, #0
_08014D3C:
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x24
	mov r3, sb
	adds r6, r3, r0
	ldrb r0, [r6]
	adds r1, #1
	mov r8, r1
	cmp r0, #0
	beq _08014D7C
	adds r4, r6, #4
	adds r5, r6, #0
	adds r5, #0x14
	movs r7, #7
_08014D5E:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08014D70
	adds r0, r5, #0
	str r2, [sp]
	bl FUN_0822dabc
	ldr r2, [sp]
	strb r2, [r4]
_08014D70:
	adds r4, #0x38
	adds r5, #0x38
	subs r7, #1
	cmp r7, #0
	bge _08014D5E
	strb r2, [r6]
_08014D7C:
	mov r1, r8
	cmp r1, #5
	ble _08014D3C
_08014D82:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014D90: .4byte 0x03000058
