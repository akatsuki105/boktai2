	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, [r7, #0x18]
	mov sl, r0
	cmp r0, #0
	bne _0820F1C8
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r0, #1
	mov sb, r0
	mov r0, sb
	strh r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	subs r1, #0xa
	adds r5, r7, r1
	adds r1, #1
	adds r6, r7, r1
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0820efc4
	adds r4, r7, #0
	adds r4, #0x28
	mov r0, r8
	ldrh r1, [r0]
	ldrb r2, [r5]
	ldrb r3, [r6]
	mov r0, sb
	str r0, [sp]
	mov r0, sl
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08055b5c
	adds r0, r4, #0
	bl FUN_08055c04
	adds r0, r4, #0
	bl FUN_08055d20
	cmp r0, #0
	beq _0820F1CE
	ldr r2, _0820F1BC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0820F1C0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0820F1C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x20
	bl Mod
	adds r0, #0x3c
	b _0820F1CC
	.align 2, 0
_0820F1BC: .4byte 0x030046B8
_0820F1C0: .4byte 0x000003FF
_0820F1C4: .4byte 0x0203B400
_0820F1C8:
	mov r0, sl
	subs r0, #1
_0820F1CC:
	str r0, [r7, #0x18]
_0820F1CE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
