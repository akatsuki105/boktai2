	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	bl FUN_0823e650
	adds r7, r0, #0
	cmp r7, #1
	bne _0823E7F4
	ldr r0, _0823E808 @ =0x03004810
	mov sb, r0
	ldrb r0, [r0]
	bl FUN_0823d930
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r1, #0xfa
	lsls r1, r1, #3
	adds r5, r5, r1
	mov r1, sb
	ldrb r0, [r1, #1]
	bl FUN_0823d930
	mov sl, r0
	mov r0, sl
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	mov r1, sb
	ldrb r0, [r1, #2]
	bl FUN_0823d930
	mov r8, r0
	mov r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r1, sb
	ldrb r0, [r1, #4]
	bl FUN_0823d930
	adds r6, r0, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r1, sb
	ldrb r0, [r1, #5]
	bl FUN_0823d930
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r1, sb
	ldrb r0, [r1, #6]
	bl FUN_0823d930
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r4, [sp]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	adds r0, r5, #0
	mov r1, sl
	mov r2, r8
	adds r3, r6, #0
	bl SetGameDateTime
_0823E7F4:
	adds r0, r7, #0
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823E808: .4byte 0x03004810
