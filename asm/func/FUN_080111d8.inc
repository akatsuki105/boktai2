	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	mov r8, r1
	adds r7, r2, #0
	movs r0, #0
	mov sb, r0
	movs r6, #0
	cmp sb, r7
	bge _0801122A
	mov r5, r8
	cmp r5, #0x8f
	bgt _0801122A
_080111F8:
	adds r0, r5, #0
	movs r1, #6
	bl Div
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #6
	bl Mod
	add r4, sl
	ldrb r1, [r4]
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	lsls r1, r6
	mov r0, sb
	orrs r0, r1
	mov sb, r0
	adds r6, #1
	cmp r6, r7
	bge _0801122A
	mov r0, r8
	adds r5, r0, r6
	cmp r5, #0x8f
	ble _080111F8
_0801122A:
	mov r0, sb
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
