	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	bge _081DDCC6
	movs r1, #0
	mov sb, r1
	ldr r2, _081DDCB8 @ =0x270F0000
	mov r8, r2
_081DDC56:
	adds r0, r7, #0
	bl FUN_081df720
	lsls r5, r7, #1
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r6, r2
	adds r4, r1, r5
	lsls r0, r0, #4
	subs r2, #0x10
	adds r1, r6, r2
	adds r1, r1, r5
	ldrh r2, [r1]
	lsls r1, r2, #3
	adds r1, r1, r2
	adds r0, r0, r1
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r6, r2
	adds r1, r1, r5
	ldrh r1, [r1]
	lsls r1, r1, #2
	subs r0, r0, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081DDC90
	mov r0, sb
	strh r0, [r4]
_081DDC90:
	movs r1, #0
	ldrsh r0, [r4, r1]
	mov r2, r8
	asrs r3, r2, #0x10
	cmp r0, r3
	ble _081DDC9E
	strh r3, [r4]
_081DDC9E:
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r2, r0, r5
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #0
	ldrsh r0, [r4, r5]
	adds r1, r1, r0
	cmp r1, r3
	ble _081DDCBC
	strh r3, [r2]
	b _081DDCBE
	.align 2, 0
_081DDCB8: .4byte 0x270F0000
_081DDCBC:
	strh r1, [r2]
_081DDCBE:
	adds r7, #1
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	blt _081DDC56
_081DDCC6:
	cmp r7, #3
	bgt _081DDCEC
	ldr r1, _081DDCF8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r7, #1
	movs r5, #0x98
	lsls r5, r5, #1
	adds r0, r0, r5
	adds r1, r0, r6
_081DDCD8:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldrh r0, [r1, #8]
	orrs r0, r2
	strh r0, [r1, #8]
	adds r1, #2
	adds r7, #1
	cmp r7, #3
	ble _081DDCD8
_081DDCEC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DDCF8: .4byte 0x0000FFFF
