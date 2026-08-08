	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	ldr r0, _082160D0 @ =0x00000E8C
	add r0, sb
	mov r8, r0
	ldr r0, _082160D4 @ =0x000012BC
	add r0, sb
	movs r1, #0
	ldrsh r6, [r0, r1]
	movs r7, #0
_08216076:
	movs r0, #2
	subs r0, r0, r7
	lsls r5, r0, #1
	adds r5, r5, r0
	lsls r5, r5, #5
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r4, r5, r0
	add r4, r8
	adds r0, r6, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sb
	adds r1, #0x18
	movs r3, #1
	bl FUN_0822f3cc
	movs r2, #0xf4
	lsls r2, r2, #1
	add r2, r8
	adds r2, r2, r5
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	adds r6, r0, #0
	adds r7, #1
	cmp r7, #2
	ble _08216076
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082160D0: .4byte 0x00000E8C
_082160D4: .4byte 0x000012BC
